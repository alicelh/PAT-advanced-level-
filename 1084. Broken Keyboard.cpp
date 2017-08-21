#include<iostream>
#include<cstring>

using namespace std;

int changetoid(char a){
	if(a>='0'&&a<='9') return a-'0';
	else if(a=='_') return 10;
	else if(a>='a'&&a<='z') return a-'a'+11;
	else return a-'A'+11;
}

int main(){
	char a[80],b[80];
	char tmp;
	int id,i;
	char num[80];
	char teststr1[80];
	char teststr2[80];
	memset(num,'#',sizeof(char));
	gets(teststr1);
	for(i=0;i<strlen(teststr1);i++){
		id=changetoid(teststr1[i]);
		num[id]=teststr1[i];
	}
	gets(teststr2);
	for(i=0;i<strlen(teststr2);i++){
		id=changetoid(teststr2[i]);
		num[id]='#';
	}
	for(i=0;i<strlen(teststr1);i++){
		id=changetoid(teststr1[i]);
		if(num[id]!='#'){
			if(num[id]>='a'&&num[id]<='z')
				num[id]=num[id]-'a'+'A';
			cout<<num[id];
			num[id]='#';
		}
	}
	return 0;
} 
