#include "EM.h"
#include "adjlistgraph.h"
#include <fstream>

int main(void)
{
	AdjTypeList AdjList(COL);
	double **Matrix;
	string typefile = "type.txt";
	string matrixfile = "matrix.txt";
	ReadType(typefile, AdjList);
	cout << "finish read type" << endl;
	Matrix = ReadMatrix(matrixfile);
	cout << "finish read matrix" << endl;
	double result[ROW][AdjList.getRNANum()];
	double *init;
	double *predict;
	double *predict_next;
	predict = (double *)malloc(sizeof(double) * AdjList.getRNANum());
	predict_next = (double *)malloc(sizeof(double) * AdjList.getRNANum());
	for(int i = 0; i < ROW; i++)
	{
		init = Matrix[i];
		for(int j = 0; j < AdjList.getRNANum(); j++)
		{
			predict[j] = init[j];
		}
		cout << "init predict" << endl;
		for(int j = 0; j < 1000; j++)
		{
			predict = EM_algorithm(init, predict, predict_next, AdjList);
			cout << j << endl;
		}
		for(int j = 0; j < AdjList.getRNANum(); j++)
		{
			result[i][j] = predict[j];
		}
		cout << i << endl;
	}
	free(predict);
	free(predict_next);
	ofstream ofile;
	ofile.open("result.txt");
	for(int i = 0; i < ROW; i++)
	{
		for(int j = 0; j < AdjList.getRNANum(); j++)
		{
			ofile << result[i][j];
			ofile << " ";
		}
		ofile << endl;
	}
//	vector<int> vec;
//	vec = AdjList.getType(2);
//	for (int i = 0; i < vec.size(); i++)
//	{
//		cout << vec.at(i) << endl;
//	}
	return 0;
}


