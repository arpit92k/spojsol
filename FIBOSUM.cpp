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
#define MOD 1000000007
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
void multiply(LL m1[][2],LL m2[][2]){
	int m[2][2];
	m[0][0]=(m1[0][0]*m2[0][0])%MOD+(m1[0][1]*m2[1][0])%MOD;
	m[0][1]=(m1[0][0]*m2[0][1])%MOD+(m1[0][1]*m2[1][1])%MOD;
	m[1][0]=(m1[1][0]*m2[0][0])%MOD+(m1[1][1]*m2[1][0])%MOD;
	m[1][1]=(m1[1][0]*m2[0][1])%MOD+(m1[1][1]*m2[1][1])%MOD;
	m1[0][0]=(m[0][0])%MOD;
	m1[0][1]=(m[0][1])%MOD;
	m1[1][0]=(m[1][0])%MOD;
	m1[1][1]=(m[1][1])%MOD;
}
void power(LL m1[][2],int p){
	if(p==1)
		return;
	if(p&1){
		LL m[2][2];
		m[0][0]=(m1[0][0]);
		m[0][1]=(m1[0][1]);
		m[1][0]=(m1[1][0]);
		m[1][1]=(m1[1][1]);
		p/=2;
		power(m1,p);
		multiply(m1,m1);
		multiply(m1,m);
	}
	else{
		p/=2;
		power(m1,p);
		multiply(m1,m1);
	}
}
LL fterm(int n){
	LL m[2][2]={{1,1},{1,0}};
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	int p=n-1;
	power(m,p);
	return m[0][0];
}
int main(){
	int t;
	II(t);
	while(t--){
		int n,m;
		III(n,m);
		printf("%lld\n",((fterm(m+2)-fterm(n+1)+MOD)%MOD));
	}
	return 0;
}
