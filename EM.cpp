#include "EM.h"
#include "adjlistgraph.h"

/* depend on the data */
#define ROW 3005
#define COL 557303

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

void ReadType(string filename, AdjTypeList AdjList)
{
	string s;
	vector<string> res;
	int linecount = 0;
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Error opening file" << endl;
		exit(1);
	}
	while(getline(fin, s))
	{
		res = tokenize(s, ' ');
		if (res.size() == 1)
		{
			AdjList.setRNANum();
		}
		for (auto a : res)
		{
			AdjList.InsertArc(linecount, stoi(a));
		}
		linecount++;
	}
}

double **ReadMatrix(string filename)
{
	string s;
	vector<string> res;
	ifstream fin(filename);
	double **p;
	p = (double**)malloc(sizeof(double*) * ROW);
	for(int i = 0; i < ROW; i++)
	{
		*(p+i) = (double*)malloc(sizeof(double) * COL);
	}
	if (!fin.is_open())
	{
		cout << "Error opening file" << endl;
		exit(1);
	}
	int num_row = 0;
	int num_col;
	while(getline(fin, s))
	{
		res = tokenize(s, ' ');
		num_col = 0;
		for (auto a : res)
		{
			p[num_row][num_col] = stod(a);
			num_col++;		
		}
		num_row++;
	}
	return p;
}

double* EM_algorithm(double *init, double *predict, double *predict_next, AdjTypeList AdjList)
{
	vector<int> vec;
	double total = 0;
	double temp[AdjList.getRNANum()];
	for (int i = 0; i < AdjList.getRNANum(); i++)
	{
		predict_next[i] = init[i];
	} 
	for (int i = AdjList.getRNANum(); i < COL; i++)
	{
		if (init[i] != 0)
		{
			vec = AdjList.getType(i);
			total = 0;
			for (int j = 0; j < vec.size(); j++)
			{
				total = total + predict[vec.at(j)];
			}
			for (int j = 0; j < vec.size(); j++)
			{
				predict_next[vec.at(j)] = predict_next[vec.at(j)] + (predict[vec.at(j)] / total * init[i]);
			}
		}
	}
	for (int i = 0; i < AdjList.getRNANum(); i++)
	{
		temp[i] = predict_next[i];
		predict[i] = temp[i];
	} 
	return predict;
}

/* string split function */ 
vector<string> tokenize(const string& s, char c) {
    auto end = s.cend();
    auto start = end;
    vector<string> v;
    for( auto it = s.cbegin(); it != end; ++it ) {
        if( *it != c ) {
            if( start == end )
                start = it;
            continue;
        }
        if( start != end ) {
            v.emplace_back(start, it);
            start = end;
        }
    }
    if( start != end )
    {
    	v.emplace_back(start, end);
	}
    return v;
}



