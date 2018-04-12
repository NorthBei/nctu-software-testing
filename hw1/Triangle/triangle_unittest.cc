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
		EXPECT_EQ("Equilateral", triangleType(100,100,100));

		EXPECT_EQ("Isosceles", triangleType(100,199,100));
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

	TEST(EquivalenceClassTesting, WeakNormal) {
		// This test is named "WeakNormal", and belongs to the "EquivalenceClassTesting"
		// test case.
		EXPECT_EQ("Equilateral", triangleType(5,5,5));
		EXPECT_EQ("Isosceles", triangleType(2,2,3));
		EXPECT_EQ("Scalene", triangleType(3,4,5));
		EXPECT_EQ("Not a triangle", triangleType(4,1,2));
	}

	TEST(EquivalenceClassTesting, WeakRobust) {
		// This test is named "WeakRobust", and belongs to the "EquivalenceClassTesting"
		// test case.
		EXPECT_EQ("Value of a is not in he range of permitted values", triangleType(-1,5,5));
		EXPECT_EQ("Value of b is not in he range of permitted values", triangleType(5,-1,5));
		EXPECT_EQ("Value of c is not in he range of permitted values", triangleType(5,5,-1));
		EXPECT_EQ("Value of a is not in he range of permitted values", triangleType(201,5,5));
		EXPECT_EQ("Value of b is not in he range of permitted values", triangleType(5,201,5));
		EXPECT_EQ("Value of c is not in he range of permitted values", triangleType(5,5,201));
	}

	TEST(EquivalenceClassTesting, StronRobust) {
		// This test is named "StronRobust", and belongs to the "EquivalenceClassTesting"
		// test case.
		EXPECT_EQ("Value of a is not in he range of permitted values", triangleType(-1,5,5));
		EXPECT_EQ("Value of b is not in he range of permitted values", triangleType(5,-1,5));
		EXPECT_EQ("Value of c is not in he range of permitted values", triangleType(5,5,-1));
		EXPECT_EQ("Value of a,b is not in he range of permitted values", triangleType(-1,-1,5));
		EXPECT_EQ("Value of b,c is not in he range of permitted values", triangleType(5,-1,-1));
		EXPECT_EQ("Value of a,c is not in he range of permitted values", triangleType(-1,5,-1));
		EXPECT_EQ("Value of a,b,c is not in he range of permitted values", triangleType(-1,-1,-1));
	}

	TEST(DecisionTableTesting, Test) {
		// This test is named "Test", and belongs to the "DecisionTableTesting"
		// test case.
		EXPECT_EQ("Not a triangle", triangleType(4,1,2));
		EXPECT_EQ("Not a triangle", triangleType(1,4,2));
		EXPECT_EQ("Not a triangle", triangleType(1,2,4));
		EXPECT_EQ("Equilateral", triangleType(5,5,5));
		EXPECT_EQ("Isosceles", triangleType(2,2,3));
		EXPECT_EQ("Isosceles", triangleType(2,3,2));
		EXPECT_EQ("Isosceles", triangleType(3,2,2));
		EXPECT_EQ("Scalene", triangleType(3,4,5));
	}
}