#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 512

#define M 21   // 滤波器阶数


float generateRandomFloat() {
    // 生成随机整数
    int randomInt = rand();
    
    // 映射到浮点数范围 [0, 10] 要取範圍多少隨意
    float randomFloat = ((float)randomInt /RAND_MAX) ; //RAND_MAX

    // 生成带符号的随机浮点数
    return (rand() % 2 == 0) ? randomFloat : -randomFloat;
}

void firLowPassFilter(float input[], float output[], float filterCoeff[], int inputLength, int filterLength);
// int OUT_NUM=NUM_SAMPLES+M-1; //output數量

int main() {
    float inputSignal[NUM_SAMPLES]; // 输入信号
    float outputSignal[NUM_SAMPLES]; // 输出信号
    float filterCoeff[M] = {-0.0105963997986059, -0.0380214361435444, -0.0365217681824527, 0.00336388262116807, 0.0454851577619937, 0.0194242970434525, -0.0610882554173864, -0.0752620124582160, 0.0734976427892512, 0.307268070442418, 0.421992848704956, 0.307268070442418, 0.0734976427892512, -0.0752620124582160, -0.0610882554173864, 0.0194242970434525, 0.0454851577619937, 0.00336388262116807, -0.0365217681824527, -0.0380214361435444, -0.0105963997986059};
    srand(time(NULL));

    // 设置随机种子
    srand((unsigned int)time(NULL));

    // 生成随机浮点数
    float randomSignal[NUM_SAMPLES];
    float sumOfSquares = 0;


    for (int i = 0; i < NUM_SAMPLES; i++) {
        randomSignal[i] = generateRandomFloat(); //-1~1之間的floating point
        sumOfSquares += randomSignal[i] * randomSignal[i];
    }

    // 调整幅度，使得平均功率为1
    float scaleFactor = 1 / sqrt(sumOfSquares);

    for (int i = 0; i < NUM_SAMPLES; i++) {
        randomSignal[i] *= scaleFactor;
        inputSignal[i]=randomSignal[i]*sqrt(NUM_SAMPLES); 
        // printf("inputsignal = %f\n", randomSignal[i]);
    }

        // 执行 FIR 低通滤波器
    firLowPassFilter(inputSignal, outputSignal, filterCoeff, NUM_SAMPLES, M);

    // 计算平均功率
    float averagePower = 0;
    for (int i = 0; i < NUM_SAMPLES; i++) {
        averagePower += inputSignal[i] * inputSignal[i];
    }
    averagePower /= NUM_SAMPLES;
    printf("Generated signal with average power = %f\n", averagePower);

    // 打印输入和输出信号
    printf("Input Signal: ");
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%f ", inputSignal[i]);
    }

    printf("\nOutput Signal (FIR Low Pass Filtered): ");
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%f ", outputSignal[i]);
    }
    // printf("%f ", outputSignal[0]);

    return 0;
}

// FIR 低通滤波器的实现
void firLowPassFilter(float input[], float output[], float filterCoeff[], int inputLength, int filterLength) {
    for (int n = 0; n < inputLength; n++) {
        output[n] = 0.0;
        for (int k = 0; k < filterLength; k++) {
            if (n - k >= 0) {
                output[n] += filterCoeff[k] * input[n - k]; //convolution
            }
        }
    }
}



//拿輸入跟輸出到matlab觀察頻譜
//fixed point 是對於二進制要用多少bits表示十進制而言