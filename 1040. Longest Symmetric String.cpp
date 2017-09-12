#include<cstdio>
#include<cstring>
char str[1010];
int dp[1010][1010];
int main(){
	int len,i,j,ans;
	gets(str);
	len=strlen(str);
	memset(dp,0,sizeof(int));
	ans=1;
	for(i=0;i<len;i++){
		dp[i][i]=1;
		if(i<len-1){
			if(str[i]==str[i+1]){
				dp[i][i+1]=1;
				ans=2;
			}
		} 
	}
	for(i=3;i<=len;i++){//最后要取到len的 
		for(j=0;j<len;j++){
			if(j+i-1<len){
				if(str[j]==str[j+i-1]){
					dp[j][j+i-1]=dp[j+1][j+i-2];
					if(dp[j][j+i-1]) ans=i;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
