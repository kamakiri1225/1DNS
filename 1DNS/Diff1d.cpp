#include "Diff1d.h"
#include <iostream>

fd1d::Diff1d::Diff1d()
{
}

Fields::vectorField1d fd1d::Diff1d::gradX1d(Fields::vectorField1d& vec)
{
	Fields::vectorField1d temp = vec;
	for (int i = 1; i < vec.size()-1; i++)
	{
		temp[i].value = (vec[i].value - vec[i - 1].value) / vec[i].x1d;
	}
	temp[0].value = temp[1].value;
	temp[vec.size() - 1].value = temp[vec.size() - 2].value;

	return temp;
}

fd1d::Diff1d::~Diff1d()
{
}
