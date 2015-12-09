
#include "triangle.h"


string Triangle(int a,int b,int c){
	
	string str1("Isosceles");
	string str2("Equilateral");
	string str3("Not a Triangle");
	string str4("Scalene");
	
	string err[3] = {"Side a is invalid.","Side b is invalid.","Side c is invalid."};
	string err_msg("");

	int side[3] = {a,b,c};
	bool IsInvalid = false;
	
	for (int i=0 ; i<3 ; i++){
		if(side[i]<=0 || side[i]>200){
			IsInvalid = true;
			err_msg = err_msg + err[i];
		}
	}
	if (IsInvalid) return err_msg;
	
	if ((a < b+c) && (b < a+c) && (c < a+b)){
		if((a==b) && (b==c)){
			return str2;
		}else if((a!=b) && (a!=c) && (b!=c)) {
			return str4;
		}else {
			return str1;
		}
	}else {
		return str3;
	}
	
}



