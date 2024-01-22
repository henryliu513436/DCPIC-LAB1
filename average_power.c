#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_SAMPLES 1000

float generateRandomFloat() {
    // 生成随机整数
    int randomInt = rand();

    // 映射到浮点数范围 [0, 1]
    float randomFloat = (float)randomInt / RAND_MAX;

    // 生成带符号的随机浮点数
    return (rand() % 2 == 0) ? randomFloat : -randomFloat;
}

int main() {
    // 设置随机种子
    srand((unsigned int)time(NULL));

    // 生成随机浮点数
    float randomSignal[NUM_SAMPLES];
    float sumOfSquares = 0;
    float inputSig[NUM_SAMPLES];

    for (int i = 0; i < NUM_SAMPLES; i++) {
        randomSignal[i] = generateRandomFloat(); //-1~1之間的floating point
        sumOfSquares += randomSignal[i] * randomSignal[i];

    }

    // 调整幅度，使得平均功率为1
    float scaleFactor = 1 / sqrt(sumOfSquares);
    // scaleFactor*=NUM_SAMPLES;

    printf("inputsignal=\n");

    for (int i = 0; i < NUM_SAMPLES; i++) {
        randomSignal[i] *= scaleFactor;
        inputSig[i]=randomSignal[i]*sqrt(NUM_SAMPLES); 
        printf("%f ", inputSig[i]);
    }

    // 计算平均功率
    float averagePower = 0;
    for (int i = 0; i < NUM_SAMPLES; i++) {
        averagePower += inputSig[i] * inputSig[i];
    }
    averagePower /= NUM_SAMPLES;

    // 打印结果
    printf("\nGenerated signal with average power = %f\n", averagePower);
    // float floatValue = 3.14159;
    // double doubleValue = 3.141592653589793;

    // // int a=floatValue;
    // // 输出浮点数，保留两位小数
    // printf("Float value: %d\n", floatValue);
    // printf("Double value: %lf\n", doubleValue);

    return 0;
}
