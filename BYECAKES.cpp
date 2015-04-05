#include<iostream>
#include<cstdio>
using namespace std;
inline int count(int n,int n1){
    if(n%n1)
    return n/n1+1;
    return n/n1;
}
int main(){
    int e,f,s,m,e1,f1,s1,m1,ea,fa,sa,ma;
    scanf("%d %d %d %d %d %d %d %d",&e,&f,&s,&m,&e1,&f1,&s1,&m1);
    while(e!=-1){
        int max=0;
        int x;
        x=count(e,e1);
        if(x>max)
        max=x;
        x=count(f,f1);
        if(x>max)
        max=x;
        x=count(s,s1);
        if(x>max)
        max=x;
        x=count(m,m1);
        if(x>max)
        max=x;
        ea=max*e1-e;
        fa=max*f1-f;
        sa=max*s1-s;
        ma=max*m1-m;
        printf("%d %d %d %d\n",ea,fa,sa,ma);
        scanf("%d %d %d %d %d %d %d %d",&e,&f,&s,&m,&e1,&f1,&s1,&m1);
    }
    return 0;
}