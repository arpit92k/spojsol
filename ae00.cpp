#include<cstdio>
#include<cmath>
using namespace std;
int ans[10001];
int main(){
    int n;
    scanf("%d",&n);
    ans[0]=0;
    ans[1]=1;
    ans[2]=2;
    ans[3]=3;
    for(int i=4;i<=n;i++){
        int sq=sqrt(i);
        ans[i]=ans[i-1]+1;
        for(int j=2;j<=sq;j++){
            if(i%j==0){
                ans[i]++;
            }
        }
    }
    printf("%d\n",ans[n]);
    return 0;
}