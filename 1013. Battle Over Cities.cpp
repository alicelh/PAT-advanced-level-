#include<cstdio>
const int maxN=1000;
int v[maxN][maxN]={0};
int N,M,K,n[1000];
bool isvisited[1000]={0};

void DFS(int start,int city){
	isvisited[start]=true;
	for(int i=1;i<=N;i++){
		if(i!=city&&isvisited[i]==false&&v[start][i]){
			DFS(i,city);
		}
	}
}
void searchroad(int &num,int city){
	for(int i=1;i<=N;i++){
		if(i!=city&&isvisited[i]==false){
			DFS(i,city);
			num++;
		}
	}
}

int main(){
	int i,j,a,b,city,num=0;
	scanf("%d %d %d",&N,&M,&K);
	for(i=0;i<M;i++){
		scanf("%d %d",&a,&b);
		v[a][b]=v[b][a]=1;
	}
	for(i=0;i<K;i++){
		scanf("%d",&city);
		searchroad(num,city);
		printf("%d\n",num-1);
		for(j=1;j<=N;j++)
			isvisited[j]=false;
		num=0;
	}
	return 0;
} 
