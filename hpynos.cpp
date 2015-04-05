#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<map>
#define LL long long
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(i=a;i<b;i++)
using namespace std;
map<int,int> mmap;
int main(){
	int n,m,d,ans;
	II(n);
	mmap[n]=1;
	ans=0;
	while(n!=1){
		m=0;
		while(n){
			d=n%10;
			n/=10;
			m+=d*d;
		}
		n=m;
		if(mmap[n])
			break;
		mmap[n]=1;
		ans++;
	}
	if(n==1)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
