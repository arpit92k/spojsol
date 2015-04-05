#include<cstdio>
int main(){
    long long int t;
    scanf("%lld",&t);
    while(t--){
        long long int n;
        scanf("%lld",&n);
        long long int sum=0,nc;
        for(int i=0;i<n;i++){
            scanf("%lld",&nc);
            sum+=nc;
            sum%=n;
        }
        if(sum)
        printf("NO\n");
        else
        printf("YES\n");
    }
    return 0;
}