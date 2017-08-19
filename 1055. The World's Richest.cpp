#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct person{
	char name[10];
	int age;
	int worth;
}p[100000];

int N,K,num,Amin,Amax;

bool cmp(person a,person b){
	if(a.worth!=b.worth)
		return a.worth>b.worth;
	else if(a.age!=b.age)
		return a.age<b.age;
	else
		return strcmp(a.name,b.name)<0;
}

int main(){
	int i,j,flag,n;
	scanf("%d %d",&N,&K);
	for(i=0;i<N;i++){
		scanf("%s %d %d",&p[i].name,&p[i].age,&p[i].worth);
	}
	sort(p,p+N,cmp); 
	for(i=0;i<K;i++){
		scanf("%d %d %d",&num,&Amin,&Amax);
		printf("Case #%d:\n",i+1);
		flag=0;
		n=0;
		for(j=0;j<N;j++){
			if(n==num) break;
			if(p[j].age>=Amin&&p[j].age<=Amax){
				printf("%s %d %d\n",p[j].name,p[j].age,p[j].worth);
				flag=1;
				n++;
			}	
		}	
		if(!flag)
			printf("None\n");
	}
	return 0;
} 
