#include<cstdio>

using namespace std;

int Increasing(int a[]){
	int i,j,tmp,sum=0;
	for(i=0;i<3;i++)
		for(j=0;j<3-i;j++){
			if(a[j]>a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
		
	for(i=0;i<4;i++)
		sum=sum*10+a[i];
	
	return sum;
}

int Decreasing(int a[]){
	int i,j,tmp,sum=0;
	for(i=0;i<3;i++)
		for(j=0;j<3-i;j++){
			if(a[j]<a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
		
	for(i=0;i<4;i++)
		sum=sum*10+a[i];
	
	return sum;
}

int main(){
	int i,flag=0;
	int n,N,inc,dec,res=0;
	int a[4];
	scanf("%d",&N);
	n=N;
	for(i=0;i<4;i++){
		a[i]=N%10;
		N=N/10;
	}
	
	for(i=0;i<3;i++)
		if(a[i]!=a[i+1])
			flag=1;
	
	if(!flag){
		printf("%04d - %04d = 0000\n",n,n);
		return 0;
	}	
	
	while(res!=6174){
		inc=Increasing(a);
		dec=Decreasing(a);
		res=dec-inc;
		for(i=0;i<4;i++){
			a[i]=res%10;
			res=res/10;
		}
		res=dec-inc;
		printf("%04d - %04d = %04d\n",dec,inc,res);
	}

	return 0;
} 
