#include<cstdio>
#include<algorithm>

using namespace std;
//容易犯错的地方是排序后的序号i和id是不一样的,所以在判断rank是否相同时要存储最后一个录取学生排序后的i 

struct student{
	int id;
	int ge;
	int gi;
	int school[6];
}stu[40010];

struct school{
	int quota;
	int num;
	int student[40010];//40000才能过 
	int last;//最后一个录取的学生序号 
}sch[110];

bool cmp(student a,student b){
	if(a.ge+a.gi!=b.ge+b.gi)
		return a.ge+a.gi>b.ge+b.gi;
	else
		return a.ge>b.ge;
}

int main(){
	int N,M,K;
	int i,j,tmp;
	int quota[100];
	scanf("%d %d %d",&N,&M,&K);
	for(i=0;i<M;i++){
		scanf("%d",&sch[i].quota);
		sch[i].num=0;
	}	
	for(i=0;i<N;i++){
		scanf("%d %d",&stu[i].ge,&stu[i].gi);
		stu[i].id=i;
		for(j=0;j<K;j++)
			scanf("%d",&stu[i].school[j]);
	}
	sort(stu,stu+N,cmp);
	for(i=0;i<N;i++){
		for(j=0;j<K;j++){
			tmp=stu[i].school[j];
			if(sch[tmp].num<sch[tmp].quota){
				sch[tmp].student[sch[tmp].num++]=stu[i].id;
				sch[tmp].last=i; 
				break;
			}
			else if(sch[tmp].num>0&&stu[sch[tmp].last].ge==stu[i].ge&&stu[sch[tmp].last].gi==stu[i].gi){
				sch[tmp].student[sch[tmp].num++]=stu[i].id;
				sch[tmp].last=i; 
				break;
			}	
		}
	}
	for(i=0;i<M;i++){
		if(sch[i].num==0)
			printf("\n");
		else{
			sort(sch[i].student,sch[i].student+sch[i].num);
			for(j=0;j<sch[i].num-1;j++)
				printf("%d ",sch[i].student[j]);
			printf("%d\n",sch[i].student[j]); 
		}
	}
	return 0;
}

