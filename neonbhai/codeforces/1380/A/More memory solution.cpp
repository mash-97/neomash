#include<iostream>
using namespace std;

int main()
{
	int T; cin>>T;
	while(T--)
	{
		int n; cin>>n;
		int ar[n];
		for(int i = 0; i<n; i++)
			cin>>ar[i];
		//so now we have the permutation in the array

		int left[n];
		int small = ar[0];
		for (int i = 0; i < n; ++i)
		{
			if(ar[i]<small)
				small = ar[i];
			left[i] = small;
		}
		
		int right[n];
		small = ar[n-1];
		for (int i = n-1; i >= 0; --i)
		{
			if (ar[i]<small)
				small = ar[i];
			right[i] = small;
		}

		for(int i = 0; i<n; i++)
			cout<<left[i];
		//now checking part
		int flag = 0;
		for (int i = 0; i < n; ++i)
		{
			if(ar[i] > left[i] && ar[i] < right[i])
			{
				flag = 1; cout<<"YES"<<endl;
				//now printing the indexes
				for (int x = 0; x < i; ++x)
				{
					if(ar[x] == left[i])
					{
						cout<<x+1; break;
					}
				}
				cout<<" "<<i+1<<" ";
				for (int x = i+1; x < n; ++x)
				{
					if(ar[x] == right[i])
					{
						cout<<x+1<<endl; break;
					}
				}
			}
		}
		if (flag == 0)
		{
			cout<<"NO"<<endl;
		}
	}
}