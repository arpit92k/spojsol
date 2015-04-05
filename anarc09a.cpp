#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<climits>
#include<stack>
#define LL long long
#define INF INT_MAX
#define NINF INT_MIN
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
stack<char> st;
int main(){
	int t=0;
	string str;
	cin>>str;
	while(str[0]!='-'){
		int l=str.length();
		int ans=0;
		for(int i=0;i<l;i++){
			if(str[i]=='{')
				st.push(str[i]);
			else {
				if(st.empty()){
					ans++;
					st.push('{');
				}
				else
					st.pop();
			}
		}
		int r=0;
		while(!st.empty()){
			st.pop();
			r++;
		}
		ans+=r/2;
		printf("%d. %d\n",++t,ans);
		cin>>str;
	}
	return 0;
}
