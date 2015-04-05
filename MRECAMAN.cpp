#include<cstdio>
#include<vector>
#include<map>
using namespace std;
map<int,bool> m;
vector<int> seq;
int main(){
    seq.push_back(0);
    m[0]=true;
    for(int i=1;i<=500000;i++){
        int x;
        x=seq[i-1]-i;
        if(x<0||m.find(x)!=m.end()){
            x=seq[i-1]+i;
        }
        m[x]=true;
        seq.push_back(x);
    }
    int x;
    scanf("%d",&x);
    while(x!=-1){
        printf("%d\n",seq[x]);
        scanf("%d",&x);
    }
    return 0;
}