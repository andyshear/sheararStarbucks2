#include "sheararStarbucks2.h"
#include "cinder/app/AppBasic.h"
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <io.h>
#include <iostream>
#include <string>


using namespace std;

grid::grid() {
	
}
grid::grid(Entry* e) {
	
	data_ = e;
	
}



sheararStarbucks2::sheararStarbucks2()
{
	a=0;b=0;c=0;d=0;ec=0;f=0;gc=0;h=0;i=0;j=0;k=0;l=0;m=0;n=0;o=0;p=0;gridLevel=1;
}

sheararStarbucks2::~sheararStarbucks2(void)
{
}



void sheararStarbucks2 :: build(Entry* c, int n){
	Entry* buildEntry = new Entry[n];
	

	for(int i = 0; i<n; i++){
		buildEntry[i] = c[i];
	}
	
	g = new grid(c);
	for(int i = 1; i<n; i++){
		insert(&c[i], g, 1);
	}

}

void sheararStarbucks2 :: buildLower(Entry* c, int n, double gridLevel){
	Entry* buildEntry = new Entry[n];
	

	for(int i = 0; i<n; i++){
		buildEntry[i] = c[i];
	}

	g = new grid(c);
	for(int i = 0; i<n; i++){
		insert(&c[i], g, gridLevel);
	}

}

grid* sheararStarbucks2::insert(Entry* e, grid* g, double gridLevel){
	
	//if( (abs( g->data_->x - e->x )<=0.00001) && (abs( g->data_->y - e->y )<=0.00001) )
	//	return g;

	double g1 = gridLevel/4;
	double g2 = gridLevel/2;
	double g3 = g1+g2;
	double g4 = gridLevel;
	

	if(e->x <= g1 && e->y <= g1){
		g->a_[a] = e;
		a++;		
		return g;
	}
	if((e->x >= g1 && e->x <= g2) && e->y <= g1){
		g->b_[b] = e;
		b++;		
		return g;
	}
	if((e->x >= g2 && e->x <= g3) && e->y <= g1){
		g->c_[c] = e;
		c++;		
		return g;
	}
	if((e->x >= g3 && e->x <= g4) && e->y <= g1){
		g->d_[d] = e;
		d++;		
		return g;
	}
	if(e->x <= g1 && (e->y >= g1 && e->y <= g2)){
		g->e_[ec] = e;
		e++;		
		return g;
	}
	if((e->x >= g1 && e->x <= g2) && (e->y >= g1 && e->y <= g2)){
		g->f_[f] = e;
		f++;		
		return g;
	}
	if((e->x >= g2 && e->x <= g3) && (e->y >= g1 && e->y <= g2)){
		g->g_[gc] = e;
		gc++;		
		return g;
	}
	if((e->x >= g3 && e->x <= g4) && (e->y >= g1 && e->y <= g2)){
		g->h_[h] = e;
		h++;		
		return g;
	}
	if(e->x <= g1 && (e->y >= g2 && e->y <= g3)){
		g->i_[i] = e;
		i++;		
		return g;
	}
	if((e->x >= g1 && e->x <= g2) && (e->y >= g2 && e->y <= g3)){
		g->j_[j] = e;
		j++;		
		return g;
	}
	if((e->x >= g2 && e->x <= g3) && (e->y >= g2 && e->y <= g3)){
		g->k_[k] = e;
		k++;		
		return g;
	}
	if((e->x >= g3 && e->x <= g4) && (e->y >= g2 && e->y <= g3)){
		g->l_[l] = e;
		l++;		
		return g;
	}
	if(e->x <= g1 && (e->y >= g3 && e->y <= g4)){
		g->m_[m] = e;
		m++;		
		return g;
	}
	if((e->x >= g1 && e->x <= g2) && (e->y >= g3 && e->y <= g4)){
		g->n_[n] = e;
		n++;		
		return g;
	}
	if((e->x >= g2 && e->x <= g3) && (e->y >= g3 && e->y <= g4)){
		g->o_[o] = e;
		o++;		
		return g;
	}
	if((e->x >= g3 && e->x <= g4) && (e->y >= g3 && e->y <= g4)){
		g->p_[p] = e;
		p++;		
		return g;
	}
	
	return g;
}


//calculateDistance forked from regojr
double sheararStarbucks2::calculateDistance( double x_, double y_, Entry* z)
{
	if(g->data_ == NULL) return 2.0; //because all points that exist will be closer
	else {
		double aSq, bSq; 
		aSq = abs(x_ - (z->x)) * abs(x_ - (z->x));
		bSq = abs(y_ - (z->y)) * abs(y_ - (z->y));
		return sqrt(aSq + bSq);
	}
}

