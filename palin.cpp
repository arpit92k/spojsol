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
char str[1000001];
int main(){
	II(t);
	while(t--){
		scanf("%s",str);
		int inc=0;
		int l=strlen(str);
		int i,j;
		if(l&1)
			i=j=l/2;
		else{
			j=l/2;
			i=j-1;
		}
		while(i<j){
			if(str[i]<str[j])
				str[j]=str[i];
			if(str[i]>str[j])
		}

	}
	return 0;
}
