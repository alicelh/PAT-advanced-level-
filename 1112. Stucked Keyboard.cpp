#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<char> key;
int stuck[50]={0};
int non[50]={0};//0-stucked 
int in[50]={0};
int hashn(char s){
	if(s>='0'&&s<='9'){
		return s-'0';
	}
	else if(s>='a'&&s<='z'){
		return s-'a'+10;
	}
	else return 36;
}
int main(){
	int k,flag,i;
	cin>>k;
	string a;
	cin>>a;
	char tmp;
	int len=a.length();
	for(i=0;i<len;i++){
		tmp=a[i];
		flag=1;
		for(int j=1;j<k;j++){
			if(a[i+j]!=tmp){
				flag=0;
				non[hashn(tmp)]=1;
			}
		}
		if(flag&&non[hashn(tmp)]==0){
			stuck[hashn(tmp)]=1;
			if(!in[hashn(tmp)]){
				key.push_back(tmp);
				in[hashn(tmp)]=1;
			}
			i+=k-1;
		}
	}
	for(i=0;i<=36;i++){
		if(non[i]) stuck[i]=0;
	}
	for(i=0;i<key.size();i++){
		if(non[hashn(key[i])]==0) printf("%c",key[i]);
	}
	printf("\n");
	for(i=0;i<len;i++){
		printf("%c",a[i]);
		if(stuck[hashn(a[i])]){
			i+=k-1;
		}
	}
	return 0;
}
