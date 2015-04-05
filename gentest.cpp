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
	int t=20;
	cout<<t<<endl;
	while(t--){
		cout<<"10 100"<<endl;
		int n=rand()%10+1;
		cout<<n<<endl;
		while(n--)
		cout<<rand()%10+1<<" "<<rand()%10+1<<endl;
	}
	return 0;
}
