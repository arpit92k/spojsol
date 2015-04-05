#include<cstdio>
#define II(X) scanf("%d",&X)
int main(){
    int a,b,t;
    II(t);
    while(t--){
        scanf("%d %d",&b,&a);
        a=a^b;
        printf("%d\n",a%10);
    }
    return 0;
}