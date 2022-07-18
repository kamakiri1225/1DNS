#include "Fields.h"
#include <iostream>

Fields::Fields():
	x1d(0.0),
	value(2.0)
{
}

Fields::vectorField1d Fields::passGridinfomation(Fields::vectorField1d& vec, vector<double>& xpts_)
{
	/*
	typedef vector<Fields> vectorField1d;
	double value;
	double x1d;
	*/
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].x1d = xpts_[i];
	}

	return vec;
}

Fields::vectorField1d operator+(const Fields::vectorField1d& vecA, const Fields::vectorField1d& vecB)
{
	Fields::vectorField1d temp = vecA;

	for (int i = 0; i < vecA.size(); i++)
	{
		temp[i].value += vecB[i].value;
	}
	return temp;
}

Fields::vectorField1d operator-(const Fields::vectorField1d& vecA, const Fields::vectorField1d& vecB)
{
	Fields::vectorField1d temp = vecA;

	for (int i = 0; i < vecA.size(); i++)
	{
		temp[i].value -= vecB[i].value;
	}
	return temp;
}

Fields::vectorField1d operator&&(const Fields::vectorField1d& vecA, const Fields::vectorField1d& vecB)
{
	Fields::vectorField1d temp = vecA;

	for (int i = 0; i < vecA.size(); i++)
	{
		temp[i].value *= vecB[i].value;
	}
	return temp;
}

Fields::vectorField1d operator*(const double& dbvalue, const Fields::vectorField1d& vecB)
{
	Fields::vectorField1d temp = vecB;

	for (int i = 0; i < vecB.size(); i++)
	{
		temp[i].value = dbvalue * vecB[i].value;
	}
	return temp;
}

Fields::vectorField1d operator*(const Fields::vectorField1d& vecB, const double& dbvalue)
{
	Fields::vectorField1d temp = vecB;

	for (int i = 0; i < vecB.size(); i++)
	{
		temp[i].value = dbvalue * vecB[i].value;
	}
	return temp;
}

Fields::~Fields()
{
}