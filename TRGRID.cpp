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
	int t;
	II(t);
	while(t--){
		int n,m;
		III(n,m);
		if(n>m){
			if(m&1)
				printf("D\n");
			else
				printf("U\n");
		}
		else{
			if(n&1)
				printf("R\n");
			else
				printf("L\n");
		}
	}
	return 0;
}
