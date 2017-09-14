#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N,K;
struct person{
	char name[10];
	int height;
}p[10010];
bool cmp(person a,person b){
	if(a.height!=b.height)
		return a.height>b.height;
	return strcmp(a.name,b.name)<0;
}
int position[11][1020];
int main(){
	int i,j,every,last;
	int num;
	scanf("%d %d",&N,&K);
	for(i=0;i<N;i++){
		scanf("%s %d",&p[i].name,&p[i].height);
	} 
	sort(p,p+N,cmp);
	every=N/K;
	last=N-every*(K-1);
	int t;
	int next;
	for(i=0;i<K;i++){
		if(i==0) num=last;
		else num=every;
		next=0;
		t=num/2+1;
		for(j=last+num*(i-1);j<last+num*i;j++){
			position[i][t+next]=j;
			if(next==0)
				next-=1;
			else if(next<0) 
				next=-next;
			else 
				next=-next-1;
		}
		for(j=1;j<=num;j++){
			if(j!=1) printf(" ");
			printf("%s",p[position[i][j]].name);
		}
		printf("\n");
	}
	return 0;
} 
