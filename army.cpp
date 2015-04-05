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
vector<int>g;
vector<int>m;
int main(){
	int t;
	II(t);
	while(t--){
		int ng,nm;
		g.clear();
		m.clear();
		III(ng,nm);
		FOR(i,0,ng){
			int x;
			II(x);
			g.push_back(x);
		}
		FOR(i,0,nm){
			int x;
			II(x);
			m.push_back(x);
		}
		sort(g.begin(),g.end());
		sort(m.begin(),m.end());
		int i,j;
		i=j=0;
		while(i<ng&&j<nm){
			if(g[i]<m[j])
				i++;
			else
				j++;
		}
		if(j==nm)
			printf("Godzilla\n");
		else
			printf("MechaGodzilla\n");
	}


	return 0;
}
