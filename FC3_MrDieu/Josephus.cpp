#include<bits/stdc++.h>
using namespace std;

int josephus(int N, int K) {
  if (N == 1)
    return 1;
  else
    return (josephus(N - 1, K) + K - 1) % N + 1;
}

int main()
{
	int n = 9;
	int k = 2;
	int kq = josephus(n, k);
	cout<<kq;
}