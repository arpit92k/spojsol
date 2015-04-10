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
LL tree[5000000],lazy[5000000];
LL insert(int n,int a,int b,int s,int e,int v){
	if(lazy[n]){
		tree[n]+=(b-a+1)*lazy[n];
			lazy[2*n]+=lazy[n];
			lazy[2*n+1]+=lazy[n];
		lazy[n]=0;
	}
	LL change=0;
	if(a==s&&b==e){
		lazy[n]+=v;
		return (b-a+1)*((LL)v);
	}
	int m=(a+b)/2;
	if(s>m)
		change=insert(2*n+1,m+1,b,s,e,v);
	else if(e<=m)
		change=insert(2*n,a,m,s,e,v);
	else{
		change=insert(2*n,a,m,s,m,v);
		change+=insert(2*n+1,m+1,b,m+1,e,v);
	}
	tree[n]+=change;
	return change;
}
LL get(int n,int a,int b,int s, int e){
	if(lazy[n]){
		tree[n]+=(b-a+1)*lazy[n];
			lazy[2*n]+=lazy[n];
			lazy[2*n+1]+=lazy[n];
		lazy[n]=0;
	}
	if(a==s&&b==e){
		return tree[n];
	}
	int m=(a+b)/2;
	if(s>m)
		return get(2*n+1,m+1,b,s,e);
	else if(e<=m)
		return get(2*n,a,m,s,e);
	else{
		return get(2*n,a,m,s,m)+get(2*n+1,m+1,b,m+1,e);
	}
}
int main(){
	int t;
	II(t);
	while(t--){
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
		int n,c;
		III(n,c);
		int q,s,e,v;
		FOR(i,0,c){
			scanf("%d %d %d",&q,&s,&e);
			if(q==0){
				II(v);
				insert(1,1,n,s,e,v);
			}
			else{
				printf("%lld\n",get(1,1,n,s,e));
			}
		}
	}
	return 0;
}
