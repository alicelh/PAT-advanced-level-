#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int i,N,M,d[100010],sum[100010]={0};//注意要取比100000大的数 
	int tmp,nears=10000100;
	scanf("%d %d",&N,&M);
	for(i=1;i<=N;i++){
		scanf("%d",&d[i]);
		sum[i]=sum[i-1]+d[i];
	}
	for(i=1;i<=N;i++){                  
		tmp=lower_bound(sum+i,sum+N+1,sum[i-1]+M)-sum;
		if(sum[tmp]-sum[i-1]==M){
			nears=M;
			break;
		}
		else if(tmp<=N&&sum[tmp]-sum[i-1]<nears){
			nears=sum[tmp]-sum[i-1];
		}
	}
	for(i=1;i<=N;i++){
		tmp=lower_bound(sum+i,sum+N+1,sum[i-1]+nears)-sum;
		if(tmp<=N&&sum[tmp]-sum[i-1]==nears){
			printf("%d-%d\n",i,tmp);
		}
	}
	return 0;
} 
