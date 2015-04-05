#include<iostream>
#include<cstdio>
#define LL long long
#define C const static int
#define I int
#define II(x) scanf("%d",&x)
using namespace std;class hugeint{C l=30;C base=1000000000;C d=9;I num[l];public:hugeint(string n){for(I i=0;i<l;i++)num[i]=0;I l=n.size();I i,j;I m;i=l-1;j=0;m=1;while(i>=0){num[j]+=m*(n[i--]-'0');m*=10;if(m==base){m=1;j++;}}}hugeint(I n){for(I i=0;i<l;i++)num[i]=0;num[l-1]=n;}void multiply(I n){LL rem=0;LL mul;for(I i=l-1;i>=0;i--){mul=num[i]*(LL)n+rem*base;num[i]=mul%base;rem=mul/=base;}}void divide(I n){LL rem=0;I div;for(I i=l-1;i>=0;i--){div=(rem*base+num[i])/n;rem=(rem*base+num[i])%n;num[i]=div;}}I mod(I d){I numc[l];for(I i=0;i<l;i++)numc[i]=num[i];divide(d);multiply(d);LL x=numc[0]+base*numc[1];return x-num[l-1];}void print(){I i=l;while(!num[--i]);printf("%d",num[i--]);while(i>=0)printf("%09d",num[i--]);}};I gcd(I a, I b){if (b==0)return a;else return gcd(b,a%b);}I main(){I t;II(t);while(t--){I a,b;string s;II(a);cin>>s;hugeint n=hugeint(s);b=n.mod(a);printf("%d\n",gcd(a,b));}return 0;}
