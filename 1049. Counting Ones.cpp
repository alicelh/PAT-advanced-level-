#include<cstdio>

/*˼·�Ǵӵ�λ����λ����(��2017Ϊ������ÿһλ��0��1��>1���ۣ����Ϊ0����ô��λȡ1�Ͱ���01X��11X,�ܹ�2*100�����������*/

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
