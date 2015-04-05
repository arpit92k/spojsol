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
using namespace std;
int main(){
	int g,b;
	III(g,b);
	while(g!=-1){
		if(g==0&&b==0){
			printf("0\n");
			III(g,b);
			continue;
		}
		if(g<b){
			int t=b;
			b=g;
			g=t;
		}
		int ans;
		b++;
		ans=g/b;
		if(g%b!=0)
			ans++;
		if(ans==0)
			ans=1;
		printf("%d\n",ans);
		III(g,b);
	}
	return 0;
}
