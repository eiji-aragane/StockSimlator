// simlator.cpp

#include "simlator.h"

#include <iomanip>
#include <iostream>
#include <locale>

#include "convert.h"
#include "portfolio.h"
#include "stock.h"

void Simlator::run() {
    Portfolio portfolio;

    std::cout << "株価シミュレーションアプリへようこそ！" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "初期所持金：" << formatWithCommas(portfolio.getCashOnHand())
              << "円" << std::endl;
    std::cout << "保有株数：" << portfolio.getShared() << "株" << std::endl;
    std::cout << std::endl;

    std::string command;
    Stock stock;

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
            std::cout << "購入株数：" << std::endl;
            int num;
            std::cin >> num;
            portfolio.buy(stock, num);
        } else if (command == "2") {
            std::cout << "売却株数：" << std::endl;
            int num;
            std::cin >> num;
            portfolio.sell(stock, num);
        } else if (command == "3") {
            portfolio.printStatus(stock);
        } else if (command == "4") {
            std::cout << "更新日数：" << std::endl;
            int num;
            std::cin >> num;
            portfolio.updatePrice(stock, num);
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