// portfolio.h
// 所持金・株価の管理

#ifndef HEADER_PORTFOLIO_H_
#define HEADER_PORTFOLIO_H_

#include <map>
#include <string>

#include "stock.h"

class Portfolio {
   public:
    Portfolio();
    ~Portfolio() = default;  // デフォルトのデストラクタ

    void buy(Stock &stock, int num);
    void sell(Stock &stock, int num);
    void printStatus(const std::map<std::string, Stock> &stocks);
    double getCashOnHand();
    // std::vector<int> getHoldingsList() const;
    void recomputeTotals(const std::map<std::string, Stock> &stocks);

   private:
    double mCashOnHand;
    double mTotalAssets;  // 総資産
    double mAssetBalance;
    std::map<std::string, int> mHoldings;
};

#endif  // HEADER_PORTFOLIO_H_