#include<cstdio>
using namespace std;

int num[100000],shu[10010]={0};

int main(){
	int N,i,j,flag;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&num[i]);
		flag=0;
		if(shu[num[i]]){//是1或-1的情况 
			shu[num[i]]=-1;
			flag=1;
		}
		if(!flag){
			shu[num[i]]=1;
		}
	}
	flag=0;
	for(i=0;i<N;i++){
		if(shu[num[i]]==1){
			printf("%d",num[i]);
			flag=1;
			break;
		}
	}
	if(!flag) printf("None");
	return 0;
}
