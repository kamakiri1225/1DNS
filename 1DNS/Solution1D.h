#ifndef SOLUTION_H
#define SOLUTION_H

class Solution1d
{
public:
	Solution1d(int&, double&); // constructor
	virtual ~Solution1d(); //deconstructor

	int nt; //ステップ数
	double dt; //時間刻み幅
};

#endif