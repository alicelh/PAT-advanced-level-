#include<iostream>
#include<cstring>

using namespace std;

char num[10][6]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wei[5][7]={"Shi","Bai","Qian","Wan","Yi"};

int main(){
	int left,right,flag,len,first,exist;
	char a[15];
	cin>>a;
	len=strlen(a);
	
	left=0;
	right=len-1;
	if(a[0]=='-'){
		cout<<"Fu ";
		left+=1;
	}
	while(right>=left){
		right-=4;
	}
	right+=4;
	first=1;//����λ
	
	while(right<len){
		exist=0;//4λ������һ������0 
		flag=0;//û���ظ�0 
		while(left<=right){
			if(a[left]=='0'&&!first){//ֻ����1λ��Ҫ������Ĵ��� 
				flag=1;
			} 
			else{
				if(flag){
					cout<<" ling";
					flag=0;
				}
				if(first){
					first=0;
				}
				else{
					cout<<" ";
				}
				cout<<num[a[left]-'0'];	
				exist=1; 
				if(left!=right)
					cout<<" "<<wei[right-left-1];
			}
			left++;
		}
		if(exist){
			if(len-right==5) cout<<" "<<wei[3];
			if(len-right==9) cout<<" "<<wei[4];
		}
//		else{   //�ⲿ�ֲ�û�п��죬���100009000����� 
//			if(right!=len-1&&a[left]!='0') cout<<" ling";
//		}
		right+=4;
	}
	return 0;
}
