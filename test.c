#include <stdio.h>

#define N 100  // 輸入信號長度
#define M 24   // 濾波器冷過濾器係數數量

// 函數原型
void firLowPassFilter(double input[], double output[], double filterCoeff[], int inputLength, int filterLength);

int main() {
    double inputSignal[N]; // 輸入信號
    double outputSignal[N]; // 輸出信號
    double filterCoeff[M] = {0.0146, 0.0239, 0.0042, -0.0226, -0.0196, 0.0258, 0.0434, -0.0150, -0.0855, -0.0261, 0.1893, 0.3956, 0.3956, 0.1893, -0.0261, -0.0855, -0.0150, 0.0434, 0.0258, -0.0196, -0.0226, 0.0042, 0.0239, 0.0146};

    // 初始化輸入信號，這裡可以根據實際情況修改
    for (int i = 0; i < N; i++) {
        inputSignal[i] = i;  // 這裡只是一個簡單的例子，實際應用中需要根據實際情況提供輸入信號
    }

    // 執行FIR低通濾波器
    firLowPassFilter(inputSignal, outputSignal, filterCoeff, N, M);

    // 打印輸入和輸出信號
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

// FIR低通濾波器的實現
void firLowPassFilter(double input[], double output[], double filterCoeff[], int inputLength, int filterLength) {
    for (int n = 0; n < inputLength; n++) {
        output[n] = 0.0;
        for (int k = 0; k < filterLength; k++) {
            if (n - k >= 0) {
                output[n] += filterCoeff[k] * input[n - k];
            }
        }
    }
}