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
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int t;
	II(t);
	while(t--){
		int a,rem;
		string s;
		II(a);
		cin>>s;
		int l=s.size();
		if(a==0){
			cout<<s<<endl;
			continue;
		}
		int i=0;
		rem=0;
		while(i<l){
			if(rem>a)
				rem%=a;
			else{
				rem*=10;
				rem+=s[i++]-'0';
			}
		}
		printf("%d\n",gcd(a,rem));
	}
	return 0;
}
