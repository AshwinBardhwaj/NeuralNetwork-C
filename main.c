#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8},
};
#define train_count (sizeof(train)/sizeof(train[0]))

// y = x*w;

float rand_float(void)
{
    return (float) rand()/(float) RAND_MAX;
}

float loss(float w)
{
    float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i) {
        float x = train[i][0];
        float y = x*w;
        float d = y - train[i][1];
        result += d*d;
        //printf("actual: %f, expected %f\n", y, train[i][1]);
    }
    result /= train_count;
    return result;
}

int main() 
{
    srand(12);
    float w = rand_float() * 10.0f;
    printf("%f\n", w);

    float eps = 1e-3;
    float rate = 1e-3;

    printf("%f\n", loss(w));
    for (size_t i = 0; i < 500; ++i){
        float dloss = (loss(w+eps) - loss(w))/eps;
        w -= rate * dloss;
        printf("cost = %f, w = %f\n", loss(w), w);
    }

    printf("-------------------------------------------\n");

    printf("%f\n", w);


    //printf("Who lives in a pineapple under the sea?\n");
    return 0;
}