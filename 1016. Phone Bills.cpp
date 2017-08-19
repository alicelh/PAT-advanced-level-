#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int toll[24];
int N;
struct record{
	char cus[21];
	int month;
	int dd;
	int hh;
	int mm;
	int flag;//1-on 0-off
}reds[1000];

bool cmp(record a,record b){
	if(strcmp(a.cus,b.cus)!=0)
		return strcmp(a.cus,b.cus)<0;
	if(a.month!=b.month)
		return a.month<b.month;
	else if(a.dd!=b.dd)
		return a.dd<b.dd;
	else if(a.hh!=b.hh)
		return a.hh<b.hh;
	else
		return a.mm<b.mm;
}

int main(){
	int i,t;
	int num,index=0;
	float total=0.0,money;
	int dd,hh,mm;
	char tmp[10];
	char tmpname[25];
	for(i=0;i<24;i++)
		scanf("%d",&toll[i]);
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s %d:%d:%d:%d %s",&reds[i].cus,&reds[i].month,&reds[i].dd,&reds[i].hh,&reds[i].mm,tmp);
		if(strcmp(tmp,"on-line")==0) reds[i].flag=1;
		else reds[i].flag=0;
	}
	
	sort(reds,reds+N,cmp);
	strcpy(tmpname,reds[0].cus);
	for(i=0;i<N-1;i++){
		if(strcmp(tmpname,reds[i].cus)==0){
			if(strcmp(tmpname,reds[i+1].cus)==0&&reds[i].flag==1&&reds[i+1].flag==0){//注意判断下一个也要是相同名字 
				money=0;
				dd=reds[i].dd;
				hh=reds[i].hh;
				mm=reds[i].mm;
				num=reds[i+1].dd*60*24+reds[i+1].hh*60+reds[i+1].mm-(reds[i].dd*60*24+reds[i].hh*60+reds[i].mm);
				t=num;
				while(t--){
					money+=toll[hh];
					mm++;
					if(mm!=60){
						continue; 
					}
					else{
						mm=0;
						hh++;
						if(hh==24){
							hh=0;
							dd++;
						}
					}	
				}
				total+=money;
				if(index==0){
					printf("%s %02d\n",tmpname,reds[i].month);
					index=1;
				}
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",reds[i].dd,reds[i].hh,reds[i].mm,reds[i+1].dd,reds[i+1].hh,reds[i+1].mm,num,money/100);
				money=0;
				i++; 
			}
		}
		else{
			if(index==1){
				printf("Total amount: $%.2f\n",total/100);
			}
			strcpy(tmpname,reds[i].cus);
			index=0;
			total=0;
			i--;
		} 
	}
	if(index==1){
		printf("Total amount: $%.2f\n",total/100);
	}
	return 0;
} 
