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
using namespace std;
int main(){
	string str;
	while(getline(cin,str)){
		//cin>>str;
		int l;
		l=str.size();
		int u,c,v;
		u=c=0;
		v=1;
		FOR(i,0,l){
			if(str[i]=='_'){
				u=1;
				if(i+1<l&&str[i+1]=='_')
					v=0;
			}
			else if(str[i]>='A'&&str[i]<='Z')
				c=1;
			else if(!(str[i]>='a'&&str[i]<='z'))
				v=0;
		}
		if(u&&c)
			v=0;
		if(str[0]>='A'&&str[0]<='Z')
			v=0;
		if(str[0]=='_')
			v=0;
		if(str[l-1]=='_')
			v=0;
		string ans;
		ans="";
		int j;
		j=0;
		if(v){
			if(u){
				while(j<l){
					while(j<l&&str[j]!='_')
						ans+=str[j++];
					j++;
					if(j<l)
					ans+=('A'+str[j++]-'a');
				}
			}
			else{
				while(j<l){
					while(j<l&&(str[j]>='a'&&str[j]<='z'))
						ans+=str[j++];
					if(j<l){
						ans+='_';
						ans+=('a'+str[j++]-'A');
					}
				}
			}
			cout<<ans<<endl;
		}
		else
			cout<<"Error!"<<endl;
	}
	return 0;
}
