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
#define MAXN 524288
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int tree[MAXN];
int lazy[MAXN];
int query(int n,int s,int e,int qs,int qe){
	int l=n<<1;
	int r=l|1;
	if(lazy[n]){
		lazy[l]=!lazy[l];
		lazy[r]=!lazy[r];
		lazy[n]=!lazy[n];
		tree[n]=e-s+1-tree[n];
	}
	if(s==qs&&e==qe)
		return tree[n];
	int m=(s+e)>>1;
	if(qe<=m)
		return query(l,s,m,qs,qe);
	else if(qs>m)
		return query(r,m+1,e,qs,qe);
	return query(l,s,m,qs,m)+query(r,m+1,e,m+1,qe);
}
int update(int n,int s,int e,int qs,int qe){
	int l=n<<1;
	int r=l|1;
	if(lazy[n]){
		lazy[l]=!lazy[l];
		lazy[r]=!lazy[r];
		lazy[n]=!lazy[n];
		tree[n]=e-s+1-tree[n];
	}
	if(s==qs&&e==qe){
		lazy[n]=!lazy[n];
		return e-s+1-tree[n]-tree[n];
	}
	int m=(s+e)>>1;
	int c=0,d=0;
	if(qe<=m)
		c=update(l,s,m,qs,qe);
	else if(qs>m)
		d=update(r,m+1,e,qs,qe);
	else{
		c=update(l,s,m,qs,m);
		d=update(r,m+1,e,m+1,qe);
	}
	tree[n]+=c;
	tree[n]+=d;
	return c+d;
}
int main(){
	int n,m;
	III(n,m);
	int c,s,e;
	FOR(i,0,m){
		scanf("%d %d %d",&c,&s,&e);
		if(c)
			printf("%d\n",query(1,1,n,s,e));
		else
			update(1,1,n,s,e);
	}
	return 0;
}
