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
int find_n(int n){
    int s,e,m,v;
    s=1;
    e=4473;
    while(s<e){
         m=(s+e)/2;
         
    }
}
int main(){
    int n,i;
    LL s=0;
    n=0;
    while(s<10000001){
        n++;
        s=n*(n+1);
        s/=2;
    }
    cout<<n<<endl;
    return 0;
}