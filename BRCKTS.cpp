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
struct node{
	int ob,cb;
	bool bal;
};
node tree[65536];
char str[30002];
void build_tree(int n,int s,int e){
	if(s==e){
		if(str[s]=='('){
			tree[n].ob=1;
			tree[n].cb=0;
		}
		else{
			tree[n].cb=1;
			tree[n].ob=0;
		}
		return;
	}
	int m=(s+e)>>1;
	int l,r;
	l=n<<1;
	r=l|1;
	build_tree(l,s,m);
	build_tree(r,m+1,e);
	if(tree[l].bal&&tree[r].bal)
		tree[n].bal=true;
	else if((tree[l].ob==tree[r].cb)&&tree[l].cb==0&&tree[r].ob==0)
		tree[n].bal=true;
	else tree[n].bal=false;
	int ob,cb;
	ob=tree[l].ob;
	cb=tree[r].cb;
	if(ob>=cb){
		ob-=cb;
		cb=0;
	}
	else{
		cb-=ob;
		ob=0;
	}
	ob+=tree[r].ob;
	cb+=tree[l].cb;
	tree[n].ob=ob;
	tree[n].cb=cb;
}
void update(int n,int s,int e,int i){
	if(s==e){
		if(str[i]=='('){
			tree[n].ob=1;
			tree[n].cb=0;
		}
		else{
			tree[n].cb=1;
			tree[n].ob=0;
		}
		return;
	}
	int m=(s+e)>>1;
	int l,r;
	l=n<<1;
	r=l|1;
	if(i<=m)
		update(l,s,m,i);
	else
		update(r,m+1,e,i);
	if(tree[l].bal&&tree[r].bal)
		tree[n].bal=true;
	else if((tree[l].ob==tree[r].cb)&&tree[l].cb==0&&tree[r].ob==0)
		tree[n].bal=true;
	else tree[n].bal=false;
	int ob,cb;
	ob=tree[l].ob;
	cb=tree[r].cb;
	if(ob>=cb){
		ob-=cb;
		cb=0;
	}
	else{
		cb-=ob;
		ob=0;
	}
	ob+=tree[r].ob;
	cb+=tree[l].cb;
	tree[n].ob=ob;
	tree[n].cb=cb;
}
void exe(int t){
	printf("Test %d:\n",t);
	int n;
	II(n);
	scanf("%s",str);
	build_tree(1,0,n-1);
	int m,c;
	II(m);
	while(m--){
		II(c);
		if(c--){
			if(str[c]=='(')
				str[c]=')';
			else
				str[c]='(';
			update(1,0,n-1,c);
		}
		else if(tree[1].bal)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
int main(){
	FOR(i,1,11)
		exe(i);
	return 0;
}
