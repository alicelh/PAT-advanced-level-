 #include<cstdio>
 #include<cmath>
 #include<queue>
 #include<algorithm>
 /*此题我利用了完全二叉树的性质构建二叉树，但更简单明了的思路是二叉查找树的中序遍历是有序的，先构建一颗无data值的
 完全二叉树（用数组），对其进行中序遍历，同时进行赋值*/
 using namespace std;
 int N,node[1010];
 struct Node{
 	int data;
 	Node* left;
 	Node* right;
 };
 Node* createtree(int l,int r,int n){
 	if(l>r) return NULL;
 	int index,lastindex,i=0;
 	if(n==1) index=l; 
 	else{
 		while(1){ 
	 		if(n<=pow(2,i)-1) break;
	 		i++;
		}
		lastindex=n-pow(2,i-1)+1;
		if(lastindex>pow(2,i-1)/2) lastindex=pow(2,i-1)/2;
		index=l+lastindex+pow(2,i-1)/2-1;
	}
	
	Node* root=new Node;
	root->data=node[index];
	root->left=createtree(l,index-1,index-l);
	root->right=createtree(index+1,r,r-index);
	return root;
 }
 void levelorder(Node* root){
 	queue<Node*> q;
 	q.push(root);
 	int num=0;
 	while(!q.empty()){
 		Node* tmp=q.front();
		q.pop();
		if(num!=0) printf(" ");
		printf("%d",tmp->data);
		num++;
		if(tmp->left!=NULL) q.push(tmp->left);
		if(tmp->right!=NULL) q.push(tmp->right); 
	}
 }
 int main(){
 	int i,j;
 	scanf("%d",&N);
 	for(i=0;i<N;i++){
 		scanf("%d",&node[i]);
	}
	sort(node,node+N);
	Node* root=createtree(0,N-1,N);
	levelorder(root);
	return 0;
 } 
