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
int power[500];
int main(){
	int t;
	II(t);
	while(t--){
		int n,m,d;
		scanf("%d %d %d",&n,&m,&d);
		FOR(i,0,n)
			II(power[i]);
		n--;
		while(n>=0&&m){
			if(power[n]-d>0){
				m--;
				power[n]-=d;
			}
			else
				n--;
		}
		if(m)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
