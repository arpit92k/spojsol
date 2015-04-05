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
int rmix[100][100],smoke[100][100];
int main(){
	int n;
	while(II(n)>0){
		FOR(i,0,n){
			II(rmix[i][i]);
		}
		FOR(l,1,n)
			FOR(i,0,n-l){
				smoke[i][i+l]=INF;
				FOR(j,i,i+l){
					if(smoke[i][j]+rmix[i][j]*rmix[j+1][i+l]<smoke[i][i+l]){
						smoke[i][i+l]=smoke[i][j]+smoke[j+1][i+l]+rmix[i][j]*rmix[j+1][i+l];
						rmix[i][i+l]=(rmix[i][j]*rmix[j+1][i+l])%100;
					}
				}
			}
		printf("%d\n",smoke[0][n-1]);
	}
	return 0;
}
