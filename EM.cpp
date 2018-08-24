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
	Matrix = ReadMatrix(matrixfile);
	double result[ROW][AdjList.getRNANum()];
	double *init;
	double *predict;
	for(int i = 0; i < ROW; i++)
	{
		init = Matrix[i];
		predict = init;
		for(int j = 0; j < 1000; j++)
		{
			predict = EM_algorithm(init, predict, AdjList);
		}
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
		for (auto a : res)
		{
			num_col = 0;
			p[num_row][num_col] = stod(a);
			cout << a << endl;
			num_col++;		
		}
		num_row++;
	}
	return p;
}

double* EM_algorithm(double *init, double *p, AdjTypeList AdjList)
{
	
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



