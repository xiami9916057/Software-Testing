// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.


#include "triangle.h"
#include "gtest/gtest.h"
#include <string>

using namespace std;

// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.




TEST(TriangleTest, MCDC){
	
	//                    | 1 2 3 4 5 6 7 8                                    
	//c1:a<b+c?           | T T T T F F F F     
	//c2:b<a+c?           | T T F F T T F F
	//c3:c<a+b?           | T F T F T F T F

	//if ( c1 & c2 & c3 )
	//   c1 c2 c3  Outcome
	// 1  T  T  T     T
	// 2  T  T  F     F
        // 3  T  F  T     F
	// 5  F  T  T     F

	/* 01 */EXPECT_STREQ("Isosceles",Triangle(10,10,15).c_str());
	/* 02 */EXPECT_STREQ("Not a Triangle",Triangle(10,10,20).c_str());
	/* 03 */EXPECT_STREQ("Not a Triangle",Triangle(10,20,10).c_str());
	/* 05 */EXPECT_STREQ("Not a Triangle",Triangle(20,10,10).c_str());


	//                    | 1 2 3 4
	//c4:a==b?            | T T F F
	//c5:b==c?            | T F T F
    
	//if (c4 & c5) =>isEquilateralTriangle?
	//   c4 c5  Outcome
	// 1  T  T     T
	// 4  F  F     F

	/* 01 */EXPECT_STREQ("Equilateral",Triangle(10,10,10).c_str());
	/* 04 */EXPECT_STREQ("Scalene",Triangle(10,15,20).c_str());


	//                    | 1 2 3 4 5 6 7 8 
	//c6:a!=b?            | T T T T F F F F 
	//c7:a!=c?            | T T F F T T F F
	//c8:b!=c?            | T F T F T F T F

	//if ( c6 & c7 & c8 ) => isScaleneTriangle?
	//   c6 c7 c8  Outcome
	// 1  T  T  T     T
	// 2  T  T  F     F
        // 3  T  F  T     F
	// 5  F  T  T     F	
	
	
	/* 01 */EXPECT_STREQ("Scalene",Triangle(10,15,20).c_str());
	/* 02 */EXPECT_STREQ("Isosceles",Triangle(15,10,10).c_str());
	/* 03 */EXPECT_STREQ("Isosceles",Triangle(10,15,10).c_str());
	/* 05 */EXPECT_STREQ("Isosceles",Triangle(10,10,15).c_str());
		
	
} 




// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?

