#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct car{
	char num[8];
	int hh;
	int mm;
	int ss;
	int status;//0-in 1-out
	int pair;//配对序号 
	int time;
}rec[10000]; 

bool cmp(car a,car b){
	if(a.hh!=b.hh) return a.hh<b.hh;
	else if(a.mm!=b.mm) return a.mm<b.mm;
	else return a.ss<b.ss;
}
bool cmp2(car a,car b){
	if(strcmp(a.num,b.num)!=0) return strcmp(a.num,b.num)<0;
}

bool cmp1(int hh,int mm,int ss,car a){
	if(hh<a.hh) return true;
	else if(hh==a.hh&&mm<a.mm) return true;
	else if(hh==a.hh&&mm==a.mm&&ss<a.ss) return true;
	else return false;
}

int main(){
	int N,K;
	int i,j,k,flag,tail=0,num=0,max=0;
	int hh,mm,ss;
	char tmp_status[5];
	int tmp[10000];
	memset(tmp,-1,sizeof(int));
	scanf("%d %d",&N,&K);
	for(i=0;i<N;i++){
		scanf("%s %d:%d:%d %s",&rec[i].num,&rec[i].hh,&rec[i].mm,&rec[i].ss,&tmp_status);
		if(strcmp(tmp_status,"in")==0) rec[i].status=0;
		else rec[i].status=1;
		rec[i].pair=-1; 
		rec[i].time=0;
	}
	sort(rec,rec+N,cmp);
	for(i=0;i<N;i++){
		if(rec[i].status==0){
			flag=0;
			for(j=0;j<tail;j++){
				if(tmp[j]!=-1){
					if(strcmp(rec[i].num,rec[tmp[j]].num)==0){
						tmp[j]=i;
						flag=1;
						break;
					}
				}
			}
			if(!flag) tmp[tail++]=i;
		}
		else{
			for(j=0;j<tail;j++){
				if(tmp[j]!=-1){
					if(strcmp(rec[i].num,rec[tmp[j]].num)==0){
						rec[tmp[j]].pair=i;
						rec[i].pair=tmp[j];
						rec[tmp[j]].time=rec[i].hh*3600+rec[i].mm*60+rec[i].ss-rec[tmp[j]].hh*3600-rec[tmp[j]].mm*60-rec[tmp[j]].ss;
						for(k=0;k<tmp[j];k++){
							if(rec[k].pair!=-1&&!rec[k].status&&strcmp(rec[k].num,rec[i].num)==0){
								rec[k].time+=rec[tmp[j]].time;
								if(rec[k].time>max){
									max=rec[k].time;
								}
								break;
							}
						}
						if(rec[tmp[j]].time>max){
							max=rec[tmp[j]].time;
						}
						tmp[j]=-1;
						break;
					}
				}
			}
		}
	}
	j=0;
	for(i=0;i<K;i++){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		while(j<N){
			if(rec[j].pair!=-1&&!cmp1(hh,mm,ss,rec[j])){
				if(rec[j].status){
					num--;
				}
				else{
					num++;
				} 
			}
			if(cmp1(hh,mm,ss,rec[j])){
				break;
			}
			j++;
		}
		printf("%d\n",num);//要在while外面输出，否则存在输入数大于所有的但结果无法输出 
	}
	sort(rec,rec+N,cmp2);
	for(i=0;i<N;i++){
		if(rec[i].pair!=-1&&!rec[i].status){
			if(rec[i].time==max)
				printf("%s ",rec[i].num);
		}
	}
	ss=max%60;
	hh=max/3600;
	mm=(max-ss-hh*3600)/60;
	printf("%02d:%02d:%02d",hh,mm,ss);
	return 0;
}
