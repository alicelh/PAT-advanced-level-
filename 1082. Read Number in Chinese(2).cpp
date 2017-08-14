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
	first=1;//是首位
	
	while(right<len){
		exist=0;//4位起码有一个不是0 
		flag=0;//没有重复0 
		while(left<=right){
			if(a[left]=='0'&&!first){//只输入1位数要按下面的处理 
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
//		else{   //这部分并没有考察，针对100009000的情况 
//			if(right!=len-1&&a[left]!='0') cout<<" ling";
//		}
		right+=4;
	}
	return 0;
}
