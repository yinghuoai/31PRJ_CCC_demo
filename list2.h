typedef char EleType;

typedef struct{
	
	EleType* buf;
	unsigned int n;
	unsigned int max;
	
}List;

List* CreateList(int count)
{
	List* p;
	
	p=(List*)malloc(sizeof(List));
	if(!p)	return 0;
	
	p->buf=(EleType*)malloc(count*sizeof(EleType));
	if(!p->buf)	return 0;
	
	p->n=0;
	p->max=count;
	
	return p;
}

EleType* GetAddr(List*lp,int m)
{
	EleType* p;
	int i;

	p=lp->buf;
	
	if(m<=0||m>lp->n)	return 0;
	
	for(i=1;i<m;i++)	p++;
	
	return p;
	
}

int IsFull(List* lp)
{
	if(lp->n==lp->max)	return 1;
	return 0;
}

int IsEmpty(List*lp)
{
	if(!lp->n)	return 1;
	return 0;
}


int ListAppend(List*lp,EleType data)
{
	EleType *p;
	
	if(IsFull(lp))	return 0;
	
	lp->n++;
		
	p=GetAddr(lp,lp->n);
	
	*p=data;
	
	return 1;
}

int TraverseList(List*lp,int (*f)(EleType*))
{
	EleType* p;
	
	int i;
	
	if(IsEmpty(lp))	return 0;
	
	p=lp->buf;
	
	for(i=0;i<lp->n;i++)
		while(!f(p++))	return i+1;
	
	return 0;
}

int ListInsert(List* lp,int m,EleType data)
{
	EleType* p;
	EleType* q;
	
	if(IsFull(lp))	return 0;
	
	if(m==lp->n+1)	{ListAppend(lp,data);return 1;}
	
	p=GetAddr(lp,m);
	if(!p)	return 0;
	
	q=GetAddr(lp,lp->n);
	
	while(q!=p-1)	{*(q+1)=*q;q--;}
	
	*p=data;
	lp->n++;
	
	return 1;
}

int ListDelete(List*lp,int m)
{
	EleType* p;
	EleType* q;
	
	if(IsEmpty(lp))	return 0;
	
	p=GetAddr(lp,m);
	if(!p)	return 0;
	
	q=GetAddr(lp,lp->n);
	
	while(p!=q)	{*p=*(p+1);p++;}
	
	lp->n--;
	return 1;
	
}

int GetElement(List* lp,int m,EleType*data)
{
	EleType* p;
	p=GetAddr(lp,m);
	if(!p)	return 0;
	
	*data=*p;
	return 1;
}

void ClearList(List* lp)
{
	lp->n=0;
}

void DestroyList(List* lp)
{
	free(lp->buf);
	free(lp);
}
