#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<climits>
#define LL long long
#define IL(x) scanf("%lld",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(i=a;i<b;i++)
using namespace std;
inline LL val(LL n){
	return 3*n*(n-1)+1;
}
bool find(LL v){
	LL s,e,m,mv;
	s=1;
	e=18258;
	while(s<=e){
		m=s+e;
		m/=2;
		mv=3*m*(m-1)+1;
		if(mv==v)
			return true;
		else if(mv<v)
			s=m+1;
		else
			e=m-1;
	}
	return false;
}
int main(){
	LL n;
	LL ans;
	IL(n);
	while(n!=-1){
		if(find(n))
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
		IL(n);
	}

	return 0;
}
