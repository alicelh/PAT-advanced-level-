#include<cstdio>
#include<algorithm>

using namespace std;

int N;
long long p,n[100000];

int main(){
	int i,j,tmp,tmpj=0,max=0;
	scanf("%d %lld",&N,&p);
	for(i=0;i<N;i++)
		scanf("%lld",&n[i]);
	sort(n,n+N);

	for(i=0;i<N/2+1;i++){
		for(j=tmpj;j<N;j++){//每次都从上一个结束的下个取，因为要取max所以j一定要更大才有可能，避免运行超时 
			if(n[j]<=n[i]*p){
				tmp=j-i+1;
				if(tmp>max){
					max=tmp;
				} 
			}
			else break;
		}
		tmpj=j;
	}
	printf("%d",max);
	return 0;
} 
