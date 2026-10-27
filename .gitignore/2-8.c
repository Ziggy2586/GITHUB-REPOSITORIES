#include <stdio.h>

// 枚举 [0,1,…,n–1] 的所有子集
void enum_subsets(int n) {
    int total = 1 << n;       // 执行 1 次：计算 2ⁿ
    // 当 n = 0 时，total = 1
    // 当 n = 1 时，total = 2
    // 当 n = 2 时，total = 4
    // ……
    // 一般地，total = 2ⁿ

    for (int mask = 0; mask < total; mask++) {
        // 进入循环体的次数 = total 次
        // 每次循环体做一次“生成子集”的基本操作（这里用输出 mask 代替）
        printf("Subset: %d\n", mask); // 执行 total 次
        // 本示例中不展开如何从 mask 构造子集，关注循环次数即可
    }
    
}

int main() {
    int n;
    scanf("%d", &n);               
    enum_subsets(n);//调用函数
    return 0;                
}
