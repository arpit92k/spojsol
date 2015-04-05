#include<cstdio>
#define II(X) scanf("%d",&X)
using namespace std;
int mr[11];
int fr[11];
int main(){
    int t;
    II(t);
    while(t--){
    int n;
    II(n);
    for(int i=0;i<n;i++){
        int r;
        II(r);
        mr[r]++;
    }
    for(int i=0;i<n;i++){
        int r;
        II(r);
        fr[r]++;
    }
    int i,j;
    i=j=10;
    int ans=0;
    while(i>=0&&j>=0){
        if(mr[i]&&fr[j])
            if(mr[i]>fr[j]){
                ans+=fr[j]*i*j;
                mr[i]-=fr[j];
                fr[j]=0;
            }
            else{
                ans+=mr[i]*i*j;
                fr[j]-=mr[i];
                mr[i]=0;
            }
            if(mr[i]==0)
            i--;
            if(fr[j]==0)
            j--;
        
    }
    printf("%d\n",ans);
        for(i=0;i<11;i++)
        mr[i]=fr[i]=0;
    }
    return 0;
}
