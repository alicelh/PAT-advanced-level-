#include<iostream>
#include<cstring>

using namespace std;

/*求最长公共后缀*/

int main(){
	char str1[260],str2[260],str[260];
	int N,len1,len2,minlen,len=0;
	int i,j,n=0;
	cin>>N;    
	getchar();//把整数末尾的换行符吸收掉 
	gets(str1);//gets识别换行符\n作为输入结束 
	gets(str2);
	len1=strlen(str1);
	len2=strlen(str2);
	j=len2-1;
	for(i=len1-1;i>=0;i--){//前两个比较 
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
