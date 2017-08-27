#include<cstdio>

int n1[1000010],n2[1000010],n[2000010];

int main(){
	int i,N1,N2,l1=0,l2=0;
	scanf("%d",&N1);
	for(i=0;i<N1;i++) scanf("%d",&n1[i]);
	scanf("%d",&N2);
	for(i=0;i<N2;i++) scanf("%d",&n2[i]);
	i=0;
	while(l1<N1||l2<N2){
		if(l1==N1){
			n[i]=n2[l2++];
		}
		else if(l2==N2){
			n[i]=n1[l1++];
		}
		else if(n1[l1]<n2[l2]){
			n[i]=n1[l1++];
		}
		else{
			n[i]=n2[l2++];
		}
		if(i==(N1+N2+1)/2-1) break;
		i++;
	}
	printf("%d",n[i]);
	return 0;
}
