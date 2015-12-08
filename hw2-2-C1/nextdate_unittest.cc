// Homework2
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


TEST(NextDateTest, NormalBoundary) {
	
	//  month : Upper bound = 12 , Lower bound = 1
	//  Extreme boundary test values are {1,2,11,12}
	
	//  day   : Upper bound = 31 , Lower bound = 1
	//  Extreme boundary test values are {1,2,29,30,31}	
	
	//  year  : Upper bound = 2012 , Lower bound = 1812
	//  Extreme boundary test values are {1812,1813,2011,2012}	
	
	/* Case01 */EXPECT_STREQ("1812.1.2",NextDate(1,1,1812).c_str());  
	/* Case02 */EXPECT_STREQ("1813.1.2",NextDate(1,1,1813).c_str());
	/* Case03 */EXPECT_STREQ("1912.1.2",NextDate(1,1,1912).c_str());
	/* Case04 */EXPECT_STREQ("2011.1.2",NextDate(1,1,2011).c_str());
	/* Case05 */EXPECT_STREQ("2012.1.2",NextDate(1,1,2012).c_str());
	/* Case06 */EXPECT_STREQ("1812.1.3",NextDate(1,2,1812).c_str());  
	/* Case07 */EXPECT_STREQ("1813.1.3",NextDate(1,2,1813).c_str());
	/* Case08 */EXPECT_STREQ("1912.1.3",NextDate(1,2,1912).c_str());
	/* Case09 */EXPECT_STREQ("2011.1.3",NextDate(1,2,2011).c_str());
	/* Case10 */EXPECT_STREQ("2012.1.3",NextDate(1,2,2012).c_str());
	/* Case11 */EXPECT_STREQ("1812.1.16",NextDate(1,15,1812).c_str());  
	/* Case12 */EXPECT_STREQ("1813.1.16",NextDate(1,15,1813).c_str());
	/* Case13 */EXPECT_STREQ("1912.1.16",NextDate(1,15,1912).c_str());
	/* Case14 */EXPECT_STREQ("2011.1.16",NextDate(1,15,2011).c_str());
	/* Case15 */EXPECT_STREQ("2012.1.16",NextDate(1,15,2012).c_str());
	/* Case16 */EXPECT_STREQ("1812.1.31",NextDate(1,30,1812).c_str());  
	/* Case17 */EXPECT_STREQ("1813.1.31",NextDate(1,30,1813).c_str());
	/* Case18 */EXPECT_STREQ("1912.1.31",NextDate(1,30,1912).c_str());
	/* Case19 */EXPECT_STREQ("2011.1.31",NextDate(1,30,2011).c_str());
	/* Case20 */EXPECT_STREQ("2012.1.31",NextDate(1,30,2012).c_str());
	/* Case21 */EXPECT_STREQ("1812.2.1",NextDate(1,31,1812).c_str());  
	/* Case22 */EXPECT_STREQ("1813.2.1",NextDate(1,31,1813).c_str());
	/* Case23 */EXPECT_STREQ("1912.2.1",NextDate(1,31,1912).c_str());
	/* Case24 */EXPECT_STREQ("2011.2.1",NextDate(1,31,2011).c_str());
	/* Case25 */EXPECT_STREQ("2012.2.1",NextDate(1,31,2012).c_str());
	
}


