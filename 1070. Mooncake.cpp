#include<cstdio>
#include<algorithm>

using namespace std;

int N,D;
struct cake{
	double amount;
	double price;
}c[1000];

bool cmp(cake a,cake b){
	return a.price/a.amount>b.price/b.amount;
} 

int main(){
	int i,j,sum=0;
	double sum_price=0;
	scanf("%d %d",&N,&D);
	for(i=0;i<N;i++){
		scanf("%lf",&c[i].amount);
		sum+=c[i].amount;
	}
	for(i=0;i<N;i++){
		scanf("%lf",&c[i].price);
		sum_price+=c[i].price;
	}
	if(sum<=D){
		printf("%.2f",sum_price);
		return 0;
	}
	sort(c,c+N,cmp);
	i=0;
	sum_price=0;
	while(D>0){
		if(D>=c[i].amount){
			D=D-c[i].amount;
			sum_price+=c[i].price;
		}
		else{
			sum_price+=c[i].price/c[i].amount*D;
			D=0;
		}
		i++;
	}
	printf("%.2f",sum_price);
	return 0;
}
