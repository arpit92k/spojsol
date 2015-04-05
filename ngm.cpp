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
#define FOR(i,a,b) for(i=a;i<b;i++)
#define MAX 250000001
using namespace std;
char win[MAX];
int main(){
	int n,c,b,i,d;
	unsigned char f=0x80;
	for(i=1;i<9;i++)
		win[i/8]|=(f>>(i%8));
	FOR(n,10,MAX){
		c=n;
		while(c){
			d=c%10;
			c/=10;
			if(d)
				if(win[(n-d)/8]&(f>>((n-d)%8)))
					win[n/8]|=(f>>(n%8));
		}
	}
	/*while(scanf("%d",&n)>0){
		
	}*/
	return 0;
}
