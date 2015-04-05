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
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
	int n,ex;
	stack<int>st;
	II(n);
	while(n){
		while(!st.empty())
			st.pop();
		ex=1;
		FOR(i,0,n){
			int t;
			II(t);
			if(t!=ex){
				while((!st.empty())&&ex==st.top()){
					st.pop();
					ex++;
				}
				if(t!=ex)
					st.push(t);
				else
					ex++;
			}
			else
				ex++;
		}
		while((!st.empty())&&st.top()==ex){
			st.pop();
			ex++;
		}
		if(ex>n)
			printf("yes\n");
		else
			printf("no\n");
		II(n);
	}
	return 0;
}
