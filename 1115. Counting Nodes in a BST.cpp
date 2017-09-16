#include<cstdio>

struct Node{
	int data;
	Node* left,*right;
	int height;
};
int N,height[1010]={0};
int insert(Node* &root,int data,int num){
	if(root==NULL){
		root=new Node;
		root->data=data;
		root->height=num;
		root->left=root->right=NULL;
		return num;
	}
	else if(data<=root->data){
		insert(root->left,data,num+1);
	}
	else insert(root->right,data,num+1);
}
int main(){
	int i,j,tmp,h,maxheight=-1;
	Node* root=NULL;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&tmp);
		h=insert(root,tmp,0);
		if(h>maxheight) maxheight=h;
		height[h]++;
	}
	printf("%d + %d = %d",height[maxheight],height[maxheight-1],height[maxheight]+height[maxheight-1]);
	return 0;
}
