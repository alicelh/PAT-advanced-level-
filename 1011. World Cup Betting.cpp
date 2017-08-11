#include<cstdio>

using namespace std;

int main(){
	int i;
	double a,b,c,sum;
	char index[3];
	double num[3];
	for(i=0;i<3;i++){
		scanf("%lf%lf%lf",&a,&b,&c);
		index[i]='W';
		num[i]=a;
		if(a<b){
			index[i]='T';
			num[i]=b;
		}
		if(c>num[i]){
			index[i]='L';
			num[i]=c;
		}
	}
	
	sum=(num[0]*num[1]*num[2]*0.65-1)*2;
	
	for(i=0;i<3;i++)
		printf("%c ",index[i]);
	printf("%.2f",sum);
	
	return 0;
} 
