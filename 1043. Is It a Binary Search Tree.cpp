#include<cstdio>
using namespace std;
/*已知一个二叉查找树的前序遍历，就可以通过前序遍历构建出这棵二叉查找树*/

int N,n[1010],num=0;
bool flag1=true,flag2=true;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* newnode(int v){
	Node* node=new Node;
	node->data=v;
	node->left=node->right=NULL;
	return node; 
}
void insert(Node* &root,int x){
	if(root==NULL){
		root=newnode(x);
		return;
	}
	if(x>=root->data) insert(root->right,x);
	else insert(root->left,x);
}
void preorder1(Node* root){
	if(root==NULL) return;
	if(n[num++]!=root->data){
		flag1=false;
	}
	preorder1(root->left);
	preorder1(root->right);
}
void preorder2(Node* root){
	if(root==NULL) return;
	if(n[num++]!=root->data){
		flag2=false;
	}
	preorder2(root->right);
	preorder2(root->left);
}
void postorder1(Node* root){
	if(root==NULL) return;
	postorder1(root->left);
	postorder1(root->right);
	if(num!=0) printf(" ");
	printf("%d",root->data);
	num++;
}
void postorder2(Node* root){
	if(root==NULL) return;
	postorder2(root->right);
	postorder2(root->left);
	if(num!=0) printf(" ");
	printf("%d",root->data);
	num++;
}
int main(){
	int i,j,tmp; 
	scanf("%d",&N);
	Node* root=NULL;
	for(i=0;i<N;i++){
		scanf("%d",&n[i]);
		insert(root,n[i]); 
	}
	preorder1(root);
	num=0;
	preorder2(root);
	if(flag1){
		printf("YES\n");
		num=0;
		postorder1(root);
	}
	else if(flag2){
		printf("YES\n");
		num=0;
		postorder2(root);
	}
	else printf("NO");
	return 0;
} 
