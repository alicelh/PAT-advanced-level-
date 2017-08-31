#include<cstdio>
#include<cmath>
#define maxN 10000

struct pri{
	int pm;
	int km;
}factor[10];

int p[100000];
int num=0;
bool isprime(int a){
	int n=(int)sqrt(1.0*a);
	for(int i=2;i<=n;i++){
		if(a%i==0) return false;
	}
	return true;
}

void findprime(){
	for(int i=2;i<maxN;i++){
		if(isprime(i)) p[num++]=i;
	}
}

int main(){
	int N,i,tmp;
	int k=0;
	scanf("%d",&N);
	tmp=N;
	if(N==1){
		printf("1=1");
		return 0;
	}
	findprime(); 
	for(i=0;i<num;i++){
		if(N%p[i]==0){
			while(1){
				factor[k].pm=p[i];
				factor[k].km++;
				N=N/p[i];
				if(N%p[i]!=0) break;
			}
			k++;
		}
		if(p[i]>N) break;
	}
	if(N>1){
		factor[k].pm=N;
		factor[k].km=1;
		k++;
	}
	printf("%d=",tmp);
	for(int i=0;i<k;i++){
		printf("%d",factor[i].pm);
		if(factor[i].km>1){
			printf("^%d",factor[i].km);
		}
		if(i!=k-1) printf("*");
	}
	return 0;
}
