#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
int N;
double P,r;
struct Node{
	double price;
	int product;
	vector<int> child;
}node[100010];

void BFS(){
	queue<int> q;
	q.push(0);
	node[0].price=P;
	while(!q.empty()){
		int top=q.front();
		q.pop();
		for(int i=0;i<node[top].child.size();i++){
			q.push(node[top].child[i]);
			node[node[top].child[i]].price=node[top].price*(1.0+r*0.01);
		}
	}
}
int main(){
	int i,j,n,child;
	double total;
	scanf("%d %lf %lf",&N,&P,&r);
	for(i=0;i<N;i++){
		scanf("%d",&n);
		node[i].child.clear();
		node[i].product=0;
		if(n==0){
			scanf("%d",&node[i].product);
		}
		for(j=0;j<n;j++){
			scanf("%d",&child);
			node[i].child.push_back(child); 
		}
	}
	BFS();
	for(i=0;i<N;i++){
		total+=node[i].price*node[i].product;
	} 
	printf("%.1f",total);
	return 0;
} 
