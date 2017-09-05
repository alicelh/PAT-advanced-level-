#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
int N,root;
double P,r;
struct Node{
	double price;
	vector<int> child;
}node[100010];
void BFS(){
	queue<int> q;
	q.push(root);
	node[root].price=P;
	while(!q.empty()){
		Node top=node[q.front()];
		q.pop();
		for(int i=0;i<top.child.size();i++){
			q.push(top.child[i]);
			node[top.child[i]].price=top.price*(1.0+r*0.01);
		}
	} 
}
int main(){
	int i,j,father,num=0;
	double maxprice;
	scanf("%d %lf %lf",&N,&P,&r);
	for(i=0;i<N;i++){
		scanf("%d",&father);
		if(father==-1) root=i;
		else node[father].child.push_back(i);
	}
	BFS();
	maxprice=P; 
	for(i=0;i<N;i++){
		if(node[i].price>maxprice){
			maxprice=node[i].price; 
			num=1;
		}
		else if(node[i].price==maxprice){
			num++;
		}
	}
	printf("%.2f %d",maxprice,num);
	return 0;
}
