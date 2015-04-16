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
	int n;
	II(n);
	while(n){
		int ans=0;
		while(n){
			n>>=1;
			ans++;
		}
		printf("%d\n",ans-1);
		II(n);
	}


	return 0;
}
