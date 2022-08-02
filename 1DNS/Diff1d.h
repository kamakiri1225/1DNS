#include <vector>
#include "Fields.h"
#include <cmath> //add
using std::vector;

namespace fd1d
{
	// U    U    U    U
	//*-----*----*----*
	//     i-1   i
	double returndouble(double& a)
	{
		double newdouble = a * 2.0;

		return newdouble;
	}

	Fields::vectorField1d gradX1d(Fields::vectorField1d& vec) //typedef vector<Fields> vectorField1d;
	{
		Fields::vectorField1d temp(vec.size());

		for (int i = 1; i < vec.size(); i++)
		{
			temp[i].value = (vec[i].value - vec[i - 1].value) / (vec[i].x1d - vec[i - 1].x1d);
		}

		return temp;
	}

	Fields::vectorField1d laplacianX1d(Fields::vectorField1d& vec) //typedef vector<Fields> vectorField1d;
	{
		Fields::vectorField1d temp(vec.size());

		for (int i = 1; i < vec.size() - 1; i++)
		{
			temp[i].value = (vec[i + 1].value - 2.0 * vec[i].value + vec[i - 1].value) / pow((vec[i].x1d - vec[i - 1].x1d), 2.0);
		}
		return temp;
	}
}