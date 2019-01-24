#include "UI.h"




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

void UI::mainMenuChoose()
{
	do {
		switch(userInputChar())
		{
		// jump with knight
		case 'A':
		case 'a':
			break;
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
					system("CLS");
					runMainMenu();
					break;
		//load file
		case 'L':
		case 'l':
					system("CLS");
					runFileMenu();
					break;
		
		//quit fucking, crap programm
		case 'Q':
		case 'q':	
					system("CLS");
					sayGoodBye();
					
					break;
					
					

		
		default:	
					failInput();
					runMainMenu();
					break;
		}
	} while (userInputChar() != 'Q' && userInputChar() != 'q');
}

void UI::runMainMenu()
{
	showMainMenuHead();
	showMainMenuOptions();
	mainMenuChoose();
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
		<< std::setw(TABLE_WIDTH)<<"| [S]how files" <<std::endl
		<< std::setw(TABLE_WIDTH) << "| [M]ain Menu" << std::endl;
	std::cout << "********************************************" << std::endl;
}

void UI::showLoadFileMenuChoose()
{
	do
	{
		switch (userInputChar())
		{
		// load BoardX.txt
		case 'L':
		case 'l':
			system("CLS");
			showAllSavedBoardFilesScreen();
			
			showAllSavedBoardFiles();
				
			loadBoardFiles();
			runFileMenu();
			break;





		//check if all Boards in the dir /Boards
		case 'C':
		case 'c':
			system("CLS");
			showLoadFileMenu();
			checkIfAllBoardFilesThere();
			std:: cout << "Press any key to return to load board screen" << std::endl;
			std::cin.ignore();
			system("CLS");
			runFileMenu();
			break;

		// show avaiable BoardX.txt DELETE???
		case 'S': 
		case 's':
				
		
		//run main menu
		case 'M':
		case 'm':
				system("CLS");
				runMainMenu();
				break;
		default: 
			failInput();
			runFileMenu();
			break;
		}

	} while (userInputChar() != 'H' && userInputChar() != 'h');
}

void UI::runFileMenu()
{
	showLoadFileMenu();
	showLoadFileMenuOptions();
	showLoadFileMenuChoose();
}

void UI::showCredits()
{
	std::cout << std::fixed << std::setw(TABLE_WIDTH)
		<< "************|| AWESOME ||*************" << std::endl
		<< "************|| CREDITS ||*************" << std::endl
		<< "************|| SCREEN  ||*************" << std::endl
		<< std::endl
		<< "Program written by:" << std::endl
		
		<< "---Philipp Horleander and Konrad Muench---" <<std::endl
		<< std::endl;
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


/*
Attention:
You are only able to compile the programm when you are using
the C++ 17 version, which includes the libary filesystem !
*/

void UI::checkIfAllBoardFilesThere()
{
	namespace fs = std::filesystem;
	unsigned int count=1;

	std::string path = "\Boards";
	for (const auto  showFile : fs::directory_iterator(path))
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

		boards[choose]=fileName;

		choose++;
	}
		
}
//

std::ifstream UI::loadBoardFiles()
{

	unsigned int choose = 0;
	namespace fs = std::filesystem;
	std::filesystem::path dir = "Boards/";
	std::ifstream fileName;


	choose = userInputInt();

	std::map<int, std::string>::iterator it;

	for (it = boards.begin(); it != boards.end(); it++)
	{

		if (it == boards.find(choose))
		{
			std::cout << "Loading successfull" << std::endl;
			auto fileName = it;
			break;
		}

		return fileName;
	}

}



void UI::showAllSavedBoardFiles()
{	

	std::cout << "********************************************" << std::endl;
	std::cout << "********** Please choose one board *********" << std::endl;
	std::map<int,std::string>::iterator position;
	for (position = boards.begin(); position != boards.end(); position++)
		{
			std::cout<< std::endl;
			std::cout<< std::left
			<< std::setw(TABLE_WIDTH_SMALL) <<" |Number: " "["<< (*position).first <<"]"<<" |"
			<< std::setw(TABLE_WIDTH_SMALL) <<" |Name: "<< (*position).second << " |"
			<< std::endl;
		}
	std::cout << "********************************************" << std::endl;
}



void UI::showAllSavedBoardFilesScreen()
{
	std::cout	<< "************||  LOAD  ||*************" << std::endl
				<< "************||  BOARD ||*************" << std::endl
				<< "************|| SCREEN ||*************" << std::endl;
}


UI::UI()
{
}


UI::~UI()
{
}
