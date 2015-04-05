#include<cstdio>
long long graph[100000][3];
int main(){
    int k=1;
    int n;
    scanf("%d",&n);
    while(n){
        for(int i=0;i<n;i++)
        scanf("%lld %lld %lld",&graph[i][0],&graph[i][1],&graph[i][2]);
        graph[1][0]+=graph[0][1];
        
        graph[0][2]+=graph[0][1];
        
        int m;
        m=graph[1][0];
        if(graph[0][1]<m)
        m=graph[0][1];
        if(graph[0][2]<m)
        m=graph[0][2];
        graph[1][1]+=m;
        
        
        m=graph[1][1];
        if(graph[0][1]<m)
        m=graph[0][1];
        if(graph[0][2]<m)
        m=graph[0][2];
        graph[1][2]+=m;
        
        for(int i=2;i<n;i++){
            m=graph[i-1][0];
            if(graph[i-1][1]<m)
            m=graph[i-1][1];
            graph[i][0]+=m;
            
            m=graph[i][0];
            for(int j=0;j<3;j++)
                if(graph[i-1][j]<m)
                m=graph[i-1][j];
            
            graph[i][1]+=m;
            
            m=graph[i][1];
            if(graph[i-1][1]<m)
            m=graph[i-1][1];
            if(graph[i-1][2]<m)
            m=graph[i-1][2];
            graph[i][2]+=m;
        }
        printf("%d. %lld\n",k++,graph[n-1][1]);
        scanf("%d",&n);
    }
    return 0;
}