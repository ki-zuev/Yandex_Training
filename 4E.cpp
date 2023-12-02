#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int b(string s);
void gen_binary(int control, int n1, int n2, string prefix, int n3, int n4, int n5, int n6, int n);

void gen_binary(int control, int n1, int n2, string prefix, int n3, int n4, int n5, int n6, int n)
{
	if (n1 == 0 and n2 == 0 and n3 == n5 and n4==n6)
	{
		int a = b(prefix);
		if (a == 1)
		{
			cout << prefix << "\n";
		}
	}
	else
	{
		if (n1 > 0)
		{
			gen_binary(control + 1, n1 - 1, n2, prefix + '(', n3+1, n4, n5, n6, n);
			gen_binary(control + 1, n1 - 1, n2, prefix + '[', n3, n4+1, n5, n6, n);
		}
		if (control > 0 and n2 > 0)
		{
			if (prefix[prefix.size()-1] != '[' and n4+n6 != n-1)
			{
				if ((n3+n5 == n-2 and n6 == 1) or (n3+n4+n5+n6 == n-1 and (n4+n6)%2 == 1))
				{
					int q0 = 0;
				}
				else
				{
					gen_binary(control - 1, n1, n2 - 1, prefix + ')', n3, n4, n5+1, n6, n);
				}
			}
			if (prefix[prefix.size()-1] != '(' and n3+n5 != n-1)
			{
				if ((n4+n6 == n-2 and n5 == 1) or (n3+n4+n5+n6 == n-1 and (n3+n5)%2 == 1))
				{
					int q1 = 0;
				}
				else
				{
					gen_binary(control - 1, n1, n2 - 1, prefix + ']', n3, n4, n5, n6+1, n);
				}
			}
		}
	}
}

int b(string s)
{
	int ans = 1;
	string stack;
	for (int i=0; i<s.size(); i++)
	{
		if (stack.size() == 0)
		{
			if (s[i] != ']' and s[i] != ')')
			{
				stack.push_back(s[i]);
			}
			else
			{
				ans = 0;
				break;
			}
		}
			else
			{
				if (s[i] == ']' or s[i] == ')')
				{
					char k;
					if (s[i] == ']')
						k = '[';
					if (s[i] == ')')
						k = '(';
					if (k == stack[stack.size()-1])
					{
						stack.pop_back();
					}
					else
					{
						ans = 0;
						break;
					}
				}
				else
				{
					stack.push_back(s[i]);
				}
			}
	}
	if (ans == 1 and stack.size() == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	cin >> n;
	if (n%2 == 0)
	{
		string prefix;
		gen_binary(0, n/2, n/2, prefix, 0, 0, 0, 0, n);
	}
	return 0;
}
