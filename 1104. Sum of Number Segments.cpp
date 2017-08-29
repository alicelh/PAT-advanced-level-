#include<cstdio>

double n[100000],sum=0,p[100000];

int main(){
	int i,N,j,t;
	scanf("%d",&N);
	p[0]=N;
	for(i=0;i<N;i++){
		scanf("%lf",&n[i]);
		if(i>0) p[i]=p[i-1]-i+N-i;//每个数出现次数 
		sum+=n[i]*p[i];
	}
	
	printf("%.2f",sum);
	return 0;
} 
