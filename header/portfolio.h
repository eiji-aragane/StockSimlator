// portfolio.h
// 所持金・株価の管理

#ifndef HEADER_PORTFOLIO_H_
#define HEADER_PORTFOLIO_H_

#include "stock.h"

class Portfolio {
   public:
    Portfolio();
    ~Portfolio() = default;  // デフォルトのデストラクタ

    void buy(Stock &stock, int num);
    void sell(Stock &stock, int num);
    void printStatus(Stock &stock);
    double getCashOnHand();
    int getShared() const;
    void updatePrice(Stock &stock, int num);

   private:
    double mCashOnHand;
    int mShared;
    double mTotalAssets;
    double mAssetBalance;
};

#endif  // HEADER_PORTFOLIO_H_