Entry* sheararStarbucks2::getNearest(double x, double y)
{
	return searchGrid(x, y, g);
}


Entry* sheararStarbucks2::searchGrid(double x, double y, grid* g)
{
	
	double min = 2.0;
	int pos = 0;
	
	double g1 = gridLevel/4;
	double g2 = gridLevel/2;
	double g3 = g1+g2;
	double g4 = gridLevel;
	

	if(x <= g1 && y <= g1){		
		for(int i = 0; i<a; i++){
			double temp = calculateDistance(x,y,(g->a_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->a_[i]));
				pos = i;
			}
		}				
		return g->a_[pos];
	}
	if((x >= g1 && x <= g2) && y <= g1){
		for(int i = 0; i<b; i++){
			double temp = calculateDistance(x,y,(g->b_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->b_[i]));
				pos = i;
			}
		}				
		return g->b_[pos];
	}
	if((x >= g2 && x <= g3) && y <= g1){
		for(int i = 0; i<c; i++){
			double temp = calculateDistance(x,y,(g->c_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->c_[i]));
				pos = i;
			}
		}				
		return g->c_[pos];
	}
	if((x >= g3 && x <= g4) && y <= g1){
		for(int i = 0; i<d; i++){
			double temp = calculateDistance(x,y,(g->d_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->d_[i]));
				pos = i;
			}
		}				
		return g->d_[pos];
	}
	if(x <= g1 && (y >= g1 && y <= g2)){
		for(int i = 0; i<ec; i++){
			double temp = calculateDistance(x,y,(g->e_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->e_[i]));
				pos = i;
			}
		}				
		return g->e_[pos];
	}
	if((x >= g1 && x <= g2) && (y >= g1 && y <= g2)){
		for(int i = 0; i<f; i++){
			double temp = calculateDistance(x,y,(g->f_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->f_[i]));
				pos = i;
			}
		}				
		return g->f_[pos];
	}
	if((x >= g2 && x <= g3) && (y >= g1 && y <= g2)){
		for(int i = 0; i<gc; i++){
			double temp = calculateDistance(x,y,(g->g_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->g_[i]));
				pos = i;
			}
		}				
		return g->g_[pos];
	}
	if((x >= g3 && x <= g4) && (y >= g1 && y <= g2)){
		for(int i = 0; i<h; i++){
			double temp = calculateDistance(x,y,(g->h_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->h_[i]));
				pos = i;
			}
		}				
		return g->h_[pos];
	}
	if(x <= g1 && (y >= g2 && y <= g3)){
		for(int j = 0; j<i; j++){
			double temp = calculateDistance(x,y,(g->i_[j]));
			if(temp<min){
				min = calculateDistance(x,y,(g->i_[j]));
				pos = j;
			}
		}				
		return g->i_[pos];
	}
	if((x >= g1 && x <= g2) && (y >= g2 && y <= g3)){
		for(int i = 0; i<j; i++){
			double temp = calculateDistance(x,y,(g->j_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->j_[i]));
				pos = i;
			}
		}				
		return g->j_[pos];
	}
	if((x >= g2 && x <= g3) && (y >= g2 && y <= g3)){
		for(int i = 0; i<k; i++){
			double temp = calculateDistance(x,y,(g->k_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->k_[i]));
				pos = i;
			}
		}				
		return g->k_[pos];
	}
	if((x >= g3 && x <= g4) && (y >= g2 && y <= g3)){
		for(int i = 0; i<l; i++){
			double temp = calculateDistance(x,y,(g->l_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->l_[i]));
				pos = i;
			}
		}				
		return g->l_[pos];
	}
	if(x <= g1 && (y >= g3 && y <= g4)){
		for(int i = 0; i<m; i++){
			double temp = calculateDistance(x,y,(g->m_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->m_[i]));
				pos = i;
			}
		}				
		return g->m_[pos];
	}
	if((x >= g1 && x <= g2) && (y >= g3 && y <= g4)){
		for(int i = 0; i<n; i++){
			double temp = calculateDistance(x,y,(g->n_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->n_[i]));
				pos = i;
			}
		}				
		return g->n_[pos];
	}
	if((x >= g2 && x <= g3) && (y >= g3 && y <= g4)){
		for(int i = 0; i<o; i++){
			double temp = calculateDistance(x,y,(g->o_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->o_[i]));
				pos = i;
			}
		}				
		return g->o_[pos];
	}
	if((x >= g3 && x <= g4) && (y >= g3 && y <= g4)){
		for(int i = 0; i<p; i++){
			double temp = calculateDistance(x,y,(g->p_[i]));
			if(temp<min){
				min = calculateDistance(x,y,(g->p_[i]));
				pos = i;
			}
		}				
		return g->p_[pos];
	}
	
	
}