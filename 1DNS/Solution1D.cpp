#include <iostream>
#include "Solution1D.h"

Solution1d::Solution1d(int& nt_, double& dt_, double& visc_) :
	nt(nt_),
	dt(dt_),
	visc(visc_)
{
	std::cout << "Solution1d()" << std::endl;
}

Solution1d::~Solution1d()
{
}