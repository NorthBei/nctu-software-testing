#include "triangle.h"
#include <string>

using namespace std; 

bool isRangeValid(int slide){
	return (slide >= 1) && (slide <= 200) ? true : false;
}

bool isSlideValid(int a,int b,int c){
	return a<(b+c);
}

string triangleType(int a,int b,int c){

	if(!isRangeValid(a) || !isRangeValid(b) || !isRangeValid(c) || !isSlideValid(a,b,c) || !isSlideValid(b,a,c) || !isSlideValid(c,b,a)){
		//輸入的數值要在規範(1~200)內
		return "Not a triangle";
	}

	if(a == b || b == c || a == c){
		if(a == b && b == c){
			return "Equilateral";   
		}
		return "Isosceles";
	}
	
	return "Scalene";
}