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
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int dp[2001][2001];
int main(){
	int t;
	II(t);
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		int l1,l2;
		l1=s1.length();
		l2=s2.length();
		FOR(i,0,l1)
			dp[i][0]=i;
		FOR(i,0,l2)
			dp[0][i]=i;
		FOR(i,1,l1)
			FOR(j,1,l2){
				dp[i][j]=dp[i-1][j]+1;
				if(dp[i][j-1]+1<dp[i][j])
					dp[i][j]=dp[i][j-1]+1;
				if(s1[i-1]==s2[j-1]&&dp[i-1][j-1]<dp[i][j])
					dp[i][j]=dp[i-1][j-1];
				if(s1[i-1]!=s2[j-1]&&dp[i-1][j-1]+1<dp[i][j])	
					dp[i][j]=dp[i-1][j-1]+1;
			}
		printf("%d\n",dp[l1][l2]);
	}
	return 0;
}
