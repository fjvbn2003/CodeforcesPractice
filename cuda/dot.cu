#include <stdio.h>
#include <cuda.h>

#define N 100000000

__global__ void dot_kernel(float *a, float *b, float *c) {
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    float temp = 0.0f;
    for (int j = 0; j < N; j += blockDim.x * gridDim.x) {
        temp += a[i + j] * b[i + j];
    }
    c[i] = temp;
}

int main() {
    float *h_a, *h_b, *h_c;
    float *d_a, *d_b, *d_c;
    h_a = (float*)malloc(N * sizeof(float));
    h_b = (float*)malloc(N * sizeof(float));
    h_c = (float*)malloc(N * sizeof(float));
    for (int i = 0; i < N; i++) {
        h_a[i] = i * 2.0f;
        h_b[i] = i * 3.0f;
    }
    cudaMalloc((void**)&d_a, N * sizeof(float));
    cudaMalloc((void**)&d_b, N * sizeof(float));
    cudaMalloc((void**)&d_c, N * sizeof(float));
    cudaMemcpy(d_a, h_a, N * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, N * sizeof(float), cudaMemcpyHostToDevice);
    int block_size = 256;
    int num_blocks = (N + block_size - 1) / block_size;
    dot_kernel<<<num_blocks, block_size>>>(d_a, d_b, d_c);
    cudaMemcpy(h_c, d_c, N * sizeof(float), cudaMemcpyDeviceToHost);
    float dot = 0.0f;
    for (int i = 0; i < N; i++) {
        dot += h_c[i];
    }
    printf("Dot product: %f\n", dot);
    free(h_a);
    free(h_b);
    free(h_c);
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    return 0;
}