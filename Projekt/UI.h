#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <filesystem>
#include <map>
#include <string>
#include <list>
#include "Chessboard.h"
#include "Graph.h"
#include "Edge.h"
#include "Node.h"

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
	void mainMenuChoose(Chessboard&);
	void runMainMenu(Chessboard&);
	//main menu end
	
	//load file menu start
	void showLoadFileMenu();
	void showLoadFileMenuOptions();
	void showLoadFileMenuChoose(Chessboard&);
	void runFileMenu(Chessboard&);
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
	
	std::ifstream& loadBoardFiles();
	
	//save graph path
	void savePathOfGraph(const std::list<Edge*>& edgeList);
	

	
	


	UI();
	~UI();
};

