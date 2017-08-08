#include<cstdio>

/*
d[i]原来只存储i+1到i的距离，但这样算在最坏情况下会超时，因为假设M最大为10000，
计算1到最大N的距离，for嵌套计算和复杂度就是10000*100000，而OJ的每秒承受的运算
次数大致为10^7~10^8，所以会出现运行超时。选择d[i]存储的就是1到i的距离，计算时
一减就可以了 
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
