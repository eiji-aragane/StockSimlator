// stock.h
// 株価の管理と変動

#ifndef HEADER_STOCK_H_
#define HEADER_STOCK_H_

#include <ctime>
#include <random>

class Stock {
   public:
    Stock()
        : mPrice(10000), mGen(static_cast<unsigned int>(std::time(nullptr))) {};
    ~Stock() = default;
    double updatePrice(int num);
    double getPrice() const;

   private:
    double mPrice;
    std::mt19937 mGen;
};

#endif  // HEADER_STOCK_H_
