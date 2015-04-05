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
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
 	int a,d;
	III(a,d);
	while(a||d){
		int mina;
		II(mina);
		FOR(i,1,a){
			int da;
			II(da);
			if(da<mina)
				mina=da;
		}
		int mind1,mind2;
		III(mind1,mind2);
		if(mind2<mind1){
			int t=mind2;
			mind2=mind1;
			mind1=t;
		}
		FOR(i,2,d){
			int dd;
			II(dd);
			if(dd<=mind1){
				mind2=mind1;
				mind1=dd;
			}
			else if(dd<mind2)
				mind2=dd;
		}
		if(mina<mind2)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
		III(a,d);
	}
	return 0;
}
