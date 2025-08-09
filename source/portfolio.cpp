// portfolio.cpp

#include "portfolio.h"

#include <iomanip>
#include <iostream>
#include <locale>

#include "convert.h"

Portfolio::Portfolio()
    : mCashOnHand(1000000),
      mTotalAssets(1000000),
      mAssetBalance(0),
      mHoldings() {}

void Portfolio::buy(Stock &stock, int num) {
    double price{stock.getPrice()};
    double buyPrice{num * price};
    if (mCashOnHand >= buyPrice) {
        mCashOnHand -= buyPrice;
        const std::string &name = stock.getName();
        mHoldings[name] += num;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "株を購入しました。現在の所持金: "
                  << formatWithCommas(mCashOnHand)
                  << "円、保有株数: " << mHoldings[name] << "株" << std::endl;
    } else {
        std::cout << "所持金が不足しています。" << std::endl;
    }
}

void Portfolio::sell(Stock &stock, int num) {
    const std::string &name = stock.getName();
    if (mHoldings[name] > 0 && num > 0) {
        int canSell = std::min(num, mHoldings[name]);
        if (canSell <= 0) {
            std::cout << "保有株が足りません。" << std::endl;
            return;
        }
        double price{stock.getPrice()};
        mCashOnHand += price * canSell;
        mHoldings[name] -= canSell;
        std::cout << "株を売却しました。現在の所持金: "
                  << formatWithCommas(mCashOnHand)
                  << "円、保有株数: " << mHoldings[name] << "株" << std::endl;
    } else {
        std::cout << "保有株がありません。" << std::endl;
    }
}

void Portfolio::printStatus(const std::map<std::string, Stock> &stocks) {
    double totalValue = mCashOnHand;
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "現在の所持金: " << formatWithCommas(mCashOnHand) << "円"
              << std::endl;
    std::cout << "----------------------------" << std::endl;

    for (const auto &pair : stocks) {
        const std::string &name{pair.first};
        const Stock &stock = pair.second;
        int num = mHoldings[name];
        double price = stock.getPrice();
        double value = num * price;
        totalValue += value;

        std::cout << "[" << name << "] "
                  << "保有株: " << num << "株（1株：" << price << "円）"
                  << " 評価額: " << formatWithCommas(value) << "円"
                  << std::endl;
    }

    std::cout << "----------------------------" << std::endl;
    std::cout << "総資産: " << formatWithCommas(totalValue) << "円"
              << std::endl;
}

double Portfolio::getCashOnHand() { return mCashOnHand; }

void Portfolio::recomputeTotals(const std::map<std::string, Stock> &stocks) {
    double sum = 0.0;
    for (const auto &pair : stocks) {
        const std::string &name = pair.first;
        const Stock &stock = pair.second;
        auto it = mHoldings.find(name);
        if (it == mHoldings.end()) continue;
        sum += static_cast<double>(it->second) * stock.getPrice();
    }
    mAssetBalance = sum;
    mTotalAssets = mCashOnHand + mAssetBalance;
}
