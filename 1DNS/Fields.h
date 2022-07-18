#ifndef FIELDS_H
#define FIELDS_H
#include "Mesh.h"
#include <vector>
using std::vector;

class Fields
{
public:
	Fields();//constructor
	virtual ~Fields(); //deconstructor

	typedef vector<Fields> vectorField1d;
	
	double x1d; //x座標
	double value; //Uの値

	Fields::vectorField1d passGridinfomation(Fields::vectorField1d&, vector<double>&);

	//演算子のオーバーロード
	friend Fields::vectorField1d operator+(const Fields::vectorField1d&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator-(const Fields::vectorField1d&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator&&(const Fields::vectorField1d&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator*(const double&, const Fields::vectorField1d&);
	friend Fields::vectorField1d operator*(const Fields::vectorField1d&, const double&);
};


#endif //FIELDS_H

