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
int m1[1000],m2[1000];
int main(){
	int t;
	II(t);
	while(t--){
		int n1,n2;
		II(n1);
		FOR(i,0,n1)
			II(m1[i]);
		II(n2);
		FOR(i,0,n2)
			II(m2[i]);
		sort(m1,m1+n1);
		sort(m2,m2+n2);
		int ans=1000001;
		int i,j,d;
		i=j=0;
		int f,s,b;
		while(i<n1&&j<n2){
			d=m1[i]-m2[j];
			d=d<0?-d:d;
			if(d<ans)
				ans=d;
			f=1000001;
			if(i+1<n1){
				f=m1[i+1]-m2[j];
				f=f<0?-f:f;
			}
			s=1000001;
			if(j+1<n2){
				s=m1[i]-m2[j+1];
				s=s<0?-s:s;
			}
			b=1000001;
			if(i+1<n1&&j+1<n2){
				b=m1[i+1]-m2[j+1];
				b=b<0?-b:b;
			}
			if(f<s&&f<b)
				i++;
			else if(s<f&&s<b)
				j++;
			else{
				i++;
				j++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
