#include<cstdio>
#include<algorithm>
using namespace std;
double n[10010];
int main(){
	int N;
	int i,j;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%lf",&n[i]);
	}
	sort(n,n+N);
	i=0;
	while(i<N-1){
		n[i+1]=(n[i]+n[i+1])/2;
		i=i+1;
	}
	printf("%d",(int)n[N-1]);
	return 0;
}
