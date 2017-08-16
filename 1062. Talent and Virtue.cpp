#include<cstdio>
#include<algorithm>
#include<cstring>

//由于数据量太大，使用cin,cout会出现运行超时 

using namespace std;

int N,M=0,L,H;

struct people{
	int id;
	int vg;
	int tg;
	int level;
}p[100000];

bool cmp(people a,people b){
	if(a.level!=b.level) return a.level<b.level;
	if(a.tg+a.vg!=b.vg+b.tg)
		return a.tg+a.vg>b.tg+b.vg;
	else if(a.vg!=b.vg)
		return a.vg>b.vg;
	else
	 	return a.id<b.id;
}

int main(){
	int i,tmp_tg,tmp_vg,tmp_id;
	scanf("%d %d %d",&N,&L,&H);
	for(i=0;i<N;i++){
		scanf("%d %d %d",&tmp_id,&tmp_vg,&tmp_tg);
		if(tmp_tg>=L&&tmp_vg>=L){
			p[M].id=tmp_id;
			p[M].tg=tmp_tg;
			p[M].vg=tmp_vg;
			if(tmp_tg>=H&&tmp_vg>=H){
				p[M++].level=1;
			}
			else if(tmp_tg<H&&tmp_vg>=H){
				p[M++].level=2;
			}
			else if(tmp_tg<H&&tmp_vg<H&&tmp_vg>=tmp_tg){
				p[M++].level=3;
			}
			else{
				p[M++].level=4;
			}
		}	
	}
	printf("%d\n",M);
	sort(p,p+M,cmp);

	for(i=0;i<M;i++){
		printf("%d %d %d\n",p[i].id,p[i].vg,p[i].tg);
	}
	return 0;
} 
