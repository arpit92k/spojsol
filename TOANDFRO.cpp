#include<cstdio>
#include<iostream>
#define II(X) scanf("%d",&X)
using namespace std;
int ans[100][20];
int main(){
    int c;
    char str[202];
    II(c);
    while(c){
        scanf("%s",str);
        int i=0;
        int j=0;
        int w=0;
        while(str[i]!='\0'){
            while((str[i]!='\0')&&w<c)
            ans[j][w++]=str[i++];
            if(str[i]!='\0'){
                j++;
                w--;
            }
            while((str[i]!='\0')&&w>=0)
            ans[j][w--]=str[i++];
            if(str[i]!='\0'){
                w++;
                j++;
            }
        }
        int k;
        for(k=0;k<c;k++)
            for(i=0;i<=j;i++){
                putchar(ans[i][k]);
            }
        putchar('\n');
        II(c);
    }
    return 0;
}