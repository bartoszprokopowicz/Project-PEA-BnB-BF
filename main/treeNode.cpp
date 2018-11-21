#include "pch.h"
#include "treeNode.h"

treeNode::treeNode()
{
}


treeNode::~treeNode()
{
}

treeNode treeNode::newNode(vector<vector<int>> parentMatrix, vector<int> const &path, int level, int start, int finish)
{
	//Tworzymy pusty liœæ a nastêpnie zape³niamy go danymi
	treeNode node;

	//Zapisuje poprzedni¹ œcie¿kê do momentu dojœcia do tego liœcia
	node.path = path;
	//Dodaje przejœcie do aktualnego liœcia
	node.path.push_back(finish);
	//Zapisuje przekazan¹ macierz przejœæ poprzedniego liœcia
	node.reduced_matrix = parentMatrix;

	//Zamiana wartoœci przejœæ dla miasta start i finish do -1
	for (int k = 0; k < parentMatrix.size(); k++)
	{
		//Ustawia przejœcia z miasta start do -1
		node.reduced_matrix[start][k] = -1;

		//Ustawia przejœcia do miasta finish na -1
		node.reduced_matrix[k][finish] = -1;
	}

	//Blokuje przejœcie z miasta finish do pocz¹tkowego miasta
	node.reduced_matrix[finish][path[0]] = -1;

	//Ustawienie iloœci miast przez które ju¿ przeszliœmy
	node.level = level;

	//Zapisuje aktualny numer miasta dotycz¹cy liœcia
	node.city = finish;

	return node;
}

treeNode treeNode::rootNode(vector<vector<int>> parentMatrix,const vector<int> &path , int start)
{
	treeNode node;
	//Zapisuje poprzedni¹ œcie¿kê do momentu dojœcia do tego liœcia
	node.path = path;
	//Zapisuje przekazan¹ macierz przejœæ poprzedniego liœcia
	node.reduced_matrix = parentMatrix;
	//Ustawienie iloœci miast przez które ju¿ przeszliœmy
	node.level = 0;
	//Zapisuje aktualny numer miasta dotycz¹cy liœcia
	node.city = start;

	return node;
}
