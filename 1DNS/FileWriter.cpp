#include "FileWriter.h"
#include <iostream>


FileWriter::FileWriter()
{
}

void FileWriter::write1dField(Fields::vectorField1d& vec, string& name_)
{
	string myfileType = ".dat"; //Šg’£Žq
	string path = "C:\\work\\C_lang\\20220413_diff_C_puls\\004_NS_Eq_1D_blog\\1DNS\\1DNS\\"; //â‘ÎƒpƒX
	string pathName = path.append(name_).append(myfileType); //"myOutput;" + ".dat" => "myOutput.dat"
	std::cout << "pathName = " << pathName << " :  pathName.size() = " << pathName.size() << std::endl;

	FILE* outfile;
	fopen_s(&outfile, pathName.c_str(), "w+t"); //https://www.paveway.info/entry/2018/12/25/cpp_std_string_char

	std::cout << "outfile = " << &outfile << std::endl;

	for (int i = 0; i < vec.size(); i++)
	{
		double xpos = vec[i].x1d;
		double uvel = vec[i].value;
		
		if (outfile)
		{
			fprintf(outfile, "%5.8lf\t%5.8lf\n", xpos, uvel);
		}

	}

	fclose(outfile);

}

FileWriter::~FileWriter()
{
}