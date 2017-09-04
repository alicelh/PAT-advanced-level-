#include<cstdio>
#include<queue>

using namespace std;

int p[1290][130][65],num=0;
struct node{
	int i,j,k;
};
int M,N,L,T,total=0;
bool inqueue[1290][130][65]={0};
int d_i[6]={0,0,0,0,1,-1};
int d_j[6]={1,-1,0,0,0,0};
int d_k[6]={0,0,1,-1,0,0};

bool validnum(int i,int j,int k){
	if(i<0||i>=L||j<0||j>M||k<0||k>N) return false;
	if(p[j][k][i]==0) return false;
	return true;
}
void BFS(int i,int j,int k){
	num=0;
	queue<node> q;
	node tmp;
	tmp.i=i;
	tmp.j=j;
	tmp.k=k;
	q.push(tmp);
	num++;
	inqueue[j][k][i]=true;
	while(!q.empty()){
		node top=q.front();
		q.pop();
		for(int z=0;z<6;z++){
			tmp.i=top.i+d_i[z];
			tmp.j=top.j+d_j[z];
			tmp.k=top.k+d_k[z];
			if(validnum(tmp.i,tmp.j,tmp.k)&&inqueue[tmp.j][tmp.k][tmp.i]==false){
				q.push(tmp);
				num++;
				inqueue[tmp.j][tmp.k][tmp.i]=true;
			}
		}
	}
	if(num>=T) total+=num;
}

int main(){
	int i,j,k;
	scanf("%d %d %d %d",&M,&N,&L,&T);
	for(i=0;i<L;i++){
		for(j=0;j<M;j++){
			for(k=0;k<N;k++){
				scanf("%d",&p[j][k][i]);
			}
		}
	}
	for(i=0;i<L;i++){
		for(j=0;j<M;j++){
			for(k=0;k<N;k++){
				if(validnum(i,j,k)&&inqueue[j][k][i]==false)
					BFS(i,j,k);
			}
		}
	}
	printf("%d",total);
	return 0;
}

