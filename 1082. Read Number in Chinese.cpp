#include<iostream>
#include<cstring>

using namespace std;

string n[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string wei[5]={"","","Shi","Bai","Qian"};

int main(){
	char a[12];
	int len,i,j,num=0,ind=0,flag=1,flag2=1;
	cin>>a;
	len=strlen(a);
	
	if(a[0]=='-'){
		cout<<"Fu ";
		len-=1;
		num++;
	}
	if(len==9){
		cout<<n[a[num++]-'0']<<" Yi";
		ind++;
	}
	if(len>4){
		while(len-ind>=5){
			while(a[num]=='0'&&len-ind>=5){
				if(flag&&(a[num+1]-'0')&&ind+1<len){
					if(len-ind==5&&!flag2) break;
					cout<<" ling";
					flag=0;
				}
				ind++;
				num++;
			}
			flag=1;
			if(len-ind>=5){
				if(ind!=0&&(a[num]-'0')!=0) cout<<" ";
				if((a[num]-'0')!=0){
					cout<<n[a[num]-'0'];
					if(len-ind>=6) cout<<" "<<wei[len-ind-4];
					flag2=0;
				}
				ind++;
				num++;
			}	
		}
		if(!flag2)
		cout<<" Wan";
	}
	flag=1;
	while(len-ind>1){
		while(a[num]=='0'&&ind+1<len){
			if(flag&&ind+1<len&&(a[num+1]-'0')){
				cout<<" ling";
				flag=0;
			}
			ind++;
			num++;
		}
		flag=1;
		if(len-ind>1){
			if(ind!=0&&(a[num]-'0')!=0) cout<<" ";
			if((a[num]-'0')!=0) cout<<n[a[num]-'0']<<" "<<wei[len-ind];
			num++;
			ind++;
		}
	}
	if(len-ind==1){
		if(ind!=0&&(a[num]-'0')!=0) cout<<" ";
		if((a[num]-'0')!=0||len==1) cout<<n[a[num]-'0'];
		num++;
	}
	return 0;
} 
