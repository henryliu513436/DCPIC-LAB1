#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100  // 输入信号长度
#define M 22   // 滤波器阶数+1

// 函数原型
void firLowPassFilter(float input[], float output[], float filterCoeff[], int inputLength, int filterLength);

int main() {
    float inputSignal[N]; // 输入信号
    float outputSignal[N]; // 输出信号
    float filterCoeff[M+1] = {0.0132391553337840, 0.00436915022852480, -0.0225317726518532, -0.0363994391057918, -0.00467775420277686, 0.0392882332849735, 0.0208064125153879, -0.0592058718502787, -0.0790804811345331, 0.0681355854868914, 0.307905222279586, 0.426871404051735, 0.307905222279586, 0.0681355854868914, -0.0790804811345331, -0.0592058718502787, 0.0208064125153879, 0.0392882332849735, -0.00467775420277686, -0.0363994391057918, -0.0225317726518532, 0.00436915022852480, 0.0132391553337840};
    srand(time(NULL));

    // 初始化输入信号，这里只是一个简单的例子，实际应用中需要根据实际情况提供输入信号
    for (int i = 0; i < N; i++) {
        inputSignal[i] = ((float)rand() / RAND_MAX) * 2.0 - 1.0 ;  // double x = (max - min) * rand() / (RAND_MAX + 1.0) + min;=
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
        for (int k = 0; k <= filterLength; k++) {
            if (n - k >= 0) {
                output[n] += filterCoeff[k] * input[n - k]; //convolution
            }
        }
    }
}
//拿輸入跟輸出到matlab觀察頻譜