#include <iostream>
#include <random>

int main() {
    // 乱数生成器
    std::random_device rd;

    // 乱数のエンジン（この例ではMersenne Twisterを使用）
    std::mt19937 engine(rd());

    // 1から6までの一様な分布を設定
    std::uniform_int_distribution<int> dist(1, 6);

    // ランダムな数字を生成
    for(int i = 0; i < 10; ++i) {
        std::cout << dist(engine) << std::endl;
    }
    return 0;
}
