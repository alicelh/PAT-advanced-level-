#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue> 

/*遇到排序题，可以先考虑是否可以做提前处理保证有序性，这道题要输出按权值从大到小排序，
可以一开始就将每个节点的孩子按权值排序，这样可以保证最后顺序，不过做的时候没有想到，所以
又排了一次序*/

using namespace std;
int N,M,weight,num;
struct Node{
	int w;
	int pathw;
	int level;
	int father;
	vector<int> child;
}node[110];
int result[110];
struct Path{
	int w[110];
	int len;
}path[110];
bool cmp(Path a,Path b){
	for(int i=0;i<a.len&&i<b.len;i++){
		if(a.w[i]!=b.w[i]) return a.w[i]>b.w[i];
		else continue;
	}
}
void BFS(){
	queue<int> q;
	q.push(0);
	node[0].level=1;
	node[0].pathw=node[0].w;
	node[0].father=-1;
	if(node[0].child.empty()){
		result[0]=0;
		num++;
		return;
	}
	while(!q.empty()){
		int top=q.front();
		q.pop();
		for(int i=0;i<node[top].child.size();i++){
			q.push(node[top].child[i]);
			node[node[top].child[i]].level=node[top].level+1;\
			node[node[top].child[i]].father=top;
			node[node[top].child[i]].pathw=node[top].pathw+node[node[top].child[i]].w;
			if(node[node[top].child[i]].child.empty()&&node[node[top].child[i]].pathw==weight){
				result[num++]=node[top].child[i];
			}
		}
	}
}
int main(){
	int i,j,index,childnum,child,tmp;
	scanf("%d %d %d",&N,&M,&weight);
	for(i=0;i<N;i++){
		scanf("%d",&node[i].w);
	}
	for(i=0;i<M;i++){
		scanf("%d %d",&index,&childnum);
		for(j=0;j<childnum;j++){
			scanf("%d",&child);
			node[index].child.push_back(child);
		}
	}
	BFS();
	for(i=0;i<num;i++){
		tmp=result[i];
		for(j=0;j<node[result[i]].level;j++){
			path[i].w[j]=node[tmp].w;
			tmp=node[tmp].father;
		}
		path[i].len=j;
		reverse(path[i].w,path[i].w+j);
	}
	sort(path,path+num,cmp);
	for(i=0;i<num;i++){
		for(j=0;j<path[i].len;j++){
			if(j!=0) printf(" ");
			printf("%d",path[i].w[j]);
		}
		printf("\n");
	}
	return 0;
} 
