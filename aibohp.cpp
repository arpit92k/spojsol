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
int ans[6101][6101];
int main(){
	int t;
	string str;
	II(t);
	while(t--){
		cin>>str;
		int l=str.length();
		for(int d=1;d<l;d++)
			for(int i=0;i+d<l;i++){
				int j=i+d;
				ans[i][j]=(ans[i+1][j]<ans[i][j-1]?ans[i+1][j]:ans[i][j-1])+1;
				if(str[i]==str[j]&&ans[i+1][j-1]<ans[i][j])
					ans[i][j]=ans[i+1][j-1];
			}
		printf("%d\n",ans[0][l-1]);
	}


	return 0;
}
