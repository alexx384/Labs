#include <stdio.h>


int PerSize(long long a, long long b, char c[13])
{
	long long f;
	int s;

	a--;

//размер
	if (b == 0)
		f = a+1;
	else
		f=a+1+b*(-1);

	f/=256;

	switch(f)
	{
	case 1:
		s=1;
		break;
	case 256:
		s=2;
		break;
	case 16777216:
		s=4;
		break;
	}
	printf("%s max = %lli min = %lli size = %d\n",c,a,b,s);
	return 0;
}

int main()
{
	long long i=1;
	char cha=1;
	unsigned char ucha=1;
	int nt=1;
	unsigned int unt=1;
	short rt=1;
	long int ng=1;

//1
	while(cha>0)
	{
		cha*=2;
		i*=2;
	}
    i=PerSize(i,cha,"Char");
	i=1;
//2
	while(ucha>0)
	{
		ucha*=2;
		i*=2;
	}
    i=PerSize(i,ucha,"Unsigned Char");
	i=1;
//3
	while(nt>0)
	{
		nt*=2;
		i*=2;
	}
    i=PerSize(i,nt,"Int");
	i=1;
//4
	while(unt>0)
	{
		unt*=2;
		i*=2;
	}
    i=PerSize(i,unt,"Unsigned Int");
	i=1;
//5
	while(rt>0)
	{
		rt*=2;
		i*=2;
	}
    i=PerSize(i,rt,"Short");
	i=1;
//6
	while(ng>0)
	{
		ng*=2;
		i*=2;
	}
    i=PerSize(i,ng,"Long");
	i=1;

	cha=getchar();
	return 0;
}