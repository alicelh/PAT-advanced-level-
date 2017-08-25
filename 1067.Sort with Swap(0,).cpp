#include<cstdio>
/*需要用min保存除0外第一个不在本位上的数而不是每次当0位置上是0需要交换交换时进行遍历，否则会运行超时*/ 
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
			count++;//存放除0位置外其他没有归位的数目 
		}
	}
	min=1; 
	while(count>0){
		for(i=min;i<N;i++){
			if(t[i]!=i){
				min=i;
				break;
			}
		}//找到除0外第一个不在本位上的数 
		if(t[0]==0){//如果0位置为0就交换 
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
