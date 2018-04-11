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
		//有一個條件是false，就不可能形成三角形
		return "Not a triangle";
	}

	if(a == b){
		if(b == c){
			return "Equilateral";		
		}
		return "Isosceles";
	}
	return "Scalene";
}