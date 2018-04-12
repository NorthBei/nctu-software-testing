#include <limits.h>
#include "next_date.h"
#include "gtest/gtest.h"
namespace {
	TEST(BoundaryValueTest, WorstCase) {
		// This test is named "WorstCase", and belongs to the "BoundaryValueTest" , but just select a part of worst case
		// test case.
		EXPECT_EQ("1,2,1812", getNextDate(1,1,1812));
		EXPECT_EQ("1,2,1813", getNextDate(1,1,1813));
		EXPECT_EQ("1,2,1912", getNextDate(1,1,1912));
		EXPECT_EQ("1,2,2011", getNextDate(1,1,2011));
		EXPECT_EQ("1,2,2012", getNextDate(1,1,2012));

		EXPECT_EQ("1,3,1812", getNextDate(1,2,1812));
		EXPECT_EQ("1,3,1813", getNextDate(1,2,1813));
		EXPECT_EQ("1,3,1912", getNextDate(1,2,1912));
		EXPECT_EQ("1,3,2011", getNextDate(1,2,2011));
		EXPECT_EQ("1,3,2012", getNextDate(1,2,2012));

		EXPECT_EQ("1,15,1812", getNextDate(1,16,1812));
		EXPECT_EQ("1,16,1813", getNextDate(1,15,1813));
		EXPECT_EQ("1,16,1813", getNextDate(1,15,1912));
		EXPECT_EQ("1,16,2011", getNextDate(1,15,2011));
		EXPECT_EQ("1,16,2012", getNextDate(1,15,2012));

		EXPECT_EQ("1,31,1812", getNextDate(1,30,1812));
		EXPECT_EQ("1,31,1813", getNextDate(1,30,1813));
		EXPECT_EQ("1,31,1912", getNextDate(1,30,1912));
		EXPECT_EQ("1,31,2011", getNextDate(1,30,2011));
		EXPECT_EQ("1,31,2012", getNextDate(1,30,2012));

		EXPECT_EQ("2,1,1813", getNextDate(1,31,1813));
		EXPECT_EQ("2,1,1912", getNextDate(1,31,1912));
	}

	TEST(EquivalenceClassTesting, WeakNormal) {
		// This test is named "WeakNormal", and belongs to the "EquivalenceClassTesting"
		// test case.
		EXPECT_EQ("6,15,2000", getNextDate(6,14,2000));
		EXPECT_EQ("7,30,1996", getNextDate(7,29,1996));
		EXPECT_EQ("Invalid input date", getNextDate(2,30,2002));
		EXPECT_EQ("Invalid input date", getNextDate(6,31,2000));
	}

	TEST(EquivalenceClassTesting, WeakRobust) {
		// This test is named "WeakRobust", and belongs to the "EquivalenceClassTesting"
		// test case.
		EXPECT_EQ("6,15,1912", getNextDate(6,16,1912));
		EXPECT_EQ("Invalid input date", getNextDate(-1,15,1912));
		EXPECT_EQ("Invalid input date", getNextDate(13,15,1912));
		EXPECT_EQ("Invalid input date", getNextDate(6,-1,1912));
		EXPECT_EQ("Invalid input date", getNextDate(6,32,1912));
		EXPECT_EQ("Invalid input date", getNextDate(6,15,1811));
		EXPECT_EQ("Invalid input date", getNextDate(6,15,2013));
	}

