#include<cstdio>
#include<vector>
#include<algorithm>
#include<vector>
using namespace std;
const int maxN=10010;
struct Node{
	int head; 
	int num;
	double m_estate;
	double area;
	int minnumber;
}n[maxN];
int N;
vector<int> root;
bool cmp(int a,int b){
	if(n[a].area/n[a].num!=n[b].area/n[b].num) return n[a].area/n[a].num>n[b].area/n[b].num;
	else return n[a].minnumber<n[b].minnumber;
}
int findroot(int id){
	if(n[id].head==-1) return -1;
	int head=id;
	while(head!=n[head].head){
		head=n[head].head;
	}
	while(id!=head){
		int z=n[id].head;
		n[id].head=head;
		id=z;
	}
	return head;
}
void combinetree(int a,int b){
	int faA=findroot(a);
	int faB=findroot(b);
	if(faA!=faB){
		if(faA==-1) n[a].head=faB;
		else n[faA].head=faB;
	}
	return;
}
int main(){
	int i,j,k,tmp,child,head;
	int father,mother;
	scanf("%d",&N);
	for(i=0;i<maxN;i++){
		n[i].head=-1;
		n[i].num=1;
		n[i].m_estate=0;
		n[i].area=0;
		n[i].minnumber=i; 
	}
	for(i=0;i<N;i++){
		scanf("%d",&tmp);
		head=findroot(tmp);
		if(head=-1){
			n[tmp].head=tmp;
			head=tmp;
		}
		scanf("%d%d",&father,&mother);
		if(father!=-1) combinetree(father,head);
		if(mother!=-1) combinetree(mother,head);
		scanf("%d",&k);
		for(j=0;j<k;j++){
			scanf("%d",&child);
			combinetree(child,head);
		}
		scanf("%lf%lf",&n[tmp].m_estate,&n[tmp].area);
	}
	for(i=0;i<maxN;i++){
		head=findroot(i);
		if(head!=-1){
			if(head==i){
				root.push_back(i);
			}
			else{
				if(i<n[head].minnumber) n[head].minnumber=i;
				n[head].num++;
				n[head].m_estate+=n[i].m_estate;
				n[head].area+=n[i].area;
			}
		}
	}
	sort(root.begin(),root.end(),cmp);
	printf("%d\n",root.size());
	for(i=0;i<root.size();i++){
		printf("%04d %d %.3f %.3f\n",n[root[i]].minnumber,n[root[i]].num,n[root[i]].m_estate/n[root[i]].num,n[root[i]].area/n[root[i]].num);
	}
}
