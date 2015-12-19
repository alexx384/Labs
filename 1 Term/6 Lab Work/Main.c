#include <stdio.h>

void Palindrom(char *str, char *Result, int *CountTimes, int CountSymbol)
{
	int i,j;
	int NumberToRight=1;
	int NumberToLeft=1;
	int res=0;
	int post;

	if(CountSymbol>0)
	{
		if(*str != *(str+CountSymbol))
		{
			post=res=*CountTimes;
			for(i=0;i<(CountSymbol);i++)
			{

				for(j=1;j<(CountSymbol);j++)
				{
					if(*(str+i) != -52 && *(str+CountSymbol-j) != -52)
						Palindrom(str+i, Result, CountTimes, CountSymbol-j);
					if(res<*CountTimes){	
						res=*CountTimes;	NumberToRight=i;	NumberToLeft=(j);
					}
					(*CountTimes)=post;
				}
			}
			if(res!=post)
				Palindrom(str+NumberToRight, Result, CountTimes, CountSymbol-NumberToLeft);
			else{	*(Result+*CountTimes)=*str;	(*CountTimes)++;}
		}
		else{
			if(*(str+CountSymbol) != -52)
			{
				*(Result+*CountTimes)=*(str+CountSymbol);
				(*CountTimes)++;
				Palindrom(str+1, Result, CountTimes, CountSymbol-2);
				*(Result+*CountTimes)=*(str+CountSymbol);
				(*CountTimes)++;
			}
		}
	}

	if(CountSymbol==0 && *(str+CountSymbol)!=-52)
	{
		*(Result+*CountTimes)=*(str+CountSymbol);
		(*CountTimes)++;
	}

}

int main()
{
	char str[100];
	char Result[100]={0};
	int CountSymbol;
	int CountTimes=0;

	printf("Vvedite stroky:\n");
	scanf("%s%n",&str,&CountSymbol);
	
	Palindrom(&str, &Result, &CountTimes, CountSymbol-1);

	printf("\nAnswer:\n%s",Result);
	getch();
	return 0;
}