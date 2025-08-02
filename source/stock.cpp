// stock.cpp
#include "stock.h"

#include <iomanip>
#include <iostream>

double Stock::updatePrice(int num) {
    for (int i{0}; i < num; i++) {
        std::uniform_real_distribution<double> dist(0.90, 1.10);

        double rd{dist(mGen)};
        std::cout << std::fixed << std::setprecision(2);
        double ramdomNumber{std::round(rd * 100.0) / 100.0};
        mPrice = mPrice * ramdomNumber;
    }
    std::cout << "変更後の値：" << mPrice << std::endl;
    return mPrice;
}

double Stock::getPrice() const { return mPrice; }
