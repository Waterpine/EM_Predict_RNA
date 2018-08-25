#include"adjlistgraph.h"
#include<fstream>

int main()
{
	double *a;
	double **b;
	b = (double**)malloc(sizeof(double*) * 10);
	for(int i = 0; i < 10; i++)
	{
		*(b+i) = (double*)malloc(sizeof(double) * 10);
	}
	for(int i = 0; i < 10; i++)
	{
		a = b[i];
		for(int j = 0; j < 10; j++)
		{
			cout << a[j] << endl;
		}
	}
//	AdjTypeList AdjList(557303);
//	AdjList.InsertArc(1,2);
//	AdjList.InsertArc(1,3);
//	AdjList.InsertArc(1,4);
//	vector<int> vec;
//	vec = AdjList.getType(1);
//	for (int i = 0; i < vec.size(); i++)
//	{
//		cout << vec.at(i) << endl;
//	}
//	cout << vec.size() << endl;
}


