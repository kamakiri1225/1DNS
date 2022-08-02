#ifndef SOLUTION_H
#define SOLUTION_H

class Solution1d
{
public:
	Solution1d(int&, double&, double&); // constructor
	virtual ~Solution1d(); //deconstructor

	int nt; //ステップ数
	double dt; //時間刻み幅
	double visc; //粘性係数
};

#endif