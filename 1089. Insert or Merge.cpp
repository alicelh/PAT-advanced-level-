#include<cstdio>
#include<algorithm>

using namespace std;
/*要自己实现插入排序和归并排序*/

int N,n1[110],n2[110],n0[110];

bool verify(){
	for(int i=0;i<N;i++){
		if(n1[i]!=n2[i]){
			return false;
		}
	}
	return true;
}

bool verify2(){
	for(int i=0;i<N;i++){
		if(n0[i]!=n2[i]){
			return false;
		}
	}
	return true;
}

int main(){
	int i,j,tmp,mid,flag=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&n1[i]);
		n0[i]=n1[i];
	} 
	for(i=0;i<N;i++){
		scanf("%d",&n2[i]);
	} 
	for(i=1;i<N;i++){
		tmp=n1[i];
		j=i;
		while(j>0&&tmp<n1[j-1]){
			n1[j]=n1[j-1];
			j--;
		} 
		n1[j]=tmp;
		if(flag){
			printf("Insertion Sort\n");
			for(i=0;i<N-1;i++) printf("%d ",n1[i]);
			printf("%d",n1[i]);
			return 0;
		}
		if(verify()) flag=1;
	}
	i=2;
	flag=0;
	while(i/2<=N){
		for(j=0;j<N;j+=i){
			sort(n0+j,n0+min(j+i,N));
		}
		if(flag){
			printf("Merge Sort\n");
			for(i=0;i<N-1;i++) printf("%d ",n0[i]);
			printf("%d",n0[i]);
			break;
		}
		if(verify2()) flag=1;
		i*=2;
	}
	return 0;
} 
