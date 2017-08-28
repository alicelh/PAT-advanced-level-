#include<cstdio>

int n[100000],r[100000]={0},res[100000];

int main(){
	int i,N,num=0;
	int maxx=0,minx=1000000001;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&n[i]);
	for(i=N-1;i>=0;i--){
		if(n[i]<minx) minx=n[i];
		if(n[i]>minx) r[i]=1;
	}
	for(i=0;i<N;i++){
		if(n[i]>maxx){
			maxx=n[i];
			if(!r[i]){
				res[num++]=n[i];
			}
		}
	}
	printf("%d\n",num);
	if(num==0) printf("\n");//第二行一定要存在的！ 
	for(i=0;i<num;i++){
		if(i!=0) printf(" ");
		printf("%d",res[i]);
	}
	return 0;
} 
