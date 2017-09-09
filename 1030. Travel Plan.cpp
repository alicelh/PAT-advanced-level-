#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=1000000000;
int N,M,S,D;
int d[510],pre[510],c[510],visited[510]={0};
int v[510][510],cost[510][510];

void dijkstra(int S){
	fill(d,d+N,inf);
	fill(c,c+N,inf);
	d[S]=0;
	pre[S]=S;
	c[S]=0;
	for(int j=0;j<N;j++){
		int u=-1,min=inf;
		for(int i=0;i<N;i++){
			if(!visited[i]&&d[i]<min){
				min=d[i];
				u=i;
			}
		} 
		if(u==-1) return;
		visited[u]=1;
		for(int i=0;i<N;i++){
			if(v[u][i]!=inf&&!visited[i]){
				if(d[u]+v[u][i]<d[i]){
					d[i]=d[u]+v[u][i];
					pre[i]=u;
					c[i]=c[u]+cost[u][i];
				}
				else if(d[u]+v[u][i]==d[i]&&c[u]+cost[u][i]<c[i]){
					pre[i]=u;
					c[i]=c[u]+cost[u][i];
				}
			}
		}
	}
}

void DFS(int S,int D){
	if(D==S){
		printf("%d",S);
		return;
	}
	DFS(S,pre[D]);
	printf(" %d",D);
}

int main(){
	int i,a,b;
	scanf("%d %d %d %d",&N,&M,&S,&D);
	fill(v[0],v[0]+510*510,inf);
	for(i=0;i<M;i++){
		scanf("%d %d",&a,&b);
		scanf("%d %d",&v[a][b],&cost[a][b]);
		v[b][a]=v[a][b];
		cost[b][a]=cost[a][b];
	}
	dijkstra(S);
	DFS(S,D);
	printf(" %d %d",d[D],c[D]);
	return 0;
} 
