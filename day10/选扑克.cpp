#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// 扑克牌花色
const string suits[] = {"方片", "梅花", "黑桃", "红心"};

// 扑克牌点数
const string ranks[] = {
    "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"
};

int main() {
    // 初始化随机数生成器
    srand(time(0));
    
    // 随机选择花色（0-3）
    int suitIndex = rand() % 4;
    
    // 随机选择点数（0-12）
    int rankIndex = rand() % 13;
    
    // 获取对应的花色和点数
    string suit = suits[suitIndex];
    string rank = ranks[rankIndex];
    
    // 输出结果
    cout << "随机选择的扑克牌是: " << suit << rank << endl;
    
    return 0;
}
