#include <stdio.h>

#define N 100  // 输入信号长度
#define M 8   // 滤波器阶数+1

// 函数原型
void firLowPassFilter(float input[], float output[], float filterCoeff[], int inputLength, int filterLength);

int main() {
    float inputSignal[N]; // 输入信号
    float outputSignal[N]; // 输出信号
    float filterCoeff[M] = {0.0400, 0.1201, 0.2101, 0.2502, 0.2101, 0.1201, 0.0400};

    // 初始化输入信号，这里只是一个简单的例子，实际应用中需要根据实际情况提供输入信号
    for (int i = 0; i < N; i++) {
        inputSignal[i] = i;  // 这里只是一个简单的例子，实际应用中需要提供实际的输入信号
    }

    // 执行 FIR 低通滤波器
    firLowPassFilter(inputSignal, outputSignal, filterCoeff, N, M);

    // 打印输入和输出信号
    printf("Input Signal: ");
    for (int i = 0; i < N; i++) {
        printf("%f ", inputSignal[i]);
    }

    printf("\nOutput Signal (FIR Low Pass Filtered): ");
    for (int i = 0; i < N; i++) {
        printf("%f ", outputSignal[i]);
    }

    return 0;
}

// FIR 低通滤波器的实现
void firLowPassFilter(float input[], float output[], float filterCoeff[], int inputLength, int filterLength) {
    for (int n = 0; n < inputLength; n++) {
        output[n] = 0.0;
        for (int k = 0; k < filterLength; k++) {
            if (n - k >= 0) {
                output[n] += filterCoeff[k] * input[n - k];
            }
        }
    }
}
