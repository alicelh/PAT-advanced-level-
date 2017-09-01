#include<iostream>
#include<string>
/*要考虑的情况很多，容易不过的测试点包括（4 0000 0000.00）(4 00123.56 0001235)*/
using namespace std;
int main(){
	int N,i,j,pos1,pos2,l1,l2;
	string s1,s2;
	cin>>N>>s1>>s2;
	pos1=s1.length();
	pos2=s2.length();
	for(i=0;i<s1.length();i++){
		if(s1[0]=='0'){
			while(s1[1]=='0'){
				s1.erase(0,1);
			}
			if(s1[1]=='.'){
				s1.erase(0,2);
				pos1=0;
				j=0;
				while(s1[j]=='0'){
					pos1--;
					j++;
				}
				if(j>=s1.length()) pos1=0;
				s1.erase(0,j);
				break;
			}
			else s1.erase(0,1);
			pos1=s1.length();
		}
		if(s1[i]=='.'){
			pos1=i;
			s1.erase(i,1);
		}
	}
		
	for(i=0;i<s2.length();i++){
		if(s2[0]=='0'){
			while(s2[1]=='0'){
				s2.erase(0,1);
			}
			if(s2[1]=='.'){
				s2.erase(0,2);
				pos2=0;
				j=0;
				while(s2[j]=='0'){
					pos2--;
					j++;
				}
				if(j>=s2.length()) pos2=0;
				s2.erase(0,j);
				break;
			}
			else s2.erase(0,1);
			pos2=s2.length();
		}
		if(s2[i]=='.'){
			pos2=i;
			s2.erase(i,1);
		}
	}
	l1=s1.length();
	l2=s2.length();
	if(N>s1.length()){
		for(i=0;i<N-l1;i++){
			s1+='0';
		}
	}
	if(N>s2.length()){
		for(i=0;i<N-l2;i++){
			s2+='0';
		}
	}
	if(s1.substr(0,N)==s2.substr(0,N)&&pos1==pos2){
		cout<<"YES 0."<<s1.substr(0,N)<<"*10^"<<pos1;
	}
	else{
		cout<<"NO 0."<<s1.substr(0,N)<<"*10^"<<pos1<<" 0."<<s2.substr(0,N)<<"*10^"<<pos2;
	}
	return 0;
}
