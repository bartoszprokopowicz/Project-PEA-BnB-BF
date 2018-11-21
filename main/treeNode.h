#pragma once

#include <vector>

using namespace std;

class treeNode
{
private:

public:
	//Zapisuje zredukowana macierz przejsc
	vector<vector<int>> reduced_matrix;

	//Zapisuje przebyt� do teraz �cie�k�
	vector<int> path;

	//Zapisuje najmniejsz� warto�� przej�� 
	int sum;

	//Zapisuje numer miasta
	int city;

	//Zapisuje ilo�� miast przebyt� do teraz
	int level;
	//Tworzy li�� mo�liwego przej�cia od ojca
	static treeNode newNode(vector<vector<int>> parentMatrix, vector<int> const &path,
							int level, int i, int j);
	//Tworzy korze� drzewa przej��
	static treeNode rootNode(vector<vector<int>> parentMatrix, const vector<int> &path, int start);

	treeNode();
	~treeNode();
};

