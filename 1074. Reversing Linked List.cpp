#include<cstdio>

/*可能存在无效节点==，但题目并没有说，这点要考虑*/

struct Node{
	int data;
	int next;
	int last;
}node[100010]; 

int reverse[100010];/*取临界值100000会过不去测试点*/

int main(){
	int N,K,head,now,next,data;
	int i,p,num,j,total;
	scanf("%d %d %d",&head,&N,&K);
	for(i=0;i<N;i++){
		scanf("%d %d %d",&now,&data,&next);
		node[now].data=data;
		node[now].next=next;
	} 
	p=head;
	total=0;
	while(p!=-1){
		reverse[total++]=p;
		p=node[p].next;
	}
	reverse[total]=-1;
	num=total/K;
	while(num){
		if(num==total/K) node[reverse[(num-1)*K]].next=reverse[num*K];
		else node[reverse[(num-1)*K]].next=reverse[(num+1)*K-1];
		for(i=num*K-1;i>(num-1)*K;i--){
			node[reverse[i]].next=reverse[i-1];
		}
		num--;
	}
	p=reverse[K-1];
	while(total--){
		if(total==0){
			printf("%05d %d %d",p,node[p].data,node[p].next);
			break;
		}
		printf("%05d %d %05d\n",p,node[p].data,node[p].next);
		p=node[p].next;
	}
	return 0;
}
