#include<cstdio>

/*
d[i]ԭ��ֻ�洢i+1��i�ľ��룬���������������»ᳬʱ����Ϊ����M���Ϊ10000��
����1�����N�ľ��룬forǶ�׼���͸��ӶȾ���10000*100000����OJ��ÿ����ܵ�����
��������Ϊ10^7~10^8�����Ի�������г�ʱ��ѡ��d[i]�洢�ľ���1��i�ľ��룬����ʱ
һ���Ϳ����� 
*/

int N,M;
int d[100010];
int dis[10000]={0};
int main(){
	int i,j,sum=0,dtmp;
	int tmp,start,end;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		d[i]=sum;
		scanf("%d",&dtmp);
		sum+=dtmp;	
	}
	scanf("%d",&M);
	for(i=0;i<M;i++){
		scanf("%d%d",&start,&end);
		if(start>end){
			tmp=end;
			end=start;
			start=tmp;
		}
		dis[i]=d[end]-d[start];
		if(sum-dis[i]<dis[i])
			dis[i]=sum-dis[i];
	}
	
	for(i=0;i<M;i++){		
		printf("%d\n",dis[i]);
	}
	
	return 0;
} 
