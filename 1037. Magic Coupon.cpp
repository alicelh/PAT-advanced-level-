#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int nc,np,sum=0;
	int i,j,k,x;
	int c[100000],p[100000];
	scanf("%d",&nc);
	for(i=0;i<nc;i++) scanf("%d",&c[i]);
	scanf("%d",&np);
	for(i=0;i<np;i++) scanf("%d",&p[i]);
	sort(c,c+nc);
	sort(p,p+np);
	i=0;
	j=0;
	while(p[i]<0){
		if(c[j]<0){
			sum+=p[i]*c[j];
			j++;
		}
		i++;
		if(i==np){
			printf("%d",sum);
			return 0;
		};
	} 
	if(i<np){
		if(p[i]==0) i++;
		if(i==np){
			printf("%d",sum);
			return 0;
		};
		while(c[j]<=0){
			j++;
			if(j==nc){
				printf("%d",sum);
				return 0;
			};
		}
		x=nc-1;
		for(k=np-1;k>=i;k--){
			sum+=p[k]*c[x];
			x--;
			if(x==j) break;
		}
	}
	printf("%d",sum);
	return 0;
} 
