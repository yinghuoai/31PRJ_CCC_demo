#include "stdlib.h"

typedef struct{
	
	float*top;
	float*up;
	
	unsigned int n;
	unsigned int max;
}FList;

FList*FCreateList(int count)
{
	FList* p;
	p=(FList*)malloc(sizeof(FList));
	if(!p)	{free(p);return 0;}
	
	p->top=(float*)malloc(count*sizeof(float));
	if(!p->top)	return 0;
	
	p->up=p->top;
	
	p->n=0;
	p->max=count;
	
	return p;
}

int FIsEmpty(FList*lp)
{
	if(!lp->n)	return 1;
	return 0;
}

int FIsFull(FList* lp){
	if(lp->max==lp->n)	return 1;
	
	return 0;
}

int FPush(FList* lp,float data)
{
	
	if(FIsFull(lp))	return 0;
	*(lp->top++)=data;
	
	lp->n++;
	return 1;
}

int FPop(FList* lp,float*data)
{
	if(FIsEmpty(lp))	return 0;
	
	*data=*(--lp->top);
	lp->n--;
	return 1;
}

void FShowList(FList*lp)
{
	float *p;
	int i;
	
	if(FIsFull(lp))	return;
	
	p=lp->top;
	
	for(i=0;i<lp->n;i++)
	printf("%10f",*--p);
	
	return;
	
}

int FGetTop(FList*lp,float*data)
{
	float*p;
	
	if(FIsEmpty(lp))	return 0;
	
	p=lp->top;
	
	*data=*(p-1);
	
	return 1;
	
}









