#include<cstdio>
#include<cstring>

using namespace std;

int s[20000000];

int main(){
	int M,N,i,max=0,top;
	scanf("%d %d",&M,&N);
	int a;
	memset(s,0,sizeof(int));
	for(i=0;i<M*N;i++){
		scanf("%d",&a);
		s[a]++;
		if(s[a]>max){
			max=s[a];
			top=a;
		}
	}
	printf("%d",top);
	return 0;
}
