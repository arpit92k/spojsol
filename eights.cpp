#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 10
#define II(X) scanf("%d",&X)
#define IL(X) scanf("%lld",&X)
#define PI(X) printf("%d\n",X)
#define PL(X) printf("%lld\n",X)
#define LL long long
using namespace std;
int main(){
    int count=0;
    int base[4]={192,442,692,942};
    int t;
    II(t);
    while(t--){
        LL k;
        IL(k);
        k--;
        int i;
        LL m;
        i=k%4;
        m=k/4;
        LL ans;
        ans=m*1000+base[i];
        PL(ans);
    }
    return 0;
}