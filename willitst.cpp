#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<climits>
#define LL long long
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
	LL n;
	scanf("%lld",&n);
	if(n==0||n==1)
		printf("TAK\n");
	else{
		if(n&(n-1))
			printf("NIE\n");
		else
			printf("TAK\n");
	}


	return 0;
}
