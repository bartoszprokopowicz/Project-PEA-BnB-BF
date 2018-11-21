#pragma once

#include <vector>

using namespace std;

class treeNode
{
private:

public:
	//Zapisuje zredukowana macierz przejsc
	vector<vector<int>> reduced_matrix;

	//Zapisuje przebyt¹ do teraz œcie¿kê
	vector<int> path;

	//Zapisuje najmniejsz¹ wartoœæ przejœæ 
	int sum;

	//Zapisuje numer miasta
	int city;

	//Zapisuje iloœæ miast przebyt¹ do teraz
	int level;
	//Tworzy liœæ mo¿liwego przejœcia od ojca
	static treeNode newNode(vector<vector<int>> parentMatrix, vector<int> const &path,
							int level, int i, int j);
	//Tworzy korzeæ drzewa przejœæ
	static treeNode rootNode(vector<vector<int>> parentMatrix, const vector<int> &path, int start);

	treeNode();
	~treeNode();
};