	TEST(EquivalenceClassTesting, StrongNormal) {
		// This test is named "StrongNormal", and belongs to the "EquivalenceClassTesting"
		// test case.
		EXPECT_EQ("6,15,2000", getNextDate(6,14,2000));
		EXPECT_EQ("6,15,1996", getNextDate(6,14,1996));
		EXPECT_EQ("6,15,2002", getNextDate(6,14,2002));

		EXPECT_EQ("6,30,2000", getNextDate(6,29,2000));
		EXPECT_EQ("6,30,1996", getNextDate(6,29,1996));
		EXPECT_EQ("6,30,2002", getNextDate(6,29,2002));

		EXPECT_EQ("7,1,2000", getNextDate(6,30,2000));
		EXPECT_EQ("7,1,1996", getNextDate(6,30,1996));

		EXPECT_EQ("Invalid input date", getNextDate(6,30,2002));
		EXPECT_EQ("Invalid input date", getNextDate(6,30,2000));
		EXPECT_EQ("Invalid input date", getNextDate(6,31,1996));
		EXPECT_EQ("Invalid input date", getNextDate(6,31,2002));

		EXPECT_EQ("7,15,2000", getNextDate(7,14,2000));
		EXPECT_EQ("7,15,1996", getNextDate(7,14,1996));
		EXPECT_EQ("7,15,2002", getNextDate(7,14,2002));

		EXPECT_EQ("7,30,2000", getNextDate(7,29,2000));
		EXPECT_EQ("7,30,1996", getNextDate(7,29,1996));
		EXPECT_EQ("7,30,2002", getNextDate(7,29,2002));

		EXPECT_EQ("7,31,2000", getNextDate(7,30,2000));
		EXPECT_EQ("7,31,1996", getNextDate(7,30,1996));
	}

	TEST(EquivalenceClassTesting, StrongRobust) {
		// This test is named "StrongRobust", and belongs to the "EquivalenceClassTesting"
		// test case.
		EXPECT_EQ("Invalid input date", getNextDate(-1,15,1912));
		EXPECT_EQ("Invalid input date", getNextDate(6,-1,1912));
		EXPECT_EQ("Invalid input date", getNextDate(6,15,1811));

		EXPECT_EQ("Invalid input date", getNextDate(-1,-1,1912));
		EXPECT_EQ("Invalid input date", getNextDate(6,-1,1811));
		EXPECT_EQ("Invalid input date", getNextDate(-1,15,1811));
		EXPECT_EQ("Invalid input date", getNextDate(-1,-1,1811));
	}

	TEST(EdgeValueTesting, Test){
		// This test is named "Test", and belongs to the "EdgeValueTesting"
		// test case.
		EXPECT_EQ("3,1,1900", getNextDate(2, 28, 1900));
	    EXPECT_EQ("Invalid input date", getNextDate(2, 29, 2001));
	    EXPECT_EQ("Invalid input date", getNextDate(2, 30, 2001));
	    EXPECT_EQ("Invalid input date", getNextDate(6, 31, 2001));
	    EXPECT_EQ("Invalid input date", getNextDate(2, 29, 1900));
	    EXPECT_EQ("Invalid input date", getNextDate(2, 30, 1900));
	}
	
	TEST(DecisionTableTesting, Test) {
		// This test is named "Test", and belongs to the "DecisionTableTesting"
		// test case.
		EXPECT_EQ("4,16,2001", getNextDate(4,15,2001));
		EXPECT_EQ("5,1,2001", getNextDate(4,30,2001));
		EXPECT_EQ("Invalid input date", getNextDate(4,31,2001));
		EXPECT_EQ("1,16,2001", getNextDate(1,15,2001));
		EXPECT_EQ("2,1,2001", getNextDate(1,31,2001));

		EXPECT_EQ("2,1,2001", getNextDate(1,31,2001));
		EXPECT_EQ("12,16,2001", getNextDate(12,15,2001));
		EXPECT_EQ("1,1,2002", getNextDate(12,31,2001));
		EXPECT_EQ("2,16,2001", getNextDate(2,15,2001));
		EXPECT_EQ("2,29,2004", getNextDate(2,28,2004));
		EXPECT_EQ("3,1,2001", getNextDate(2,28,2001));
		EXPECT_EQ("Invalid input date", getNextDate(2,29,2001));
		EXPECT_EQ("Invalid input date", getNextDate(2,30,2001));

	}
}