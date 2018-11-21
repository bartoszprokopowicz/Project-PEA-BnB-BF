#pragma once

#include "treeNode.h"
#include "results.h"
#include <numeric>
#include <queue>
#include <iostream>

using namespace std;

class tspBranchnBound
{
private:
	//Macierz przejœæ do miast
	vector<vector<int>> matrix;
	//Zredukowanie wierszy
	vector<int> rowReduction(vector<vector<int>> &matrix);
	//Zredukowanie kolumn
	vector<int> columnReduction(vector<vector<int>> &matrix);
	//Obliczenie sumy zredukowanych wierszy i kolumn
	int calculateCost(vector<vector<int>> &matrix);

public:
	
	tspBranchnBound(vector<vector<int>> matrix);

	results branchnBound(const int start);

	tspBranchnBound();
	~tspBranchnBound();
};