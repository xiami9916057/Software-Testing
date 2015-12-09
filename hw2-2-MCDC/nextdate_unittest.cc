// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.


#include "nextdate.h"
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




TEST(NextDateTest, MCDC){

        //if(month==1,3,5,7,8,10 && day<31)
	//                        | 1 2 3 4                                 
	//c1:month==1,3,5,7,8,10? | T T F F 
	//c2:day<31?              | T F T F

	//if (c1 && c2)
	//   c1 c2  Outcome
	// 1  T  T     T
	// 4  F  F     F	
	
	/* 01 */EXPECT_STREQ("2010.1.16",NextDate(1,15,2010).c_str());
	/* 04 */EXPECT_STREQ("Invalid",NextDate(4,31,2010).c_str());

	
        
        //if(month==4,6,9,11 && day<30) 
	//                        | 1 2 3 4                                 
	//c3:month==4,6,9,11?     | T T F F 
	//c4:day<30?              | T F T F	
	
	//if (c3 && c4)
	//   c3 c4  Outcome
	// 1  T  T     T
	// 4  F  F     F	

	/* 01 */EXPECT_STREQ("2010.4.16",NextDate(4,15,2010).c_str());
	/* 04 */EXPECT_STREQ("2010.3.31",NextDate(3,30,2010).c_str());	
	
	
        //if(month==12 && day==31 && year==2012)
	//                     | 1 2 3 4 5 6 7 8                                    
	//c5:month==12?        | T T T T F F F F     
	//c6:day==31?          | T T F F T T F F
	//c7:year==2012?       | T F T F T F T F

	//if ( c5 && c6 && c7 )
	//   c5 c6 c7  Outcome
	// 1  T  T  T     T
	// 2  T  T  F     F
        // 3  T  F  T     F
	// 5  F  T  T     F		
		
	/* 01 */EXPECT_STREQ("Year is out of range.",NextDate(12,31,2012).c_str());
	/* 02 */EXPECT_STREQ("2011.1.1",NextDate(12,31,2010).c_str());
	/* 03 */EXPECT_STREQ("2012.12.16",NextDate(12,15,2012).c_str());
	/* 05 */EXPECT_STREQ("2012.2.1",NextDate(1,31,2012).c_str());
	
	
	//If(month==2 && day==28 && year % 4 == 0)
	//                     | 1 2 3 4 5 6 7 8                                    
	//c8:month==2?         | T T T T F F F F     
	//c9:day==28?          | T T F F T T F F
	//c10:year%4==0?       | T F T F T F T F

	//if ( c5 && c6 && c7 )
	//   c8 c9 c10  Outcome
	// 1  T  T   T     T
	// 2  T  T   F     F
        // 3  T  F   T     F
	// 5  F  T   T     F		

	/* 01 */EXPECT_STREQ("2012.2.29",NextDate(2,28,2012).c_str());
	/* 02 */EXPECT_STREQ("2010.3.1",NextDate(2,28,2010).c_str());
	/* 03 */EXPECT_STREQ("2012.2.16",NextDate(2,15,2012).c_str());
	/* 05 */EXPECT_STREQ("2012.4.29",NextDate(4,28,2012).c_str());				
	
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

