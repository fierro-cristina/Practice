#include "permutations.cpp"
#include <gtest/gtest.h>

TEST(permutationTest, rightAns){
	int P5[] = {4, 1, 5, 2, 3};
	EXPECT_EQ(6, permutation(5, P5));
	
	int P7[] = { 4, 6, 7, 1, 5, 2, 3};
	EXPECT_EQ(2, permutation(7, P7));
	
	int P9[] = { 6, 9, 8, 7, 4, 1, 5, 2, 3};
	EXPECT_EQ(12, permutation(9, P9));
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
