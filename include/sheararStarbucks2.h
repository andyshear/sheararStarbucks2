#pragma once
#include "Starbucks.h"

using namespace std;

class grid
{
public:
	Entry* a_[2000];
	Entry* b_[2000];
	Entry* c_[2000];
	Entry* d_[2000];
	Entry* e_[2000];
	Entry* f_[2000];
	Entry* g_[2000];
	Entry* h_[2000];
	Entry* i_[2000];
	Entry* j_[2000];
	Entry* k_[2000];
	Entry* l_[2000];
	Entry* m_[2000];
	Entry* n_[2000];
	Entry* o_[2000];
	Entry* p_[2000];

	Entry* data_;

	grid* g;

	grid();
	grid(Entry* e);
	
};



class sheararStarbucks2 : public Starbucks
{
public:
	grid* g;
	int a,b,c,d,ec,f,gc,h,i,j,k,l,m,n,o,p;
	double gridLevel;
	Entry* buildEntry;
	sheararStarbucks2(void);
	~sheararStarbucks2(void);
	virtual void build(Entry* entry, int n);
	void buildLower(Entry* entry, int n, double gridLevel);
	virtual Entry* getNearest(double x, double y);
	grid* insert(Entry* e, grid* g, double gridLevel);
	double calculateDistance( double x_, double y_, Entry* z);
	Entry* searchGrid(double x, double y, grid* g);
	
private:
	sheararStarbucks2* ssb;
};