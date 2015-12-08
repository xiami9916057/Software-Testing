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


TEST(TriangleTest, NormalBoundary) {

	//Upper bound = 200 , Lower bound = 1
	//Extreme boundary test values are {1,2,199,200}
	
	/* Case01 */EXPECT_STREQ("Isosceles",Triangle(100,100,1).c_str());  
	/* Case02 */EXPECT_STREQ("Isosceles",Triangle(100,100,2).c_str());
	/* Case03 */EXPECT_STREQ("Equilateral",Triangle(100,100,100).c_str());
	/* Case04 */EXPECT_STREQ("Isosceles",Triangle(100,100,199).c_str());
	/* Case05 */EXPECT_STREQ("Not a Triangle",Triangle(100,100,200).c_str());
	/* Case06 */EXPECT_STREQ("Isosceles",Triangle(100,1,100).c_str());
	/* Case07 */EXPECT_STREQ("Isosceles",Triangle(100,2,100).c_str());
	/* Case08 */EXPECT_STREQ("Equilateral",Triangle(100,100,100).c_str());	
	/* Case09 */EXPECT_STREQ("Isosceles",Triangle(100,199,100).c_str());
	/* Case10 */EXPECT_STREQ("Not a Triangle",Triangle(100,200,100).c_str());
	/* Case11 */EXPECT_STREQ("Isosceles",Triangle(1,100,100).c_str());
	/* Case12 */EXPECT_STREQ("Isosceles",Triangle(2,100,100).c_str());
	/* Case13 */EXPECT_STREQ("Equilateral",Triangle(100,100,100).c_str());	
	/* Case14 */EXPECT_STREQ("Isosceles",Triangle(199,100,100).c_str());
	/* Case15 */EXPECT_STREQ("Not a Triangle",Triangle(200,100,100).c_str());	
	
}

TEST(TriangleTest, WorstCaseBoundary) {
	
	//Upper bound = 200 , Lower bound = 1
	//Extreme boundary test values are {1,2,199,200}
	//More than one extreme boundary

	/* Case01 */EXPECT_STREQ("Equilateral",Triangle(1,1,1).c_str());  
	/* Case02 */EXPECT_STREQ("Not a Triangle",Triangle(1,1,2).c_str());
	/* Case03 */EXPECT_STREQ("Not a Triangle",Triangle(1,1,100).c_str());
	/* Case04 */EXPECT_STREQ("Not a Triangle",Triangle(1,1,199).c_str());
	/* Case05 */EXPECT_STREQ("Not a Triangle",Triangle(1,1,200).c_str());
	/* Case06 */EXPECT_STREQ("Not a Triangle",Triangle(1,2,1).c_str());
	/* Case07 */EXPECT_STREQ("Isosceles",Triangle(1,2,2).c_str());
	/* Case08 */EXPECT_STREQ("Not a Triangle",Triangle(1,2,100).c_str());	
	/* Case09 */EXPECT_STREQ("Not a Triangle",Triangle(1,2,199).c_str());
	/* Case10 */EXPECT_STREQ("Not a Triangle",Triangle(1,2,200).c_str());
	
	/* Case11 */EXPECT_STREQ("Not a Triangle",Triangle(1,100,1).c_str());
	/* Case12 */EXPECT_STREQ("Not a Triangle",Triangle(1,100,2).c_str());
	/* Case13 */EXPECT_STREQ("Isosceles",Triangle(1,100,100).c_str());	
	/* Case14 */EXPECT_STREQ("Not a Triangle",Triangle(1,100,199).c_str());
	/* Case15 */EXPECT_STREQ("Not a Triangle",Triangle(1,100,200).c_str());		
	/* Case16 */EXPECT_STREQ("Not a Triangle",Triangle(1,199,1).c_str());
	/* Case17 */EXPECT_STREQ("Not a Triangle",Triangle(1,199,2).c_str());
	/* Case18 */EXPECT_STREQ("Not a Triangle",Triangle(1,199,100).c_str());	
	/* Case19 */EXPECT_STREQ("Isosceles",Triangle(1,199,199).c_str());
	/* Case20 */EXPECT_STREQ("Not a Triangle",Triangle(1,199,200).c_str());
	
	/* Case21 */EXPECT_STREQ("Not a Triangle",Triangle(1,200,1).c_str());
	/* Case22 */EXPECT_STREQ("Not a Triangle",Triangle(1,200,2).c_str());
	/* Case23 */EXPECT_STREQ("Not a Triangle",Triangle(1,200,100).c_str());	
	/* Case24 */EXPECT_STREQ("Not a Triangle",Triangle(1,200,199).c_str());
	/* Case25 */EXPECT_STREQ("Isosceles",Triangle(1,200,200).c_str());		

}



