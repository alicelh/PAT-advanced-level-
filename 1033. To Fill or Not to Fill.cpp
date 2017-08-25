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
	rr=Davg*Cmax;//���������߶�Զ
	dd=0;//ʣ������ 
	while(rtmp<D){
		min=s[tmp].Pi;
		for(i=tmp;i<N&s[i].Di<=s[tmp].Di+rr;i++){
			if(s[i].Pi<min){
				min=s[i].Pi;
				next=i;
				break;
			}
		}
		if(min!=s[tmp].Pi){//rr���м۸��С�ľͳ䵽���۸��С������� 
			ptmp+=((s[next].Di-rtmp)/Davg-dd)*s[tmp].Pi;
			rtmp=s[next].Di;
			tmp=next;
			dd=0;
		}
		else{//rr�������ļ���վ������ 
			if(rtmp+rr>=D){//�Ѿ�����ֱ�ӵ��յ��� 
				ptmp+=((D-rtmp)/Davg-dd)*s[tmp].Pi;
				rtmp=D;
				dd=0;
			}
			else{//�ֲ���ֱ�ӵ��յ� 
				ptmp+=(Cmax-dd)*s[tmp].Pi; 
				dd=Cmax;//�ȳ��� 
				if((tmp<N-1&&rtmp+rr<s[tmp+1].Di)||(tmp==N-1&&rtmp+rr<D)){//�����������յ� 
					printf("The maximum travel distance = %.2f",rtmp+rr);
					return 0;
				}
				else//�����ܵ��ľ����м۸���С����������� 
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
