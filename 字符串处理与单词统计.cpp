#include<bits/stdc++.h>
using namespace std;
int a[10005][2];
int main()
{
	string s;
	getline(cin,s);
	int j=1;
	for(int i=0;i<s.size();i++)
		if(s[i]==' '||s[i]=='.')
		{
			a[j][0]=i;
			a[j][1]=i-a[j-1][0]-(j!=1);
			j++;
		}
	for(int i=j;i>=1;i--)
		swap(a[i][0],a[i-1][0]);
	for(int i=1;i<=j;i++)
	{
		for(int k=1;k<j-i;k++)
		{
			if(a[k][1]>a[k+1][1])
			{
				swap(a[k][0],a[k+1][0]);
				swap(a[k][1],a[k+1][1]);
			}
		}
	}
	cout<<j-1<<' ';
	for(int i=a[j-1][0];i<a[j-1][0]+a[j-1][1];i++)
	{
		cout<<s[i];
	}
	cout<<' '<<a[j-1][1]<<endl;
	for(int i=1;i<=j;i++)
	{
		if(a[i][0]==0)
			a[i][0]=-1;
		for(int k=a[i][0]+1;k<=a[i][0]+a[i][1];k++)
		{
			cout<<s[k];
		}
		cout<<' ';
	}
	return 0;
}
