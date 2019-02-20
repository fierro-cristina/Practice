#include "pch.h"
#include "permutations.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <gtest/gtest.h>

using namespace std;

long long gcd(long long a, long long b) {
 while (a%b != 0) {
	 a = a % b;
	 swap(a, b);
 }
 return b;
}

int permutation(int N, int P[]) {
	if (N > 1000) {
		cout << "1 < N < 1000" << endl;
		return -1;
	}
	else if (N > 0 && N <= 1000) {
		for (int i = 0; i < N; i++) {
			//cin >> P[i];
			P[i]--;
		}
	}
	long long ans = 1;
	bool visited[1000];
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < N; ++i) {
		if (visited[i]) continue;

		int pos = i;
		int sz = 0;

		while (!visited[pos]) {
			visited[pos] = true;
			pos = P[pos];
			sz++;
		}
		ans = ans / gcd(ans, (long long)sz)*sz;
	}
	printf("%lld\n", ans);
}

TEST (TestName, subtest1) 
{
	ASSERT_TRUE(1 == 1);

}


int main(int argc, char* argv[]) {
	int P5[] = {4, 1, 5, 2, 3};
	int permutation1 = permutation(5, P5);//6

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	/*int P7[] = { 4, 6, 7, 1, 5, 2, 3 };
	permutation(7, P7); //2
	int P9[] = { 6, 9, 8, 7, 4, 1, 5, 2, 3 };
	permutation(9, P9); //12 */
}