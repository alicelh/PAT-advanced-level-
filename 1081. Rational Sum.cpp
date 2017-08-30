#include<cstdio>
#include<stdlib.h>//abs()在这个库里

int N;
struct fraction{
	int nu;
	int de;
}f[100];

int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}

fraction ref(fraction a){
	if(a.nu==0) a.de=1;
	int g=gcd(abs(a.nu),abs(a.de));
	a.nu/=g;
	a.de/=g;
	return a;
}

fraction addfraction(fraction a,fraction b){
	fraction tmp;
	tmp.nu=a.nu*b.de+b.nu*a.de;
	tmp.de=a.de*b.de;
	return ref(tmp);
}

int main(){
	int i;
	fraction sum;
	sum.nu=0;
	sum.de=1;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d/%d",&f[i].nu,&f[i].de);
		sum=addfraction(sum,f[i]);
	}
	if(sum.nu==0||sum.de==1) printf("%d",sum.nu);
	else if(abs(sum.nu/sum.de)>0){
		printf("%d %d/%d",sum.nu/sum.de,abs(sum.nu)%sum.de,sum.de);
	}
	else printf("%d/%d",sum.nu,sum.de);
	return 0;
}
