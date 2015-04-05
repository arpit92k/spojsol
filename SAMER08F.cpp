#include<cstdio>
#include<iostream>
#define II(X) scanf("%d",&X)
using namespace std;
int ans[101];
int main(){
    int n,i;
    ans[0]=0;
    for(i=1;i<=100;i++)
        ans[i]=i*i+ans[i-1];
    II(i);
    while(i){
        printf("%d\n",ans[i]);
        II(i);
    }
    return 0;
}