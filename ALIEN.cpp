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
int ppl[300001];
int main(){
	int t;
	II(t);
	while(t--){
		int n,b;
		III(n,b);
		FOR(i,0,n)
			II(ppl[i]);
		int maxst,minppl,cst,cppl;
		maxst=minppl=cst=cppl=0;
		int s,e;
		s=0,e=0;
		while(e<n){
			while(e<n&&cppl+ppl[e]<=b){
				cppl+=ppl[e++];
				cst++;
			}
			if(cst>maxst){
				maxst=cst;
				minppl=cppl;
			}
			else if(cst==maxst&&cppl<minppl)
				minppl=cppl;
			if(e<n){
				cppl+=ppl[e++];
				cst++;
			}
			while(cppl>b){
				cppl-=ppl[s++];
				cst--;
			}
		}
		if(cst>maxst){
			maxst=cst;
			minppl=cppl;
		}
		else if(cst==maxst&&cppl<minppl)
			minppl=cppl;
		printf("%d %d\n",minppl,maxst);
	}	return 0;
}
