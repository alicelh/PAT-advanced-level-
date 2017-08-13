#include<iostream>
#include<cstring>

using namespace std;

char a[65],b[66],c[65],d[65];
string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

bool Isletter(char s){
	int tmp1=s-'a';
	int tmp2=s-'A';
	if((tmp1>=0&&tmp1<26)||(tmp2>=0&&tmp2<26)) return true;
	return false;
}

bool Ishour(char s){
	int tmp1=s-'0';
	int tmp2=s-'A';
	if((tmp1>=0&&tmp1<10)||(tmp2>=0&&tmp2<14)) return true;
	return false;
}

int main(){
	int i,tmp,flag=0;
	int min1,min2;
	
	cin>>a>>b>>c>>d;
	min1=strlen(a)<strlen(b)?strlen(a):strlen(b);
	min2=strlen(c)<strlen(d)?strlen(c):strlen(d);	
	for(i=0;i<min1;i++){
		if(a[i]==b[i]){
			if(!flag){
				tmp=b[i]-'A'; //区分大小写，且要注意范围 0-6 
				if(tmp<0||tmp>6) continue;
				cout<<week[tmp]<<' ';
				flag=1;
			}
			else{
				if(!Ishour(a[i])) continue;
				if(a[i]-'0'<10){
					cout<<0<<a[i]-'0';
				}
				else{
					cout<<a[i]-'A'+10;
				}
				cout<<':';
				break;
			}	
		}
	}
	for(i=0;i<min2;i++){
		if(c[i]==d[i]){
			if(!Isletter(c[i])) continue;
			if(i<10) cout<<0<<i;
			else cout<<i;
		}
	}
	
	return 0;
} 
