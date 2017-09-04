 #include<cstdio>
 #include<queue>
 
 using namespace std;
 int N,po[35],in[35];
 
 struct Node{
 	int data;
 	Node* lchild;
 	Node* rchild;
 };
 
 Node* createTree(int poL,int poR,int inL,int inR){
 	if(poL>poR){
 		return NULL;
	}
	Node* root=new Node;
	root->data=po[poR];
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==po[poR]) break;
	} 
	int numLeft=k-inL;
	root->lchild=createTree(poL,poL+numLeft-1,inL,k);
	root->rchild=createTree(poL+numLeft,poR-1,k+1,inR);
	return root;
 }
 
 int main(){
 	int i;
 	scanf("%d",&N);
 	for(i=0;i<N;i++)
 		scanf("%d",&po[i]);
	for(i=0;i<N;i++)
		scanf("%d",&in[i]);
	Node* root=createTree(0,N-1,0,N-1);
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* now=q.front();
		q.pop();
		if(now!=root) printf(" ");
		printf("%d",now->data);
		if(now->lchild!=NULL) q.push(now->lchild);
		if(now->rchild!=NULL) q.push(now->rchild);
	}
	return 0;
 } 
