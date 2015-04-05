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
int trt[2000];
int sum[2000][2000];
int value[2000][2000];
int main(){
	int n;
	II(n);
	FOR(i,0,n)
		II(trt[i]);
	FOR(i,0,n){
		sum[i][i]=trt[i];
		value[i][i]=trt[i];
	}
	FOR(i,0,n)
		FOR(j,i+1,n)
			sum[i][j]=sum[i][j-1]+trt[j];
	int v;
	FOR(gap,1,n)
		for(int i=0,j=i+gap;j<n;i++,j++){
				value[i][j]=value[i][j-1]+sum[i][j-1]+trt[j];
				v=value[i+1][j]+sum[i+1][j]+trt[i];
				if(v>value[i][j])
					value[i][j]=v;
		}
	printf("%d\n",value[0][n-1]);
	return 0;
}
