#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int N,tmpg;
	char gender,ID[2][11],name[2][11];
	char tmpname[11],tmpID[11];
	int grade[2]={-1,101};
	int i;
	
	cin>>N;
	for(i=0;i<N;i++){
		cin>>tmpname>>gender>>tmpID>>tmpg;
		if(gender=='M'){
			if(grade[0]==-1||(grade[0]!=-1&&tmpg<grade[0])){
				strcpy(name[0],tmpname);
				strcpy(ID[0],tmpID);
				grade[0]=tmpg;
			}	
		}
		else{
			if(grade[1]==101||(grade[1]!=101&&tmpg>grade[1])){
				strcpy(name[1],tmpname);
				strcpy(ID[1],tmpID);
				grade[1]=tmpg;
			}
		}
	}
	
	for(i=1;i>=0;i--){
		if(grade[i]==-1||grade[i]==101){
			cout<<"Absent"<<endl;
			continue;
		}
		cout<<name[i]<<" "<<ID[i]<<endl;
	}
	
	if(grade[0]==-1||grade[1]==101)
		cout<<"NA"<<endl;
	else
		cout<<grade[1]-grade[0]<<endl;
		
	return 0;
}
