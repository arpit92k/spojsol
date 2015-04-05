#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#define LL long long
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define MOD 1000007
using namespace std;
int main(){
	int t;
	II(t);
	while(t--){
		int n;
		II(n);
		LL ans;
		ans=(n*(n+1))%MOD;
		if(n&1){
			ans+=(((n-1)/2)*n)%MOD;
			ans%=MOD;
		}
		else{
			ans+=((n/2)*(n-1))%MOD;
			ans%=MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
