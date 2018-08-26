#include"adjlistgraph.h"
#include<fstream>
#include<vector>
#include<string>

vector<string> tokenize(const string& s, char c);

int main()
{
	vector<string> vec;
	vec = tokenize("\n", ' ');
	cout << vec.size() << endl;
//	double *a;
//	double **b;
//	b = (double**)malloc(sizeof(double*) * 10);
//	for(int i = 0; i < 10; i++)
//	{
//		*(b+i) = (double*)malloc(sizeof(double) * 10);
//	}
//	for(int i = 0; i < 10; i++)
//	{
//		a = b[i];
//		for(int j = 0; j < 10; j++)
//		{
//			cout << a[j] << endl;
//		}
//	}
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
//	AdjList.setRNANum();
//	cout << AdjList.getRNANum() << endl;
}

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