TEST(NextDateTest, EquivalenceClass) {

	//Valid
	//M1 = {month : month has 30 days }
	//M2 = {month : month has 31 days }
	//M3 = {month : month is February }
	//D1 = {day : 1<=day<=28 }
	//D2 = {day : day=29 }
	//D3 = {day : day=30 }
	//D4 = {day : day=31 }
	//Y1 = {year : year=2000 }
	//Y2 = {year : year is a non-century leap year }
	//Y3 = {year : year is a common year }	
	
	//Invalid 
	//M4 = {month : month<1 }
	//M5 = {month : month>12 }
	//D5 = {day : day<1 }
	//D6 = {day : day>31 }
	//Y4 = {year : year<1812 }
	//Y5 = {year : year>2012 }	
	
	/* WN01=M1,D1,Y1 */EXPECT_STREQ("2000.6.15",NextDate(6,14,2000).c_str()); 
	/* WN02=M2,D2,Y2 */EXPECT_STREQ("1996.7.30",NextDate(7,29,1996).c_str()); 
	/* WN03=M3,D4,Y3 */EXPECT_STREQ("Invalid",NextDate(2,30,2002).c_str()); 
	/* WN04=M1,D4,Y1 */EXPECT_STREQ("Invalid",NextDate(6,31,2000).c_str()); 

	/* SN01=M1,D1,Y1 */EXPECT_STREQ("2000.6.15",NextDate(6,14,2000).c_str()); 
	/* SN02=M1,D1,Y2 */EXPECT_STREQ("1996.6.15",NextDate(6,14,1996).c_str()); 
	/* SN03=M1,D1,Y3 */EXPECT_STREQ("2002.6.15",NextDate(6,14,2002).c_str()); 
	/* SN04=M1,D2,Y1 */EXPECT_STREQ("2000.6.30",NextDate(6,29,2000).c_str()); 
	/* SN05=M1,D2,Y2 */EXPECT_STREQ("1996.6.30",NextDate(6,29,1996).c_str()); 
	/* SN06=M1,D2,Y3 */EXPECT_STREQ("2002.6.30",NextDate(6,29,2002).c_str());	
	/* SN07=M1,D3,Y1 */EXPECT_STREQ("2000.7.1",NextDate(6,30,2000).c_str()); 
	/* SN08=M1,D3,Y2 */EXPECT_STREQ("1996.7.1",NextDate(6,30,1996).c_str()); 
	/* SN09=M1,D3,Y3 */EXPECT_STREQ("2002.7.1",NextDate(6,30,2002).c_str());
	/* SN10=M1,D4,Y1 */EXPECT_STREQ("Invalid",NextDate(6,31,2000).c_str()); 
	/* SN11=M1,D4,Y2 */EXPECT_STREQ("Invalid",NextDate(6,31,1996).c_str()); 
	/* SN12=M1,D4,Y3 */EXPECT_STREQ("Invalid",NextDate(6,31,2002).c_str());
	
	/* SN13=M2,D1,Y1 */EXPECT_STREQ("2000.7.15",NextDate(7,14,2000).c_str()); 
	/* SN14=M2,D1,Y2 */EXPECT_STREQ("1996.7.15",NextDate(7,14,1996).c_str()); 
	/* SN15=M2,D1,Y3 */EXPECT_STREQ("2002.7.15",NextDate(7,14,2002).c_str()); 
	/* SN16=M2,D2,Y1 */EXPECT_STREQ("2000.7.30",NextDate(7,29,2000).c_str()); 
	/* SN17=M2,D2,Y2 */EXPECT_STREQ("1996.7.30",NextDate(7,29,1996).c_str()); 
	/* SN18=M2,D2,Y3 */EXPECT_STREQ("2002.7.30",NextDate(7,29,2002).c_str());	
	/* SN19=M2,D3,Y1 */EXPECT_STREQ("2000.7.31",NextDate(7,30,2000).c_str()); 
	/* SN20=M2,D3,Y2 */EXPECT_STREQ("1996.7.31",NextDate(7,30,1996).c_str()); 
	/* SN21=M2,D3,Y3 */EXPECT_STREQ("2002.7.31",NextDate(7,30,2002).c_str());
	/* SN22=M2,D4,Y1 */EXPECT_STREQ("2000.8.1",NextDate(7,31,2000).c_str()); 
	/* SN23=M2,D4,Y2 */EXPECT_STREQ("1996.8.1",NextDate(7,31,1996).c_str()); 
	/* SN24=M2,D4,Y3 */EXPECT_STREQ("2002.8.1",NextDate(7,31,2002).c_str());
	
	
	/* SN25=M3,D1,Y1 */EXPECT_STREQ("2000.2.15",NextDate(2,14,2000).c_str()); 
	/* SN26=M3,D1,Y2 */EXPECT_STREQ("1996.2.15",NextDate(2,14,1996).c_str()); 
	/* SN27=M3,D1,Y3 */EXPECT_STREQ("2002.2.15",NextDate(2,14,2002).c_str()); 
	/* SN28=M3,D2,Y1 */EXPECT_STREQ("2000.3.1",NextDate(2,29,2000).c_str()); 
	/* SN29=M3,D2,Y2 */EXPECT_STREQ("1996.3.1",NextDate(2,29,1996).c_str()); 
	/* SN30=M3,D2,Y3 */EXPECT_STREQ("Invalid",NextDate(2,29,2002).c_str());	
	/* SN31=M3,D3,Y1 */EXPECT_STREQ("Invalid",NextDate(2,30,2000).c_str()); 
	/* SN32=M3,D3,Y2 */EXPECT_STREQ("Invalid",NextDate(2,30,1996).c_str()); 
	/* SN33=M3,D3,Y3 */EXPECT_STREQ("Invalid",NextDate(2,30,2002).c_str());
	/* SN34=M3,D4,Y1 */EXPECT_STREQ("Invalid",NextDate(2,31,2000).c_str()); 
	/* SN35=M3,D4,Y2 */EXPECT_STREQ("Invalid",NextDate(2,31,1996).c_str()); 
	/* SN36=M3,D4,Y3 */EXPECT_STREQ("Invalid",NextDate(2,31,2002).c_str());



	
	/* WR01 */EXPECT_STREQ("1912.6.16",NextDate(6,15,1912).c_str());   
	/* WR02 */EXPECT_STREQ("Month is out of range.",NextDate(-1,15,1912).c_str()); 
	/* WR03 */EXPECT_STREQ("Month is out of range.",NextDate(13,15,1912).c_str()); 
	/* WR04 */EXPECT_STREQ("Day is out of range.",NextDate(6,-1,1912).c_str()); 
	/* WR05 */EXPECT_STREQ("Day is out of range.",NextDate(6,32,1912).c_str());  
	/* WR06 */EXPECT_STREQ("Year is out of range.",NextDate(6,15,1811).c_str()); 
	/* WR07 */EXPECT_STREQ("Year is out of range.",NextDate(6,15,2013).c_str()); 
	
	/* SR01 */EXPECT_STREQ("Month is out of range.",NextDate(-1,15,1912).c_str()); 
	/* SR02 */EXPECT_STREQ("Day is out of range.",NextDate(6,-1,1912).c_str()); 
	/* SR03 */EXPECT_STREQ("Year is out of range.",NextDate(6,15,1811).c_str()); 
	/* SR04 */EXPECT_STREQ("Month is out of range.Day is out of range.",NextDate(-1,-1,1912).c_str()); 
	/* SR05 */EXPECT_STREQ("Day is out of range.Year is out of range.",NextDate(6,-1,1811).c_str()); 
	/* SR06 */EXPECT_STREQ("Month is out of range.Year is out of range.",NextDate(-1,15,1811).c_str()); 
	/* SR07 */EXPECT_STREQ("Month is out of range.Day is out of range.Year is out of range.",NextDate(-1,-1,1811).c_str()); 
	
}

