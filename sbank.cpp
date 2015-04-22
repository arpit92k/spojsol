#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstring>
#include<utility>
#include<climits>
#define LL long long
#define II(x) scanf("%d",&x)
#define III(x,y) scanf("%d %d",&x,&y)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
int cnt[10],start[10];
vector<char>accno[100000];
int indx[100000],sorted[100000];
int inp() {
	  char c = gc();
	    while(c<'0' || c>'9') c = gc();
	      int ret = 0;
	      while(c>='0' && c<='9') {
		          ret = 10 * ret + c - 48;
			      c = gc();
			        }
	        return ret;
}
int main(){
	int t;
	t=inp();
	while(t--){
		int n;
		char c;
		n=inp();
		FOR(i,0,n){
			indx[i]=i;
			while((c=gc())!='\n')
				if(c>='0'&&c<='9')
					accno[i].push_back(c);
		}
		for(int j=25;j>=0;j--){
			memset(cnt,0,sizeof(cnt));
			memset(start,0,sizeof(start));
			FOR(i,0,n)
				cnt[accno[i][j]-'0']++;
			FOR(i,1,10){
				start[i]=cnt[i-1];
				cnt[i]+=cnt[i-1];
			}
			FOR(i,0,n)
				sorted[start[accno[indx[i]][j]-'0']++]=indx[i];
			FOR(i,0,n)
				indx[i]=sorted[i];
		}
		int cc;
		FOR(i,0,n){
			FOR(j,0,26){
				if(j==2||j==10||j==14||j==18||j==22)
					pc(' ');
				pc(accno[indx[i]][j]);
			}
			cc=1;
			while(++i<n){
				int k;
				for(k=0;k<26;k++)
					if(accno[indx[i-1]][k]!=accno[indx[i]][k])
						break;
				accno[indx[i-1]].clear();
				if(k==26)
					cc++;
				else
					break;
			}
			printf(" %d\n",cc);
			if(i<n)
			i--;
		}
		accno[indx[n-1]].clear();
		pc('\n');
	}
	return 0;
}
