#include <iostream>
#include <random>
#include <vector>
#include <chrono>

int rollDice(std::mt19937& rng) {
    std::uniform_int_distribution<int> dist(1, 6);
    return dist(rng);
}

int getSum(int dice1, int dice2, int dice3) {
    return dice1 + dice2 + dice3;
}

int simulateGame(std::mt19937& rng, int startingMoney, int betAmount, int stopAmount) {
    int dice1, dice2, dice3;
    int sum;
    int money = startingMoney;
    int bet = betAmount;

    while (money >= bet && money <= stopAmount) {
        std::uniform_int_distribution<int> choiceDist(1, 2);
        int choice = choiceDist(rng); // 随机选择大或小

        // 投掷骰子
        dice1 = rollDice(rng);
        dice2 = rollDice(rng);
        dice3 = rollDice(rng);
        sum = getSum(dice1, dice2, dice3);

        // 判断游戏胜负
        if (dice1 == dice2 && dice2 == dice3) {
            money -= bet;
            bet *= 2;
        } else if ((sum >= 4 && sum <= 10 && choice == 2) || (sum >= 11 && sum <= 17 && choice == 1)) {
            money += bet;
            bet = betAmount; // 猜对了大小，下注金额回到初始下注金额
        } else {
            money -= bet;
            if (bet * 2 > money) {
                bet = money; // 下注金额超过身上的钱，将身上的钱全部用来下注
            } else {
                bet *= 2;
            }
        }
    }

    return money;
}

int main() {
    std::cout << "欢迎来到赌场！" << std::endl;

    int startingMoney;
    std::cout << "请输入本金金额：";
    std::cin >> startingMoney;

    int betAmount;
    std::cout << "请输入下注金额：";
    std::cin >> betAmount;

    int stopAmount;
    std::cout << "请输入结束游戏的金额阈值：";
    std::cin >> stopAmount;

// 使用当前时间作为随机数种子
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);
    
    std::vector<int> finalFunds;
    int countOverStopAmount = 0;

    for (int i = 0; i < 100; i++) {
        int finalMoney = simulateGame(rng, startingMoney, betAmount, stopAmount);
        finalFunds.push_back(finalMoney);

        if (finalMoney > stopAmount) {
            countOverStopAmount++;
        }
    }

    std::cout << "100次模拟的最终资金：" << std::endl;
    for (int i = 0; i < finalFunds.size(); i++) {
        std::cout << "第 " << i + 1 << " 次模拟：" << finalFunds[i] << " 元" << std::endl;
    }

    std::cout << "超过阈值的最终资金数量：" << countOverStopAmount << std::endl;

    return 0;
}