#pragma once

#include "results.h"
#include <vector>
#include <iostream>

using namespace std;

class tspBruteForce
{
private:
	//Macierz przej�� mi�dzy miastami
	vector<vector<int>> matrix;

public:

	tspBruteForce(vector<vector<int>> matrix);
	tspBruteForce();
	results bruteForce(const int start);

	~tspBruteForce();
};