TEST(NextDateTest, Edge) {
	
	//  month : Upper bound = 12 , Lower bound = 1
	//  Normal test values are {1,2,5,6,11,12}
	//  Robust test values are {-1,13}

	
	//  day   : Upper bound = 31 , Lower bound = 1
	//  Normal test values are {1,2,15,16,29,30,31}	
	//  Robust test values are {-1,32}

	
	//  year  : Upper bound = 2012 , Lower bound = 1812
	//  Normal test values are {1812,1813,1912,1996,2000,2011,2012}		
	//  Robust test values are {1811,2013}	
	
	//Valid
	//M1 = {month : month has 30 days }
	//M2 = {month : month has 31 days }
	//M3 = {month : month is February }
	//D1 = {day : 1<=day<=27 }
	//D2 = {day : day=28 }
	//D3 = {day : day=29 }
	//D4 = {day : day=30 }
	//D5 = {day : day=31 }
	//Y1 = {year : year=2000 }
	//Y2 = {year : year is a non-century leap year }
	//Y3 = {year : year is a common year }	
	
	//Invalid 
	//M4 = {month : month<1 }
	//M5 = {month : month>12 }
	//D6 = {day : day<1 }
	//D7 = {day : day>31 }
	//Y4 = {year : year<1812 }
	//Y5 = {year : year>2012 }	
	
	/* WN01=M1,D1,Y1 */EXPECT_STREQ("2000.6.15",NextDate(6,14,2000).c_str()); 
	/* WN02=M2,D3,Y2 */EXPECT_STREQ("1996.7.30",NextDate(7,29,1996).c_str()); 
	/* WN03=M3,D4,Y3 */EXPECT_STREQ("Invalid",NextDate(2,30,2002).c_str()); 
	/* WN04=M1,D5,Y1 */EXPECT_STREQ("Invalid",NextDate(6,31,2000).c_str()); 

	/* SN01=M1,D1,Y1 */EXPECT_STREQ("2000.6.15",NextDate(6,14,2000).c_str()); 
	/* SN02=M1,D1,Y2 */EXPECT_STREQ("1996.6.15",NextDate(6,14,1996).c_str()); 
	/* SN03=M1,D1,Y3 */EXPECT_STREQ("2002.6.15",NextDate(6,14,2002).c_str()); 
	/* SN04=M1,D3,Y1 */EXPECT_STREQ("2000.6.30",NextDate(6,29,2000).c_str()); 
	/* SN05=M1,D3,Y2 */EXPECT_STREQ("1996.6.30",NextDate(6,29,1996).c_str()); 
	/* SN06=M1,D3,Y3 */EXPECT_STREQ("2002.6.30",NextDate(6,29,2002).c_str());	
	/* SN07=M1,D4,Y1 */EXPECT_STREQ("2000.7.1",NextDate(6,30,2000).c_str()); 
	/* SN08=M1,D4,Y2 */EXPECT_STREQ("1996.7.1",NextDate(6,30,1996).c_str()); 
	/* SN09=M1,D4,Y3 */EXPECT_STREQ("2002.7.1",NextDate(6,30,2002).c_str());
	/* SN10=M1,D5,Y1 */EXPECT_STREQ("Invalid",NextDate(6,31,2000).c_str()); 
	/* SN11=M1,D5,Y2 */EXPECT_STREQ("Invalid",NextDate(6,31,1996).c_str()); 
	/* SN12=M1,D5,Y3 */EXPECT_STREQ("Invalid",NextDate(6,31,2002).c_str());
	
	/* SN13=M2,D1,Y1 */EXPECT_STREQ("2000.7.15",NextDate(7,14,2000).c_str()); 
	/* SN14=M2,D1,Y2 */EXPECT_STREQ("1996.7.15",NextDate(7,14,1996).c_str()); 
	/* SN15=M2,D1,Y3 */EXPECT_STREQ("2002.7.15",NextDate(7,14,2002).c_str()); 
	/* SN16=M2,D3,Y1 */EXPECT_STREQ("2000.7.30",NextDate(7,29,2000).c_str()); 
	/* SN17=M2,D3,Y2 */EXPECT_STREQ("1996.7.30",NextDate(7,29,1996).c_str()); 
	/* SN18=M2,D3,Y3 */EXPECT_STREQ("2002.7.30",NextDate(7,29,2002).c_str());	
	/* SN19=M2,D4,Y1 */EXPECT_STREQ("2000.7.31",NextDate(7,30,2000).c_str()); 
	/* SN20=M2,D4,Y2 */EXPECT_STREQ("1996.7.31",NextDate(7,30,1996).c_str()); 
	/* SN21=M2,D4,Y3 */EXPECT_STREQ("2002.7.31",NextDate(7,30,2002).c_str());
	/* SN22=M2,D5,Y1 */EXPECT_STREQ("2000.8.1",NextDate(7,31,2000).c_str()); 
	/* SN23=M2,D5,Y2 */EXPECT_STREQ("1996.8.1",NextDate(7,31,1996).c_str()); 
	/* SN24=M2,D5,Y3 */EXPECT_STREQ("2002.8.1",NextDate(7,31,2002).c_str());
	
	
	/* SN25=M3,D1,Y1 */EXPECT_STREQ("2000.2.15",NextDate(2,14,2000).c_str()); 
	/* SN26=M3,D1,Y2 */EXPECT_STREQ("1996.2.15",NextDate(2,14,1996).c_str()); 
	/* SN27=M3,D1,Y3 */EXPECT_STREQ("2002.2.15",NextDate(2,14,2002).c_str()); 
	/* SN28=M3,D3,Y1 */EXPECT_STREQ("2000.3.1",NextDate(2,29,2000).c_str()); 
	/* SN29=M3,D3,Y2 */EXPECT_STREQ("1996.3.1",NextDate(2,29,1996).c_str()); 
	/* SN30=M3,D3,Y3 */EXPECT_STREQ("Invalid",NextDate(2,29,2002).c_str());	
	/* SN31=M3,D4,Y1 */EXPECT_STREQ("Invalid",NextDate(2,30,2000).c_str()); 
	/* SN32=M3,D4,Y2 */EXPECT_STREQ("Invalid",NextDate(2,30,1996).c_str()); 
	/* SN33=M3,D4,Y3 */EXPECT_STREQ("Invalid",NextDate(2,30,2002).c_str());
	/* SN34=M3,D5,Y1 */EXPECT_STREQ("Invalid",NextDate(2,31,2000).c_str()); 
	/* SN35=M3,D5,Y2 */EXPECT_STREQ("Invalid",NextDate(2,31,1996).c_str()); 
	/* SN36=M3,D5,Y3 */EXPECT_STREQ("Invalid",NextDate(2,31,2002).c_str());


	/* WR01 */EXPECT_STREQ("1912.6.16",NextDate(6,15,1912).c_str());   
	/* WR02 */EXPECT_STREQ("Month is out of range.",NextDate(-1,15,1912).c_str()); 
	/* WR03 */EXPECT_STREQ("Month is out of range.",NextDate(13,15,1912).c_str()); 
	/* WR04 */EXPECT_STREQ("Day is out of range.",NextDate(6,-1,1912).c_str()); 
	/* WR05 */EXPECT_STREQ("Day is out of range.",NextDate(6,32,1912).c_str());  
	/* WR06 */EXPECT_STREQ("Year is out of range.",NextDate(6,15,1811).c_str()); 
	/* WR07 */EXPECT_STREQ("Year is out of range.",NextDate(6,15,2013).c_str()); 
	
	/* SR01 */EXPECT_STREQ("Month is out of range.",NextDate(-1,15,1912).c_str()); 
	/* SR02 */EXPECT_STREQ("Day is out of range.",NextDate(6,-1,1912).c_str()); 
	/* SR03 */EXPECT_STREQ("Year is out of range.",NextDate(6,15,1811).c_str()); 
	/* SR04 */EXPECT_STREQ("Month is out of range.Day is out of range.",NextDate(-1,-1,1912).c_str()); 
	/* SR05 */EXPECT_STREQ("Day is out of range.Year is out of range.",NextDate(6,-1,1811).c_str()); 
	/* SR06 */EXPECT_STREQ("Month is out of range.Year is out of range.",NextDate(-1,15,1811).c_str()); 
	/* SR07 */EXPECT_STREQ("Month is out of range.Day is out of range.Year is out of range.",NextDate(-1,-1,1811).c_str()); 
	
}



