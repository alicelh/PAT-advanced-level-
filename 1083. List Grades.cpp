#include<cstdio>
#include<algorithm>

using namespace std;

struct record{
	char name[11];
	char id[11];
	int grade;
}rec[110];

bool cmp(record a,record b){
	return a.grade>b.grade;
}

int main(){
	int N,grade1,grade2,flag=0;
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s %s %d",&rec[i].name,&rec[i].id,&rec[i].grade);
	}
	scanf("%d %d",&grade1,&grade2);
	sort(rec,rec+N,cmp);
	for(i=0;i<N;i++){
		if(rec[i].grade<=grade2&&rec[i].grade>=grade1){
			printf("%s %s\n",rec[i].name,rec[i].id);
			flag=1;
		}
	}
	if(!flag) printf("NONE");
	return 0;
}
