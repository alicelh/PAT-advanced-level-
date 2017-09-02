#include<cstdio>
#include<stack>

using namespace std;

stack<int> s;

int main(){
	int M,N,K;
	int i,tmp,j,flag;
	scanf("%d %d %d",&M,&N,&K);
	while(K--){
		while(!s.empty()){
			s.pop();
		}
		j=1;
		flag=0;
		for(i=0;i<N;i++){
			scanf("%d",&tmp);
			for(;j<=tmp;j++){
				s.push(j);
				if(s.size()>M){
					flag=1;
					break;
				}
			}
			if(s.top()==tmp) s.pop();
			else{
				flag=1;
			}
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
