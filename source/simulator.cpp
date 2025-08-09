// simulator.cpp

#include "simulator.h"

#include <iomanip>
#include <iostream>
#include <locale>
#include <map>

#include "convert.h"
#include "portfolio.h"
#include "stock.h"


void Simulator::run() {
    Portfolio portfolio;

    std::cout << "株価シミュレーションアプリへようこそ！" << std::endl;
    std::map<std::string, Stock> stocks;
    stocks["AAPL"] = Stock("AAPL", 10000.00);
    stocks["TSLA"] = Stock("TSLA", 9000.00);
    stocks["GGLE"] = Stock("GGLE", 8000.00);
    portfolio.printStatus(stocks);

    // std::cout << std::fixed << std::setprecision(2);
    // std::cout << "初期所持金：" <<
    // formatWithCommas(portfolio.getCashOnHand())
    //           << "円" << std::endl;
    // std::cout << "保有株数：" << portfolio.getShared() << "株" << std::endl;
    // std::cout << std::endl;

    std::string command;

    while (true) {
        std::cout << "=========================" << std::endl;
        std::cout << "コマンドを入力してください：" << std::endl;
        std::cout << "[1] 株を買う" << std::endl;
        std::cout << "[2] 株を売る" << std::endl;
        std::cout << "[3] 現在のステータスを表示" << std::endl;
        std::cout << "[4] 日数を進める" << std::endl;
        std::cout << "[q] シミュレーションを終了" << std::endl;
        std::cout << "コマンド: ";
        std::cout << std::endl;
        std::cin >> command;

        if (command == "1") {
            std::cout << "=========================" << std::endl;
            std::cout << "購入する株を入力してください：" << std::endl;
            std::cout << "[1] AAPL：" << stocks["AAPL"].getPrice() << "円"
                      << std::endl;
            std::cout << "[2] TSLA：" << stocks["TSLA"].getPrice() << "円"
                      << std::endl;
            std::cout << "[3] GGLE：" << stocks["GGLE"].getPrice() << "円"
                      << std::endl;
            // 購入株銘柄
            int buyStockNum;
            std::cin >> buyStockNum;
            std::cout << "購入株数：" << std::endl;
            // 購入株数
            int buyStockQuantity;
            std::cin >> buyStockQuantity;

            switch (buyStockNum) {
                case 1:
                    portfolio.buy(stocks["AAPL"], buyStockQuantity);
                    portfolio.recomputeTotals(stocks);
                    break;
                case 2:
                    portfolio.buy(stocks["TSLA"], buyStockQuantity);
                    portfolio.recomputeTotals(stocks);
                    break;
                case 3:
                    portfolio.buy(stocks["GGLE"], buyStockQuantity);
                    portfolio.recomputeTotals(stocks);
                    break;

                default:
                    std::cout << "無効な銘柄です：" << std::endl;
                    break;
            }

        } else if (command == "2") {
            std::cout << "=========================" << std::endl;
            std::cout << "売却する株を入力してください：" << std::endl;
            std::cout << "[1] AAPL：" << stocks["AAPL"].getPrice() << "円"
                      << std::endl;
            std::cout << "[2] TSLA：" << stocks["TSLA"].getPrice() << "円"
                      << std::endl;
            std::cout << "[3] GGLE：" << stocks["GGLE"].getPrice() << "円"
                      << std::endl;
            // 売却株銘柄
            int sellStockNum;
            std::cin >> sellStockNum;

            std::cout << "売却株数：" << std::endl;
            // 売却株数
            int buyStockQuantity;
            std::cin >> buyStockQuantity;

            switch (sellStockNum) {
                case 1:
                    portfolio.sell(stocks["AAPL"], buyStockQuantity);
                    portfolio.recomputeTotals(stocks);
                    break;
                case 2:
                    portfolio.sell(stocks["TSLA"], buyStockQuantity);
                    portfolio.recomputeTotals(stocks);
                    break;
                case 3:
                    portfolio.sell(stocks["GGLE"], buyStockQuantity);
                    portfolio.recomputeTotals(stocks);
                    break;

                default:
                    std::cout << "無効な銘柄です：" << std::endl;
                    break;
            }
        } else if (command == "3") {
            portfolio.printStatus(stocks);
        } else if (command == "4") {
            std::cout << "更新日数：" << std::endl;
            int num;
            std::cin >> num;

            for (auto& pair : stocks) {
                pair.second.updatePrice(num);
            }
            // 合計を出し直す
            portfolio.recomputeTotals(stocks);

            std::cout << "株価が更新されました。" << std::endl;
        } else if (command == "q") {
            std::cout << "シミュレーションを終了します。" << std::endl;
            break;
        } else {
            std::cout << "無効なコマンドです。もう一度入力してください。"
                      << std::endl;
        }
    }
    std::cout << "シミュレーションを終了しました。" << std::endl;
}