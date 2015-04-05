#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<climits>
#define LL unsigned long long
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
LL ncr(LL n, LL r){
	if(r>n-r)
		r=n-r;
	LL ans=1;
	FOR(i,1,r){
		ans*=(n-i+1);
		ans/=i;
	}
	return ans;
}
int main(){
	int t;
	II(t);
	while(t--){
		int n,k;
		III(n,k);
		LL ans=0;
		ans=ncr(n-1,k-1);
		printf("%lld\n",ans);
	}
	return 0;
}
