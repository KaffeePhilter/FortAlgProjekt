#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>
#include <string>
#include "Chessboard.h"

//------------------------------------------
#define TABLE_WIDTH 24
#define TABLE_WIDTH_SMALL 8
//------------------------------------------


class UI
{
private:
	
public:
	//map with all boards
	std::map<int,std::string>boards;
	
	//user input
	char userInputChar();
	int userInputInt();

	//main menu start
	void showMainMenuHead();
	void showMainMenuOptions();
	void mainMenuChoose();
	void runMainMenu();
	//main menu end
	
	//load file menu start
	void showLoadFileMenu();
	void showLoadFileMenuOptions();
	void showLoadFileMenuChoose();
	void runFileMenu();
	//load file menu end

	//nice messages
	void showCredits();
	void failInput();
	void sayGoodBye();
	
	//read board files
	
	void checkIfAllBoardFilesThere();

	
	void saveAllBoardFiles();
	
	void showAllSavedBoardFilesScreen();
	void showAllSavedBoardFiles();

	std::ifstream loadBoardFiles();
	


	
	


	UI();
	~UI();
};

