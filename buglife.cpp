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
int check[2001];
vector<int>graph[2001];
bool dfs(int n,int gen){
	check[n]=gen;
	gen=(gen==1?2:1);
	int l=graph[n].size();
	FOR(i,0,l){
		if(check[graph[n][i]]){
			if(check[graph[n][i]]==check[n])
				return false;
		}
		else if(!dfs(graph[n][i],gen))
			return false;
	}
	return true;
}
int main(){
	int t,s;
	II(t);
	s=1;
	while(t--){
		int n,r;
		III(n,r);
		memset(check,0,sizeof(check));
		for(int i=1;i<=n;i++)
			graph[i].clear();
		int a,b;
		while(r--){
			III(a,b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		bool flag=true;
		for(int i=1;flag&&i<=n;i++)
			if(!check[i])
				flag=dfs(i,1);
		if(flag)
			printf("Scenario #%d:\nNo suspicious bugs found!\n",s++);
		else
			printf("Scenario #%d:\nSuspicious bugs found!\n",s++);
	}
	return 0;
}
