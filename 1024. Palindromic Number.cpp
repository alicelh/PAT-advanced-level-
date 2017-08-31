#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char N[15];
int K;
struct number{
	int p[60];//Òª×ã¹»´ó 
	int len;
	number(){
		memset(p,0,sizeof(int));
		len=0;
	}
}n1;

void convertnum(){
	int l=strlen(N);
	for(int i=l-1;i>=0;i--){
		n1.p[l-i-1]=N[i]-'0';
	}
	n1.len=l;
	return;
}

bool Ispal(number a){
	for(int i=0;i<=a.len/2;i++){
		if(a.p[i]!=a.p[a.len-i-1]) return false;
	}
	return true;
}

number sum(number a,number b){
	int carry=0,tmp,i;
	number sum;
	for(i=0;i<a.len||i<b.len;i++){
		tmp=a.p[i]+b.p[i]+carry; 
		sum.p[i]=tmp%10;
		carry=tmp/10;
	}
	sum.len=i;
	if(carry>0){
		sum.p[sum.len++]=carry;
	}
	return sum;
}

number reversenum(number a){
	number b;
	b.len=a.len;
	for(int i=0;i<a.len;i++){
		b.p[i]=a.p[a.len-i-1];
	}
	return b;
}

int main(){
	int i;
	scanf("%s %d",&N,&K);
	convertnum();
	for(i=0;i<K;i++){
		if(Ispal(n1)) break;
		n1=sum(n1,reversenum(n1));
	}
	for(int j=n1.len-1;j>=0;j--){
		printf("%d",n1.p[j]);
	}
	printf("\n");
	printf("%d",i);
	return 0;
}
