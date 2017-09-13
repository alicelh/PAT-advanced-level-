#include<cstdio>
#include<queue>
using namespace std;
/*这道题要注意的是不能服务输出Sorry的顾客是17点之后开始的顾客，对于17点之前开始
即使结束时间超过17点仍是算作可以服务的*/
int N,M,K,Q,index;
const int Inf=1000000000;
int pro[1010],query[1010],t[1010]={0},pp[1010];
queue<int> q[22],mintime;
int main(){
	int i,j,tm=0,tmp,k;
	int mm,hh;
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	for(i=1;i<=K;i++){
		scanf("%d",&pro[i]);
		pp[i]=pro[i];
	}
	for(i=1;i<=Q;i++)
		scanf("%d",&query[i]);
	j=1;
	while(j<=K&&j<=N*M){
		for(i=1;i<=N;i++){
			q[i].push(j++);
			if(j>K||j>N*M) break;
		}
	}
	while(1){
		int min=Inf;
		for(i=1;i<=N;i++){
			if(!q[i].empty()){
				if(min>pro[q[i].front()]){
					tmp=mintime.size();
					while(tmp--) mintime.pop();
	 				mintime.push(i);
	 				min=pro[q[i].front()];
				}
				else if(min==pro[q[i].front()])
					mintime.push(i);		
			}
		}
		if(mintime.empty()) break;
		min=pro[q[mintime.front()].front()];
		tm+=min;
		for(i=1;i<=N;i++){
			if(!q[i].empty()){
				pro[q[i].front()]-=min;
			}
		}
		for(i=1;i<=mintime.size();i++){
			tmp=mintime.front();
			mintime.pop();
			t[q[tmp].front()]=tm;
			q[tmp].pop();
			if(j<=K) q[tmp].push(j++);
		}
	}
	for(i=1;i<=Q;i++){
		if(t[query[i]]-pp[query[i]]>=540) printf("Sorry\n");
		else{
			mm=t[query[i]]%60;
			hh=8+t[query[i]]/60;
			printf("%02d:%02d\n",hh,mm);
		}
	}
	return 0;
} 
