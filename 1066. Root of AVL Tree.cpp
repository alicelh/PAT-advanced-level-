#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
	int data,height;
	Node* left;
	Node* right;
}; 
Node* newnode(int v){
	Node* root=new Node;
	root->data=v;
	root->height=1;
	root->left=root->right=NULL;
	return root;
}
int getheight(Node* root){
	if(root==NULL) return 0;
	else return root->height;
}
void updateheight(Node* root){
	root->height=max(getheight(root->left),getheight(root->right))+1;
}
int getbalance(Node* root){
	return getheight(root->left)-getheight(root->right);
}
void L(Node* &root){
	Node* tmp=root->right;
	root->right=tmp->left;
	tmp->left=root;
	updateheight(root);
	updateheight(tmp);
	root=tmp;
}
void R(Node* &root){
	Node* tmp=root->left;
	root->left=tmp->right;
	tmp->right=root;
	updateheight(root);
	updateheight(tmp);
	root=tmp;
} 
void insert(Node* &root,int v){
	if(root==NULL) root=newnode(v);
	else if(v>root->data){
		insert(root->right,v);
		updateheight(root);
		if(getbalance(root)==-2){
			if(getbalance(root->right)==1){
				R(root->right);
				L(root);
			}
			else L(root);
		}
	}
	else{
		insert(root->left,v);
		updateheight(root);
		if(getbalance(root)==2){
			if(getbalance(root->left)==-1){
				L(root->left);
				R(root); 
			} 
			else R(root);
		}
	}
}
int main(){
	int N,i,data;
	scanf("%d",&N);
	Node* root=NULL;
	for(i=0;i<N;i++){
		scanf("%d",&data);
		insert(root,data);
	}
	printf("%d",root->data);
	return 0;
}
