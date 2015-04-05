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
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int coin[500][2];
int value[100001];
int main(){
	int t;
	II(t);
	while(t--){
		int e,f,w;
		III(e,f);
		w=f-e;
		FOR(i,0,w)
			value[i]=INF;
		value[w]=INF;
		value[0]=0;
		int nc;
		II(nc);
		FOR(i,0,nc){
			III(coin[i][0],coin[i][1]);
			value[coin[i][1]]=coin[i][0];
		}
		w++;
		FOR(i,0,w){
			FOR(j,0,nc){
				if(i>=coin[j][1]&&value[i-coin[j][1]]!=INF&&value[i-coin[j][1]]+coin[j][0]<value[i])
						value[i]=value[i-coin[j][1]]+coin[j][0];
			}
		}
		w--;
		if(w==0)
			printf("The minimum amount of money in the piggy-bank is 0.\n");
		else if(value[w]==INF)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",value[w]);
	}
	return 0;
}
