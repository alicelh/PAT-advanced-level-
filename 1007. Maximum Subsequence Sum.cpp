#include<iostream>

using namespace std;

int K;
int a[10001];

//��tpmsum��ʱ�Ժͽ��и��£�һ��tmpsum<0��˵��ǰ��Ŀ������������Ŀ����ں����������¿�ʼ��tmpsum 

int main(){
	int sum=0;
	int tmpsum=0;
	int i,j;
	int front=0,rear=0,tmpfront=0,flag=0,tmp=0;
	cin>>K;
	for(i=0;i<K;i++){
		cin>>a[i];
	}
	
	for(i=0;i<K;i++){
		tmpsum+=a[i];
		if(tmpsum<0){
			tmpsum=0;
			tmpfront=i+1;
			flag=1;
		}
		else if(tmpsum>sum){
			rear=i;	
			sum=tmpsum;
			if(flag==1){
				front=tmpfront;
				flag=0;
			}
		}
		else if(tmpsum==sum&&sum==0&&tmp==0){//Ҫ����������и�����0����� 
			rear=i;
			front=i;
			tmp=1;
		}
	}
	
	if(sum==0&&!tmp)
		cout<<0<<" "<<a[0]<<" "<<a[K-1];
	else
		cout<<sum<<" "<<a[front]<<" "<<a[rear];
		
	return 0;
	
} 
