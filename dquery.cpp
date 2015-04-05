#include<iostream>
#include<cstdio>
#define II(x) scanf("%d",&x)
using namespace std;
int mark[1000001];
int arr[30001];
struct node{
	int val,l,r;
	node *left,*right;
	node(){
		val=l=r=-1;
		left=right=NULL;
	}
};
node *root=NULL;
void setup(node * n,int s,int e){
	if(s==e){
		n->l=n->r=s;
		n->val=1;
		return ;
	}
	setup(n->left=new node(),s,(s+e)/2);
	setup(n->right=new node(),(s+e)/2+1,e);
	n->l=s;
	n->r=e;
	n->val=0;
	for(int i=s;i<=e;i++)
		if(mark[arr[i]]==0){
			n->val++;
			mark[arr[i]]=1;
		}
	for(int i=s;i<=e;i++)
		mark[arr[i]]=0;
}
int query(node * n,int s,int e){
	if(s==n->l&&e==n->r)
		return n->val;
	int m=n->l+n->r;
	m/=2;
	if(m>=e)
		return query(n->left,s,e);
	if(m<s)
		return query(n->right,s,e);
	return query(n->left,s,m)+query(n->right,m+1,e);
}
int main(){
	int n,q,i,j;
	II(n);
	for(i=0;i<n;i++){
		II(arr[i]);
	}
	root=new node();
	setup(root,1,n);
	II(q);
	while(q--){
		scanf("%d%d",&i,&j);
		printf("%d\n",query(root,i,j));
	}
	return 0;

}