TEST(NextDateTest, DecisionTable){


	//Valid
	//M1 = {month : month has 30 days }
	//M2 = {month : month has 31 days }
	//M3 = {month : month is February }
	//D1 = {day : 1<=day<=27 }
	//D2 = {day : day=28 }
	//D3 = {day : day=29 }
	//D4 = {day : day=30 }
	//D5 = {day : day=31 }
	//Y1 = {year : year is a leap year }
	//Y2 = {year : year is a common year }	
	
	//Invalid 
	//M4 = {month : month<1 }
	//M5 = {month : month>12 }
	//D6 = {day : day<1 }
	//D7 = {day : day>31 }
	//Y3 = {year : year<1812 }
	//Y4 = {year : year>2012 }	

    //Decision Table
	//                   | 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22
	//c1:Month in M1?    | M1 M1 M1 M1 M1 M2 M2 M2 M2 M2 M3 M3 M3 M3 M3 M4 M4 M4 M4 M4 M4 M4
	//c2:Month in M2?    | D1 D2 D3 D4 D5 D1 D2 D3 D4 D5 D1 D2 D3 D4 D5 D1 D2 D2 D3 D3 D4 D5 
	//c3:Month in M3?    | -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Y1 Y2 Y1 Y2 -- -- 
    //-------------------+------------------------------------------------------------------
	//a1:Impossible      |             X                                            X  X  X                    
	//a2:Day Increase    | X  X  X        X  X  X  X     X  X  X  X     X  X                                                             
	//a3:Day Reset       |          X                 X              X        X  X                                
	//a4:Month Increase  |          X                 X                       X  X                                
	//a5:Month Reset     |                                           X                                  
	//a6:Year Increase   |                                           X                                
	
	/* DT01~03 */EXPECT_STREQ("2001.4.16",NextDate(4,15,2001).c_str());
	/* DT04    */EXPECT_STREQ("2001.5.1",NextDate(4,30,2001).c_str());
	/* DT05    */EXPECT_STREQ("Invalid",NextDate(4,31,2001).c_str());
	/* DT06~09 */EXPECT_STREQ("2001.1.16",NextDate(1,15,2001).c_str());
	/* DT10    */EXPECT_STREQ("2001.2.1",NextDate(1,31,2001).c_str());
	/* DT11~14 */EXPECT_STREQ("2001.12.16",NextDate(12,15,2001).c_str());
	/* DT15    */EXPECT_STREQ("2002.1.1",NextDate(12,31,2001).c_str());
	/* DT16    */EXPECT_STREQ("2001.2.16",NextDate(2,15,2001).c_str());
	/* DT17    */EXPECT_STREQ("2004.2.29",NextDate(2,28,2004).c_str());
	/* DT18    */EXPECT_STREQ("2001.3.1",NextDate(2,28,2001).c_str());	
	/* DT19    */EXPECT_STREQ("2004.3.1",NextDate(2,29,2004).c_str());			
	/* DT20    */EXPECT_STREQ("Invalid",NextDate(2,29,2001).c_str());	
	/* DT21~22 */EXPECT_STREQ("Invalid",NextDate(2,30,2001).c_str());				
	
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

