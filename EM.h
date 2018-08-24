#ifndef EM_H
#define EM_H

#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include"adjlistgraph.h"

using namespace std;

void ReadType(string filename, AdjTypeList AdjList);
double **ReadMatrix(string filename);
void E_step();
void M_step();
vector<string> tokenize(const string& s, char c);

#endif
