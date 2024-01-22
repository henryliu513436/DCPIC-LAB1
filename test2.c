#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100 // 信号长度
#define M 6    // 滤波器阶数

// FIR filter coefficients
float filterCoeff[M + 1] = {0.0400, 0.1201, 0.2101, 0.2502, 0.2101, 0.1201, 0.0400};

// Function prototypes
void generateTestPatterns(float input[]);
void firFilter(float input[], float output[]);
float computeAveragePower(float signal[]);
float inputsignal[],outputsignal[];

float generateRandomFloat() {
    // 生成随机整数
    int randomInt = rand();

    // 映射到浮点数范围 [0, 1]
    float randomFloat = (float)randomInt / RAND_MAX;

    // 生成带符号的随机浮点数
    return (rand() % 2 == 0) ? randomFloat : -randomFloat;
}

int main() {
    // 设置随机数种子
    srand((unsigned int)time(NULL));

    // 生成随机测试模式
    float testPatterns[N];
    generateTestPatterns(testPatterns);

    // 执行FIR滤波
    float filteredOutput[N];
    firFilter(testPatterns, filteredOutput);

    // 计算输入信号的平均功率
    float inputPower = computeAveragePower(testPatterns);

    // 输出结果
    printf("Average Power of Input Signal: %f\n", inputPower);

    //     printf("\nInput Signal: ");
    // for (int i = 0; i < N; i++) {
    //     printf("%f ", input[i]);
    // }

    // printf("\nOutput Signal (FIR Low Pass Filtered): ");
    // for (int i = 0; i < N; i++) {
    //     printf("%f ", output[i]);
    // }

    // TODO: 进行其他分析，例如输出信号的功率等

    return 0;
}

// FIR滤波器实现
void firFilter(float input[], float output[]) {
    for (int n = 0; n < N; ++n) {
        output[n] = 0.0;
        for (int k = 0; k <= M; ++k) {
            if (n - k >= 0) {
                output[n] += filterCoeff[k] * input[n - k];
            }
        }
    }
    printf("\nInput Signal: ");
    for (int i = 0; i < N; i++) {
        printf("%f ", input[i]);
    }

    printf("\nOutput Signal (FIR Low Pass Filtered): ");
    for (int i = 0; i < N; i++) {
        printf("%f ", output[i]);
    }
}

// 生成随机测试模式
void generateTestPatterns(float input[]) {
    for (int i = 0; i < N; ++i) {
        input[i] = ((float)rand() / RAND_MAX) * 2.0 - 1.0; // 生成范围在[-1, 1)内的随机浮点数
    }
}

// 计算信号的平均功率
float computeAveragePower(float signal[]) {
    float sum = 0.0;
    for (int i = 0; i < N; ++i) {
        sum += signal[i] * signal[i];
    }
    return sum / N;
}
