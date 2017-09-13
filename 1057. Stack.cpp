#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n[100010],table[100010]={0},block[317]={0};
int main(){
	int N,num=0,key,i,j,index,sum;
	char op[15];
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s",op);
		if(strcmp(op,"Push")==0){
			scanf("%d",&key);
			n[++num]=key;
			table[key]++;
			block[key/317]++;
		}
		else if(strcmp(op,"Pop")==0){
			if(num==0) printf("Invalid\n");
			else{
				printf("%d\n",n[num]);
				table[n[num]]--;
				block[n[num]/317]--;
				num--;
			} 
		}
		else{
			if(num==0) printf("Invalid\n");
			else{
				if(num%2==0) index=num/2;
				else index=(num+1)/2;
				sum=0;
				j=0;
				while(index>sum){
					sum+=block[j++]; 
				}
				sum-=block[--j];
				j=j*317;
				while(index>sum){
					if(table[j]!=0) sum+=table[j];
					j++;
				}
				printf("%d\n",j-1);
			}
		}
	}
	return 0;
} 
