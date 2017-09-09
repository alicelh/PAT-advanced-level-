#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int Cmax,N,Sp,M;
int v[510][510],bikes[510],d[510],visited[510]={0};
const int Inf=1000000000;
vector<int> path,tmp_path;
vector<int> pre[510];
void dijkstra(){
	int i,j;
	fill(d,d+N+1,Inf);
	d[0]=0;
	for(i=0;i<=N;i++){
		int u=-1,min=Inf;
		for(j=0;j<=N;j++){
			if(!visited[j]&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		visited[u]=1;
		for(j=0;j<=N;j++){
			if(!visited[j]&&v[u][j]!=Inf){
				if(d[u]+v[u][j]<d[j]){
					d[j]=d[u]+v[u][j];
					pre[j].clear();
					pre[j].push_back(u);
				}
				else if(d[u]+v[u][j]==d[j]){
					pre[j].push_back(u);
				}
			}
		}
	}
}

void DFS(int start,int des,int &need,int& back){
	if(start==des){
		int w=0,tmp_need=0,tmp_back=0;
		for(int i=tmp_path.size()-1;i>=0;i--){//注意对need和back的处理，以及路上的自行车要随时处理 
			w+=bikes[tmp_path[i]]-Cmax/2;
			if(w<0){
				tmp_need+=-w;
				w=0;
			}
		}
		if(w>0) tmp_back=w;
		if(tmp_need<need||(tmp_need==need&&tmp_back<back)){
			path=tmp_path;
			need=tmp_need;
			back=tmp_back;
		}
		return;
	} 
	tmp_path.push_back(des);
	for(int i=0;i<pre[des].size();i++){
		DFS(start,pre[des][i],need,back);
	}
	tmp_path.pop_back();
}
int main(){
	int i,j,a,b,weight;
	scanf("%d %d %d %d",&Cmax,&N,&Sp,&M);
	fill(v[0],v[0]+510*510,Inf);
	for(i=1;i<=N;i++){
		scanf("%d",&bikes[i]);
	}
	for(i=0;i<M;i++){
		scanf("%d %d %d",&a,&b,&weight);
		v[a][b]=v[b][a]=weight;
	}
	dijkstra();
	int need=Inf; 
	int back=Inf;
	DFS(0,Sp,need,back);
	printf("%d ",need);
	printf("0->"); 
	for(i=path.size()-1;i>=0;i--){
		printf("%d",path[i]);
		if(i!=0) printf("->");
	}
	printf(" %d",back);
	return 0;
}
