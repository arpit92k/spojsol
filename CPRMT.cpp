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
int main(){
	char s1[1001],s2[1001];
	int f1['z'+1],f2['z'+1];
	while(scanf("%s",s1)>0){
		scanf("%s",s2);
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		for(int i=0;s1[i]!='\0';i++)
			f1[s1[i]]++;
		for(int i=0;s2[i]!='\0';i++)
			f2[s2[i]]++;
		for(int i='a';i<='z';i++){
			while(f1[i]--&&f2[i]--)
				printf("%c",i);
		}
		printf("\n");
	}
	return 0;
}
