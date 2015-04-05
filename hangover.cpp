#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 10
#define II(X) scanf("%d",&X)
#define IL(X) scanf("%lld",&X)
#define PI(X) printf("%d\n",X)
#define PL(X) printf("%lld\n",X)
#define LL long long int
using namespace std;
int main(){
    double t;
    scanf("%lf",&t);
    while(t>0){
        double ans;
        int count;
        ans=count=0;
        count++;
        while(ans<t){
            count++;
            ans+=(1.0L/count);
        }
        printf("%d card(s)\n",--count);
        scanf("%lf",&t);
    }
    return 0;
}