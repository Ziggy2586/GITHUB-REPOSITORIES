#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 // 栈最大容量
typedef int ElemType; // 栈中存储的数据类型为 int

// 栈结构体定义
typedef struct {
    ElemType *data; // 存储栈中元素的数组
    int top; // 栈顶指针（指向栈顶元素的下标）
} Stack;

// 枚举类型：用于标识表达式中符号的类型
typedef enum {
    LEFT_PARE, RIGHT_PARE, // 左右括号（本例中未使用）
    ADD, SUB, MUL, DIV, MOD, // 运算符：加减乘除模
    EOS, // 表达式结束符
    NUM  // 数字
} contentType;
// 示例表达式（后缀形式）：中缀为 ((8 / 2) + 2) - (5 * 6)
char expr[] = "82/2+56*-";
// 初始化栈
Stack* initStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack)); // 分配栈结构体空间
    s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE); // 分配栈数组空间
    s->top = -1; // 初始化栈顶指针为 -1（空栈）
    return s;
}
// 入栈操作
int push(Stack *s, ElemType e) {
    if (s->top >= MAXSIZE - 1) {
        printf("满了\n");
        return 0;
    }
    s->top++; // 栈顶指针上移
    s->data[s->top] = e; // 新元素入栈
    return 1;
}

// 出栈操作
int pop(Stack *s, ElemType *e) {
    if (s->top == -1) {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top]; // 取出栈顶元素
    s->top--; // 栈顶指针下移
    return 1;
}
// 分析表达式中当前字符类型（返回 contentType 枚举值）
contentType getToken(char *symbol, int *index) {
    *symbol = expr[*index];    // 获取当前字符
    *index = *index + 1;       // 移动到下一个字符
    switch(*symbol) {
        case '(': return LEFT_PARE;
        case ')': return RIGHT_PARE;
        case '+': return ADD;
        case '-': return SUB;
        case '*': return MUL;
        case '/': return DIV;
        case '%': return MOD;
        case '\0': return EOS;         // 字符串结束
        default: return NUM;           // 默认按数字处理（这里只处理单字符数字）
    }
}
// 后缀表达式求值函数
int eval(Stack *s) {
    char symbol; // 当前读取的字符
    int op1, op2; // 操作数
    int index = 0; // 当前解析到的表达式位置
    ElemType result;
    contentType token = getToken(&symbol, &index); // 获取第一个符号类型

    // 表达式尚未结束
    while(token != EOS) {
        if (token == NUM) {
            push(s, symbol - '0'); // 将数字字符转为整型并入栈
        } else {
            pop(s, &op2); // 先出栈的是右操作数
            pop(s, &op1); // 再出栈的是左操作数
            // 根据符号类型执行对应运算
            switch(token) {
                case ADD: push(s, op1 + op2); break;
                case SUB: push(s, op1 - op2); break;
                case MUL: push(s, op1 * op2); break;
                case DIV: push(s, op1 / op2); break;
                case MOD: push(s, op1 % op2); break;
                default: break;
            }
        }
        token = getToken(&symbol, &index);  // 获取下一个符号
    }

    pop(s, &result); // 结果出栈
    printf("%d\n", result); // 输出结果
    return 1;
}
// 主函数
int main(int argc, char const *argv[]) {
    Stack *s = initStack();        // 初始化栈
    eval(s);                       // 执行表达式求值
    return 0;
}
