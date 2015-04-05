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
#define FOR(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int perm[100001];
int main(){
	int n;
	II(n);
	while(n){
		int i;
		FOR(i,1,n)
			II(perm[i]);
		FOR(i,1,n){
			if(perm[perm[i]]!=i)
				break;
		}
		if(i>n)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
		II(n);
	}
	return 0;
}
