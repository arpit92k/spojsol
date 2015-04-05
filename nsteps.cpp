#include<cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int x,y,ans;
        scanf("%d %d",&x,&y);
        ans=2*x;
        if(x==y){
            if(x&1)
                ans--;
            printf("%d\n",ans);
        }
        else if(x==y+2){
            ans-=2;
            if(x&1)
                ans--;
            printf("%d\n",ans);
        }
        else
            printf("No Number\n");
    }
    return 0;
}