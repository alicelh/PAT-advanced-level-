#include<cstdio>
/*��Ҫ��min�����0���һ�����ڱ�λ�ϵ���������ÿ�ε�0λ������0��Ҫ��������ʱ���б�������������г�ʱ*/ 
int N,t[100000];

void swap(int* a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int main(){
	int i,num=0,count=0,tmp,min;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&t[i]);
		if(t[i]!=i&&i!=0){
			count++;//��ų�0λ��������û�й�λ����Ŀ 
		}
	}
	min=1; 
	while(count>0){
		for(i=min;i<N;i++){
			if(t[i]!=i){
				min=i;
				break;
			}
		}//�ҵ���0���һ�����ڱ�λ�ϵ��� 
		if(t[0]==0){//���0λ��Ϊ0�ͽ��� 
			if(count>1){
				t[0]=t[min]; 
				t[min]=0;
				num++;
			}
		}
		swap(&t[0],&t[t[0]]);
		num++;
		count--;
	}
	printf("%d",num);
	return 0;                                                                 
}
