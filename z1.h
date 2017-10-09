#include "stdlib.h"

typedef struct{
	
	char*top;
	char*up;
	
	unsigned int n;
	unsigned int max;
}CList;

CList*CCreateList(int count)
{
	CList* p;
	p=(CList*)malloc(sizeof(CList));
	if(!p)	{free(p);return 0;}
	
	p->top=(char*)malloc(count*sizeof(char));
	if(!p->top)	return 0;
	
	p->up=p->top;
	
	p->n=0;
	p->max=count;
	
	return p;
}

int CIsEmpty(CList*lp)
{
	if(!lp->n)	return 1;
	return 0;
}

int CIsFull(CList* lp){
	if(lp->max==lp->n)	return 1;
	
	return 0;
}

int CPush(CList* lp,char data)
{
	
	if(CIsFull(lp))	return 0;
	*(lp->top++)=data;
	
	lp->n++;
	return 1;
}

int CPop(CList* lp,char*data)
{
	if(CIsEmpty(lp))	return 0;
	
	*data=*(--lp->top);
	lp->n--;
	return 1;
}

void CShowList(CList*lp)
{
	char *p;
	int i;
	
	if(CIsFull(lp))	return;
	
	p=lp->top;
	
	for(i=0;i<lp->n;i++)
	printf("%c",*--p);
	
	return;
	
}

int CGetTop(CList*lp,char*data)
{
	char*p;
	
	if(CIsEmpty(lp))	return 0;
	
	p=lp->top;
	
	*data=*(p-1);
	
	return 1;
	
}









