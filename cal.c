#include<z1.h>
#include<z2.h>

#include <math.h>
#include<stdlib.h>

void AClear(char*);
float operation(float,char,float);
int InOp(char);
int judge(char,char);

main(){
	
	CList *Cp;
	FList *Fp;

	int i,j;
	char *p;
	char *a;
	
	char data;
	char ddd;
	
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
			do{
				a[j]=p[i];
				j++;i++;
			}while(!InOp(p[i]));
			
			FPush(Fp,atof(a));
			j=0;
			i--;
			AClear(a);continue;
		}
		
		else
		{
			CGetTop(Cp,&data);
			
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
				
			}
		
		}
		
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



float operation(float a,char ch,float b)
{
	
	if(ch=='+')	return a+b;
	else if(ch=='-')	return a-b;
	else if(ch=='*')	return a*b;
	else if(ch=='/')
		{
			if(b==0)	{printf("div is 0\n");return 0;}
			else return a/b;
		}
	else if(ch=='^')	return pow(a,b);
		
	else printf("op is error");
	
	
}

int InOp(char ch)
{
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='^'||ch=='=')
	return 1;

	else return 0;
	
}
int judge(char ch1,char ch2)
{

	if(ch1=='+'||ch1=='-')
		{
			if(ch2=='+'||ch2=='-'||ch2==')'||ch2=='=')	return 1;
			else return -1;
		}
		
	if(ch1=='*'||ch1=='/')
		{
			if(ch2=='^'||ch2=='(')	return -1;	
			else return 1;
		}
	
	if(ch1=='^')
		{
			if(ch2=='(')	return -1;
			else return 1;
		}
		
	if(ch1=='(')
		{
			if(ch2=='=')	return 1;
			else if(ch2==')')	return 0;
			else return -1;
		}
		
	if(ch1==')')	
			return 1;
	
	if(ch1=='=')	
		{if(ch2=='=')	return 0;
			else  return -1;
		}
	
}




