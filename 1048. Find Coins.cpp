#include<cstdio>

int c[100000],e[1000]={0};

int main(){
	int N,M;
	int i,j,flag=0;
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++){
		scanf("%d",&c[i]);
		if(e[c[i]]==-1){
			e[c[i]]=M-c[i];
			e[M-c[i]]=c[i];
		}
		if(!e[M-c[i]]) e[M-c[i]]=-1;
	}
	for(i=0;i<1000;i++){
		if(e[i]!=0&&e[i]!=-1){
			printf("%d %d",i,e[i]);
			flag=1;
			break;
		}
	}
	if(!flag) printf("No Solution");
	return 0;
} 
