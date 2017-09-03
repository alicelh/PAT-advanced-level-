#include<cstdio>
#include<algorithm>

/**判断正的key是否出现过用hash的方法，更快**/

using namespace std;

struct Node{
	int add;
	int data;
	int next;
}node[100010],rem[100010];

int d[10010]={0};

int main(){
	int i,head,N,index,p,pre,rem_p=0,num=0;
	scanf("%d %d",&head,&N);
	for(i=0;i<N;i++){
		scanf("%d",&index);
		scanf("%d %d",&node[index].data,&node[index].next);
	}
	pre=head;
	d[abs(node[pre].data)]=1;
	p=node[pre].next;
	while(p!=-1){
		if(d[abs(node[p].data)]==1){
				if(rem_p!=0) rem[rem_p-1].next=p;
				rem[rem_p].add=p;
				rem[rem_p].data=node[p].data;
				rem_p++;
				node[pre].next=node[p].next; 
				p=node[p].next;
		}
		else{
			d[abs(node[p].data)]=1;
			pre=p;
			p=node[p].next; 
		} 
	}
	if(rem_p!=0) rem[rem_p-1].next=-1;
	p=head; 
	while(p!=-1){
		if(node[p].next==-1) printf("%05d %d %d\n",p,node[p].data,node[p].next);
		else printf("%05d %d %05d\n",p,node[p].data,node[p].next);
		p=node[p].next;
	}
	i=0;
	while(i<rem_p){
		if(i==rem_p-1) printf("%05d %d %d\n",rem[i].add,rem[i].data,rem[i].next);
		else printf("%05d %d %05d\n",rem[i].add,rem[i].data,rem[i].next);
		i++;
	}
	return 0;
} 
