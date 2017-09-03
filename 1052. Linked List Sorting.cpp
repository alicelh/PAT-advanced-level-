#include<cstdio>
#include<algorithm>

using namespace std;

struct Node{
	int add;
	int data;
	int next;
}node[100010],n[100010];

bool cmp(Node a,Node b){
	return a.data<b.data;
}

int main(){
	int N,head,now,data,next,p,num=0,i;
	scanf("%d %d",&N,&head);
	for(i=0;i<N;i++){
		scanf("%d %d %d",&now,&data,&next);
		node[now].data=data;
		node[now].next=next;
	}
	p=head;
	while(p!=-1){
		n[num].add=p;
		n[num].data=node[p].data;
		num++;
		p=node[p].next;
	}
	sort(n,n+num,cmp);
	if(num!=0) printf("%d %05d\n",num,n[0].add);
	else printf("0 -1");//注意num为0的情况 
	for(i=0;i<num;i++){
		printf("%05d %d ",n[i].add,n[i].data);
		if(i==num-1) printf("-1");
		else printf("%05d\n",n[i+1].add);
	}
	return 0;
} 
