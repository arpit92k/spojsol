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
char sent[10000],trimmed[10000];
int trim(){
	int i=0;
	while(sent[i]!='\0'&&sent[i]==' ')
		i++;
	int j=0;
	while(sent[i]!='\0')
		trimmed[j++]=sent[i++];
	while(trimmed[--j]==' ');
	trimmed[++j]='\0';
	return j;
}
int main(){
	scanf("%[^\n]d",sent);
	trim();
	while(trimmed[0]!='*'){
		int i=0;
		char s=tolower(trimmed[0]);
		while(trimmed[i]!='\0'){
			while(trimmed[i]!=' '&&trimmed[i]!='\0')
				i++;
			if(trimmed[i]==' '){
				i++;
				if(tolower(trimmed[i])!=s)
					break;
			}
		}
		if(trimmed[i]=='\0')
			printf("Y\n");
		else
			printf("N\n");
		getchar();
		scanf("%[^\n]d",sent);
		trim();
	}
	return 0;
}
