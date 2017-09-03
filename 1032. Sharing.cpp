#include<cstdio>

struct Node{
	char data;
	int next;
	int visited;
}node[100010];

int main(){
	int head1,head2,N,now,data,next;
	int i,p,find=-1;
	scanf("%d %d %d",&head1,&head2,&N);
	for(i=0;i<N;i++){
		scanf("%d %c %d",&now,&data,&next);
		node[now].data=data;
		node[now].next=next;
		node[now].visited=0;
	}
	p=head1;
	while(p!=-1){
		node[p].visited=1;
		p=node[p].next;
	}
	p=head2;
	while(p!=-1){
		if(node[p].visited){
			find=p;
			break;
		}
		p=node[p].next;
	}
	if(find==-1) printf("%d",find);
	else printf("%05d",find);//别忘了五位数的限制 
	return 0;	
} 
