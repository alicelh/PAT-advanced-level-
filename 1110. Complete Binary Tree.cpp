#include<cstdio>
#include<queue>
using namespace std;
struct Node{
	int left,right;
}node[25];
int n[25],show[25]={0};

void BFS(int root,int &po){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(top==-1) return;
		n[po++]=top;
		q.push(node[top].left);
		q.push(node[top].right);
	}
}
int main(){
	int N,tmp,root,i,po=0;
	char a[5],b[5];
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s %s",a,b);
		if(a[0]=='-'){
			node[i].left=-1;
		}
		else{
			sscanf(a,"%d",&tmp);
			node[i].left=tmp;
			show[tmp]=1;
		}
		if(b[0]=='-'){
			node[i].right=-1;
		}
		else{
			sscanf(b,"%d",&tmp);
			node[i].right=tmp;
			show[tmp]=1;
		}
	}
	for(i=0;i<N;i++){
		if(!show[i]){
			root=i;
			break;
		}
	}
	BFS(root,po);
	if(po==N){
		printf("YES %d",n[po-1]);
	}
	else printf("NO %d",root);
	return 0;
}
