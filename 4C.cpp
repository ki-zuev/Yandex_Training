#include <iostream> 
#include <string> 
#include <bitset> 
#include <vector>
#include <cmath>
using namespace std;

vector<int> bin(int n, long long int decnum)
{
	vector<int> binnum(n,0);
	int k=0;
	while(decnum!=0)
	{
		binnum[k++]=decnum%2;
		decnum=decnum/2;
	}
	return binnum;
}

int main() 
{ 
	int a;
	cin >> a;
	int n = a;
	vector<vector<int>> g(n);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cin >> a;
			g[i].push_back(a);
		}
	}

	vector<int> binnum;
	long long int p = pow(2,n)/2;
	int max0 = 0, max1 = 0;
	vector<int> ans;
	for (long long int i=1; i<p; i++)
	{
		binnum = bin(n, i);
		max0 = 0;
		for (int j=n-1; j>=0; j--)
		{
			if (binnum[j] == 0)
			{
				for (int k=n-1; k>=0; k--)
				{
					if (binnum[k] == 1)
					{
						max0 += g[n-1-j][n-1-k];
					}
				}
			}
		}
		if (max0 > max1)
		{
			max1 = max0;
			ans = binnum;
		}
	}

	cout << max1 << "\n";
	for (int i=n-1; i>=0; i--)
	{
		cout << ans[i]+1 << " ";
	}
	cout << "\n";

	return 0; 
}
