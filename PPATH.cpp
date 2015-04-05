#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>
#include<cmath>
#include<queue>
#define LIMIT 10000
using namespace std;
queue<int> q;
int primes[10000];
int visited[10000];
int p1,p2,ans;
/*void dfs(int n,int s){
    visited[n]=s;
    if(n==p2&&s<ans){
        ans=s;
        return;
    }
    int d;
    d=n;
    for(int i=0;i<10;i++){
        d/=10;
        d*=10;
        d+=i;
        if(!primes[d]){
            if(d!=p1&&visited[d]==0)
            bfs(d,s+1);
            else if(visited[d]>s+1)
            bfs(d,s+1);
        }
    }
    d=n;
    int t=n%100;
    t/=10;
    t*=10;
    d-=t;
    for(int i=0;i<10;i++){
        d+=i*10;
        if(!primes[d]){
            if(d!=p1&&visited[d]==0)
            bfs(d,s+1);
            else if(visited[d]>s+1)
            bfs(d,s+1);
        }
        d-=i*10;
    }
    d=n;
    t=n%1000;
    t/=100;
    t*=100;
    d-=t;
    for(int i=0;i<10;i++){
        d+=i*100;
        if(!primes[d]){
            if(d!=p1&&visited[d]==0)
            bfs(d,s+1);
            else if(visited[d]>s+1)
            bfs(d,s+1);
        }
        d-=i*100;
    }
    d=n;
    t=n;
    t/=1000;
    t*=1000;
    d-=t;
    for(int i=1;i<10;i++){
        d+=i*1000;
        if(!primes[d]){
            if(d!=p1&&visited[d]==0)
            bfs(d,s+1);
            else if(visited[d]>s+1)
            bfs(d,s+1);
        }
        d-=i*1000;
    }
}*/
int bfs(int p1){
    int level=0;
    int n;
    q.push(p1);
    q.push(-1);
    visited[p1]=1;
    while(!q.empty()){
        while((n=q.front())!=-1){
            q.pop();
            if(n==p2)
            return level;
            int d;
            d=n;
            for(int i=0;i<10;i++){
                d/=10;
                d*=10;
                d+=i;
                if((!primes[d])&&(!visited[d])){
                    visited[d]=1;
                    q.push(d);
                }
            }
            d=n;
            int t=n%100;
            t/=10;
            t*=10;
            d-=t;
            for(int i=0;i<10;i++){
                d+=i*10;
                if((!primes[d])&&(!visited[d])){
                    visited[d]=1;
                    q.push(d);
                }
                d-=i*10;
            }
            d=n;
            t=n%1000;
            t/=100;
            t*=100;
            d-=t;
            for(int i=0;i<10;i++){
                d+=i*100;
                if((!primes[d])&&(!visited[d])){
                    visited[d]=1;
                    q.push(d);
                }
                d-=i*100;
            }
            d=n;
            t=n;
            t/=1000;
            t*=1000;
            d-=t;
            for(int i=1;i<10;i++){
                d+=i*1000;
                if((!primes[d])&&(!visited[d])){
                    visited[d]=1;
                    q.push(d);
                }
                d-=i*1000;
            }
        }
        q.pop();
        level++;
        if(!q.empty())
        q.push(-1);
    }
    return -1;
}
int main(){
    primes[0]=primes[1]=1;
    for(int i=2;i<=sqrt(LIMIT);i++){
        if(!primes[i])
            for(int j=2*i;j<LIMIT;j+=i)
            primes[j]=1;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        memset(visited,0,sizeof(visited));
        while(!q.empty()){
            q.pop();
        }
        scanf("%d %d",&p1,&p2);
        //ans=INT_MAX;
        //dfs(p1,0);
        ans=bfs(p1);
        if(ans==-1)
        printf("Impossible\n");
        else
        printf("%d\n",ans);
    }
    return 0;
}