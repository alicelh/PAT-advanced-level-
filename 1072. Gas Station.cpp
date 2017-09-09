#include<cstdio>
#include<algorithm>
using namespace std;
const int Inf=1000000000;
int N,M,K,Ds; 
int v[1020][1020],d[1020],visited[1020]; 

void dijkstra(int start){
	fill(visited,visited+1020,0);
	fill(d,d+1020,Inf);
	d[start]=0;
	int i,j;
	for(i=1;i<=N+M;i++){
		int u=-1,min=Inf;
		for(j=1;j<=N+M;j++){
			if(!visited[j]&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		visited[u]=1;
		for(j=1;j<=N+M;j++){
			if(!visited[j]&&v[u][j]!=Inf){
				if(d[u]+v[u][j]<d[j]){
					d[j]=d[u]+v[u][j];
				}
			}
		}
	}
}

int getid(char a[]){//一开始把输入数字都当个位数处理的==，但其实最大可以达到1000！！ 
	int i=0,sum=0;
	while(a[i]!='\0'){
		if(a[i]=='G'){
			i++;
			continue;
		} 
		sum=sum*10+a[i]-'0';
		i++;
	}
	if(a[0]=='G') return sum+N;
	else return sum;
}

int main(){
	int i,j,dis,s1,s2;
	char a[5],b[5];
	fill(v[0],v[0]+1020*1020,Inf);
	scanf("%d%d%d%d",&N,&M,&K,&Ds);
	for(i=0;i<K;i++){
		scanf("%s %s %d",&a,&b,&dis);
		s1=getid(a);
		s2=getid(b);
		v[s1][s2]=v[s2][s1]=dis;
	}
	int index=-1,flag;
	double mindis=-1,min,sum,minsum=Inf;
	for(i=N+1;i<=N+M;i++){
		flag=0;
		dijkstra(i);
		min=Inf;
		sum=0;
		for(j=1;j<=N;j++){
			if(d[j]<min){
				min=d[j];
			}
			if(d[j]>Ds){
				flag=1;
				break;
			}
			sum+=d[j]*1.0/N;
		}
		if(flag) continue;
		if(min>mindis){
			mindis=min;
			index=i-N;
			minsum=sum;
		}
		else if(min==mindis){
			if(sum<minsum){
				minsum=sum;
				index=i-N;
			}
		}
	}
	if(index==-1) printf("No Solution");
	else{
		printf("G%d\n",index);
		printf("%.1f %.1f",mindis,minsum);
	} 
	return 0;
}
