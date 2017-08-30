#include<cstdio>
#include<queue>
#include<cmath>

using namespace std;

int main(){
	int N,num=0,i,j,k,tmp,n[20];
	queue<int> q;
	scanf("%d",&N);
	tmp=N;
	for(i=2;i<=sqrt(1.0*N)+1;i++){
		if(tmp%i==0){
			q.push(i);
			tmp=tmp/i;
		}
		else{
			if(q.size()>num){
				num=q.size();
				i=q.front();
				for(j=0;j<num;j++){
					n[j]=q.front();
					q.pop();
				}
			}
			else{
				k=q.size();
				for(j=0;j<k;j++) q.pop();
			}
			tmp=N;
		}
	}
	if(num==0){
		printf("1\n");
		printf("%d",N);
	}
	else{
		printf("%d\n",num);
		for(i=0;i<num;i++){
			printf("%d",n[i]);
			if(i!=num-1) printf("*");
		}
	}
	
	return 0;
}
