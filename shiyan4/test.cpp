#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000+50;
int n,a[maxn],b[maxn];
int main(){
	int i;
	while(1){
		cin>>n;
		if(n==0)break;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++)cin>>b[i];
		sort(a+1,a+1+n);sort(b+1,b+1+n);
		int opt1=1,opt2=1,up1=n,up2=n,win=0,lose=0;
		while(up1>=opt1){
			if(a[up1]>b[up2])win++,up1--,up2--;
			else {
				if(a[opt1]>b[opt2])win++,opt1++,opt2++;
				else if(a[opt1]<b[up2])lose--,opt1++,up2--;
				else opt1++,up2--;
			}
		}
	//	cout<<win<<' '<<lose<<endl;
		cout<<win+lose<<endl;
	}
	return 0;
}
