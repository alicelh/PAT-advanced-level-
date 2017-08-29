#include<cstdio>

/*思路是从低位到高位分析(以2017为例），每一位分0、1、>1讨论，如果为0，那么这位取1就包括01X、11X,总共2*100种情况。。。*/

int main(){
	int n,num=0,a=1,left,now,right;
	scanf("%d",&n);
	while(n/a!=0){
		left=n/(a*10);
		now=n/a%10;
		right=n%a;
		if(now==0) num+=left*a;
		if(now==1) num+=left*a+right+1;
		if(now>1) num+=(left+1)*a;
		a*=10;
	}
	printf("%d",num);
	return 0;
}
