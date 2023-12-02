#include<iostream>
#include<vector>
#include<math.h>
#define ll long long
using namespace std;

int main() {
 int x; cin >> x;
 ll a = 1, b = 1;
 for (int tmp = 0; tmp < x-1; tmp++) {
  if (pow(a, 2) < pow(b, 3)) {
   a++;
  } else if (pow(a, 2) > pow(b, 3)) {
   b++;
  } else if (pow(a, 2) == pow(b, 3)) {
   a++; b++;
  }
 }
 cout << (ll)min(pow(a, 2), pow(b, 3)) << "\n";
 return 0;
}
