#include<cstdio>
#include<cstring>

int main() {
	int len,i,j;
	int point,e,exp,n=0;
	char a[20000];
	char b[20000];
	gets(a);
	len=strlen(a);

	b[n++]=a[0];
	for(i=1; i<len; i++) {
		if(a[i]=='.') point=i-1;
		if(a[i]=='E') {
			e=i;
			break;
		}
	}  
	sscanf(a+e+1,"%d",&exp);

	point+=exp;
	if(point<=0) {
		b[n++]='0';
		b[n++]='.';
		for(i=0; i<(-point); i++)
			b[n++]='0';
	}
	for(i=1; i<e; i++) {
		if(point+1==n)
			b[n++]='.';
		if(a[i]!='.')
			b[n++]=a[i];
	}
	if(point>=0) {
		for(i=0; i<point-e+2; i++)
			b[n++]='0';
	}
	b[n]='\0';

	if(b[0]=='+') printf("%s",&b[1]);
	else printf("%s",b);

	return 0;
}
