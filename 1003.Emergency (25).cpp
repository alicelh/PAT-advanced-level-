#include<iostream>
#define maxN 510
#define INF 1000000000
using namespace std;
int weight[maxN],num[maxN];
int dmatrix[maxN][maxN];
int team[maxN];
int known[maxN],d[maxN];
void dijkstra(int N,int C1,int C2){
	int i,j,k,u,min;
	for(i=0;i<N;i++){
		known[i]=0;
		d[i]=INF;
		weight[i]=0;//沿途达到的救援队数量 
		num[i]=0;//最短路径条数 
	}
	d[C1]=0;
	weight[C1]=team[C1];
	num[C1]=1;
	for(i=0;i<N;i++){
			min=INF;
			u=-1; 
			for(j=0;j<N;j++)
				if(!known[j]&&d[j]<min){
					min=d[j];
					u=j;
				}
			if(u==-1&&u==C2) return;//u=-1说明找不到小于INF的d[u],说明剩下的顶点和起点不连通 
			known[u]=1;
			for(k=0;k<N;k++)
				if(!known[k]&&dmatrix[u][k]!=INF){
					if(d[u]+dmatrix[u][k]<d[k]){
						d[k]=d[u]+dmatrix[u][k];
						weight[k]=weight[u]+team[k];
						num[k]=num[u];
					}
					else if(d[u]+dmatrix[u][k]==d[k]){
						if(weight[u]+team[k]>weight[k])
							weight[k]=weight[u]+team[k];
						num[k]+=num[u];
					}						
				}		
	}
	
	return;
}

int main(){
	int N,M,C1,C2;
	int i,j,k,l;
	
	cin>>N>>M>>C1>>C2;
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			dmatrix[i][j]=INF;
	for(i=0;i<N;i++)
		cin>>team[i];
	for(i=0;i<M;i++){
		cin>>j>>k>>l;
		dmatrix[j][k]=l;
		dmatrix[k][j]=l;
	}
	
	dijkstra(N,C1,C2);
	cout<<num[C2]<<' '<<weight[C2];
	
	return 0;
} 
