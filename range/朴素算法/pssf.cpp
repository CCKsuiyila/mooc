#include<iostream>
using namespace std;
int main(){
	int n;int m;int c[10];int d[10];int k=0;int v=0;int a;int b;
	cout<<"����Ҫ������ٸ���?"<<endl;
	cin>>n;
	cout<<"����Ҫ������ٸ�����?"<<endl;
	cin>>m;
	cout<<"������"<<n<<"����:";
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<m;i++){
		cout<<"����������:";
		cin>>a>>b;
		for(int j=0;j<n;j++){
			if(c[j]>=a&&c[j]<=b){
				d[v++]=c[j];
				k++;
			}
		}
		cout<<"������[a,b]����"<<k<<"����"<<endl;
		k=0;
	}
	return 0;
}
