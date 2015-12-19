#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int IsPerepolnenie(int *a,char *rs)
{
	int res=0;
	int i=0;
	char imax[10]="2147483647";
	char imin[11]="-2147483648";

	if(*(rs) != '-' && *a < 10 || *(rs) == '-' && *a < 11)  
	{
		res++;
	    *a=atoi(rs);
	}
	else
	{
		if(*(rs) != '-' && *a > 10 || *(rs) == '-' && *a > 11)
			res=0;
		else
		{
			if(*(rs) != '-')
			{
				if(*(rs) <= '2')
				{
					*a=atoi(rs);
					if(*a < 2147483647)
						res++;
					else
					{
						res=0;

						for(i=0; *rs != '\0' ; rs++)
						{
							if(*rs != imax[i])
							{
								res=0;
								rs=rs+i-1;
							}else{
								i++;
								res=1;
							}
						}
					}
				}
				else
					res=0;
			}
			else//-----------------
			{
				if(*(rs-1) <= '2')
				{
					*a=atoi(rs);
					if(*a >= -2147483648)
						res++;
					else
					{
						res=0;

						for(i=0; *rs != '\0' ; rs++)
						{
							if(*rs != imax[i])
							{
								res=0;
								rs=rs+i-1;
							}else{
								i++;
								res=1;
							}
						}
					}
				}
				else
					res=0;
			}
		}
	}

	return res;
}

void Osnova()
{
	int a,b;
	int tr,fl;
	char c;
	char numb1[12];
	char numb2[12];
	scanf("%s%n %c %s%n",&numb1,&a,&c,&numb2,&b);

	b=b-3-a;
	tr= IsPerepolnenie(&a,numb1);	
	fl= IsPerepolnenie(&b,numb2);

	if(tr==1 && fl==1)
	{	

		switch (c)
		{
		case 43:           //+++++

			if(b > 0 && a>0 && (a+b)>0 || b < 0 && a < 0 && (a+b)<0 || b == 0 || a==0 || b < 0 && a > 0 || b > 0 && a < 0)
			{
				a+=b;
			    printf("\n%d",a);
			}else
				printf("Error");
			break;

		case 45:           //-----

			if(a > 0 && b > 0 || a > 0 && b < 0 && -1*b <= INT_MAX-a || a < 0 && b > 0 && a >= INT_MIN+b || a < 0 && b < 0 || a == 0 && b!=INT_MIN || b == 0 && a!=INT_MIN )
			{
				a-=b;
				printf("\n%d",a);

			}else

				printf("Error");
			break;

		case 42:           //*****

			if(a==0 || b==0 || a>0 && b>0 && a<=INT_MAX/b || a>0 && b<0 && b>=INT_MIN/a || a<0 && b>0 && a>=INT_MIN/b 
				|| a!=INT_MIN && b!=INT_MIN && a<0 && b<0 && (-1)*a<=(-1)*INT_MAX/b || a==INT_MIN && b<2 && b>-1 
				|| b==INT_MIN && a<2 && a>-1)
			{
				a*=b;
				printf("\n%d",a);

			}else{
				printf("Error");
			}
			
			break;

		case 47:           ///////
			if(b==0 || a==INT_MIN && b==-1 || b==INT_MIN && a==-1)
			{
				printf("Error");
				
			}else{
				if(fabs(a % b) >= b/2 && b!=1 && b!=-1)
				{
					a/=b;
					a++;
				}else
					a/=b;

				printf("\n%d",a);
			}

			break;
		}

	}else					printf("Error");
}

int main()
{
	int i=1;

	while(i!=2)
	{
		Osnova();
		printf("\nPress -1- to continue, -2- to stop\nYou must choose\n");
		scanf("%d\n",&i);
	}

	return 0;
}