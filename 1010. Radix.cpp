#include<iostream>
#include<cstring>

using namespace std;

int tag,radix;
char N[2][11];
long long n[2]={0};

long long fen(){
	int i,len,tmp,maxx=0;
	long long left,mid,right;
	len=strlen(N[2-tag]);
	for(i=0;i<len;i ++){
		if(N[2-tag][i]>='0'&&N[2-tag][i]<='9') tmp=N[2-tag][i]-'0';
		else tmp=N[2-tag][i]-'a'+10;
		if(tmp>maxx) maxx=tmp;
	}
	left=maxx+1;//�½�Ϊ����λ�������ļ�1 
	if(n[tag-1]>left) right=n[tag-1]+1;//�Ͻ�Ϊ�½��n[tag-1]��ļ�1 
	else right=left+1;
	while(left<=right){
		mid=(left+right)/2;
		n[2-tag]=0;
		for(i=0;i<len;i++){
			if(N[2-tag][i]>='0'&&N[2-tag][i]<='9') tmp=N[2-tag][i]-'0';
			else tmp=N[2-tag][i]-'a'+10;
			n[2-tag]=n[2-tag]*mid+tmp;
		}
		if(n[2-tag]==n[tag-1]) return mid;
		else if(n[2-tag]>n[tag-1]||n[2-tag]<0) right=mid-1;//δ֪���Ƶ�����ת��ʱ���ܻ���� 
		else left=mid+1;
	}
	return -1;
}

int main(){
	int i,tmp,len;
	long long result;
	cin>>N[0]>>N[1]>>tag>>radix;
	len=strlen(N[tag-1]);
	for(i=0;i<len;i++){//Ĭ����֪���Ƶ�ת��Ϊ10���Ʋ������ 
		if(N[tag-1][i]>='0'&&N[tag-1][i]<='9') tmp=N[tag-1][i]-'0';
		else tmp=N[tag-1][i]-'a'+10;
		n[tag-1]=n[tag-1]*radix+tmp;
	}
	result=fen();
	if(result==-1) cout<<"Impossible";
	else cout<<result;
	return 0;
} 
