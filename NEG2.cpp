#include<iostream>
#include<cstdio>
#include<stack>
#define LL long long
using namespace std;
stack<int> ans;
int negabinary(unsigned int value)
{
	unsigned int Schroeppel = 0xAAAAAAAA;
	return (value + Schroeppel) ^ Schroeppel;
}
int main(){
	LL n;
	scanf("%lld",&n);
	if(n==0){
	    printf("0\n");
	    return 0;
	}
	/*int nb=negabinary(n);
    unsigned int mask=0x80000000;
    while((nb&mask)==0)
    mask>>=1;
    while(mask){
        if(nb&mask)
        printf("1");
        else
        printf("0");
        mask>>=1;
    }*/
	while (n != 0)
	{
		int remainder = n % -2;
		n = n / -2;
 
		if (remainder < 0)
		{
			remainder += 2;
			n += 1;
		}
		ans.push(remainder);
	}
	while(!ans.empty()){
	    printf("%d",ans.top());
	    ans.pop();
	}
	printf("\n");
	return 0;
}
