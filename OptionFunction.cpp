//
// Created by Jasper Wang on 17/2/24.
//

#include "OptionFunction.h"
#include <cmath>

using namespace std;

double normalCFD(double value) {
    return 0.5 * erfc(-value * M_SQRT1_2);
}

double europeanCallOption(
        double stockPrice,
        double strikePrice,
        double rate,
        double expireTime,
        double volatility,
        double dividendYield
) {
    double d1 = (log(stockPrice / strikePrice) + (rate - dividendYield + volatility * volatility / 2) * expireTime)
                / (volatility * sqrt(expireTime));
    double d2 = d1 - volatility * sqrt(expireTime);
    return stockPrice * normalCFD(d1) - strikePrice * exp(-1 * rate * expireTime) * normalCFD(d2);
}

double europeanPutOption(
        double stockPrice,
        double strikePrice,
        double rate,
        double expireTime,
        double volatility,
        double dividendYield
) {
    double d1 = (log(stockPrice / strikePrice) + (rate - dividendYield + volatility * volatility / 2) * expireTime)
                / (volatility * sqrt(expireTime));
    double d2 = d1 - volatility * sqrt(expireTime);
    return strikePrice * exp(-1 * rate * expireTime) * normalCFD(-d2) - stockPrice * normalCFD(-d1);
}

double OptionFunction::estimateVolatility(
        double stockPrice,
        double strikePrice,
        double rate,
        double expireTime,
        double dividendYield,
        double callOrPutPrice,
        double (*optionFunc) (double, double, double, double, double, double)
) {
    double volatilityUpper = 1;
    double volatilityLower = 0;
    while (volatilityUpper - volatilityLower > 0.00001) {
        double higher = (*optionFunc)(stockPrice, strikePrice, rate, expireTime, volatilityUpper, dividendYield);
        double lower = (*optionFunc)(stockPrice, strikePrice, rate, expireTime, volatilityLower, dividendYield);
        if (abs(higher - callOrPutPrice) > abs(lower - callOrPutPrice)) {
            volatilityUpper = (volatilityUpper + volatilityLower) / 2;
        } else {
            volatilityLower = (volatilityUpper + volatilityLower) / 2;
        }
    }
    return volatilityLower;
}