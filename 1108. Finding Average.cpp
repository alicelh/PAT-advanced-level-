#include<cstdio>
#include<cmath>
#include<cstring>

char a[100];
int N;
double sum=0;

bool pro(char a[]){
	int i=0,flag=0;
	int len=strlen(a);
	if(a[0]=='-'){
		i=1;
	}
	if(i==len) return false;
	for(;i<len;i++){
		if(a[i]=='.'){
			if(i==0||flag) return false;
			flag=i;
		}
		else{
			if(a[i]<'0'||a[i]>'9') return false;
		}
	}
	if(flag!=0&&len-flag-1>2) return false;//有小数点才需要判断 
	return true;
}
int main(){
	int i,j,num=0;
	bool flag;
	double result;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s",a);
		flag=pro(a);
		if(flag){
			sscanf(a,"%lf",&result);
			if(result<=1000.0&&result>=-1000.0){
				sum+=result;
				num++;
			}
			else printf("ERROR: %s is not a legal number\n",a);
		}
		else printf("ERROR: %s is not a legal number\n",a);
	}
	if(num==1) printf("The average of 1 number is %.2f\n",sum);
	else if(num==0){
		printf("The average of 0 numbers is Undefined\n");
	}
	else printf("The average of %d numbers is %.2f\n",num,sum/num);
	return 0;
}
