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
int room[101][101];
int ans[101][101];
int main(){
	int t;
	II(t);
	while(t--){
		int i,j,h,w,a;
		III(h,w);
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				II(room[i][j]);
		for(j=0;j<w;j++)
			ans[0][j]=room[0][j];
		for(i=1;i<h;i++){
			for(j=0;j<w;j++){
				ans[i][j]=0;
				if(j>0)
					ans[i][j]=ans[i-1][j-1];
				if(ans[i-1][j]>ans[i][j])
					ans[i][j]=ans[i-1][j];
				if(j!=w-1&&ans[i-1][j+1]>ans[i][j])
					ans[i][j]=ans[i-1][j+1];
				ans[i][j]+=room[i][j];
			}
		}
		a=-1;
		for(i=0;i<w;i++)
			if(ans[h-1][i]>a)
				a=ans[h-1][i];
		cout<<a<<endl;
	}
	return 0;
}
