#include<cstdio>
#include<string>

using namespace std;

int main(){
	int i,M,in=0,out=0;
	int hh,mm,ss;
	int minhh=24,minmm=60,minss=60;
	int maxhh=0,maxmm=0,maxss=0;
	scanf("%d",&M);
	string t1;//��char t1[15]������Щ 
	string t2;
	string tmp;
	t1.resize(15);//��scanf��ֵstringǰ��Ҫȷ����С 
	t2.resize(15);
	tmp.resize(15);
	
	for(i=0;i<M;i++){
		scanf("%s",&tmp[0]);
		scanf("%d:%d:%d",&hh,&mm,&ss);
		if(hh<minhh){
			minhh=hh;
			minmm=mm;
			minss=ss;
			t1=tmp;
		}
		else if(hh==minhh&&mm<minmm){
			minmm=mm;
			minss=ss;
			t1=tmp;
		}
		else if(hh==minhh&&mm==minmm&&ss<minss){
			minss=ss;
			t1=tmp;
		}
		scanf("%d:%d:%d",&hh,&mm,&ss);
		if(hh>maxhh){
			maxhh=hh;
			maxmm=mm;
			maxss=ss;
			t2=tmp;
		}
		else if(hh==maxhh&&mm>maxmm){
			maxmm=mm;
			maxss=ss;
			t2=tmp;
		}
		else if(hh==maxhh&&mm==maxmm&&ss>maxss){
			maxss=ss;
			t2=tmp;
		}
	}
	
	printf("%s %s",t1.c_str(),t2.c_str());
	return 0;
} 
