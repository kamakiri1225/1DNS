#ifndef DIFF1D_H
#define DIFF1D_H
#include "Mesh.h"
#include <vector>
#include"Fields.h"
using std::vector;

namespace fd1d
{
	// U    U    U    U
	//*-----*----*----*
	//     i-1   i
	class Diff1d
	{
	public:
		Diff1d();
		Fields::vectorField1d gradX1d(Fields::vectorField1d&);
		virtual ~Diff1d();
	};
}


#endif //FIELDS_H

