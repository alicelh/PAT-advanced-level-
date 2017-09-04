#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

vector<int> tmp,ans;
int max_facsum=0;
int N,K,P;
void fac(int num,int t,int sum,int factor_sum){
	tmp.push_back(t);
	if(t<=0||num>K||sum>N) return;
	int flag=0;
	if(num==K&&sum==N){
		if(factor_sum>max_facsum){
			flag=1;
		}
		else if(factor_sum==max_facsum){
			for(int i=0;i<K;i++){
				if(tmp[i]>ans[i]){
					flag=1;
					break;
				}
			}
		}
		if(flag){
			ans.clear();
			for(int i=0;i<K;i++)
				ans.push_back(tmp[i]);
			max_facsum=factor_sum;
		} 
		return;
	}
	if(num==K&&sum!=N) return;
	fac(num+1,t,sum+pow(t,P),factor_sum+t);
	tmp.pop_back();
	if(num<K&&sum<N){
		fac(num+1,t+1,sum+pow(t+1,P),factor_sum+t+1);
		tmp.pop_back();
	}
}

int main(){
	scanf("%d %d %d",&N,&K,&P);
	fac(1,1,1,1);
	for(int i=0;i<K;i++)
		printf("%d ",ans[i]);
	return 0;
} 
