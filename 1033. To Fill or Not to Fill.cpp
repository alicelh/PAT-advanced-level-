#include<cstdio>
#include<algorithm>

using namespace std;

int Cmax,D,Davg,N;
struct station{
	double Pi;
	int Di;
}s[500];

bool cmp(station a,station b){
	return a.Di<b.Di;
}

int main(){
	int i,j,next=0,tmp=0;
	double min,rr,dd,ptmp=0,rtmp=0;
	scanf("%d %d %d %d",&Cmax,&D,&Davg,&N);
	for(i=0;i<N;i++){
		scanf("%lf %d",&s[i].Pi,&s[i].Di);
	}
	sort(s,s+N,cmp);
	if(s[0].Di!=0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	rr=Davg*Cmax;//充满可以走多远
	dd=0;//剩余油量 
	while(rtmp<D){
		min=s[tmp].Pi;
		for(i=tmp;i<N&s[i].Di<=s[tmp].Di+rr;i++){
			if(s[i].Pi<min){
				min=s[i].Pi;
				next=i;
				break;
			}
		}
		if(min!=s[tmp].Pi){//rr内有价格更小的就充到到价格更小的那里的 
			ptmp+=((s[next].Di-rtmp)/Davg-dd)*s[tmp].Pi;
			rtmp=s[next].Di;
			tmp=next;
			dd=0;
		}
		else{//rr内其他的加油站都更贵 
			if(rtmp+rr>=D){//已经可以直接到终点了 
				ptmp+=((D-rtmp)/Davg-dd)*s[tmp].Pi;
				rtmp=D;
				dd=0;
			}
			else{//又不能直接到终点 
				ptmp+=(Cmax-dd)*s[tmp].Pi; 
				dd=Cmax;//先充满 
				if((tmp<N-1&&rtmp+rr<s[tmp+1].Di)||(tmp==N-1&&rtmp+rr<D)){//根本到不了终点 
					printf("The maximum travel distance = %.2f",rtmp+rr);
					return 0;
				}
				else//到所能到的距离中价格最小的那里充满油 
					min=s[tmp+1].Pi;
					next=tmp+1;
					for(i=tmp+1;i<N&&s[i].Di<=s[tmp].Di+rr;i++){
						if(s[i].Pi<min){
							min=s[i].Pi;
							next=i; 
				 		} 
					}
					rtmp=s[next].Di;
					dd=dd-(rtmp-s[tmp].Di)/Davg;
					tmp=next;
				}
			}
		}
	} 
	printf("%.2f",ptmp);
	return 0;
} 
