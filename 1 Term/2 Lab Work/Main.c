#include <stdio.h>
#include <math.h>
#include <float.h>


double factorial (int n)
{
  double r;
  for (r = 1; n > 1; r *= (n--))
    ;
  return r;
}

int main()
{
	double sum,bef,toch,levo,dop,sn;
	int n;
	float h,x;


//Delete Later
	double i=0; //факториал
	double j=0; //степенная функция
	
	h=0;
	sum=0;
	bef=0;
	toch=1;
	levo=1;
	
	printf("Vvedite x: ");
	scanf("%g",&x);

	printf("Vvedite tochnost': ");
	scanf("%g",&h);


	for(n=0; 1/j != 0 && 1/i != 0 ;n++)
	{
		bef=sum;

		i=factorial(2*n+1);
		j=pow(x,2*n+1);

		printf("Factorial = %.21Lf\n",i);
		printf("Stepen = %.21Lf\n",j);

		dop=pow(-1,n)*j/i;
		sum=sum+dop;
	//	printf("dop = %.100lf\n",dop);
	//	printf("sum = %.100lf\n",sum);

		//-----------расчётточности введённой пользователем------------
		if (fabs(sum-bef) < h && toch == 1)
		{
			toch=sum;
			levo=bef;
		}
		//-----------------------------------------------
	}




	//==========Проверка на точность============
	if(toch==1 && levo==1)
		printf("Izza perepolneniya s takoy tochnost'u\n programma ne mozhet schitat'");
	else
	{
		printf("levo: %.100lf\n",levo);
	    printf("Answer: %.100lf\n",toch);
	}
	//==========================================

	if(bef==0)
		printf("\nAnswer: %.100G\n",x);
	else
		printf("\nAnswer: %.100G\n",bef);

	sn=sin(x);
	printf("sin = %.100lf\n",sn);


	scanf("%g",&x);
	return 0;
}