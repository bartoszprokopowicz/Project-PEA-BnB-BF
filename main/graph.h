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
	//Macierz przej�� mi�dzy miastami
	vector<vector<int>> matrix;
public:
	graph();
	//Za�adowanie pliku z podanego adresu
	int loadFile(string fp);
	vector<vector<int>> getMatrix();
	void setMatrix(vector<vector<int>> &_matrix);
	//Wy�wietlenie macierzy przej��
	void showGraph();
	//Wygenerowanie macierzy przej�� z zadan� ilo�ci� miast
	void generateGraph(int city);
	~graph();
};

