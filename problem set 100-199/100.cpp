#include <iostream>
#include <algorithm>
//#include <chrono>
//#include <ctime>

int list[1000000];

int Collatz_count(int n)
{
	int count=1;
	while (n>1)
	{
		
		if(n%2)
		{
			n=n*3+1;
			n>>=1;
			count+=2;
		}
		else
		{
			n>>=1;
			count++;
		}
	}
	return count;
	
}
int cyclen(int n)
{
	if(n==1)
		return 1;
	if(list[n]!=0)
		return list[n];

	int len =Collatz_count(n);
	list[n]=len;
	return len;
}



int main()
{
	//std::chrono::time_point<std::chrono::system_clock> start, end;
	int a,b;
	//start = std::chrono::system_clock::now();
	while(std::cin>>a>>b)
	{
		int lower=std::min(a,b);
		int upper= std::max(a,b);
		int maxN=0;
		for(int i=lower;i<=upper;i++)
		{
			int temp=cyclen(i);
			maxN=std::max(maxN,temp);
		}

		std::cout<<a<<" "<<b<<" "<<maxN<<std::endl;
	}
	//end = std::chrono::system_clock::now();
	//std::chrono::duration<double> elapsed_seconds = end-start;
	//std::cout<<elapsed_seconds.count()<<std::endl;
}