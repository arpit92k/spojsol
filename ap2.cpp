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
#define III(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
	int t;
	II(t);
	while(t--){
		LL x,y,s;
		III(x,y,s);
		LL a,d,n;
		n=2*s/(x+y);
		d=(y-x)/(n-5);
		a=x-2*d;
		printf("%lld\n",n);
		FOR(i,0,n){
			printf("%lld ",a);
			a+=d;
		}
	}


	return 0;
}
