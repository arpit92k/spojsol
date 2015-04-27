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
char win[1000001];
int main(){
	int k,l,m,n;
	III(k,l);
	FOR(i,1,1000001){
		if(!win[i-1])
			win[i]=1;
		else if(i>=k&&!win[i-k])
			win[i]=1;
		else if(i>=l&&!win[i-l])
			win[i]=1;
	}
	II(m);
	while(m--){
		II(n);
		if(win[n])
			printf("A");
		else
			printf("B");
	}
	printf("\n");
	return 0;
}
