#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<climits>
#include <deque>
#define LL long long
#define INF INT_MAX
#define NINF INT_MIN
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
deque<int> q;
vector<int>array;
int main(){
	int n,k,x,i;
	II(n);
	for(i=0;i<n;i++){
		II(x);
		array.push_back(x);
	}
	II(k);
	q.push_back(0);
	for(i=1;i<k;i++){	
		x=array[i];
		while((!q.empty())&&(array[q.back()]<=array[i]))
			q.pop_back();
		q.push_back(i);
	}
	for(i=k;i<n;i++){
		printf("%d ",array[q.front()]);
		while(!q.empty()&&q.front()<=i-k)
			q.pop_front();
		while((!q.empty())&&(array[q.back()]<=array[i]))
			q.pop_back();
		q.push_back(i);
	}
	printf("%d\n",array[q.front()]);
	return 0;
}
