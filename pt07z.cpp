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
using namespace std;
int visited[10001];
vector<int> adj[10001];
int ans;
int visit(int n){
	visited[n]=1;
	int pl;
	int max1=0;
	int max2=0;
	int l=adj[n].size();
	for(int i=0;i<l;i++)
		if(!visited[adj[n][i]]){
			pl=visit(adj[n][i]);
			pl++;
			if(pl>=max1){
				max2=max1;
				max1=pl;
			}
			else if(pl>max2)
				max2=pl;
		}
	max2+=max1;
	if(max2>ans)
		ans=max2;
	return max1;
}
int main(){
	int n;
	II(n);
	for(int i=1;i<n;i++){
		int a,b;
		III(a,b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	visit(1);
	printf("%d\n",ans);
	return 0;
}
