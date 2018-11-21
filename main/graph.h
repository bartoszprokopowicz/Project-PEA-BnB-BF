#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class graph
{
private:
	//Macierz przejœæ miêdzy miastami
	vector<vector<int>> matrix;
public:
	graph();
	//Za³adowanie pliku z podanego adresu
	int loadFile(string fp);
	vector<vector<int>> getMatrix();
	void setMatrix(vector<vector<int>> &_matrix);
	//Wyœwietlenie macierzy przejœæ
	void showGraph();
	//Wygenerowanie macierzy przejœæ z zadan¹ iloœci¹ miast
	void generateGraph(int city);
	~graph();
};

