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
int pizza[3];
int main(){
	int n;
	II(n);
	int ans=0;
	FOR(i,0,n){
		int x,y;
		scanf("%d/%d",&x,&y);
		if(x==1){
			if(y==4)
				pizza[0]++;
			else
				pizza[1]++;
		}
		else
			pizza[2]++;
	}
	while(pizza[2]--){
		ans++;
		if(pizza[0])
		pizza[0]--;
	}
	while(pizza[1]--){
		ans++;
		if(pizza[0]>0)
			pizza[0]-=2;
		else if(pizza[1])
			pizza[1]--;
	}
	while(pizza[0]>0){
		pizza[0]--;
		ans++;
	}
	printf("%d\n",++ans);
	return 0;
}
