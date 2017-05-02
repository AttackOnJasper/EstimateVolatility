//
//  main.cpp
//  StockVolatility
//
//  Created by Jasper Wang on 17/2/24.
//  Copyright © 2017 Jasper. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "OptionFunction.h"

using namespace std;

int main(int argc, char* argv[]) {
	string filePath = "./spx.txt";
	switch (argc) {
		case 2:
			filePath = argv[1];
			break;
		case 1:
			break;
		default:
			cerr << "invalid arguments" << endl;
			exit(0);
	}
    ifstream inFile(filePath.c_str());
    string inputString;
    double input;
    const int colSize = 9;
    double data[colSize] = {};
    for (int i = 0; i < colSize; i++) {
        inFile >> inputString;
        cout << inputString << (i == 0? "\t\t" : "\t");
    }
    cout << "callBidImpV\tcallAskImpV\tputBidImpV\tputAskImpV" << endl;
    OptionFunction optionFunction;
    while (inFile >> inputString) {
        cout << inputString << "\t";
        for (int i = 0; i < colSize; i++) {
            inFile >> input;
            data[i] = input;
            cout << input << "\t";
        }
        cout << optionFunction.estimateVolatility(data[1], data[5], 0, data[0] / 365, 0, data[3], europeanCallOption) << "\t";
        cout << optionFunction.estimateVolatility(data[1], data[5], 0, data[0] / 365, 0, data[4], europeanCallOption) << "\t";
        cout << optionFunction.estimateVolatility(data[1], data[5], 0, data[0] / 365, 0, data[6], europeanPutOption) << "\t";
        cout << optionFunction.estimateVolatility(data[1], data[5], 0, data[0] / 365, 0, data[7], europeanPutOption) << "\t";
        cout << endl;
    }
    return 0;
}
