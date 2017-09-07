#include<cstdio>
#include<algorithm>
using namespace std;
int N,n1[110],n2[110],result[110];
void insert(int i){
	int temp=n1[i],j=i;
	while(j>1&&temp<n1[j-1]){
		n1[j]=n1[j-1];
		j--;
	}
	n1[j]=temp;
}
bool insertsort(){
	int flag;
	for(int i=2;i<=N;i++){
		flag=1;
		insert(i);
		for(int j=1;j<=N;j++)
			if(n1[j]!=result[j]){
				flag=0;
				break;
			}
		if(flag){
			printf("Insertion Sort\n");
			insert(i+1);
			for(i=1;i<=N;i++){
				if(i!=1) printf(" ");
				printf("%d",n1[i]);
			}
			return true;
		}
	}
	return false;
}
void downadjust(int low,int high){
	int i=low,j=i*2;
	while(j<=high){
		if(j+1<=high&&n2[j+1]>n2[j]){
			j=j+1;
		}
		if(n2[j]>n2[i]){
			swap(n2[j],n2[i]);
			i=j;
			j=i*2;
		}
		else break;
	}
}
void createheap(){
	for(int i=N/2;i>=1;i--){
		downadjust(i,N);
	}
}
void heapsort(){
	createheap();
	int flag,i,j;
	for(i=N;i>1;i--){
		flag=1;
		swap(n2[1],n2[i]);
		downadjust(1,i-1);
		for(j=1;j<=N;j++){
			if(n2[j]!=result[j]){
				flag=0;
				break;
			}
		}
		if(flag){
			printf("Heap Sort\n");
			swap(n2[1],n2[i-1]);
			downadjust(1,i-2);
			for(i=1;i<=N;i++){
				if(i!=1) printf(" ");
				printf("%d",n2[i]);
			}
			return;
		}
	}
}
int main(){
	int i;
	bool flag;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&n1[i]);
		n2[i]=n1[i];
	}
	for(i=1;i<=N;i++){
		scanf("%d",&result[i]);
	}
	flag=insertsort();
	if(flag) return 0;
	else{
		heapsort();
		return 0;
	}
} 
