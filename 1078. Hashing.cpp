#include<cstdio>
#include<cmath>

bool hash[11000]={0};
int s[10000],M,N;
bool IsPrime(int a){
	if(a==0||a==1) return false;
	for(int i=2;i<=sqrt(1.0*a);i++){
		if(a%i==0) return false;
	}
	return true;
}

int findPrime(int a){
	if(IsPrime(a)) return a;
	else{
		while(!IsPrime(a)){
			a++;
		}
		return a;
	}
}

int hashpro(int a){
	int p;
	int tmp=a%M;
	for(int i=0;i<=(M-1)/2;i++){//¶þ´ÎÌ½²é 
		p=(tmp+i*i)%M;
		if(!hash[p]) break;
	}
	if(!hash[p]){
		hash[p]=1;
		return p;
	}
	else return -1;
	
}
int main(){
	int i,tmp;
	scanf("%d %d",&M,&N);
	M=findPrime(M);
	for(i=0;i<N;i++)
		scanf("%d",&s[i]);
	for(i=0;i<N;i++){
		tmp=hashpro(s[i]);
		if(tmp==-1) printf("-");
		else printf("%d",tmp);
		if(i!=N-1) printf(" "); 
	}
	return 0;
}
