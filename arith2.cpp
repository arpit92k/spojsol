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
char buff=0;
LL read_num(){
	LL n=0;
	int ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		n*=10;
		n+=ch-'0';
		ch=getchar();
	}
	buff=ch;
	return n;
}
char read_op(){
	char ch;
	if(buff=='+'||buff=='-'||buff=='*'||buff=='/'||buff=='=')
		return buff;
	ch=getchar();
	while(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!='=')
		ch=getchar();
	return ch;
}
int main(){
	LL ans,n;
	int t;
	II(t);
	while(t--){
		char op;
		ans=read_num();
		op=read_op();
		while(op!='='){
			n=read_num();
			if(op=='+')
				ans+=n;
			else if(op=='-')
				ans-=n;
			else if(op=='*')
				ans*=n;
			else if(op=='/')
				ans/=n;
			op=read_op();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
