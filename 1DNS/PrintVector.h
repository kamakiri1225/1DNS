#include "Fields.h"
#include <iostream>
#include <string>

void PrintVector(Fields::vectorField1d& vec, std::string& name)
{
	std::cout << "====== " << name << ".x1d ====== " << std::endl;
 	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << name << "[" << i << "] = " << vec[i].x1d << std::endl;
	}

	std::cout << "====== " << name << ".value ====== " << std::endl;
	for (int i = 0 ; i < vec.size(); i++)
	{
		std::cout << name << "[" << i << "] = " << vec[i].value << std::endl;
	}
}