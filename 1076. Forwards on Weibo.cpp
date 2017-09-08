#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
/*对于一层一层算的最好用BFS*/
int N,L,v[1010][1010]={0};
int visited[1010]={0};
int layer[1010]={0};

void BFS(int start,int &num){
	queue<int> q;
	q.push(start);
	layer[start]=0;
	visited[start]=1;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(layer[top]>=L) continue;
		for(int i=1;i<=N;i++){
			if(v[top][i]&&!visited[i]){
				q.push(i);
				visited[i]=1;
				num++;
				layer[i]=layer[top]+1;
			}
		}
	}
}
int main(){
	int i,j,n,tmp,K,num;
	scanf("%d %d",&N,&L);
	for(i=1;i<=N;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&tmp);
			v[tmp][i]=1;
		}
	}
	scanf("%d",&K);
	while(K--){
		num=0;
		scanf("%d",&tmp);
		BFS(tmp,num);
		fill(visited,visited+N+1,0);
		printf("%d\n",num);
	}
	return 0;
}
