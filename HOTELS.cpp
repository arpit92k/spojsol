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
int val[300001];
int main(){
	int n,m;
	LL max=0;
	LL cval=0;
	III(n,m);
	FOR(i,0,n)
		II(val[i]);
	int j=0,i=0;
	while(i<n){
		while(i<n&&(cval+val[i]<=m))
			cval+=val[i++];
		if(cval>max)
			max=cval;
		if(i<n)
			cval+=val[i++];
		while(cval>m)
			cval-=val[j++];
	}
	if(cval>max)
		max=cval;
	printf("%lld\n",max);
	return 0;
}
