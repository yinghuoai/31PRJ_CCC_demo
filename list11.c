#include <list2.h>

char a[20]="perfect world";

void showlist(List*);

int fun(EleType*);


main(){
	
	List*p;
	int i;
	
	char x,y;
	
	p=CreateList(20);
	if(!p)	return 0;
	
	for(i=0;a[i];i++)
		ListAppend(p,a[i]);
	
	showlist(p);
	
	ListInsert(p,1,'I');
	ListInsert(p,2,' ');
	ListInsert(p,16,'!');
	ListInsert(p,3,' ');
	ListInsert(p,3,'a');
	ListInsert(p,2,'n');

	showlist(p);
	
	GetElement(p,1,&x);
	GetElement(p,19,&y);
	
	printf("1=%c,19=%c\n",x,y);
	
	ListDelete(p,11);
	ListDelete(p,5);
	ListDelete(p,10);
	ListDelete(p,6);
	ListDelete(p,8);
	ListDelete(p,5);
	ListDelete(p,13);
	ListDelete(p,6);
	ListDelete(p,5);
	
	showlist(p);
	
	
	
	ClearList(p);
	showlist(p);
	
	printf("the return is %d\n",IsEmpty(p));
	
}




void showlist(List* lp)
{
	TraverseList(lp,fun);
	printf("\n");
	
}

int fun(EleType*data)
{
	printf("%c",*data);
	return 1;
}
