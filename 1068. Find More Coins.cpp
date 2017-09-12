#include<cstdio>
#include<algorithm>
using namespace std;
int N,M,coin[10010],dp[110]={0};
int result[10010][110]={0},flag[10010]={0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int i,j;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++){
		scanf("%d",&coin[i]);
	}
	sort(coin,coin+N,cmp);
	for(i=0;i<N;i++){
		for(j=M;j>=coin[i];j--){
			if(dp[j-coin[i]]+coin[i]>=dp[j]){
				dp[j]=dp[j-coin[i]]+coin[i];
				result[i][j]=1; 
			}
		}
	}
	if(dp[M]!=M){
		printf("No Solution");
		return 0;
	}
	i=N;
	j=M;
	int num=0;
	while(j){
		if(result[i][j]){
			flag[i]=1;
			j=j-coin[i];
			num++;
		}
		i--;
	}  
	
	for(i=N;i>=0;i--){
		if(flag[i]==1){
			printf("%d",coin[i]);
			num--;
			if(num>0) printf(" ");
		}
	}
	return 0;
} 
