#include<iostream>
#include<cstring>

using namespace std;

/*���������׺*/

int main(){
	char str1[260],str2[260],str[260];
	int N,len1,len2,minlen,len=0;
	int i,j,n=0;
	cin>>N;    
	getchar();//������ĩβ�Ļ��з����յ� 
	gets(str1);//getsʶ���з�\n��Ϊ������� 
	gets(str2);
	len1=strlen(str1);
	len2=strlen(str2);
	j=len2-1;
	for(i=len1-1;i>=0;i--){//ǰ�����Ƚ� 
		if(j==-1) break;
		if(str1[i]==str2[j--]){
			str[n++]=str1[i];
		}
		else{
			break;
		}
	}
	len=strlen(str);
	for(i=0;i<N-2;i++){	
		gets(str1);
		n=strlen(str1);
		for(j=0;j<len;j++){
			if(n==0){
				str[j]='\0';
				break;
			}
			if(str[j]==str1[--n]){
				str[j]=str1[n];
			}
			else{
				str[j]='\0';
				break;
			}
		}
		len=strlen(str);
	} 
	
	if(!len) cout<<"nai";
	else 
		for(i=len-1;i>=0;i--)
			cout<<str[i]; 
		
	return 0;
}
