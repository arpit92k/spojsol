#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<climits>
#define LL long long
#define INF INT_MAX
#define NINF INT_MIN
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
class hugeint{
	const static int l=30;
	const static int base=1000000000;
	const static int d=9;
	int num[l];
	public:
	hugeint(string n){
		for(int i=0;i<l;i++)
			num[i]=0;
		int l=n.size();
		int i,j;
		int m;
		i=l-1;
		j=0;
		m=1;
		while(i>=0){
			num[j]+=m*(n[i--]-'0');
			m*=10;
			if(m==base){
				m=1;
				j++;
			}
		}
	}
	hugeint(int n){
		for(int i=0;i<l;i++)
			num[i]=0;
		num[l-1]=n;
	}
	void multiply(int n){
		LL rem=0;
		LL mul;
		for(int i=l-1;i>=0;i--){
			mul=num[i]*(LL)n+rem*base;
			num[i]=mul%base;
			rem=mul/=base;
		}
	}
	void divide(int n){
		LL rem=0;
		int div;
		for(int i=l-1;i>=0;i--){
			div=(rem*base+num[i])/n;
			rem=(rem*base+num[i])%n;
			num[i]=div;
		}
	}
	int mod(int d){
		int numc[l];
		for(int i=0;i<l;i++)
			numc[i]=num[i];
		divide(d);
		multiply(d);
		LL x=numc[0]+base*numc[1];
		return x-num[l-1];
		/*int brw=0;
		for(i=l-1;i>=0;i--){
			if(numc[i]<num[i]){
				brw++;
				num[i]+=base-num[i];
				if(num[i-1]){
					num[i-1]--;
					brw=0;
				}
				else{
					j=i-1;
					while(!num[j]){
						num[j]=base-1;
						j--;
					}
				}
			}
			else{
			}
		}*/
	}
	void print(){
		int i=l;
		while(!num[--i]);
		printf("%d",num[i--]);
		while(i>=0)
			printf("%09d",num[i--]);
	}
};
int gcd(int a, int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main(){
	int t;
	II(t);
	while(t--){
		int a,b;
		string s;
		II(a);
		cin>>s;
		hugeint n=hugeint(s);
		b=n.mod(a);
		printf("%d\n",gcd(a,b));
	}
	return 0;
}
