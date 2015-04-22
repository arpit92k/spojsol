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
#define MAX 100001
using namespace std;
int bit[MAX];
void add(int ind){
	while(ind<MAX){
		bit[ind]++;
		ind+=(ind&-ind);
	}
}
void del(int ind){
	while(ind<MAX){
		bit[ind]--;
		ind+=(ind&-ind);
	}
}
int csum(int ind){
	int ans=0;
	while(ind>0){
		ans+=bit[ind];
		ind-=(ind&-ind);
	}
	return ans;
}
int reportkth(int k){
	int s,e,m,ck,ans;
	s=1;
	e=MAX;
	while(s<=e){
		m=(s+e)>>1;
		ck=csum(m);
		if(ck>=k){
			ans=m;
			e=m-1;
		}
		else
			s=m+1;
	}
	return ans;
}
int reportrank(int ind){
	if(ind==1)
		return 1;
	ind--;
	return csum(ind)+1;
}
int main(){
	int t;
	II(t);
	while(t--){
		memset(bit,0,sizeof(bit));
		int q,k,x;
		II(q);
		while(q--){
			III(k,x);
			switch(k){
				case 1:
					add(x);
					break;
				case 2:
					del(x);
					break;
				case 3:
					printf("%d\n",reportkth(x));
					break;
				case 4:
					printf("%d\n",reportrank(x));
			}
		}
	}
	return 0;
}
