#ifndef TRADE_H
#define TRADE_H


#include "vector.h"
#include <iostream>
using std::cout;
using pep::vector;
using std::endl;


class Trade {
protected:
    int buyTime;
    int sellTime;

public:
    Trade(const int buyTimeIn, const int sellTimeIn)
        : buyTime(buyTimeIn), sellTime(sellTimeIn) {
    }

    int getBuyTime() const {
        return buyTime;
    }

    int getSellTime() const {
        return sellTime;
    }

};

// TODO your code goes here:

Trade bestBuySellTime(const vector<int> & prices) {
	
    int buyTime = 0;
    int sellTime = 0;
 
	int diff = 0;
	
  	for (int i=0; i<prices.size()-1; i++) {

		for (int j=i+1; j<prices.size(); j++)  {
		  
			if (prices[j] - prices[i] > diff) {
				diff = prices[j] - prices[i];
				buyTime = i;
				sellTime = j;
			}
		}	  
	}
		  

    Trade trade(buyTime, sellTime);
	
    return trade;
	
}

// Don't write any code below this line

#endif
