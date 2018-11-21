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
	//Tworzymy pusty li�� a nast�pnie zape�niamy go danymi
	treeNode node;

	//Zapisuje poprzedni� �cie�k� do momentu doj�cia do tego li�cia
	node.path = path;
	//Dodaje przej�cie do aktualnego li�cia
	node.path.push_back(finish);
	//Zapisuje przekazan� macierz przej�� poprzedniego li�cia
	node.reduced_matrix = parentMatrix;

	//Zamiana warto�ci przej�� dla miasta start i finish do -1
	for (int k = 0; k < parentMatrix.size(); k++)
	{
		//Ustawia przej�cia z miasta start do -1
		node.reduced_matrix[start][k] = -1;

		//Ustawia przej�cia do miasta finish na -1
		node.reduced_matrix[k][finish] = -1;
	}

	//Blokuje przej�cie z miasta finish do pocz�tkowego miasta
	node.reduced_matrix[finish][path[0]] = -1;

	//Ustawienie ilo�ci miast przez kt�re ju� przeszli�my
	node.level = level;

	//Zapisuje aktualny numer miasta dotycz�cy li�cia
	node.city = finish;

	return node;
}

treeNode treeNode::rootNode(vector<vector<int>> parentMatrix,const vector<int> &path , int start)
{
	treeNode node;
	//Zapisuje poprzedni� �cie�k� do momentu doj�cia do tego li�cia
	node.path = path;
	//Zapisuje przekazan� macierz przej�� poprzedniego li�cia
	node.reduced_matrix = parentMatrix;
	//Ustawienie ilo�ci miast przez kt�re ju� przeszli�my
	node.level = 0;
	//Zapisuje aktualny numer miasta dotycz�cy li�cia
	node.city = start;

	return node;
}
