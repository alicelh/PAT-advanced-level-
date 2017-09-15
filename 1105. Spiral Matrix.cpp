#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxN=10000;
vector<int> nv;
int v[maxN][maxN];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int N,i,j,k,tmp;
	int m,n,right=0,down=0,left=0,up=0,num=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&tmp);
		nv.push_back(tmp);
	}
	sort(nv.begin(),nv.end(),cmp);
	tmp=(int)sqrt(N);
	for(i=tmp;i>=1;i--){
		if(N%i!=0) continue;
		if(N%i==0){
			n=i;
			m=N/i;
			break;
		}
	}
	i=0;
	j=0;
	right=1;
	for(k=0;k<N;k++){
		v[i][j]=nv[k];
		if(right){
			if(j>=n-num-1){
				right=0;
				down=1;
				i++;
			}
			else j++;
		}
		else if(down){
			if(i>=m-num-1){
				down=0;
				left=1;
				j--;
			}
			else i++;
		}
		else if(left){
			if(j<=num){
				left=0;
				up=1;
				i--;
			}
			else j--;
		}
		else{
			if(i<=num+1){
				up=0;
				right=1;
				j++;
				num++;
			}
			else i--;
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(j!=0) printf(" ");
			printf("%d",v[i][j]);
		}
		printf("\n");
	}
	return 0;
}
