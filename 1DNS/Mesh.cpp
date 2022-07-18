#include "Mesh.h"
#include <iostream>

Mesh::Mesh()
{
}

Mesh::Mesh(int& n, double& txlengthx):
	NumberOfNode(n),//x分割数
	lengthx(txlengthx),//x方向長さ
	xpts(NumberOfNode, 0.0)//vector(要素数, 値)
{
		dx1d = lengthx / (NumberOfNode-1);
		discritized1dgrid(xpts); //add
}

void Mesh::discritized1dgrid(vector<double>& vec)
{
	for (int i = 1; i < vec.size(); i++) //vec[0]=0なのでi=1からループする
	{
		vec[i] = vec[i - 1] + dx1d;
	}
}

Mesh::~Mesh()
{
}