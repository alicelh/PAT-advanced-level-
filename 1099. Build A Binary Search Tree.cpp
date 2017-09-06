#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std; 
struct Node{
	int data;
	int left;
	int right;
}node[110];
int N,n[110],num=0;

void inorder(int i){
	if(i==-1) return;
	inorder(node[i].left);
	node[i].data=n[num++];
	inorder(node[i].right);
}
void levelorder(){
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int top=q.front();
		q.pop();
		if(top!=0) printf(" ");
		printf("%d",node[top].data);
		if(node[top].left!=-1) q.push(node[top].left);
		if(node[top].right!=-1) q.push(node[top].right); 
	} 
}
int main(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d %d",&node[i].left,&node[i].right);
	}	
	for(i=0;i<N;i++)
		scanf("%d",&n[i]);
	sort(n,n+N);
	inorder(0);
	levelorder(); 
	return 0;
} 
