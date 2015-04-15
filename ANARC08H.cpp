#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<climits>
#define LL long long
#define INF INT_MAX
#define NINF INT_MIN
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
	int n,d;
	III(n,d);
	while(n||d){
		int ans=0;
		for(int i=2;i<=n;i++)
			ans=(ans+d)%i;
		printf("%d %d %d\n",n,d,ans+1);
		III(n,d);
	}
	return 0;
}
