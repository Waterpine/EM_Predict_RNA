#include "EM.h"
#include "adjlistgraph.h"

int main(void)
{
	string typefile = "type.txt";
	string matrixfile = "matrix.txt";
	
	return 0;
}

AdjTypeList ReadType(string filename)
{
	string s;
	vector<string> res;
	int linecount = 0;
	// hard code
	AdjTypeList AdjList(557303);
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "Error opening file" << endl;
		exit(1);
	}
	while(getline(fin, s))
	{
		res = tokenize(s, ' ');
		for (auto a : res)
		{
			AdjList.InsertArc(linecount, stoi(a));
		}
		linecount++;
	}
	return AdjList;
}

double **ReadMatrix(string filename)
{
	string s;
	vector<string> res;
	ifstream fin(filename);
	double **p;
	// hard code
	int row = 3005;
	int col = 557303;
	p = (double**)malloc(sizeof(double*) * row);
	for(int i = 0; i < row; i++)
	{
		*(p+i) = (double*)malloc(sizeof(double) * col);
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
			num_col++;		
		}
		num_row++;
	}
	return p;
}

void E_step()
{
	
}

void M_step()
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



