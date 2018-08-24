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
	VexTable = (struct VexNode*)malloc(sizeof(struct VexNode) * VexMaxNum);
}

AdjTypeList::~AdjTypeList()
{
	free(VexTable);
//	if(VexTable != NULL)
//	{
//		delete []VexTable;
//	}
}

void AdjTypeList::InsertArc(int Vex1, int Vex2)
{
	struct ArcNode *p;
	struct ArcNode *q;
	p = VexTable[Vex1].Next;
	VexTable[Vex1].Next = (struct ArcNode*)malloc(sizeof(struct ArcNode));
	q = VexTable[Vex1].Next;
	q->Num = Vex2;
	q->Next = p;
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
