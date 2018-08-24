#ifndef ADJLISTGRAPH_H
#define ADJLISTGRAPH_H

#include<iostream>
#include<queue>

using namespace std;

struct ArcNode
{
	int Num;
	struct ArcNode *Next;
	
	ArcNode():Next(NULL) {}
	
	ArcNode(int value, struct ArcNode *_Next = NULL)
	{
		Num = value;
		Next = _Next;
	}
};

struct VexNode
{
	int Num;
	struct ArcNode *Next;
	
	VexNode():Next(NULL) {}
	
	VexNode(int value, struct ArcNode *_Next = NULL)
	{
		Num = value;
		Next = _Next;
	}
};

class AdjTypeList
{
	public:
		AdjTypeList(int _VexNum = 0);
		~AdjTypeList();
		void InsertArc(int Vex1, int Vex2);
		vector<int> getType(int Vex); 
	private:
		int VexMaxNum;
		int VexNum;
		int ArcNum;
		struct VexNode *VexTable;
};

AdjTypeList::AdjTypeList(int _VexMaxNum)
{
	VexMaxNum = _VexMaxNum;
	VexNum = 0;
	ArcNum = 0;
	VexTable = new VexNode[VexMaxNum];
}

AdjTypeList::~AdjTypeList()
{
	if(VexTable != NULL)
	{
		delete []VexTable;
	}
}

void AdjTypeList::InsertArc(int Vex1, int Vex2)
{
	VexTable[Vex1].Next = new ArcNode(Vex2, VexTable[Vex1].Next);
	ArcNum++;
}

vector<int> AdjTypeList::getType(int Vex)
{
	struct ArcNode *p;
	vector<int> vec;
	p = VexTable[Vex].Next;
	while(p != NULL)
	{
		vec.push_back(p->Num);
		p = p->Next;
	}
	return vec;
}

#endif
