#include<cstdio>
int main(){
	int n,d;
	int ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&d);
		ans^=d;
	}
	printf("%d\n",ans);
	return 0;
}
