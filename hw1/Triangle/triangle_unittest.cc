#include <limits.h>
#include "triangle.h"
#include "gtest/gtest.h"
namespace {
	TEST(BoundaryValueTest, NormalCases) {
		// This test is named "NormalCases", and belongs to the "BoundaryValueTest"
		// test case.
		EXPECT_EQ("Isosceles", triangleType(100,100,1));
		EXPECT_EQ("Isosceles", triangleType(100,100,2));
		EXPECT_EQ("Equilateral", triangleType(100,100,100));
		EXPECT_EQ("Isosceles", triangleType(100,100,199));
		EXPECT_EQ("Not a triangle", triangleType(100,100,200));
		EXPECT_EQ("Isosceles", triangleType(100,1,100));
		EXPECT_EQ("Isosceles", triangleType(100,2,100));
		EXPECT_EQ("Isosceles", triangleType(100,100,100));
		EXPECT_EQ("Isosceles", triangleType(100,100,2));
		EXPECT_EQ("Equilateral", triangleType(100,100,2));

		EXPECT_EQ("Isosceles", triangleType(100,99,100));
		EXPECT_EQ("Not a triangle", triangleType(100,200,100));
		EXPECT_EQ("Isosceles", triangleType(1,100,100));
		EXPECT_EQ("Isosceles", triangleType(2,100,100));
		EXPECT_EQ("Equilateral", triangleType(100,100,100));
		EXPECT_EQ("Isosceles", triangleType(199,100,100));
		EXPECT_EQ("Not a triangle", triangleType(200,100,100));
	}

	TEST(BoundaryValueTest, WorstCase) {
		// This test is named "WorstCase", and belongs to the "BoundaryValueTest" , but just select a part of worst case
		// test case.
		EXPECT_EQ("Equilateral", triangleType(1,1,1));
		EXPECT_EQ("Not a triangle", triangleType(1,1,2));
		EXPECT_EQ("Not a triangle", triangleType(1,1,100));
		EXPECT_EQ("Not a triangle", triangleType(1,1,199));
		EXPECT_EQ("Not a triangle", triangleType(1,1,200));
		EXPECT_EQ("Not a triangle", triangleType(1,2,1));
		EXPECT_EQ("Isosceles", triangleType(1,2,2));
		EXPECT_EQ("Not a triangle", triangleType(1,2,100));
		EXPECT_EQ("Not a triangle", triangleType(1,2,199));
		EXPECT_EQ("Not a triangle", triangleType(1,2,200));
		//Not a triangle
		EXPECT_EQ("Not a triangle", triangleType(1,100,1));
		EXPECT_EQ("Not a triangle", triangleType(1,100,2));
		EXPECT_EQ("Isosceles", triangleType(1,100,100));
		EXPECT_EQ("Not a triangle", triangleType(1,100,199));
		EXPECT_EQ("Not a triangle", triangleType(1,100,200));
		EXPECT_EQ("Not a triangle", triangleType(1,199,1));
		EXPECT_EQ("Not a triangle", triangleType(1,199,2));
		EXPECT_EQ("Not a triangle", triangleType(1,199,100));
		EXPECT_EQ("Isosceles", triangleType(1,199,199));
		EXPECT_EQ("Not a triangle", triangleType(1,199,200));

		EXPECT_EQ("Not a triangle", triangleType(1,200,1));
		EXPECT_EQ("Not a triangle", triangleType(1,200,2));
		EXPECT_EQ("Not a triangle", triangleType(1,200,100));
		EXPECT_EQ("Not a triangle", triangleType(1,200,199));
		EXPECT_EQ("Isosceles", triangleType(1,200,200));
	}	
}