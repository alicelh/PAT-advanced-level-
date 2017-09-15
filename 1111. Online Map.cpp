#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxN=510;
const int Inf=1000000000;
int vt[maxN][maxN],vl[maxN][maxN];
int N,M,source,des;
int d[maxN],visited[maxN];
vector<int> pre[maxN];
vector<int> pathd,tmp_path,patht;
void dijkstra(int s,int v[][maxN]){
	int mind,u;
	fill(d,d+maxN,Inf);
	fill(visited,visited+maxN,0);
	d[s]=0;
	for(int i=0;i<N;i++){
		mind=Inf;
		u=-1;
		for(int j=0;j<N;j++){
			if(!visited[j]&&d[j]<mind){
				mind=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		visited[u]=1;
		for(int j=0;j<N;j++){
			if(v[u][j]!=Inf&&!visited[j]){
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
void DFS_length(int s,int d,int &minsum){
	if(s==d){
		tmp_path.push_back(d);
		int dis=0;
		for(int j=tmp_path.size()-1;j>0;j--){
			dis+=vt[tmp_path[j]][tmp_path[j-1]];
		}
		if(dis<minsum){
			minsum=dis;
			pathd=tmp_path;
		}
		tmp_path.pop_back();
		return;
	}
	tmp_path.push_back(d);
	for(int i=0;i<pre[d].size();i++){
		DFS_length(s,pre[d][i],minsum);
	}
	tmp_path.pop_back();
}
void DFS_time(int s,int d,int &minsum){
	if(s==d){
		tmp_path.push_back(d);
		int dis=tmp_path.size();
		if(dis<minsum){
			minsum=dis;
			patht=tmp_path;
		}
		tmp_path.pop_back();//¼ÇµÃpop 
		return;
	}
	tmp_path.push_back(d);
	for(int i=0;i<pre[d].size();i++){
		DFS_time(s,pre[d][i],minsum);
	}
	tmp_path.pop_back();
}
bool equalpath(){
	if(patht.size()!=pathd.size()) return false;
	for(int i=0;i<patht.size();i++){
		if(patht[i]!=pathd[i]) return false;
	}
	return true;
}
void printtime(){
	for(int i=patht.size()-1;i>=0;i--){
		printf("%d",patht[i]);
		if(i!=0) printf(" -> ");
	}
}
void printlength(){
	for(int i=pathd.size()-1;i>=0;i--){
		printf("%d",pathd[i]);
		if(i!=0) printf(" -> ");
	}
}
int main(){
	int i,j,a,b,one_way,length,time;
	int mindis,mintime,minsum=Inf;
	scanf("%d %d",&N,&M);
	fill(vt[0],vt[0]+maxN*maxN,Inf);
	fill(vl[0],vl[0]+maxN*maxN,Inf);
	for(i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		scanf("%d%d%d",&one_way,&length,&time);
		vt[a][b]=time;
		vl[a][b]=length;
		if(!one_way){
			vt[b][a]=time;
			vl[b][a]=length;
		}
	}
	scanf("%d%d",&source,&des);
	dijkstra(source,vl);
	mindis=d[des];
	DFS_length(source,des,minsum);
	for(i=0;i<N;i++){
		pre[i].clear();
	}
	dijkstra(source,vt);
	mintime=d[des];
	minsum=Inf;
	tmp_path.clear();
	DFS_time(source,des,minsum);
	if(equalpath()){
		printf("Distance = %d; Time = %d: ",mindis,mintime);
		printtime();
	}
	else{
		printf("Distance = %d: ",mindis);
		printlength();
		printf("\n");
		printf("Time = %d: ",mintime);
		printtime();
	}
	return 0;
} 