TEST(TriangleTest, EquivalenceClass) {
	
	//Is it a Triangle?
	//D1 = {<a,b,c> : a>b+c }
	//D2 = {<a,b,c> : b>a+c }
	//D3 = {<a,b,c> : c>a+b }

	//Triangle Type
	//T1 = {<a,b,c> : a=b=c }
	//T2 = {<a,b,c> : a=b,a!=c }
	//T3 = {<a,b,c> : a=c,a!=b }
	//T4 = {<a,b,c> : b=c,a!=b }
	//T5 = {<a,b,c> : a!=b,a!=c,b!=c }
	
	//Robust test values are {-1,201}
	
	/* WN01=T1 */EXPECT_STREQ("Equilateral",Triangle(5,5,5).c_str());
	/* WN02=T2 */EXPECT_STREQ("Isosceles",Triangle(2,2,3).c_str());
	/* WN03=T5 */EXPECT_STREQ("Scalene",Triangle(3,4,5).c_str());
	/* WN04=D1 */EXPECT_STREQ("Not a Triangle",Triangle(4,1,2).c_str());
	
	/* WR01 */EXPECT_STREQ("Side a is invalid.",Triangle(-1,5,5).c_str());  
	/* WR02 */EXPECT_STREQ("Side b is invalid.",Triangle(5,-1,5).c_str());
	/* WR03 */EXPECT_STREQ("Side c is invalid.",Triangle(5,5,-1).c_str());
	/* WR04 */EXPECT_STREQ("Side a is invalid.",Triangle(201,5,5).c_str());	
	/* WR05 */EXPECT_STREQ("Side b is invalid.",Triangle(5,201,5).c_str());  
	/* WR06 */EXPECT_STREQ("Side c is invalid.",Triangle(5,5,201).c_str());
	
	/* SR01 */EXPECT_STREQ("Side a is invalid.",Triangle(-1,5,5).c_str()); 
	/* SR02 */EXPECT_STREQ("Side b is invalid.",Triangle(5,-1,5).c_str());
	/* SR03 */EXPECT_STREQ("Side c is invalid.",Triangle(5,5,-1).c_str());
	/* SR04 */EXPECT_STREQ("Side a is invalid.Side b is invalid.",Triangle(-1,-1,5).c_str()); 
	/* SR05 */EXPECT_STREQ("Side b is invalid.Side c is invalid.",Triangle(5,-1,-1).c_str()); 
	/* SR06 */EXPECT_STREQ("Side a is invalid.Side c is invalid.",Triangle(-1,5,-1).c_str());
	/* SR07 */EXPECT_STREQ("Side a is invalid.Side b is invalid.Side c is invalid.",Triangle(-1,-1,-1).c_str());	
	
}


