#include<iostream>
#include<string>
#include<map>

using namespace std;

bool isnum(char &a){
	if((a>='0'&&a<='9')||(a>='a'&&a<='z')) return true;
	else if(a>='A'&&a<='Z'){
		a=a-'A'+'a';
		return true;
	}
	return false;
}
map<string,int> n;
int main(){
	int len,i=0,front,rear,flag=0,max=0;
	string a;
	getline(cin,a);//因为以换行符作为结束，一个一个读的话无法判断结束标志 
	while(i<a.length()){
		if(isnum(a[i])){
			if(!flag){
				front=i;
				flag=1;
			}
		}
		else{
			if(flag){
				rear=i;
				if(n.find(a.substr(front,rear-front))!=n.end()) n[a.substr(front,rear-front)]++;
				else n[a.substr(front,rear-front)]=1;
				flag=0;
			}
		}
		i++;
	}
	if(flag){//最后一个以num结尾别忘了判断 
		rear=i;
		if(n.find(a.substr(front,rear-front))!=n.end()) n[a.substr(front,rear-front)]++;
		else n[a.substr(front,rear-front)]=1;
	}
	for(map<string,int>::iterator itr=n.begin();itr!=n.end();itr++){
		if(itr->second>max){
			max=itr->second;
			a=itr->first;
		}
	}
	cout<<a<<" "<<max;
	return 0;
}
