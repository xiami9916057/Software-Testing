
#include "nextdate.h"

#include <sstream>



bool IsLeapYear(int year){
  if(( (year%4)==0 && (year%100)!=0 )|| ((year%400) ==0)){
    return true;
  } else {
    return false;
  } 	
	
}



string NextDate(int month,int day,int year){

	int tomorrowDay=day,tomorrowMonth=month,tomorrowYear=year;

	string err[3] = {"Month is out of range.","Day is out of range.","Year is out of range."};
	string err_invalid("Invalid");
	string err_msg("");
	
	
	bool IsInvalid = false;
	
	bool c1= ((month>=1) && (month<=12));
	bool c2= ((day>=1) && (day<=31));
	bool c3= ((year>=1812) && (year<=2012));
	bool cond[3] = {c1,c2,c3};
	
	for (int i=0 ; i<3 ; i++){
		if(!cond[i]){
			IsInvalid = true;
			err_msg = err_msg + err[i];
		}
	}
	if (IsInvalid) return err_msg;
	
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			if(day < 31){
				tomorrowDay = day + 1;
			}else{
				tomorrowDay = 1;
				tomorrowMonth = month + 1;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(day < 30){
				tomorrowDay = day + 1;
			}else if(day == 30){
				tomorrowDay = 1;
				tomorrowMonth = month + 1;				
			}else{
				return err_invalid;
			}
			break;
		case 12:
			if(day < 31){
				tomorrowDay = day + 1;
			}else{
				tomorrowDay = 1;
				tomorrowMonth = 1;
				if(year == 2012){
					return err[2];
				}else{
					tomorrowYear = year + 1;
				}
			}
			break;
		case 2:
			if(day < 28){
				tomorrowDay = day + 1;
			}else if(day == 28){
				if(IsLeapYear(year)){
					tomorrowDay = 29;
				}else{
					tomorrowDay = 1;
					tomorrowMonth = 3;					
				}
			}else if(day == 29){
				if(IsLeapYear(year)){
					tomorrowDay = 1;
					tomorrowMonth = 3;					
				}else{
					return err_invalid;
				}				
			}else{
				return err_invalid;
			}
			break;
		default:
			break;
	}

	
	stringstream mm,dd,yy;
	string m,d,y;
	
	mm<<tomorrowMonth;
	dd<<tomorrowDay;
	yy<<tomorrowYear;	
	
	mm>>m;
	dd>>d;
	yy>>y;
	
	string dot(".");
	string tomorrowDate("");
	tomorrowDate = y+dot+m+dot+d;
	
	return tomorrowDate;
	
}



