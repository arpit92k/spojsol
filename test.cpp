/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>l2;
inline int find(int n,int l){
	int s=0;
	int e=l;
	int m;
	while(s<=e){
		m=(s+e)/2;
		if(l2[m]>=n)
			e=m-1;
		else
			s=m+1;
	}
	if(l2[s]==n){
		int is=s;
		s=0;
		e=l;
		while(s<=e){
			m=(s+e)/2;
			if(l2[m]<=n)
				s=m+1;
			else
				e=m-1;
		}
		return e-is+1;
	}
	else
		return 0;
}
int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        l2.push_back(x);
    }
    sort(l2.begin(),l2.end());
    cout<<find(1,n-1)<<endl;
    return 0;
}*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[4000],b[4000],c[4000],d[4000];
int l1[16000000],l2[16000000];
inline int find(int n,int l){
	int s=0;
	int e=l;
	int m;
	while(s<=e){
		m=(s+e)/2;
		if(l2[m]>=n)
			e=m-1;
		else
			s=m+1;
	}
	if(l2[s]==n){
		int is=s;
		s=0;
		e=l;
		while(s<=e){
			m=(s+e)/2;
			if(l2[m]<=n)
				s=m+1;
			else
				e=m-1;
		}
		return e-is+1;
	}
	else
		return 0;
}
inline int trim(int *arr,int n){
	int j=1;
	for(int i=1;i<n;i++)
		if(arr[i]!=arr[i-1])
		arr[j++]=arr[i];
	return j;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d %d %d",a+i,b+i,c+i,d+i);
	int la,lb,lc,ld;
	/*sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);
	sort(d,d+n);
	la=trim(a,n);
	lb=trim(b,n);
	lc=trim(c,n);
	ld=trim(d,n);*/
	int k1=0;
	la=lb=lc=ld=n;
	for(int i=0;i<la;i++)
		for(int j=0;j<lb;j++)
			l1[k1++]=a[i]+b[j];
	int k2=0;
	for(int i=0;i<lc;i++)
		for(int j=0;j<ld;j++)
			l2[k2++]=c[i]+d[j];
	long long ans=0;
	sort(l2,l2+k2);
	k2--;
	for(int i=0;i<k1;i++)
		ans+=find(-l1[i],k2);
	cout<<ans<<endl;
	return 0;
}