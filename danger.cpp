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
	int pow[7]={1,10,100,1000,10000,100000,1000000};
	int n,p;
	scanf("%de%d",&n,&p);
	while(n||p){
		n*=pow[p];
		int ans=1;
		while(n-ans>=ans)
			ans<<=1;
		n-=ans;
		printf("%d\n",2*n+1);
		scanf("%de%d",&n,&p);
	}


	return 0;
}
