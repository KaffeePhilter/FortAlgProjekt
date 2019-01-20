#pragma once
#include "Field.h"
#include <sstream>
#include <iostream>
class Chesboard
{
public:
	Chesboard();
	~Chesboard();

	Field findKnight();
	Field findKing();
	void initialize(std::ifstream file);
	std::stringstream draw();
};

