/*
******Projekt to solve the knight problem********
*************************************************
Authors:	Philipp Horlaender & Konrad Muench
Course:		Computer Engineering
Semsester:	WiSe 2018/2019
**************************************************
*/


#include "UI.h"
#include "Graph.h"
#include <map>


//User input functions------------------------

char UI::userInputChar()
{
	char inputChar;
	std::cin >> inputChar;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	return inputChar;
}

int UI::userInputInt()
{
	int inputInt;
	std::cin >> inputInt;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	return inputInt;
}


//Functions------------------------------------

void UI::checkIfAllBoardFilesThere()
{
	namespace fs = std::filesystem;
	unsigned int count = 1;

	std::string path = "\Boards";
	for (const auto showFile : fs::directory_iterator(path))
	{
		if (!path.empty())
		{
			std::cout << "*|File " << count << " found!|*" << std::endl;
			std::cout << "path\ filename: " << showFile.path() << std::endl;
		}
		else
		{
			std::cout << "*|No files found!|*" << std::endl;
		}
		count++;
	}
}

/*
Attention:
You are only able to compile the programm, when you are using
the C++ 17 version which includes the libary filesystem !
*/
void UI::saveAllBoardFiles()
{
	unsigned int choose = 1;
	std::string fileName;

	namespace fs = std::filesystem;
	std::filesystem::path dir = "Boards/";

	for (const auto & entry : fs::directory_iterator(dir))
	{
		entry.path().filename();

		fs::path path = entry.path().filename();

		fileName = path.u8string();

		boards[choose] = "Boards\\" + fileName;

		choose++;
	}

}

/*
Attention:
You are only able to compile the programm when you are using
the C++ 17 version, which includes the libary filesystem !
*/
std::ifstream& UI::loadBoardFiles()
{

	int choose = 0;
	namespace fs = std::filesystem;
	std::filesystem::path dir = "Boards/";

	choose = userInputInt();

	if (choose <= 0)
		throw "invalid input";
	

	std::cout << "Board " << choose << " loaded" << std::endl;

	std::string choosenPath = boards[choose];

	std::cout << boards[choose] << std::endl;

	m_choosenBoard = choose;

	std::ifstream* boardFile = new std::ifstream(boards[choose]);

	return *boardFile;
	
	delete boardFile;
}

//build the graph
void UI::buildGraph(Chessboard & rBoard, Graph & rGraph)
{
	BoardVector boardVec = *rBoard.getBoardVector();
	BoardMap boardMap = *rBoard.getBoardMap();

	int i, j, k, l;

	for (i = 0; i < boardMap.size(); i++)
	{
		rGraph.addNode(boardMap[i + 1]);
	}

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			for (k = i - 3; k < i + 3; k++)
			{
				for (l = j - 3; l < j + 3; l++)
				{
					//std::cout << "i = " << i << ", j = " << j << ", k = " << k << ", l = " << l << std::endl;
					if (((-1 < k) && (k < 8))
						&& ((-1 < l) && (l < 8)))
					{
						Piece* p = boardVec[k][l]->getPiece().get();

						if ((abs(i - k) == 1 && abs(j - l) == 2) || (abs(i - k) == 2 && abs(j - l) == 1))
							if (p == nullptr || p == rBoard.findKing()->getPiece().get())
							{
								//adding and creating Edge from startnode of jump to endnode of jump
								rGraph.addEdge(new Edge(*boardVec[i][j], *boardVec[k][l]));
							}
					}
				}
			}
		}
	}

	std::cout << "Graph created" << std::endl;
}

// Saves the path of the Graph into a textfile doc
void UI::savePathOfGraph(const std::deque<Edge*>& edgeList)
{
	std::ofstream output;
	std::stringstream path;
	path << "SavedPaths/PathOfBoard" << m_choosenBoard << ".txt";
	output.open(path.str());

	for (Edge* e : edgeList)
	{
		output << e->toString() << ", \n";
		std::cout << e->toString() << "," << std::endl;
	}
	output.close();

	std::cout << "\n shortest path for \"Board" << m_choosenBoard << "\" saved in \"" << path.str() << "\"" << std::endl;

}



//Screens------------------------------------

void UI::showAllSavedBoardFiles()
{
	std::cout << std::endl;
	std::cout << "********** Please choose one board *********" << std::endl;
	for (int i = 0; i < boards.size(); i++)
	{
		std::cout << std::endl;
		std::cout << std::left
			<< std::setw(TABLE_WIDTH_SMALL) << " |Number: " "[" << i + 1 << "]" << " |"
			<< std::setw(TABLE_WIDTH_SMALL) << " |Name: " << boards[i + 1] << " |"
			<< std::endl;
	}
	std::cout << "********************************************" << std::endl;
}

