#include<cstdio>
#include<vector>
#define II(X) scanf("%d",&X)
using namespace std;
int v[10001];
int main(){
    int n,c,ans,total;
    II(n);
    total=0;
    while(n!=-1){
        for(int i=0;i<n;i++){
            II(c);
            v[i]=c;
            total+=c;
        }
        if(total%n)
            printf("-1\n");
        else{
            ans=0;
            total/=n;
            for(int i=0;i<n;i++){
                if(v[i]>total)
                ans+=v[i]-total;
            }
            printf("%d\n",ans);
        }
        total=0;
        II(n);
    }
    return 0;
}