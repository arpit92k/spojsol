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
int arr[20000];
int main(){
	int t;
	II(t);
	while(t--){
		int n,k;
		III(n,k);
		FOR(i,0,n)
			II(arr[i]);
		sort(arr,arr+n);
		int min=INF;
		int i,j;
		for(i=0,j=k-1;j<n;i++,j++)
			if(arr[j]-arr[i]<min)
				min=arr[j]-arr[i];
		printf("%d\n",min);
	}
	return 0;
}
