#include<cstdio>
#include<algorithm>//含有abs()函数 ，一开始用的是cstdio，单对于long long类型却不支持，要使用llabs,int型取绝对值还是用algorithm吧 

using namespace std;

char fu[4]={'+','-','*','/'};

struct fraction{
	long long nu;
	long long de;
};

long long gcd(long long a,long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}

fraction reduction(fraction a){
	if(a.de==0) return a;
	if(a.de<0){
		a.de=-a.de;
		a.nu=-a.nu;
	}
	if(a.nu==0) a.de=1;
	else{
		int tmp=gcd(abs(a.nu),abs(a.de));
		a.nu/=tmp;
		a.de/=tmp;
	} 
	return a;
}

fraction add(fraction a,fraction b){
	fraction tmp;
	tmp.nu=a.nu*b.de+a.de*b.nu;
	tmp.de=a.de*b.de;
	return reduction(tmp);
}
fraction diff(fraction a,fraction b){
	fraction tmp;
	tmp.nu=a.nu*b.de-b.nu*a.de;
	tmp.de=a.de*b.de;
	return reduction(tmp);
}
fraction prod(fraction a,fraction b){
	fraction tmp;
	tmp.nu=a.nu*b.nu;
	tmp.de=a.de*b.de;
	return reduction(tmp);
}
fraction quot(fraction a,fraction b){
	fraction tmp;
	tmp.nu=a.nu*b.de;
	tmp.de=a.de*b.nu;
	return reduction(tmp);
}

void putnum(fraction a){
	a=reduction(a);
	if(a.de==0) printf("Inf");
	else if(a.de==1){
		if(a.nu<0) printf("(%lld)",a.nu);
		else printf("%lld",a.nu);
	}
	else if(abs(a.nu)>a.de){
		if(a.nu<0) printf("(%lld %lld/%lld)",a.nu/a.de,abs(a.nu)%a.de,a.de);
		else printf("%lld %lld/%lld",a.nu/a.de,a.nu%a.de,a.de);
	}
	else{
		if(a.nu<0) printf("(%lld/%lld)",a.nu,a.de);
		else printf("%lld/%lld",a.nu,a.de);
	}
}
int main(){
	fraction a,b,n[4];
	int i;
	scanf("%lld/%lld %lld/%lld",&a.nu,&a.de,&b.nu,&b.de);
	a=reduction(a);
	b=reduction(b);
	n[0]=add(a,b);
	n[1]=diff(a,b);
	n[2]=prod(a,b);
	n[3]=quot(a,b);
	for(i=0;i<4;i++){
		putnum(a);
		printf(" %c ",fu[i]);
		putnum(b);
		printf(" = ");
		putnum(n[i]);
		if(i<3) printf("\n");
	}
	return 0;
}
