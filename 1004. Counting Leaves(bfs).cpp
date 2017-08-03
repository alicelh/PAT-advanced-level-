#include<iostream>
#include<vector>
#include<queue> 
#define maxN 100

using namespace std;

vector<int> G[maxN];
int N,M;
int h[maxN];//每个结点所在的高度 
int num[maxN]={0};//每层所含叶节点数 
int max_h=1;

void bfs(){
	int id,i;
	queue<int> Q;//利用队列对每一层进行遍历实现广度优先搜索 
	Q.push(1);
	while(!Q.empty()){
		id=Q.front();
		Q.pop();
		max_h=max(max_h,h[id]);
		if(!G[id].size()){
			num[h[id]]++; 
		}
		for(i=0;i<G[id].size();i++){
			Q.push(G[id][i]);
			h[G[id][i]]=h[id]+1;
		}
	}
}

int main(){
	int i,j,id,k,child;
	cin>>N>>M;
	for(i=0;i<M;i++){
		cin>>id>>k;
		for(j=0;j<k;j++){
			cin>>child;
			G[id].push_back(child);
		}
	}
	
	h[1]=1;
	bfs();
	
	for(i=0;i<max_h-1;i++)
		cout<<num[i+1]<<" ";
	cout<<num[max_h];
	
	return 0;
}
