#include <math.h>


float operation(float a,char ch,float b){
	
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