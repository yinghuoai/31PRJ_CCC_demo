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
			if(ch2=='=')	return 2;
			else if(ch2==')')	return 0;
			else return -1;
		}
		
	if(ch1==')')	
		{
			return 2;
		}
	
	
	if(ch1=='=')	
		{if(ch2=='=')	return 0;
			else  return -1;
		}
	
}

