struct OptionFunction {
    double estimateVolatility(
            double stockPrice,
            double strikePrice,
            double rate,
            double expireTime,
            double dividendYield,
            double callOrPutPrice,
            double (*optionFunc) (double, double, double, double, double, double)
    );
};

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

