#include<cstdio>
#include<queue>
using namespace std;
int p[1100],order[1100];
queue<int> a,b;
int main(){
	int np,ng;
	int i,tmp,max,maxindex,len,l;
	scanf("%d %d",&np,&ng);
	for(i=0;i<np;i++)
		scanf("%d",&p[i]);
	for(i=0;i<np;i++){
		scanf("%d",&tmp);
		a.push(tmp);
	}
	if(a.size()==1){
		printf("1");
		return 0;
	}
	while(a.size()>0){
		len=a.size();
		while(!a.empty()){
			max=-1;
			l=a.size();
			for(i=0;i<ng&&i<l;i++){
				if(p[a.front()]>max){
					max=p[a.front()];
					maxindex=a.front();
				}
				if(len%ng==0) order[a.front()]=len/ng+1;//注意排名跟划分组数的关系 
				else order[a.front()]=len/ng+2;
				a.pop();
			}
			b.push(maxindex);
		}
		while(!b.empty()){
			a.push(b.front());
			b.pop();
		}
		if(a.size()==1){
			order[a.front()]=1;
			break;
		}
	}
	for(i=0;i<np;i++){
		if(i>0) printf(" ");
		printf("%d",order[i]);
	}
	return 0;
}