TEST(TriangleTest, Edge) {
	
	//Normal test values are {1,2,49,50,51,149,150,151,199,200}
    //Robust test values are {0,201}

	//Is it a Triangle? {Boolean}
	//D1 = {<a,b,c> : a>b+c }
	//D2 = {<a,b,c> : b>a+c }
	//D3 = {<a,b,c> : c>a+b }

	//Triangle Type
	//T1 = {<a,b,c> : a=b=c }
	//T2 = {<a,b,c> : a=b,a!=c }
	//T3 = {<a,b,c> : a=c,a!=b }
	//T4 = {<a,b,c> : b=c,a!=b }
	//T5 = {<a,b,c> : a!=b,a!=c,b!=c }	
	
	/* WN01=T1 */EXPECT_STREQ("Equilateral",Triangle(50,50,50).c_str());
	/* WN02=D3 */EXPECT_STREQ("Not a Triangle",Triangle(1,49,50).c_str());
	/* WN03=T2 */EXPECT_STREQ("Isosceles",Triangle(150,150,1).c_str());
	/* WN04=T5 */EXPECT_STREQ("Scalene",Triangle(151,49,199).c_str());

	/* WR01 */EXPECT_STREQ("Side a is invalid.",Triangle(0,50,50).c_str());  
	/* WR02 */EXPECT_STREQ("Side b is invalid.",Triangle(50,0,50).c_str());
	/* WR03 */EXPECT_STREQ("Side c is invalid.",Triangle(50,50,0).c_str());
	/* WR04 */EXPECT_STREQ("Side a is invalid.",Triangle(201,50,50).c_str());	
	/* WR05 */EXPECT_STREQ("Side b is invalid.",Triangle(50,201,50).c_str());  
	/* WR06 */EXPECT_STREQ("Side c is invalid.",Triangle(50,50,201).c_str());
	
	/* SR01 */EXPECT_STREQ("Side a is invalid.Side b is invalid.",Triangle(0,0,150).c_str()); 
	/* SR02 */EXPECT_STREQ("Side b is invalid.Side c is invalid.",Triangle(150,0,0).c_str()); 
	/* SR03 */EXPECT_STREQ("Side a is invalid.Side c is invalid.",Triangle(0,150,0).c_str());
	/* SR04 */EXPECT_STREQ("Side a is invalid.Side b is invalid.Side c is invalid.",Triangle(201,201,201).c_str());	
}


TEST(TriangleTest, DecisionTable){
	
	//c1:a<b+c?          | F T T T T T T T T T T
	//c2:b<a+c?          | - F T T T T T T T T T
	//c3:c<a+b?          | - - F T T T T T T T T
	//c4:a=b?            | - - - T T T T F F F F
	//c5:a=c?            | - - - T T F F T T F F
	//c6:b=c?            | - - - T F T F T F T F
    //-------------------+-----------------------
	//a1:Not a Triangle  | X X X 
	//a2:Scalene         |                     X
	//a3:Isosceles       |             X   X X
	//a4:Equilateral     |       X
	//a5:Impossible      |         X X   X
	
	/* DT01 */EXPECT_STREQ("Not a Triangle",Triangle(4,1,2).c_str());  // c1=T,c2=T,c3=F
	/* DT02 */EXPECT_STREQ("Not a Triangle",Triangle(1,4,2).c_str());
	/* DT03 */EXPECT_STREQ("Not a Triangle",Triangle(1,2,4).c_str());
	/* DT04 */EXPECT_STREQ("Equilateral",Triangle(5,5,5).c_str());
	/* DT05   EXPECT_STREQ("Impossible",Triangle(?,?,?).c_str());*/
	/* DT06   EXPECT_STREQ("Impossible",Triangle(?,?,?).c_str());*/
	/* DT07 */EXPECT_STREQ("Isosceles",Triangle(2,2,3).c_str());
	/* DT08   EXPECT_STREQ("Impossible",Triangle(?,?,?).c_str());*/
	/* DT09 */EXPECT_STREQ("Isosceles",Triangle(2,3,2).c_str());
	/* DT10 */EXPECT_STREQ("Isosceles",Triangle(3,2,2).c_str());	
	/* DT11 */EXPECT_STREQ("Scalene",Triangle(3,4,5).c_str());		
	
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

