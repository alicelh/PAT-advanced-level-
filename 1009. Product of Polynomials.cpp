#include<cstdio>

int main(){
	int i,j,max;
	int K,index;
	double c;
	double a1[1001]={0.0},a2[1001]={0.0},result[2001]={0.0};
	
	scanf("%d",&K);
	for(i=0;i<K;i++){
		scanf("%d%lf",&index,&c);
		a1[index]=c;
	}
	scanf("%d",&K);
	for(i=0;i<K;i++){
		scanf("%d%lf",&index,&c);
		a2[index]=c;
	}
	
	for(i=0;i<1001;i++){
		if(a1[i]!=0){
			for(j=0;j<1001;j++){
				if(a2[j]!=0){
					result[i+j]+=a1[i]*a2[j];
				}
			}
		}
	}
	j=0;
	for(i=0;i<2001;i++){
		if(result[i]!=0){
			j++;
			max=i;
		}			
	}
	
	printf("%d",j);
	for(i=max;i>=0;i--)
		if(result[i]!=0)
			printf(" %d %.1f",i,result[i]);
	
	return 0;
} 
