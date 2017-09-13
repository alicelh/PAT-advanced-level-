#include<cstdio>
#include<algorithm>
using namespace std;
struct customer{
	int arrive;
	int pro;
}n[10010];
int window[110];
bool cmp(customer a,customer b){
	return a.arrive<b.arrive;
}
const int Inf=1000000000;
int main(){
	int N,K,i,j,num=0;
	double sum=0;
	int hh,mm,ss,index,l,mintime;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++){
		scanf("%d:%d:%d",&hh,&mm,&ss);
		n[num].arrive=hh*60*60+mm*60+ss-8*60*60;
		scanf("%d",&n[num].pro);
		if(n[num].arrive>9*60*60){
			num--;
		}
		num++;
	}
	sort(n,n+num,cmp);
	for(i=0;i<K&&i<num;i++){
		if(n[i].arrive<0){
			sum+=abs(n[i].arrive);
			n[i].arrive=0;
		}
		window[i]=n[i].arrive+n[i].pro*60; 
	}
	l=i;
	while(l<num){
		mintime=Inf;
		for(i=0;i<K;i++){
			if(window[i]<mintime){
				mintime=window[i];
				index=i;
			}
		}
		if(window[index]>n[l].arrive){
			sum+=window[index]-n[l].arrive;
			window[index]+=n[l].pro*60;
		}
		else window[index]=n[l].arrive+n[l].pro*60;
		l++;
	}
	printf("%.1f",(sum/60)/num);
} 
