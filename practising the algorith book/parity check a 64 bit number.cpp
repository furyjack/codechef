#include<iostream>

using namespace std;


short parity_check(unsigned long x)
{
	short result=0;
	while(x)
	{
		result ^=1;
		x=x&(x-1);

	}
	return result;


}