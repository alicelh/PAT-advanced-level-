#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct person{
	int id;
	int score[6];
	int total_score;
	int num;//perfectly solved numbers 
	int rank;
	int flag;//标记是否列入排名 
}p[10010];

int mark[6],N,K,M;
bool cmp(person a,person b){
	if(a.total_score!=b.total_score)
		return a.total_score>b.total_score; 
	else if(a.num!=b.num)
		return a.num>b.num;
	else
		return a.id<b.id;
}
int main(){
	int i,j,id,pro,sco;
	
	scanf("%d %d %d",&N,&K,&M);
	for(i=1;i<=N;i++){
		for(j=1;j<=K;j++){
			p[i].score[j]=-10;
		}
		p[i].num=0;
		p[i].id=i;
		p[i].flag=0;
		p[i].total_score=-10;
	}
	for(i=1;i<K+1;i++)
		scanf("%d",&mark[i]);
	for(i=0;i<M;i++){
		scanf("%d %d %d",&id,&pro,&sco);
		if(sco>=0)
			p[id].flag=1;
		if(sco>p[id].score[pro]){
			p[id].score[pro]=sco;
			if(sco==-1) p[id].score[pro]=0;//编译不通过时得分为0 
			if(sco==mark[pro])
				p[id].num++;
		}
	}
	for(i=1;i<=N;i++){
		if(p[i].flag){
			p[i].total_score=0;
			for(j=1;j<=K;j++){
				if(p[i].score[j]!=-10)
					p[i].total_score+=p[i].score[j];
			}
		}
	}
	sort(p+1,p+N+1,cmp);
	i=1;	
	while(i<=N){
		if(p[i].flag){
			if(i>=2&&p[i].total_score==p[i-1].total_score)
				p[i].rank=p[i-1].rank;
			else
				p[i].rank=i;
			printf("%d %05d %d",p[i].rank,p[i].id,p[i].total_score);
			for(j=1;j<=K;j++){
				if(p[i].score[j]==-10)
					printf(" -");
				else
					printf(" %d",p[i].score[j]); 
			}
			printf("\n");
		}
		i++;
	}
	return 0;
}
