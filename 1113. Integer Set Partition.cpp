#include<cstdio>
#include<algorithm>
using namespace std;
int n[100010];
int main(){
	int N,n1,n2;
	int i,j,num1=0,num2=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&n[i]);
	}
	if(N%2==0){
		n1=n2=N/2;
	}
	else{
		n2=N/2;
		n1=N-n2;
	}
	sort(n,n+N);
	for(i=N-1;i>=0;i--){
		if(N-i<=n1){
			num1+=n[i]; 
			
		}
		else num2+=n[i];
	}
	printf("%d ",abs(n1-n2));
	printf("%d",abs(num1-num2));
	return 0;
} 
