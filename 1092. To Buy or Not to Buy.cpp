#include<iostream>
#include<cstring>

using namespace std;

int changetoint(char a){
	if(a>='0'&&a<='9') return a-'0';
	else if(a>='a'&&a<='z') return a-'a'+10;
	else return a-'A'+36;
}

int main(){
	int a[70]={0},b[70]={0};
	int miss=0,more=0;
	char tmp;
	int i,id;
	tmp=getchar();
	while(tmp!='\n'){
		id=changetoint(tmp);
		a[id]++;
		tmp=getchar();
	}
	tmp=getchar();
	while(tmp!='\n'){
		id=changetoint(tmp);
		b[id]++;
		tmp=getchar();
	} 
	for(i=0;i<=61;i++){
		if(a[i]<b[i]){
			miss+=b[i]-a[i];
		}
		else more+=a[i]-b[i];
	}
	if(miss>0)
		cout<<"No "<<miss;
	else 
		cout<<"Yes "<<more;
	return 0;
}
