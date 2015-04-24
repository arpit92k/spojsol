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
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
vector<int>freq,csum;
int tree[131072];
int build_tree(int n,int s,int e){
	if(s==e)
		return tree[n]=freq[s];
	int m=(s+e)>>1;
	int l,r;
	l=n<<1;
	r=l|1;
	l=build_tree(l,s,m);
	r=build_tree(r,m+1,e);
	return tree[n]=(l>r?l:r);
}
int query(int n,int s,int e,int qs,int qe){
	if(s==qs&&e==qe)
		return tree[n];
	int m=(s+e)>>1;
	int l=n<<1;
	int r=l|1;
	if(qe<=m)
		return query(l,s,m,qs,qe);
	else if(qs>m)
		return query(r,m+1,e,qs,qe);
	l=query(l,s,m,qs,m);
	r=query(r,m+1,e,m+1,qe);
	return l>r?l:r;
}
int findind(int sum){
	int s=0,e=csum.size()-1;
	int ind,m;
	while(s<=e){
		m=(s+e)>>1;
		if(csum[m]>=sum){
			ind=m;
			e=m-1;
		}
		else
			s=m+1;
	}
	return ind;
}
int main(){
	int n,q,f,px,x;
	II(n);
	while(n){
		freq.clear();
		csum.clear();
	freq.push_back(0);
	csum.push_back(0);
	II(q);
	II(px);
	f=1;
	FOR(i,2,n){
		II(x);
		if(x!=px){
			freq.push_back(f);
			csum.push_back(f);
			px=x;
			f=1;
		}
		else
		f++;
	}
	if(f){
		freq.push_back(f);
		csum.push_back(f);
	}
	int l=freq.size()-1;
	FOR(i,2,l)
		csum[i]+=csum[i-1];
	build_tree(1,1,l);
	while(q--){
		int s,e,si,ei;
		III(s,e);
		si=findind(s);
		ei=findind(e);
		int ans=-1;
		if(si==ei)
			ans=e-s+1;
		else{ 
			if(ei-si>1)
				ans=query(1,1,l,si+1,ei-1);
			if(csum[si]-s+1>ans)
				ans=csum[si]-s+1;
			if(freq[ei]-csum[ei]+e>ans)
				ans=freq[ei]-csum[ei]+e;
		}
		printf("%d\n",ans);
	}
	II(n);
	}
	return 0;
}
