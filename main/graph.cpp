#include "pch.h"
#include "graph.h"


graph::graph()
{

}

int graph::loadFile(string fp)
{
	fstream file;
	int temp = 0;
	int rows = 0, columns = 0;
	file.open(fp, fstream::in);

	if (file.is_open() == false) {
		return -1;
	}

	file >> temp;

	matrix.clear();

	matrix.resize(temp);

	while (!file.eof()) {

		for (int i = 0; i < matrix.size(); i++) {
			file >> temp;
			matrix[i].push_back(temp);
		}
	}

	vector<vector<int>> t;

	columns = matrix.size();
	rows = matrix[0].size();

	t.resize(rows, vector<int>(columns));
	//Przepisanie macierzy do tymczasowego kontenera
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			t[j][i] = matrix[i][j];
		}
	}

	matrix = t;
	t.clear();

	file.close();
	return 1;
}

vector<vector<int>> graph::getMatrix()
{
	return matrix;
}

void graph::setMatrix(vector<vector<int>> &_matrix)
{
	matrix = _matrix;
}

void graph::showGraph() {

	if (matrix.size() != 0) {
		cout << "   ";
		for (int i = 0; i < matrix.size(); i++)
			cout << setw(4) << i;

		cout << endl << endl;

		for (int i = 0; i < matrix.size(); i++) {
			cout << setw(4) << i;
			for (int j = 0; j < matrix[i].size(); j++)
				cout << setw(4) << matrix[i][j];

			cout << endl;
		}

		cin.ignore();
		cin.get();
	}
	else {
		cout << "Najpierw wczytaj graf!" << endl;
		cin.ignore();
		cin.get();
	}
}

void graph::generateGraph(int city)
{
	//Zadanie nasiona dla generatora liczb pseudolosowych
	srand(1);
	//Powiêkszenie macierzy przejœæ do potrzebnych rozmiarów
	matrix = vector<vector<int>>(city, vector<int>(city, 0));
	
	int i = 0, j = 0;
	//Zape³nienie macierzy przejœæ wartoœciami z zakresu 9 do 89
	for (; i < matrix.size(); i++) {
		j = 0;
		for (; j < matrix.size(); j++) {
			matrix[i][j] = rand() % 90 + 9;
		}
	}

	i = 0;
	j = 0;
	//Zape³nienie przek¹tnej macierzy wartoœci¹ -1
	for (; i < matrix.size(); i ++, j++) {
		matrix[i][j] = -1;
	}
}

graph::~graph()
{
	matrix.clear();
}

