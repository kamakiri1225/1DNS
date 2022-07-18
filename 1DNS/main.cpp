#include <iostream>
#include <vector>
#include "Mesh.h" //���b�V���ݒ� 
#include "Fields.h" //��̒�` 
#include "Diff1d.h" //��Ԕ���
#include "Solution1D.h" //���ԃ��[�v 
#include "FileWriter.h" //�t�@�C���o��
#include "PrintVector.h" //���print��

using namespace std;
using std::vector;

int main()
{
	int Nx =100;
	double totallength = 2.0;
	Mesh mesh_(Nx, totallength);//Mesh�N���X�̃C���X�^���X��

	//Fields�̐ݒ�
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
	string name = "1dLinearConvec";
	FileWriter filewriterObject_;

	filewriterObject_.write1dField(Unew, name);

	// solution class
	int ntimestep = 1000;
	double dt = 0.01;
	fd1d::Diff1d diff1d;
	Solution1d sol1d(ntimestep, dt);

	for (int nt = 0; nt < sol1d.nt; nt++)
	{
		cout << "Iteration no : " << nt << endl;
		U= Unew;
		double wavespeed = 1.0;
		double cdt = sol1d.dt * wavespeed;
		Fields::vectorField1d Diff = diff1d.gradX1d(U); 
		Unew = U - (cdt * Diff); // du/dt = c*du/dx => Unew{i} = U{i} - c*dt(u{i} - u{i-1})/dx 
	}

	//file writer
	string name2 = "1dLinearConvec_final";
	FileWriter filewriterObject_1;

	filewriterObject_1.write1dField(Unew, name2);

	return 0;
}