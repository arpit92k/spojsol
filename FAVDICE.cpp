#include<cstdio>
#include<iostream>
#include <iomanip>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        double n,p,ans;
        scanf("%lf",&n);
        p=1.0/n;
        ans=0;
        for(double i=1;i<=n;i++){
            ans+=i*p;
        }
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}