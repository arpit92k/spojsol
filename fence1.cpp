#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<climits>
#include<iomanip>
#define LL long long
#define II(x) scanf("%lf",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
	double n;
	II(n);
	while(n){
		cout<<fixed<<setprecision(2)<<(n*n)/(2*M_PI)<<endl;
		II(n);
	}
	return 0;
}
