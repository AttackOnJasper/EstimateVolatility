//
// Created by Jasper Wang on 17/2/24.
//

#ifndef STOCKVOLATILITY_EUROPEANCALLOPTION_H
#define STOCKVOLATILITY_EUROPEANCALLOPTION_H

double europeanCallOption(
        double stockPrice,
        double strikePrice,
        double rate,
        double expireTime,
        double volatility,
        double dividendYield
);

double europeanPutOption(
        double stockPrice,
        double strikePrice,
        double rate,
        double expireTime,
        double volatility,
        double dividendYield
);

double estimateVolatility(
        double stockPrice,
        double strikePrice,
        double rate,
        double expireTime,
        double dividendYield,
        double callOrPutPrice,
        double (*optionFunc) (double, double, double, double, double, double)
);

#endif //STOCKVOLATILITY_EUROPEANCALLOPTION_H
