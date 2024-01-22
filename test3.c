#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float generateRandomFloat() {
    // 设置随机种子
    srand((unsigned int)time(NULL));

    // 生成随机整数
    int randomInt = rand();

    // 映射到带符号浮点数范围
    float randomFloat = (float)randomInt / RAND_MAX; // 将整数映射到 [0, 1] 范围

    // 生成带符号的随机浮点数
    return (rand() % 2 == 0) ? randomFloat : -randomFloat;
}

int main() {
    // 生成带符号的随机浮点数
    float randomValue = generateRandomFloat();

    // 打印结果
    printf("Random Float: %f\n", randomValue);

    return 0;
}
