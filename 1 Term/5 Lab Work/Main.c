#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <limits.h>
#include <float.h>

int main()
{
	double x,n,s,res;

	scanf("%lf",&x);
	scanf("\n%lf",&n);

	if(x-n > 10)
		s=sqrt(x-n);
	if (x<=n)
	{
		s=(x-n);
		if (s!=0)
		{
			s*=-1;
			s=(-1)*powf(s,1.0/3.0);
		}else s=0;
	}

	if ((x-n>5) && (x-n<=10))
		s=sqrt (x) - sqrt (n);

	if ((x-n)>0 && (x-n)<=5)
		s=sin(x) - cos (x);
	res=log10(x);
	if(log10(x)-1 > DBL_DIG || log10(n)-1 > DBL_DIG)	printf("Error");
	else								printf ("%lf\n", s);

	getchar();
	getchar();
//	system ("pause");
	return 0;


}