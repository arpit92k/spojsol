#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#define LL long long
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(i=a;i<b;i++)
using namespace std;
int hash(string seq){
	if(seq=="TTT")
		return 0;
	if(seq=="TTH")
		return 1;
	if(seq=="THT")
		return 2;
	if(seq=="THH")
		return 3;
	if(seq=="HTT")
		return 4;
	if(seq=="HTH")
		return 5;
	if(seq=="HHT")
		return 6;
	if(seq=="HHH")
		return 7;
}
int main(){
	int t,n;
	int count[8];
	string s,seq;
	II(t);
	n;
	while(t--){
		II(n);
		memset(count,0,sizeof(count));
		cin>>s;
		seq="XXX";
		seq[1]=s[0];
		seq[2]=s[1];
		for(int i=2;i<40;i++){
			seq[0]=seq[1];
			seq[1]=seq[2];
			seq[2]=s[i];
			count[hash(seq)]++;
		}
		printf("%d ",n);
		for(int i=0;i<8;i++){
			printf("%d ",count[i]);
		}
		printf("\n");
	}
	return 0;
}
