#include<iostream>
using namespace std;
int main(){
    int t;
    long long a,b,c,ans;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        ans=a*a-2*b;
        if(ans<0)
        ans=-ans;
        cout<<ans<<endl;
    }
}
