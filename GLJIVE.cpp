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
int ans;
int main(){
	int x,d,cd;
	ans=0;
	FOR(i,0,10){
		II(x);
		d=100-ans;
		d=d<0?-d:d;
		cd=100-ans-x;
		cd=cd<0?-cd:cd;
		if(cd<=d)
			ans+=x;
		else
			break;
	}
	printf("%d\n",ans);
	return 0;
}
