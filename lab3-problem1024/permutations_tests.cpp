#include "permutations.cpp"
#include <gtest/gtest.h>
#include <time.h>


TEST(permutationTest, rightAns){
	int P5[] = {4, 1, 5, 2, 3};
	EXPECT_EQ(6, permutation(5, P5));

	int P7[] = { 4, 6, 7, 1, 5, 2, 3};
	EXPECT_EQ(2, permutation(7, P7));
	
	int P9[] = { 6, 9, 8, 7, 4, 1, 5, 2, 3};
	EXPECT_EQ(12, permutation(9, P9));

}


TEST(permutationElements, ZeroToThousand){
	int P5[] = {4, 1, 5, 2, 3};
	EXPECT_TRUE(sizeof(P5) <= 1000 && sizeof(P5) > 0);

	int P7[] = { 4, 6, 7, 1, 5, 2, 3};
	EXPECT_TRUE(sizeof(P7) <= 1000 && sizeof(P7) > 0);

	int P9[] = { 6, 9, 8, 7, 4, 1, 5, 2, 3};
	EXPECT_TRUE(sizeof(P9) <= 1000 && sizeof(P9) > 0);
}

TEST(permutationElements1, isArraySorted){
	int P5[] = {4, 1, 5, 2, 3};
	int P5_sorted[] = {1, 2, 3, 4, 5};
	ASSERT_FALSE(P5 == P5_sorted);

	int P7[] = {4, 6, 7, 1, 5, 2, 3};
	int P7_sorted[] = {1, 2, 3, 4, 5, 6, 7};
	ASSERT_FALSE(P7 == P7_sorted);

	int P9[] = {6, 9, 8, 7, 4, 1, 5, 2, 3};
	int P9_sorted[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	ASSERT_FALSE(P9 == P9_sorted);
}

TEST(permuationRunTime, checkRuntimeP5){

	clock_t start, end;
	start = clock();
	
	int P5[] = {4, 1, 5, 2, 3};
	permutation(5, P5);

	end = clock();
	double runtimeSEC = double(end-start)/CLOCKS_PER_SEC;

	ASSERT_TRUE(runtimeSEC <= 0.003);
}

TEST(permuationRunTime1, checkRuntimeP7){

	clock_t start, end;
	start = clock();
	
	int P7[] = {4, 6, 7, 1, 5, 2, 3};
	permutation(7, P7);

	end = clock();
	double runtimeSEC = double(end-start)/CLOCKS_PER_SEC;

	ASSERT_TRUE(runtimeSEC <= 0.003);
}

TEST(permuationRunTime2, checkRuntimeP9){

	clock_t start, end;
	start = clock();
	
	int P9[] = {6, 9, 8, 7, 4, 1, 5, 2, 3};
	permutation(9, P9);

	end = clock();
	double runtimeSEC = double(end-start)/CLOCKS_PER_SEC;

	ASSERT_TRUE(runtimeSEC <= 0.003);
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
