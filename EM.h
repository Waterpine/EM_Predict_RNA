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
double* EM_algorithm(double *init, double *p, AdjTypeList AdjList);
vector<string> tokenize(const string& s, char c);

#endif
