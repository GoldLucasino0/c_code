#include <iostream>
#include <assert.h>
#include <sys/time.h>
using namespace std;

int Fib1(int n)
{
   if (n==0)
	   return 0;
   if (n==1)
	   return 1;
   if (n>1)
	   return Fib1(n-1)+Fib1(n-2);
}

int Fib2(int n)
{
   int F[n];
   F[0]=0;
   F[1]=1;
   
   for (int i=2;i<=n;i++)
   {
	F[i] = F[i-1]+F[i-2];
   }
   return F[n];
}


int Fib3(int n)
{
   int prev, prevprev, cur;
   if (n==0)
	   return 0;
   if (n==1)
	   return 1;
   prev=1;
   prevprev=0;
   for (int i=2;i<=n;i++)
   {
	cur = prev+prevprev;
	prevprev = prev;
	prev=cur;
   }
   return cur;
}

int main()
{
   struct timeval begin,end;
   double elapsed;
   int result1, result2;

   cout <<"n   T(n)ofFib2        F(n)\n";
   for (int i=100;i<=1000;i++)
   {
	gettimeofday (&begin,NULL);   
   	result2 = Fib2(i);
	gettimeofday (&end,NULL);   
	elapsed = (end.tv_sec-begin.tv_sec)+
		((end.tv_usec-begin.tv_usec)/1000000.0);

	cout <<i<<"\t"<< elapsed << "\t" << result2<<endl;
   }

   cout <<"Enter any key to continue:";
   char q;
   cin >> q;

   cout <<"n   T(n)ofFib1    F(n)\n";
   for (int i=10;i<=50;i++)
   {
	gettimeofday (&begin,NULL);   
   	result1 = Fib1(i);
	//assert (result1==result2);
	gettimeofday (&end,NULL);   
	elapsed = (end.tv_sec-begin.tv_sec)+
		((end.tv_usec-begin.tv_usec)/1000000.0);

	cout <<i<<"\t"<<elapsed<<"\t" <<result1<<endl;
   }
}
