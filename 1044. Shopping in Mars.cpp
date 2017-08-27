#include<cstdio>

int N,M;
int d[100010]={0},r[100010]={0};

int main(){
	int i,left=1,right=1,sum=0,min;
	scanf("%d %d",&N,&M);
	for(i=1;i<=N;i++){
		scanf("%d",&d[i]);
	}
	sum+=d[left];
	min=1000;
	while(left<=N&&right<=N){
		if(sum-M>=0&&sum-M<min){
			min=sum-M;
		}
		if(sum==M){
			r[right]=left;
			right+=1; 
			sum+=d[right];
		}
		else if(sum>M){
			sum-=d[left];
			left+=1;
		}
		else{
			right+=1;
			sum+=d[right];
		}
	}
	if(min==0){
		for(i=0;i<=N;i++){
			if(r[i]!=0){
				printf("%d-%d\n",r[i],i);
			}
		}
		return 0;
	}
	else{
		left=right=1;
		sum=d[left];
		while(left<=N&&right<=N){
			if(sum-M==min){
				printf("%d-%d\n",left,right);
			}
			if(sum>M){
				sum-=d[left];
				left+=1;
			}
			else{
				right+=1;
				sum+=d[right];
			}
			
		}
		return 0;
	}
} 
