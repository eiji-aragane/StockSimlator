// portfolio.cpp

#include "portfolio.h"

#include <iomanip>
#include <iostream>
#include <locale>

#include "convert.h"

Portfolio::Portfolio()
    : mCashOnHand(1000000), mShared(0), mTotalAssets(0), mAssetBalance(0) {}

void Portfolio::buy(Stock &stock, int num) {
    double price{stock.getPrice()};
    double buyPrice{num * price};
    if (mCashOnHand >= buyPrice) {
        mCashOnHand -= buyPrice;
        mShared = mShared + num;
        mTotalAssets = mCashOnHand + (mShared * price);
        mAssetBalance = mShared * price;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "株を購入しました。現在の所持金: "
                  << formatWithCommas(mCashOnHand)
                  << "円、保有株数: " << mShared << "株" << std::endl;
    } else {
        std::cout << "所持金が不足しています。" << std::endl;
    }
}

void Portfolio::sell(Stock &stock, int num) {
    if (mShared > 0) {
        double price{stock.getPrice()};
        double sellPrice{num * price};
        mCashOnHand += sellPrice;
        mShared = mShared - num;
        mTotalAssets = mCashOnHand + (mShared * price);
        mAssetBalance = mShared * price;
        std::cout << "株を売却しました。現在の所持金: "
                  << formatWithCommas(mCashOnHand)
                  << "円、保有株数: " << mShared << "株" << std::endl;
    } else {
        std::cout << "保有株がありません。" << std::endl;
    }
}

void Portfolio::printStatus(Stock &stock) {
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "現在の所持金: " << formatWithCommas(mCashOnHand) << "円"
              << std::endl;
    std::cout << "保有株数: " << formatWithCommas(mShared) << "株" << std::endl;
    std::cout << "資産残高: " << formatWithCommas(mAssetBalance) << "円"
              << std::endl;
    std::cout << "総資産: " << formatWithCommas(mTotalAssets) << "円"
              << std::endl;
}

double Portfolio::getCashOnHand() { return mCashOnHand; }

int Portfolio::getShared() const { return mShared; }

void Portfolio::updatePrice(Stock &stock, int num) {
    double updatePrice{stock.updatePrice(num)};
    mTotalAssets = mCashOnHand + (mShared * updatePrice);
    mAssetBalance = mShared * updatePrice;
}
