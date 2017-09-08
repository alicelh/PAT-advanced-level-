#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N,isVisited[10010]={0},maxdepth,maxd=1;
vector<int> node[10010];
int layer[10010]={0},depth[10010];
bool cmp(int a,int b){
	return a>b;
}
void BFS(int start){
	queue<int> q;
	q.push(start);
	layer[start]=1; 
	depth[start]=maxdepth;
	int tmp;
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		isVisited[tmp]=1;
		for(int i=0;i<node[tmp].size();i++){
			if(!isVisited[node[tmp][i]]){
				q.push(node[tmp][i]);	
				layer[node[tmp][i]]=layer[tmp]+1;
				if(layer[tmp]+1>maxdepth){
					maxdepth=layer[tmp]+1;
				}
			}
		}
	}
}
int graphshow(int start){
	int num=0;
	maxdepth=1;
	for(int i=start;i<=N;i++){
		if(!isVisited[i]){
			BFS(i);
			num++;
		}
	}
	depth[start]=maxdepth;
	if(maxdepth>maxd) maxd=maxdepth;
	return num;
}
int main(){
	int i,a,b,num,flag=0,max;
	scanf("%d",&N);
	for(i=0;i<N-1;i++){
		scanf("%d %d",&a,&b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for(i=1;i<=N;i++){
		num=graphshow(i);
		if(num!=1){
			flag=1;
			break;
		}
		fill(isVisited,isVisited+N+1,0);
		fill(layer,layer+N+1,0);
	}
	
	if(flag){
		printf("Error: %d components",num);
	}
	else{
		for(i=1;i<=N;i++)
			if(depth[i]==maxd)
				printf("%d\n",i);
	}
	return 0;
}
