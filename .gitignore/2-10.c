#include <stdio.h>


int demo_nlogn(int n) {
    int count = 0;                  
    // 外层循环：i 从 0 到 n–1，总共执行 n 次
    for (int i = 0; i < n; i++) {   // 执行 n 次
        // 内层循环：j 从 1 开始，每次乘 2，直到 j >= n
        // 执行 ≈ ⌊log₂n⌋ + 1 次
        for (int j = 1; j < n; j *= 2) {
            count++;                
        }
    }
    return count;                   
}

int main() {
    int n;
    scanf("%d", &n);
    int total = demo_nlogn(n);
    printf("Total operations for n=%d: %d\n", n, total);
    return 0;                       
}

