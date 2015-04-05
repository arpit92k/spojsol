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
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int fun[501][101];
int cost[501][101];
vector<pair<int,int> >party;
int main(){
	int b,n;
	III(b,n);
	while(b){
	party.clear();
	party.push_back(make_pair<int,int>(0,0));
	FOR(i,1,n){
		int c,f;
		III(c,f);
		party.push_back(make_pair<int,int>(c,f));
	}
	int c,p;
	FOR(c,1,b)
		FOR(p,1,n){
			fun[c][p]=fun[c][p-1];
			cost[c][p]=cost[c][p-1];
			if((c-party[p].first>=0)&&(fun[c-party[p].first][p-1]+party[p].second>fun[c][p])){
				fun[c][p]=fun[c-party[p].first][p-1]+party[p].second;
				cost[c][p]=cost[c-party[p].first][p-1]+party[p].first;
			}
			if(fun[c-1][p]>=fun[c][p]){
				fun[c][p]=fun[c-1][p];
				cost[c][p]=cost[c-1][p];
			}
		}
	printf("%d %d\n",cost[b][n],fun[b][n]);
	III(b,n);
	}
	return 0;
}
