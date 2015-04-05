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
class bigint{
	static const int len=10;
	static const int base=1000000000;
	int val[len];
	public:
	bigint(int n){
		FOR(i,1,len)
			val[i]=0;
		val[0]=n;
	}
	void multiply(int n){
		int rem=0;
		FOR(i,0,len){
			LL r=(long long)val[i]*n+rem;
			val[i]=r%base;
			rem=r/base;
		}
	}
	LL divide(int n){
		int rem=0;
		for(int i=len-1;i>=0;i--){
			LL r=(long long)val[i]+(long long)base*rem;
			val[i]=r/n;
			rem=r%n;
		}
	}
	void print(){
		bool f=0;
		for(int i=len-1;i>=0;i--){
			if(!f&&val[i]){
				printf("%d",val[i]);
				f=1;
				continue;
			}
			if(val[i])
				printf("%09d",val[i]);
		}
		if(f)
			printf("\n");
		else
			printf("0\n");
	}
};
void ncr(int n, int r){
	if(r>n/2)
		r=n-r;
	bigint ans(1);
	FOR(i,1,r+1){
		ans.multiply(n-i+1);
		ans.divide(i);
	}
	ans.print();
}
int main(){
	int t;
	II(t);
	while(t--){
		int n,k;
		III(n,k);
		ncr(n-1,k-1);
	}
	return 0;
}