void UI::showCredits()
{
	std::cout << std::setw(TABLE_WIDTH)
		<< "||************|| AWESOME ||************||" << std::endl
		<< "||************|| CREDITS ||************||" << std::endl
		<< "||************|| SCREEN  ||************||" << std::endl
		<< std::endl;
		
	std::cout << "||**************************************||" << std::endl
		<< "|	Program written by :" << std::endl
		<< "|						" << std::endl
		<< "|	Philipp Horleander  " << std::endl
		<< "|	\tand" << std::endl
		<< "|	Konrad Muench" << std::endl
		<< "||**************************************||" << std::endl;
	
}

void UI::showAllSavedBoardFilesScreen()
{
	std::cout 
		<< "||************||  LOAD  ||************||" << std::endl
		<< "||************||  BOARD ||************||" << std::endl
		<< "||************|| SCREEN ||************||" << std::endl;
}

void UI::showMainMenuHead()
{
	std::cout << std::fixed << std::setw(TABLE_WIDTH)
		<< "||************||  MAIN  ||************||" << std::endl
		<< "||************||  MENU  ||************||" << std::endl
		<< "||************|| SCREEN ||************||" << std::endl
		<< std::endl;
}

void UI::showMainMenuOptions()
{
			
	std::cout << "||************************************||" << std::endl
		<< std::left << std::setw(TABLE_WIDTH) << "| [S]tart Knight" << std::setw(TABLE_WIDTH) << "| [L]oad Board |" << std::endl
		<< std::setw(TABLE_WIDTH) << "| [C]redits " << std::setw(TABLE_WIDTH) << "| [Q]uit       |" << std::endl;
 std::cout << "||************************************||" << std::endl;
}

void UI::mainMenuChoose(Chessboard& rBoard)
{
	bool run = true;
	do
	{
		system("CLS");

		showMainMenuHead();
		showMainMenuOptions();

		switch (userInputChar())
		{
			// jump with knight
		case 'S':
		case 's':
		{
			Graph knightGraph;

			if (rBoard.getBoardMap()->empty())
			{
				std::cout << "no board loaded" << std::endl;
				std::cout << "*|Press [ENTER] to return to main menu|*" << std::endl;
				std::cin.ignore();
				break;
			}

			std::cout << rBoard.draw().str() << std::endl;

			std::cout
				<< "*|Press [ENTER] to start the search for the shortest path from knight to king|*"
				<< std::endl;
			std::cin.ignore();

			// build graph

			buildGraph(rBoard, knightGraph);

			// use builded graph // Djikstra

			Node& knightField = *rBoard.findKnight();
			Node& kingField = *rBoard.findKing();
			std::deque<Edge*> shortPath;

			try
			{
				knightGraph.findShortestPathDijkstra(shortPath, knightField, kingField);
			}
			catch (...)
			{
			}

			if (!shortPath.empty())
			{
				std::cout << "shortest path found: \n" << std::endl;

				// safe path
				std::deque<Edge*> allEdges;
				for (Edge* e : knightGraph.getEdges())
				{
					allEdges.push_back(e);
				}

				savePathOfGraph(shortPath);

				std::cout << "*|Press [ENTER] to return to main menu|*" << std::endl;
				std::cin.ignore();

				
			}
			else
			{
				std::cout << "*|there is no path, try another board !|* \n " << std::endl;
				std::cout << "*|Press [ENTER] to return to main menu|*" << std::endl;
				std::cin.ignore();
				Chessboard board;
				runMainMenu(board);
			}
		}
		//empty
		case 'E':
		case 'e':
			break;
			//show credits
		case 'C':
		case 'c':
			system("CLS");
			showCredits();
			std::cout << "*|Press [ENTER] to return to main menu|*" << std::endl;
			std::cin.ignore();
			break;
			//load file
		case 'L':
		case 'l':
			system("CLS");
			runFileMenu(rBoard);
			break;

			//quit fucking, crap programm
		case 'Q':
		case 'q':
			system("CLS");
			sayGoodBye();
			run = false;
			break;

		default:
			failInput();
			break;
		}
	} while (run);
	delete &rBoard;
}

void UI::runMainMenu(Chessboard& rBoard)
{
	mainMenuChoose(rBoard);
}

