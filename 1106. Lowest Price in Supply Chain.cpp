#include<cstdio>
#include<queue>
#define maxN ((1<<31)-1)
using namespace std;

int N,total;
double P,r,minprice=maxN;
struct Node{
	double price;
	vector<int> child;
}node[100010];

void BFS(){
	queue<int> q;
	q.push(0);
	node[0].price=P; 
	if(node[0].child.empty()&&node[0].price<minprice){
		minprice=node[0].price;
		total=1;
	}
	while(!q.empty()){
		Node top=node[q.front()];
		q.pop();
		for(int i=0;i<top.child.size();i++){
			q.push(top.child[i]);
			node[top.child[i]].price=top.price*(1.0+r*0.01);
			if(node[top.child[i]].child.empty()&&node[top.child[i]].price<minprice){
				minprice=node[top.child[i]].price;
				total=1;
			}
			else if(node[top.child[i]].child.empty()&&node[top.child[i]].price==minprice){
				total++;
			}
		}
	}
}

int main(){
	int i,j,num,child;
	scanf("%d %lf %lf",&N,&P,&r);
	for(i=0;i<N;i++){
		scanf("%d",&num);
		for(j=0;j<num;j++){
			scanf("%d",&child);
			node[i].child.push_back(child);
		}
	}
	BFS();
	printf("%.4f %d",minprice,total);
	return 0;
}
