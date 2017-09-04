#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
struct node{
	int data;
	node* lchild;
	node* rchild;
};

int N,num,pre[35],in[35];
node* createtree(int preL,int preR,int inL,int inR){
	if(preR<preL) return NULL;
	node* root=new node;
	root->data=pre[preL];
	int i;
	for(i=inL;i<inR;i++){
		if(pre[preL]==in[i]){
			break;
		}
	}
	int numleft=i-inL;
	root->lchild=createtree(preL+1,preL+numleft,inL,i-1);
	root->rchild=createtree(preL+numleft+1,preR,i+1,inR);
	return root;
}

void posttra(node* root){
	if(root==NULL) return;
	posttra(root->lchild);
	posttra(root->rchild);
	printf("%d",root->data);
	num++;
	if(num!=N) printf(" ");
}

int main(){
	int i,number,j=0,k=0;
	stack<int> a;
	char act[5];
	scanf("%d",&N);
	for(i=0;i<N*2;i++){
		scanf("%s",&act);
		if(strcmp(act,"Push")==0){
			scanf("%d",&number);
			pre[j++]=number;
			a.push(number);
		}
		else{
			in[k++]=a.top();
			a.pop();
		}
	}
	node* root=createtree(0,N-1,0,N-1);
	num=0;
	posttra(root);
	return 0;
} 
