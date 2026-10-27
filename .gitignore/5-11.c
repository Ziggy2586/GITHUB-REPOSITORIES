#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 100         // 最大节点数
#define MAX_LEAF 6        // 叶子节点个数（即字符种类数）
#define MAX_CODE_LEN 20   // 最大编码长度
// 哈夫曼树结点结构
typedef struct {
    int weight;     // 权值
    int parent;     // 父节点下标
    int lchild;     // 左孩子下标
    int rchild;     // 右孩子下标
} HTNode;

// 哈夫曼编码结构（每个字符对应一个编码）
typedef char HuffmanCode[MAX_LEAF][MAX_CODE_LEN];

// 在HT[0...n-1]中选择两个权值最小且无父节点的结点
void selectTwoMin(HTNode HT[], int n, int *s1, int *s2) {
    int i;
    *s1 = *s2 = -1;
    for (i = 0; i < n; i++) {
        if (HT[i].parent == -1) {
            if (*s1 == -1 || HT[i].weight < HT[*s1].weight) {
                *s2 = *s1;
                *s1 = i;
            } else if (*s2 == -1 || HT[i].weight < HT[*s2].weight) {
                *s2 = i;
            }
        }
    }
}

// 构造哈夫曼树
void createHuffmanTree(HTNode HT[], int weights[], int n) {
    int m = 2 * n - 1;  // 哈夫曼树的结点总数
    for (int i = 0; i < m; i++) {
        HT[i].weight = (i < n) ? weights[i] : 0;
        HT[i].parent = HT[i].lchild = HT[i].rchild = -1;
    }

    for (int i = n; i < m; i++) {
        int s1, s2;
        selectTwoMin(HT, i, &s1, &s2);
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[s1].parent = HT[s2].parent = i;
    }
}

// 根据构造好的哈夫曼树生成编码
void createHuffmanCode(HTNode HT[], HuffmanCode HC, int n) {
    char temp[MAX_CODE_LEN];
    int i, j, p;
    for (i = 0; i < n; i++) {
        j = 0;
        int c = i;
        p = HT[c].parent;

        while (p != -1) {
            if (HT[p].lchild == c)
                temp[j++] = '0'; // 左孩子记为0
            else
                temp[j++] = '1'; // 右孩子记为1
            c = p;
            p = HT[c].parent;
        }

        temp[j] = '\0';
        // 反转 temp 存到 HC[i] 中
        int len = strlen(temp);
        for (int k = 0; k < len; k++) {
            HC[i][k] = temp[len - k - 1];
        }
        HC[i][len] = '\0';
    }
}

int main() {
    // 字符与权值对应：A=27, B=8, C=15, D=15, E=30, F=5
    char chars[MAX_LEAF] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int weights[MAX_LEAF] = {27, 8, 15, 15, 30, 5};
    HTNode HT[MAX_N];
    HuffmanCode HC;

    createHuffmanTree(HT, weights, MAX_LEAF);
    createHuffmanCode(HT, HC, MAX_LEAF);

    printf("字母\t频率\t哈夫曼编码\n");
    for (int i = 0; i < MAX_LEAF; i++) {
        printf("  %c\t%2d\t%s\n", chars[i], weights[i], HC[i]);
    }

    return 0;
}
