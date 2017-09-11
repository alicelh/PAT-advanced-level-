#include<cstdio>

int fav[210]={0};//¸øÏ²»¶ÅÅÃû 
int str[10010],pd[10010];
int main(){
	int N,M,L,max;
	int i,j,tmp;
	scanf("%d",&N);
	scanf("%d",&M);
	for(i=1;i<=M;i++){
		scanf("%d",&tmp);
		fav[tmp]=i;
	}
	scanf("%d",&L);
	for(i=0;i<L;i++){
		scanf("%d",&str[i]); 
	}
	for(i=0;i<L;i++){
		if(!fav[str[i]]) pd[i]=0;
		else{
			pd[i]=1;
			for(j=0;j<i;j++){
				if(fav[str[i]]>=fav[str[j]]&&pd[j]+1>pd[i]){
					pd[i]=pd[j]+1;
				}
			}
		}
	}
	max=0;
	for(i=0;i<L;i++){
		if(pd[i]>max){
			max=pd[i];
		} 
	}
	printf("%d",max);
	return 0;
} 
