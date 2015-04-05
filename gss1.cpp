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
#define getcx getchar_unlocked
inline void inp( int &n )//fast input function
{
	n=0;
	int ch=getcx();
	int sign=1;
	while( ch < '0' || ch > '9' )
	{if(ch=='-')sign=-1; ch=getcx();}
	while( ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}
struct node{
	int max,lmax,rmax,sum;
	node *left,*right;
	node(){
		left=right=NULL;
	}
};
int arr[50000];
node *root;
node *merge(node *n1,node *n2){
	node *t=new node();
	//sum
	t->sum=n1->sum+n2->sum;
	//max
	t->max=n1->max;
	if(n2->max>t->max)
		t->max=n2->max;
	if(n1->rmax+n2->lmax>t->max)
		t->max=n1->rmax+n2->lmax;
	//lmax
	t->lmax=n1->lmax;
	if(n1->sum+n2->lmax>t->lmax)
		t->lmax=n1->sum+n2->lmax;
	//rmax
	t->rmax=n2->rmax;
	if(n2->sum+n1->rmax>t->rmax)
		t->rmax=n2->sum+n1->rmax;
	t->left=n1;
	t->right=n2;
	return t;
}
node *merge_n_del(node *n1,node *n2){
	node *t=new node();
	//sum
	t->sum=n1->sum+n2->sum;
	//max
	t->max=n1->max;
	if(n2->max>t->max)
		t->max=n2->max;
	if(n1->rmax+n2->lmax>t->max)
		t->max=n1->rmax+n2->lmax;
	//lmax
	t->lmax=n1->lmax;
	if(n1->sum+n2->lmax>t->lmax)
		t->lmax=n1->sum+n2->lmax;
	//rmax
	t->rmax=n2->rmax;
	if(n2->sum+n1->rmax>t->rmax)
		t->rmax=n2->sum+n1->rmax;
	delete(n1);
	delete(n2);
	return t;
}
node * build(int s,int e){
	if(s==e){
		node *t=new node();
		t->sum=t->max=t->lmax=t->rmax=arr[s];
		return t;
	}
	else{
		int m=(s+e)/2;
		return merge(build(s,m),build(m+1,e));
	}
}
node* query(node *root,int s,int e,int qs,int qe){
	if(s==qs&&e==qe){
		node *t=new node();
		t->max=root->max;
		t->lmax=root->lmax;
		t->rmax=root->rmax;
		t->sum=root->sum;
		return t;
	}
	int m=(s+e)/2;
	if(qe<=m)
		return query(root->left,s,m,qs,qe);
	else if(qs>m)
		return query(root->right,m+1,e,qs,qe);
	else
		return merge_n_del(query(root->left,s,m,qs,m),query(root->right,m+1,e,m+1,qe));
}
int main(){
	int n;
	inp(n);
	FOR(i,0,n)
		inp(arr[i]);
	root=build(0,n-1);
	int m;
	inp(m);
	FOR(i,0,m){
		int s,e;
		inp(s);
		inp(e);
		s--;
		e--;
		node *ans;
		ans=query(root,0,n-1,s,e);
		printf("%d\n",ans->max);
		delete(ans);
	}
	return 0;
}
