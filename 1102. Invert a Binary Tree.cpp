#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int lchild;
	int rchild;
}n[12];
int N,root;
void traversalnum(int s,int& num){
	num++;
	if(n[s].lchild!=-1) traversalnum(n[s].lchild,num);
	if(n[s].rchild!=-1) traversalnum(n[s].rchild,num);
}
void inorder(int s,int& num){
	if(s==-1) return;
	inorder(n[s].lchild,num);
	if(num!=0) printf(" "); 
	num++;
	printf("%d",s);
	inorder(n[s].rchild,num);
}
int main(){
	scanf("%d",&N);
	int i,tmp,num;
	char left,right,k;
	for(i=0;i<N;i++){
		cin>>right>>left;//反转只要输入的时候反着接受就可以了 
		if(left=='-') n[i].lchild=-1;
		else n[i].lchild=left-'0';
		if(right=='-') n[i].rchild=-1;
		else n[i].rchild=right-'0';
	}
	for(i=0;i<N;i++){//这里做麻烦了，只要找到那个不做其他节点孩子的节点就是根节点 
		num=0;
		traversalnum(i,num);
		if(num==N){
			root=i;
			break;
		}
	}
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		tmp=q.front();
		q.pop();
		if(tmp!=root) printf(" ");
		printf("%d",tmp);		
		if(n[tmp].lchild!=-1) q.push(n[tmp].lchild);
		if(n[tmp].rchild!=-1) q.push(n[tmp].rchild);
	}
	printf("\n");
	num=0;
	inorder(root,num);
	return 0;
}
