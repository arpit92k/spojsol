#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<climits>
#define LL long long
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int tree=1;
vector<int> graph[10001];
int visited[10001];
int finishd[10001];
void visit(int p,int n){
	visited[n]=1;
	int l=graph[n].size();
	FOR(i,0,l){
		if(!visited[graph[n][i]])
			visit(n,graph[n][i]);
		else if(graph[n][i]!=p)
			tree=0;
	}
}
int main(){
	int n,m;
	III(n,m);
	FOR(i,0,m){
		int a,b;
		III(a,b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i=1;tree&&i<=n;i++)
		if(!visited[i])
			visit(0,i);
	if(tree)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
