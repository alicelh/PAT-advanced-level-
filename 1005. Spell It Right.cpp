#include<iostream>

using namespace std;

char* number[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
char N[110]; //考虑到可输入位数，用char来存储N 
int result[110];
int main(){
	int i;
	int sum=0;
	cin>>N;
	
	for(i=0;N[i]!='\0';i++){
		sum+=N[i]-'0';
	}
	
	if(sum==0){//注意0的情况 
		cout<<number[0];
		return 0;
	}
	
	for(i=0;sum!=0;i++){
		result[i]=sum%10;
		sum=sum/10;
	}
	
	while(i-1){
		cout<<number[result[i-1]]<<" ";
		i--;
	}
	cout<<number[result[i-1]];
	return 0;
} 
