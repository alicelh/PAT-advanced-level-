#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct testee{
	char reg[15];//原来用的longlong,虽然好比较，但0098这种数字输出会出问题，所以还是要用char型 
	int score;
	int loc;
	int loc_rank;
	int fnl_rank;
}te[30010];

bool cmp(testee a,testee b){
	if(a.score!=b.score)
		return a.score>b.score;
	else
		return strcmp(a.reg,b.reg)<0;
}

int main(){
	int N,K[100];
	int i,j,k,r,n=0,start=0;
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>K[i-1];
		for(j=1;j<=K[i-1];j++){
			cin>>te[n].reg>>te[n].score;
			te[n++].loc=i; 
		}
		sort(&te[start],&te[start+K[i-1]],cmp);
		te[start].loc_rank=1;
		for(k=1;k<K[i-1];k++){
			if(te[k+start].score==te[k-1+start].score)
				te[k+start].loc_rank=te[k-1+start].loc_rank;
			else
				te[k+start].loc_rank=k+1;
		}
		start+=K[i-1];
	}
	
	sort(&te[0],&te[start],cmp);
	cout<<start<<endl;
	te[0].fnl_rank=1;
	for(i=0;i<start-1;i++){
		if(te[i+1].score==te[i].score)
			te[i+1].fnl_rank=te[i].fnl_rank;
		else
			te[i+1].fnl_rank=i+2;
		cout<<te[i].reg<<" "<<te[i].fnl_rank<<" "<<te[i].loc<<" "<<te[i].loc_rank<<endl;
	}
	cout<<te[i].reg<<" "<<te[i].fnl_rank<<" "<<te[i].loc<<" "<<te[i].loc_rank<<endl;
	return 0;
} 
