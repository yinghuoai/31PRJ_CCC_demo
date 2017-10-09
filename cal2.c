#include<z1.h>
#include<z2.h>
#include<op.h>
#include<lever.h>

#include<stdlib.h>

void AClear(char*);

main(){
	
	CList *Cp;
	FList *Fp;

	int i,j;
	char *p;
	char *a;
	
	char data;
	char ddd;
	
	int flag=1;
	
	float x,y,result;
	char oper;
	
	Cp=CCreateList(100);
	Fp=FCreateList(100);
	
	p=(char*)malloc(100);
	a=(char*)malloc(10);
	
	/*p="3.3-2*4*(3+2/1)=";*/
	
	gets(p);
	
	AClear(a);
	CPush(Cp,'=');
	
	for(i=0,j=0;p[i];i++)
	{
		if((p[i]>='0'&&p[i]<='9')||(p[i]=='.'))
		{
			a[j]=p[i];
			j++;
			
			
			if(InOp(p[i+1]));
			{
			FPush(Fp,atof(a)*flag);
			j=0;
			flag=1;
			i--;
			AClear(a);continue;}
		}
		
		else if(InOp(p[i]))
		{
			CGetTop(Cp,&data);
			
			if((p[i+1]=='-')&&(p[i]=='(')) {FPush(Fp,0);CPush(Cp,'(');continue;}
			
			if((i==0)&&(p[i]=='-')) {flag=-1;continue;}
			
			/*
			FShowList(Fp);
			CShowList(Cp);
			*/
			switch(judge(data,p[i]))
			{
			case -1:	{CPush(Cp,p[i]);break;}
			case 0:		{CPop(Cp,&ddd);break;}
				
			case 1:		
				{
					CPop(Cp,&oper);
					FPop(Fp,&y);
					FPop(Fp,&x);
					
					result=operation(x,oper,y);
					FPush(Fp,result);
					printf("%f %c %f=%f\n",x,oper,y,result);
					i--;
					break;
				}
			default:	{printf("error!");return;}
			}
		
		}
		
		else printf("error!\n");
		
	}
	
	printf("the resule is:");
	FShowList(Fp);
	
	
	
}


void AClear(char* b)
{
	int i;
	for(i=0;b[i];i++)
	b[i]='\0';
	
}




