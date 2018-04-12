#include "next_date.h"
#include <string>
#include <sstream>

using namespace std; 

string getNextDate(int month,int day,int year){
	if( (month<1 || month>12) || (day<1 || day>31) || (year<1812 || year>2012) )
		return "Invalid input date";

	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
		if(month == 12 && day == 31){
			year+=1;
			month = 1;
			day =1;
		}
		else if(day == 31){
			month += 1;
			day=1;
		}
		else{
			day = day+1;
		}
	}
	else if(month == 2){
		if(day < 28)
            day+=1;
        else{
            if(day == 28){
                if(year % 4 == 0 && year != 1900)
                    day = 29;
                else{
                    month += 1;
                    day = 1;
                }    
            }
            else if(day == 29){
                if(year % 4 == 0 && year != 1900){
                    month += 1;
                    day = 1;
                }
                else
                    return "Invalid input date";
            }
            else
                return "Invalid input date";
        }    
	}
	else{
		//4,6,9,11
		if(day > 30)
            return "Invalid input date";

		if(day==30){
			month += 1;
			day=1;
		}
		else{
			day += 1;
		}
	}
	stringstream ss;
    
	ss << month << "," << day << "," << year;
	return ss.str();
}