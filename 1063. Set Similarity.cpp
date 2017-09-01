#include<cstdio>
#include<set>

using namespace std;

set<int> n[51];

int main(){
	int N,M,K,number,num=0;
	int i,j,n1,n2,s1,s2;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&M);
		for(j=0;j<M;j++){
			scanf("%d",&number);
			n[i].insert(number);
		} 
	}
	scanf("%d",&K);
	set<int>::iterator itr1,itr2;
	for(i=0;i<K;i++){
		scanf("%d %d",&n1,&n2);
		num=0;
		s1=n[n1].size();
		s2=n[n2].size();
		itr1=n[n1].begin();
		itr2=n[n2].begin(); 
		while(itr1!=n[n1].end()&&itr2!=n[n2].end()){
			if(*itr1==*itr2){
				num++;
				itr1++;
				itr2++;
			}
			else if(*itr1<*itr2){
				itr1++;
			}
			else itr2++;
		}
		printf("%.1f%\n",num*1.0/(s1+s2-num)*100.0);
	}
	return 0;
} 
