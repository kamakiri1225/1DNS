#include <iostream>
#include <vector>
#include "Mesh.h" //メッシュ設定 
#include "Fields.h" //場の定義 
#include "Diff1d.h" //空間微分
#include "Solution1D.h" //時間ループ 
#include "FileWriter.h" //ファイル出力
#include "PrintVector.h" //場のprint文

using namespace std;
using std::vector;

int main()
{
	int Nx =100;
	double totallength = 2.0;
	Mesh mesh_(Nx, totallength);//Meshクラスのインスタンス化

	//Fieldsの設定
	#include "creatFields.h";


	//initial condition
	cout << "Initial :: Iteration completed, writing the final file" << endl;

	for (int i = 0; i < U.size(); i++)
	{
		U[i].value = 1.0;
		if ((U[i].x1d > 0.5) && (U[i].x1d < 1.0))
		{
			U[i].value = 2.0;
		}
	}

	Unew = U;

	string U_name = "Unew";
	PrintVector(Unew, U_name);

	//file writer
	string name = "1dBurgers _initial";
	FileWriter filewriterObject_;

	filewriterObject_.write1dField(Unew, name);

	// solution
	int ntimestep = 500;
	double dt = 0.001;
	double visc = 1e-3;

	Solution1d sol1d(ntimestep, dt, visc);

	for (int nt = 0; nt < sol1d.nt; nt++)
	{
		cout << "Iteration no : " << nt << endl;
		U= Unew;
		double wavespeed = 1.0;
		double cdt = sol1d.dt * wavespeed;
		
		Fields::vectorField1d Diff1 = fd1d::gradX1d(U);
		Fields::vectorField1d Diff2 = fd1d::laplacianX1d(U);
		Fields::vectorField1d E = sol1d.dt * (U && Diff1);
		Fields::vectorField1d D = sol1d.dt * sol1d.visc * Diff2;

		//Unew = U - (cdt * Diff1); // du/dt = c*du/dx => unew{i} = u{i} - c*dt(u{i} - u{i-1})/dx 
		//Unew = U - sol1d.dt * (U && Diff1); // du/dt = u*du/dx => unew{i} = u{i} - u*dt(u{i} - u{i-1})/dx 
		Unew = U - E + D;

		// 周期境界条件
		double dx = mesh_.dx1d;
		Unew[0].value = U[0].value - (sol1d.dt * U[0].value * (U[0].value - U[U.size() - 1].value) / dx + sol1d.dt * sol1d.visc * (U[1].value - 2.0 * U[0].value + U[U.size() - 1].value) / (dx * dx));
		}

	//file writer
	string name2 = "1dBurgers_final";
	FileWriter filewriterObject_1;

	filewriterObject_1.write1dField(Unew, name2);

	return 0;
}