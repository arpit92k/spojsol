#include<cstdio>
using namespace std;
int bus[101][101];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&bus[i][j]);
    int min;
    for(int i=1;i<n;i++){
        min=bus[i-1][0];
        if(bus[i-1][1]<min)
        min=bus[i-1][1];
        bus[i][0]+=min;
        for(int j=1;j+1<m;j++){
            min=bus[i-1][j-1];
            if(bus[i-1][j]<min)
            min=bus[i-1][j];
            if(bus[i-1][j+1]<min)
            min=bus[i-1][j+1];
            bus[i][j]+=min;
        }
        min=bus[i-1][m-2];
        if(bus[i-1][m-1]<min)
        min=bus[i-1][m-1];
        bus[i][m-1]+=min;
    }
    min=bus[n-1][0];
    for(int i=1;i<m;i++)
        if(bus[n-1][i]<min)
            min=bus[n-1][i];
    printf("%d\n",min);
    return 0;
}