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
vector<int> stamps;
int main(){
	int t,sn;
	II(t);
	sn=1;
	while(t--){
		stamps.clear();
		int r,f;
		III(r,f);
		int ans=0;
		int sum=0;
		int x;
		FOR(i,0,f){
			II(x);
			stamps.push_back(x);
		}
		sort(stamps.begin(),stamps.end());
		int i=f-1;
		while(sum<r&&i>=0){
			ans++;
			sum+=stamps[i--];
		}
		if(sum>=r)
			printf("Scenario #%d:\n%d\n\n",sn++,ans);
		else
			printf("Scenario #%d:\nimpossible\n\n",sn++);
	}
	return 0;
}
