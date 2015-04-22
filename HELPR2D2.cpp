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
#define MAX 1000001
using namespace std;
int segtree[1<<21];
int ind;
int ship[MAX];
int query(int n,int s,int e,int qs,int qe){
	if(s==qs&&e==qe)
		return segtree[n];
	int m=(s+e)>>1;
	if(qe<=m)
		return query(n<<1,s,m,qs,qe);
	if(qs>m)
		return query((n<<1)|1,m+1,e,qs,qe);
	int lm,rm;
	lm=query(n<<1,s,m,qs,m);
	rm=query((n<<1)|1,m+1,e,m+1,qe);
	return lm>rm?lm:rm;
}
void insert(int n,int s,int e,int x,int v){
	if(s==e){
		segtree[n]-=v;
		return ;
	}
	int m=(s+e)>>1;
	if(x<=m)
		insert(n<<1,s,m,x,v);
	else
		insert((n<<1)|1,m+1,e,x,v);
	segtree[n]=segtree[n<<1]>segtree[(n<<1)|1]?segtree[n<<1]:segtree[(n<<1)|1];
}
void add(int v){
	if(ind==0){
		ship[ind]+=v;
		insert(1,0,MAX-1,ind++,v);
		return ;
	}
	int max_av;
	max_av=query(1,0,MAX-1,0,ind-1);
	if(max_av<v){
		ship[ind]+=v;
		insert(1,0,MAX-1,ind++,v);
		return;
	}
	int s,e,m;
	s=0;
	e=ind-1;
	while(s<e){
		m=(s+e)>>1;
		max_av=query(1,0,MAX-1,s,m);
		if(max_av>=v)
			e=m;
		else
			s=m+1;
		
	}
	ship[s]+=v;
	insert(1,0,MAX-1,s,v);
}
int main(){
	int t;
	II(t);
	while(t--){
		ind=0;
		int k,n,r,v;
		char d;
		II(k);
		II(n);
		FOR(i,0,1<<21)
			segtree[i]=k;
		memset(ship,0,sizeof(ship));
		getchar();
		while(n){
			d=getchar();
			if(d!='b'){
				v=d-'0';
				d=getchar();
				while(d>='0'&&d<='9'){
					v*=10;
					v+=d-'0';
					d=getchar();
				}
				n--;
				add(v);
			}
			else{
				III(r,v);
				getchar();
				n-=r;
				while(r--)
					add(v);
			}
		}
		int wst=0;
		FOR(i,0,ind)
			wst+=k-ship[i];
		printf("%d %d\n",ind,wst);
	}
	return 0;
}
