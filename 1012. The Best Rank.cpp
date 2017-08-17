#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct student{
	int id; //用string时sort会崩溃,应该是因为大小不固定？ 
	int grade[4];
	int rank[4];
}stu[2010];

int now;
int id[2010];
char cc[4]={'A','C','M','E'};

bool cmp(student a,student b){
	return a.grade[now]>b.grade[now];
} 

int main(){
	int i,j,r,min,k,course,flag=0;
	int N,M;
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++){
		scanf("%d %d %d %d",&stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
		stu[i].grade[0]=stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3];
	}
	for(i=0;i<M;i++){
		scanf("%d",&id[i]); 
	}
	
	for(now=0;now<4;now++){
		sort(stu,stu+N,cmp);
		stu[0].rank[now]=1;
		for(i=1;i<N;i++){//排序是1224而不是1223 
			if(stu[i].grade[now]!=stu[i-1].grade[now]){
				stu[i].rank[now]=i+1;
			}
			else{
				stu[i].rank[now]=stu[i-1].rank[now];
			}
		}
	}
	
	for(i=0;i<M;i++){
		flag=0;
		for(j=0;j<N;j++){
			if(id[i]==stu[j].id){
				flag=1;
				min=stu[j].rank[0];
				course=0;
				for(k=1;k<4;k++){
					if(stu[j].rank[k]<min){
						min=stu[j].rank[k];
						course=k;
					}
				}
				break;
			}
		}
		if(flag){
			printf("%d %c\n",min,cc[course]); 
		}
		else{
			printf("N/A\n");
		}
	}
	return 0;
} 
