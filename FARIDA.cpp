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
#define IL(x) scanf("%lld",&x)
#define IIL(x,y) scanf("%lld %lld",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int coins[10001];
LL ans[10001];
int main(){
	int t;
	II(t);
	for(int ct=1;ct<=t;ct++){
		int n;
		II(n);
		if(n>2){
			III(coins[0],coins[1]);
			ans[0]=coins[0];
			ans[1]=coins[1]>coins[0]?coins[1]:coins[0];
			FOR(i,2,n){
				II(coins[i]);
				ans[i]=(ans[i-2]+coins[i])>ans[i-1]?(ans[i-2]+coins[i]):ans[i-1];
			}
			printf("Case %d: %lld\n",ct,ans[n-1]);
		}
		else if(n==2){
			int x,y;
			III(x,y);
			printf("Case %d: %d\n",ct,x>y?x:y);
		}
		else if(n==1){
			int x;
			II(x);
			printf("Case %d: %d\n",ct,x);
		}
		else
			printf("Case %d: 0\n",ct);
	}
	return 0;
}
