#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<climits>
#define LL long long
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int stall[1000000];
bool arrange(int d,int n,int c){
	int placed,last;
	placed=1;
	last=stall[0];
	FOR(i,1,n)
		if(stall[i]-last>=d){
			last=stall[i];
			if(++placed==c)
				return true;
		}
	return false;
}
int findmaxmin(int n,int c){
	int s,e,m;
	s=0;
	e=stall[n-1];
	while(s<=e){
		m=s+e;
		m/=2;
		if(arrange(m,n,c))
			s=m+1;
		else
			e=m-1;
	}
	return s-1;
}
int main(){
	int t;
	II(t);
	while(t--){
		int n,c;
		III(n,c);
		FOR(i,0,n)
			II(stall[i]);
		sort(stall,stall+n);
		printf("%d\n",findmaxmin(n,c));
	}
	return 0;
}
