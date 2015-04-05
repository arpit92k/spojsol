#include<cstdio>
#define MAX 100000000
#define LL long long int
LL coins[MAX];
LL ans(int i){
    if(i<MAX)
    return coins[i];
    LL ex=ans(i/2)+ans(i/3)+ans(i/4);
    return ex>i?ex:i;
}
int main(){
    LL ex;
    coins[1]=1;
    for(int i=2;i<MAX;i++){
        ex=coins[i/2]+coins[i/3]+coins[i/4];
        coins[i]=ex>i?ex:i;
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",ans(n));
    }
    return 0;
}