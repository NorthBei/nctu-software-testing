#include "commission.h"
#include <sstream>
#include <string>

using namespace std; 

string calcCommission(int locks, int stocks, int barrels){
	const float LOCK_PRICE = 45.0f;
	const float STOCK_PRICE = 30.0f;
	const float BARREL_PRICE = 25.0f;

    float result;
    
    if(locks == -1)
        return "Program terminates";
    if( (locks < 1 || locks > 70) || (stocks < 1 || stocks > 80) || (barrels < 1 || barrels > 90))
        return "Invalid items' amount";

    float lockSales = locks*LOCK_PRICE;
    float stockSales = STOCK_PRICE * stocks;
    float barrelSales = BARREL_PRICE * barrels;
    float sales = lockSales + stockSales + barrelSales;

    if(sales > 1800.0){
        result = 0.10*1000.0 + 0.15*800.0 + 0.2*(sales - 1800.0);
    }
    else if(sales > 1000.0){
        result = 0.10*1000.0 + 0.15*(sales - 1000.0);
    }
    else{
        result = 0.10*sales;
    }
    
    stringstream ss;
	ss << result;
    return ss.str();
}