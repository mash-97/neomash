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
		int ii,j,k; //i is already used is index
		int flag = 0;
		for(int index = 0; index < n; index++)
		{
			bool biggerfound = false;
			bool smallerfound = false;
			ii = index;
			int big = ar[index]; 
			for (int i = index+1; i < n; ++i)
			{
				if( !biggerfound && ar[i] > big)
				{
					biggerfound = true;
					big = ar[i];
					j = i;
				}
				if(biggerfound)
				{
					if(ar[i] < big)
					{
						smallerfound = true;
						k = i;
						flag = 1;
						break;
					}
				}
			}
			if(flag == 1)
			{
				cout<<"YES"<<"\n"<<ii+1<<" "<<j+1<<" "<<k+1<<endl; break;
			}
		}
		if (flag == 0)
		{
			cout<<"NO"<<endl;
		}		
	}				
}	

// 
// 5 3 5 2 4