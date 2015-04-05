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
#define IL(x) scanf("%lld",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MAX 1000002
using namespace std;
LL sq[MAX];
bool find(LL v){
	LL m,s,e;
	s=0;
	e=MAX-1;
	while(s<=e){
		m=(s+e)/2;
		if(v==sq[m])
			return true;
		else if(v<sq[m])
			e=m-1;
		else
			s=m+1;
	}
	return false;
}
int main(){
	int t;
	FOR(i,0,MAX)
		sq[i]=i*((LL)i);
	II(t);
	while(t--){
		LL n;
		IL(n);
		int i=0;
		while(n-sq[i]>=0){
			if(find(n-sq[i]))
				break;
			i++;
		}
		if(n-sq[i]>=0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
