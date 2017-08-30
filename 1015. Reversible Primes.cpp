#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
int radix(int N,int D){
	int result[32],rev=0;
	int n,i=1,num=0,j=0;
	while(N>=i){
		i*=D;	
		num++;
	}
	i/=D;
	n=num;
	while(n--){
		result[j++]=N/i;
		N=N-result[j-1]*i;
		i/=D;
	}
	reverse(result,result+j);
	for(i=0;i<num;i++){
		rev+=result[i]*pow(D,num-i-1);
	}
	return rev;
}

int isprime(int a){
	if(a==0||a==1) return 0;
	for(int i=2;i<=sqrt(a*1.0);i++){
		if(a%i==0) return 0;
	}
	return 1;
} 

int main(){
	int N,D;
	int i,n;
	scanf("%d",&N);
	while(N>=0){
		scanf("%d",&D);
		n=radix(N,D);
		if(isprime(N)&&isprime(n)) printf("Yes\n");
		else printf("No\n");
		scanf("%d",&N);
	}
	return 0;
} 
