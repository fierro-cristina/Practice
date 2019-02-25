#include "permutations.cpp"
#include <gtest/gtest.h>
#include <time.h>

int P5[] = {4, 1, 5, 2, 3};
int P7[] = { 4, 6, 7, 1, 5, 2, 3};
int P9[] = { 6, 9, 8, 7, 4, 1, 5, 2, 3};

TEST(permutation, rightAns){
	EXPECT_EQ(6, permutation(5, P5));
	EXPECT_EQ(2, permutation(7, P7));
	EXPECT_EQ(12, permutation(9, P9));
}


TEST(permutation, ElementsZeroToThousand){
	EXPECT_TRUE(sizeof(P5) <= 1000 && sizeof(P5) > 0);
	EXPECT_TRUE(sizeof(P7) <= 1000 && sizeof(P7) > 0);
	EXPECT_TRUE(sizeof(P9) <= 1000 && sizeof(P9) > 0);
}

/*According to the mathematical rules, if the input permutation is sorted the order of its permutation will be equals to 1
theta = sorted permuation; theta^1, where theta is elevated to the k order will give the right answer. 
When the input permutation is not sorted, the order k will be bigger than 1*/

TEST(permutation, arrayNotSorted){
	EXPECT_TRUE(permutation(5, P5) > 1);
	EXPECT_TRUE(permutation(7, P7) > 1);
	EXPECT_TRUE(permutation(9, P9) > 1);
}

TEST(permutation, checkRuntime){

	clock_t startP5, startP7, startP9, endP5,endP7, endP9;
	startP5 = clock();
	permutation(5, P5);
	endP5 = clock();
	double runtimeSEC_P5 = double(endP5-startP5)/CLOCKS_PER_SEC;
	
	startP7 = clock();
	permutation(7, P7);
	endP7 = clock();
	double runtimeSEC_P7 = double(endP7-startP7)/CLOCKS_PER_SEC;

	startP9 = clock();
	permutation(9, P9);
	endP9 = clock();
	double runtimeSEC_P9 = double(endP9-startP9)/CLOCKS_PER_SEC;

	EXPECT_TRUE(runtimeSEC_P5 <= 0.003 && runtimeSEC_P7 <= 0.003 && runtimeSEC_P9 <= 0.003);
}

TEST(gcd, gcdNotZero){
	EXPECT_TRUE(permutation(5, P5) > 0 
		 && permutation(7, P7) > 0
		 && permutation(9, P9) > 0);
}

TEST(gcd, gcdRuntime){
	clock_t start, end;
	start = clock();
	gcd(100, 85);
	end = clock();
	double runtimeSEC = double(end-start)/CLOCKS_PER_SEC;
	EXPECT_TRUE(runtimeSEC <= 0.003);
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
