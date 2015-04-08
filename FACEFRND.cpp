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
int frnd[10000];
vector<int>frndlist[100];
int main(){
	int n;
	II(n);
	FOR(i,0,n){
		int fid,nf,ffid;
		III(fid,nf);
		frnd[fid]=1;
		FOR(j,0,nf){
			II(ffid);
			frndlist[i].push_back(ffid);
		}
	}
	int ans=0;
	FOR(f,0,n){
		int nf;
		nf=frndlist[f].size();
		FOR(j,0,nf)
			if(!frnd[frndlist[f][j]]){
				ans++;
				frnd[frndlist[f][j]]=1;
			}
	}
	printf("%d\n",ans);
	return 0;
}
