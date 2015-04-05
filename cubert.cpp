#include<iostream>
#define SIZE 300
#define PRECISION 15
using namespace std;
class Bignum{
	char num[SIZE];
	char precision[PRECISION];
	int ndig,ndec;
	void justify(){
		for(int i=ndig-1,int j=SIZE-1;i>=0;i--)
			num[j--]=num[i];
	}
	public:
	bool readnum(){
		char ch;
		ndig=0;
		while((ch=getchar())!='\n')
			if(ch>='0'&&ch<='9')
				num[ndig++]=ch-'0';
		this->justify();
		return ndig>0?true:false;
	}
	void copy(char* first,char* second){
		int i=0;
		while(first[i]!='\0')
			num[i++]=first[i];
		ndig=i;
		i=0;
		while(second[i]!='\0')
			num[i++]=second[i];
		ndec=i;
		this->justify();
	}
	void add(int n){
		int c,d;
		for(int i=SIZE-1,c=0;(i>=(SIZE-ndig))&&n;i--){
			d=n%10;
			n/=10;
			d+=c;
			num[i]+=d%10;
			c=d/10;
		}
		if(i>=SIZE-ndig)
			num[i]+=c;
		else
			num[i]=c;
	}
	void divide(int div){
		char result1[SIZE];
		char result2[PRECISION];
		int n,i,rd;
		rd=n=0;
		i=SIZE-ndig;
		while(i<SIZE){
			n*=10;
			n+=num[i++];
			if(n>=div){
				result1[rd++]=n/div;
				n=n%div;
			}
			else
				result1[rd++]=0;
		}
		result1[i]='\0';
		rd=i=0;
		while(i<ndec){
			n*=10;
			n+=precision[i++];
			if(n>=div){
				result2[rd++]=n/div;
				n%=div;
			}
			else
				result2[rd++]=0;
		}
		result2[i]='\0';
		this->copy(result1,result2);
	}
}
