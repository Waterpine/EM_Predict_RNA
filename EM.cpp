#include "EM.h"
#include "adjlistgraph.h"

#define ROW 3005
#define COL 557303

int main(void)
{
	AdjTypeList AdjList(COL);
	double **Matrix;
	string typefile = "type.txt";
	string matrixfile = "matrix.txt";
	ReadType(typefile, AdjList);
	vector<int> vec;
	vec = AdjList.getType(2);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << endl;
	}
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
		for (auto a : res)
		{
			AdjList.InsertArc(linecount, stoi(a));
		}
		linecount++;
//		cout << linecount << endl;
//		if(linecount == COL)
//		{
//			break;
//		}
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



