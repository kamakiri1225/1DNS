#ifndef MESH_H
#define MESH_H
#include "Mesh.h"
#include <vector>
using std::vector;

class Mesh
{
public:
	Mesh();	//constructor
	Mesh(int&, double&); //ˆø”‚ ‚èconstructor
	virtual ~Mesh();//deconstructor

	int NumberOfNode;//x•ªŠ„”
	double lengthx;//x•ûŒü’·‚³
	double dx1d;//•ªŠ„•
	vector<double> xpts;//xÀ•W

	//add
	void discritized1dgrid(vector<double>&); //x[i]‚Ìì¬
	//add end
};

#endif //MESH_H