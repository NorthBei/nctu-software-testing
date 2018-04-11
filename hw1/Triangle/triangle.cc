#include "triangle.h"
#include <string>
#include<vector>

using namespace std; 

bool isRangeValid(int slide){
	//輸入的數值要在規範(1~200)內
	return (slide >= 1) && (slide <= 200) ? true : false;
}

bool isSlideValid(int a,int b,int c){
	return a<(b+c);
}

vector<string> isInputValid(int a,int b,int c){
	vector<string> array;

	if(!isRangeValid(a)){array.push_back("a");}
	if(!isRangeValid(b)){array.push_back("b");}
	if(!isRangeValid(c)){array.push_back("c");}

	return array;
}

string triangleType(int a,int b,int c){
	vector<string> list = isInputValid(a,b,c);
	if(!list.empty()){
		string slides;
		int size = list.size();
		for(int i = 0; i< size;i++){
			slides += (i == size-1 ? list[i] : list[i]+",");
		}
		return "Value of "+slides+" is not in he range of permitted values";
	}

	if(!isSlideValid(a,b,c) || !isSlideValid(b,a,c) || !isSlideValid(c,b,a)){
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