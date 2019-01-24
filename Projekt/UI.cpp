#include "UI.h"
#include "Graph.h"
#include <map>


//Vars.------------------------------

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

//-----------------------------------


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
			std::cout << "*** File " << count << " found! ***" << std::endl;
			std::cout << "path\ filename: " << showFile.path() << std::endl;
		}
		else
		{
			std::cout << "*** No files found! ***" << std::endl;
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

	unsigned int choose = 0;
	namespace fs = std::filesystem;
	std::filesystem::path dir = "Boards/";

	choose = userInputInt();

	std::cout << "Board " << choose << " loaded" << std::endl;

	std::string choosenPath = boards[choose];

	std::cout << boards[choose] << std::endl;

	std::ifstream* boardFile = new std::ifstream(boards[choose]);

	return *boardFile;

}


//-----------------------------------

//Screens------------------------------------

void UI::showAllSavedBoardFiles()
{

	std::cout << "********************************************" << std::endl;
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
	std::cout << std::fixed << std::setw(TABLE_WIDTH)
		<< "************|| AWESOME ||*************" << std::endl
		<< "************|| CREDITS ||*************" << std::endl
		<< "************|| SCREEN  ||*************" << std::endl
		<< std::endl
		<< "Program written by:" << std::endl

		<< "---Philipp Horleander and Konrad Muench---" << std::endl
		<< std::endl;
}

void UI::showAllSavedBoardFilesScreen()
{
	std::cout << "************||  LOAD  ||*************" << std::endl
		<< "************||  BOARD ||*************" << std::endl
		<< "************|| SCREEN ||*************" << std::endl;
}

void UI::showMainMenuHead()
{
	std::cout << std::fixed << std::setw(TABLE_WIDTH)
		<< "************||  MAIN  ||*************" << std::endl
		<< "************||  MENU  ||*************" << std::endl
		<< "************|| SCREEN ||*************" << std::endl
		<< std::endl;
}

void UI::showMainMenuOptions()
{
	std::cout << "********************************************" << std::endl
		<< std::left << std::setw(TABLE_WIDTH) << "| [S]tart Knight" << std::setw(TABLE_WIDTH) << "| [L]oad Board" << std::endl
		<< std::setw(TABLE_WIDTH) << "| [C]redits " << std::setw(TABLE_WIDTH) << "| [Q]uit " << std::endl;
	std::cout << "********************************************" << std::endl;
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
				std::cout << "Press any key to return to main menu" << std::endl;
				std::cin.ignore();
				break;
			}

			std::cout << rBoard.draw().str() << std::endl;

			std::cout
				<< "Press any key to start the search for the shortest path from knight to king"
				<< std::endl;
			std::cin.ignore();

			// Graph bauen
			BoardVector boardVec = *rBoard.getBoardVector();

			int i, j, k, l, counter = 0;

			for (i = 0; i < rBoard.getBoardMap()->size(); i++)
			{
				knightGraph.addNode(new Node());
			}

			std::map<int, Node*> nodeMap;
			for (Node* n : knightGraph.getNodes())
			{
				nodeMap[counter] = n;
				counter++;
			}

			for (i = 0, j = 0; i, j < 8; i++)
			{
				for (k = i, l = j; k < i + 3, l < j + 3; k++)
				{
					//std::cout << "i = " << i << ", j = " << j << ", k = " << k << ", l = " << l << std::endl;
					if (k < 8 && l < 8)
					{
						Piece* f = boardVec[k][l]->getPiece().get();

						if ((abs(i - k) == 1 && abs(j - l) == 2) || (abs(i - k) == 2 && abs(j - l) == 1))
							if (f == nullptr || f == rBoard.findKing().getPiece().get())
							{
								//adding and creating Edge from startnode of jump to endnode of jump
								knightGraph.addEdge(&Edge(*nodeMap[i + j * 8], *nodeMap[k + l * 8]));
							}
					}
					if (k >= (i + 2))
					{
						k = i;
						l++;
					}
				}

				if (i == 7)
				{
					i = 0;
					j++;
				}
			}

			// Graph nutzen // dickstra


			// path speichern


			std::cout << "Press any key to return to main menu" << std::endl;
			std::cin.ignore();

			break;
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
			std::cout << "Press any key to return to main menu" << std::endl;
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
	std::cout << "********************************************" << std::endl
		<< std::left << std::setw(TABLE_WIDTH) << "| [L]oad files"
		<< std::setw(TABLE_WIDTH) << "| [C]heck files" << std::endl
		<< std::setw(TABLE_WIDTH) << "| [M]ain Menu" << std::endl;
	std::cout << "********************************************" << std::endl;
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
			system("CLS");
			showAllSavedBoardFilesScreen();
			showAllSavedBoardFiles();

			rBoard.initialize(loadBoardFiles());
			std::cin.ignore();
			system("CLS");
			break;

			//check if all Boards in the dir /Boards
		case 'C':
		case 'c':
			system("CLS");
			showLoadFileMenu();
			checkIfAllBoardFilesThere();
			std::cout << "Press any key to return to load board screen" << std::endl;
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
	std::cout << "Invalid input, please try again!" << std::endl;
	std::cin.ignore();
	system("CLS");
}

void UI::sayGoodBye()
{
	std::cout << std::fixed << std::setw(TABLE_WIDTH)
		<< "************|| GOOD   ||*************" << std::endl
		<< "************||  BYE   ||*************" << std::endl
		<< "************|| SCREEN ||*************" << std::endl;
}

//-----------------------------------


//Construtors--------------------------------

UI::UI()
{
}

//-----------------------------------

//Deconstrutors------------------------------

UI::~UI()
{
}

//-----------------------------------
