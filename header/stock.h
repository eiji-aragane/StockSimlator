// stock.h
// 株価の管理と変動

#ifndef HEADER_STOCK_H_
#define HEADER_STOCK_H_

#include <ctime>
#include <random>

class Stock {
   public:
    Stock()
        : mName(""),
          mPrice(0.0),
          mGen(static_cast<unsigned int>(std::time(nullptr))) {}
    Stock(std::string name, double price)
        : mName(name),
          mPrice(price),
          mGen(static_cast<unsigned int>(std::time(nullptr))) {};
    ~Stock() = default;
    double updatePrice(int num);
    double getPrice() const;
    const std::string& getName() const { return mName; }

   private:
    std::string mName;
    double mPrice;
    std::mt19937 mGen;
};

#endif  // HEADER_STOCK_H_
