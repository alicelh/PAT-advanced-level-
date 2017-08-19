#include<cstdio>
#include<cstring>
#include<algorithm>

//用iostream会运行超时== 

using namespace std;

struct student{
	char id[8];
	char name[10];
	int grade;
}rec[100000];

int C,N;

bool cmp(student a,student b){
	if(C==1)
		return strcmp(a.id,b.id)<0;
	else if(C==2){
		if(strcmp(a.name,b.name)!=0)
			return strcmp(a.name,b.name)<0;
		else
			return strcmp(a.id,b.id)<0;
	}
	else{
		if(a.grade!=b.grade)
			return a.grade<b.grade;
		else
			return strcmp(a.id,b.id)<0;
	}
}
int main(){
	int i;
	
	scanf("%d %d",&N,&C);
	for(i=0;i<N;i++){
		scanf("%s %s %d",&rec[i].id,&rec[i].name,&rec[i].grade);
	}
	sort(rec,rec+N,cmp);
	for(i=0;i<N;i++){
		printf("%s %s %d\n",rec[i].id,rec[i].name,rec[i].grade);
	}
	return 0;
} 