void UI::showLoadFileMenu()
{
	std::cout << std::fixed << std::setw(TABLE_WIDTH)
		<< "************||  LOAD  ||*************" << std::endl
		<< "************||  BOARD ||*************" << std::endl
		<< "************|| SCREEN ||*************" << std::endl
		<< std::endl;
}

void UI::showLoadFileMenuOptions()
{
	std::cout << "||************************************||" << std::endl
		<< std::setw(TABLE_WIDTH) << "| [L]oad files "
		<< std::setw(TABLE_WIDTH) << "|[C]heck files |" << std::endl
		<< std::setw(TABLE_WIDTH) << "| [M]ain menu " << std::endl;
	std::cout << "||************************************||" << std::endl;
}

void UI::showLoadFileMenuChoose(Chessboard& rBoard)
{
	bool run = true;
	saveAllBoardFiles();
	do
	{
		showLoadFileMenu();
		showLoadFileMenuOptions();

		switch (userInputChar())
		{
			// load BoardX.txt
		case 'L':
		case 'l':
		{
			bool failed = false;
			do
			{
				failed = false;
				system("CLS");
				showAllSavedBoardFilesScreen();
				showAllSavedBoardFiles();

				try
				{
					rBoard.initialize(loadBoardFiles());
				}
				catch (...)
				{
					failInput();
					failed = true;
				}
			} while (failed);

			std::cin.ignore();
			system("CLS");
			break;
		}
			//check if all Boards in the dir /Boards
		case 'C':
		case 'c':
			system("CLS");
			showLoadFileMenu();
			checkIfAllBoardFilesThere();
			std::cout<<std::endl;
			std::cout << "*|Press [ENTER] to return to load board screen|*" << std::endl;
			std::cin.ignore();
			system("CLS");
			break;



			//run main menu
		case 'M':
		case 'm':
			system("CLS");
			run = false;
			break;
		default:
			failInput();
			break;
		}

	} while (run);
}

void UI::runFileMenu(Chessboard& rBoard)
{
	showLoadFileMenuChoose(rBoard);
}

void UI::failInput()
{
	std::cout << "*|Invalid input, please try again!|*" << std::endl;
	std::cin.ignore();
	system("CLS");
}

void UI::sayGoodBye()
{
	std::cout << std::fixed << std::setw(TABLE_WIDTH)
		<< "||************||  GOOD  ||************||" << std::endl
		<< "||************||  BYE   ||************||" << std::endl
		<< "||************||  SEE U ||************||" << std::endl;
}

void UI::showKnightLogo()
{
	  std::cout << std::fixed << std::setw(TABLE_WIDTH)
	<< "||************||  WELCOME  ||************||" << std::endl
	<< "||************||  TO OUR   ||************||" << std::endl
	<< "||************||  PROGRAM  ||************||" << std::endl;
	
	std::cout << "\t\t     ,...., " << std::endl;
	std::cout << "\t\t   ,::::::< " << std::endl;
	std::cout << "\t\t   ,::/^\\""``. " << std::endl;
	std::cout << "\t\t ,::/, `   0`. " << std::endl;
	std::cout << "\t\t ,::; |        '. " << std::endl;
	std::cout << "\t\t ,::|  \___,-.  ^^) " << std::endl;
	std::cout << "\t\t ;::|     \\   '-' " << std::endl;
	std::cout << "\t\t ;::|      \\ " << std::endl;
	std::cout << "\t\t ;::|   _.=`\\ " << std::endl;
	std::cout << "\t\t `;:|.=` _.=`\\ " << std::endl;
	std::cout << "\t\t   '|_.=`   __\\ " << std::endl;
	std::cout << "\t\t    `\\_..==`` / " << std::endl;
	std::cout << "\t\t     .'.___.-'. " << std::endl;
	std::cout << "\t\t    /         \\ " << std::endl;
	std::cout << "\t\t   ('--......--') " << std::endl;
	std::cout << "\t\t  // --......--\\\\" << std::endl;
	std::cout << "\t\t (____--...--____) " << std::endl;
	std::cout << "\t\t         |  " << std::endl;
	std::cout << "\t\t CHESS   |   KNIGHT " << std::endl;
	std::cout << "\t\t		    		 " << std::endl;
	std::cout << "\t\t      PROBLEM 		\n " << std::endl;
	
	
	std::cout << "\tPRESS [ENTER] TO START PROGRAM" <<std::endl;
	std::cin.ignore();
}

//-----------------------------------


//Construtors------------------------

UI::UI()
{
}



//Destructors------------------------

UI::~UI()
{
}


