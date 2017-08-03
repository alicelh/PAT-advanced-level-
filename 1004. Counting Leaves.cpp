#include<iostream>
#include<algorithm>
#define maxN 100

using namespace std;

typedef struct node{//only save the non-leaf node
	int id;
	int childnum;
	int child[maxN];
}treenode;

treenode nodelist[maxN];
int num[maxN];
int N,M;//N-the number of nodes in a tree, M (< N)-the number of non-leaf nodes
int level=0;//������㼶 
int height=0;

void countleaf(int id){
	int i,j,flag,nodeid;
	level++; 
	for(i=0;i<M;i++){
		if(nodelist[i].id==id)
			nodeid=i;
	}
	for(i=0;i<nodelist[nodeid].childnum;i++){
		flag=1;//��ǽڵ��Ƿ�ΪҶ�ڵ� 
		for(j=0;j<M;j++){
			if(nodelist[nodeid].child[i]==nodelist[j].id){//�˺��ӽڵ��Ҷ�ڵ� 
				countleaf(nodelist[nodeid].child[i]);
				flag=0;//�ҵ�˵������Ҷ�ڵ� 
			}			
		}
		if(flag){
			num[level]++;
		} 
	}
	if(level>height) height=level;
	level--;
}

int main(){
	int i,j,root;
	
	cin>>N>>M;	
	if(M==0){
		cout<<1;
		return 0;
	}
	for(i=0;i<M;i++){
		cin>>nodelist[i].id>>nodelist[i].childnum;
		for(j=0;j<nodelist[i].childnum;j++)
			cin>>nodelist[i].child[j];
	}

	fill(num,num+maxN,0);
	countleaf(1);
	
	for(i=0;i<height;i++)
		cout<<num[i]<<" ";
	cout<<num[height];
	
	return 0;
} 
