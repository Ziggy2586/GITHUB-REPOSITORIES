#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

// 栈结构定义
typedef struct {
    ElemType *data; // 存储栈中元素的数组
    int top;        // 栈顶指针
} Stack;

// 枚举表达式中的符号类型
typedef enum {
    LEFT_PARE, RIGHT_PARE,    // 左右括号
    ADD, SUB, MUL, DIV, MOD,  // 运算符
    EOS,                      // 表达式结束标志
    NUM                       // 操作数（变量或数字）
} contentType;

// 示例中缀表达式（假设表达式只含变量和运算符）
char expr[] = "x/(i-j)*y";

// 初始化栈
Stack* initStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    s->top = -1;
    return s;
}

// 判断栈是否为空
int isEmpty(Stack *s) {
    if (s->top == -1) {
        printf("空的\n");
        return 1;
    } else {
        return 0;
    }
}

// 入栈操作
int push(Stack *s, ElemType e) {
    if (s->top >= MAXSIZE - 1) {
        printf("满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

// 出栈操作
int pop(Stack *s, ElemType *e) {
    if (s->top == -1) {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

// 获取栈顶元素（不出栈）
int getTop(Stack *s, ElemType *e) {
    if (s->top == -1) {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

// 词法分析器：根据字符获取其类型（用于转换）
contentType getToken(char *symbol, int *index) {
    *symbol = expr[*index]; // 取当前字符
    *index = *index + 1; // 向后移动一位
    switch(*symbol) {
        case '(': return LEFT_PARE;
        case ')': return RIGHT_PARE;
        case '+': return ADD;
        case '-': return SUB;
        case '*': return MUL;
        case '/': return DIV;
        case '%': return MOD;
        case '\0': return EOS;
        default: return NUM; // 默认为操作数（变量）
    }
}

// 打印符号对应的字符
int print_token(contentType token) {
    switch(token) {
        case ADD: printf("+"); break;
        case SUB: printf("-"); break;
        case MUL: printf("*"); break;
        case DIV: printf("/"); break;
        case MOD: printf("%%"); break;
        default: return 0;
    }
    return 1;
}

// 中缀转后缀核心函数
void postfix(Stack *s) {
    // 运算符在栈中和栈外的优先级表（下标对应 contentType 枚举）
    int in_stack[]  = {  0, 19, 12, 12, 13, 13, 13,  0 };  // 栈内优先级
    int out_stack[] = { 20, 19, 12, 12, 13, 13, 13,  0 };  // 栈外优先级

    contentType token;
    int index = 0;
    char symbol;
    ElemType e;

    // 初始化：压入一个 EOS 表示“栈底哨兵”
    s->top = 0;
    s->data[0] = EOS;

    // 扫描整个表达式
    token = getToken(&symbol, &index);
    while(token != EOS) {
        if (token == NUM) {
            // 操作数：直接输出（即成为后缀表达式的一部分）
            printf("%c", symbol);
        }
        else if (token == RIGHT_PARE) {
            // 右括号：弹出并输出栈中所有操作符，直到遇到左括号
            while(s->data[s->top] != LEFT_PARE) {
                pop(s, &e);
                print_token(e);
            }
            pop(s, &e); // 弹出左括号（不输出）
        }
        else {
            // 处理运算符：比较当前符号与栈顶符号的优先级
            while(in_stack[s->data[s->top]] >= out_stack[token]) {
                pop(s, &e);
                print_token(e);
            }
            // 当前运算符入栈
            push(s, token);
        }

        // 继续读取下一个符号
        token = getToken(&symbol, &index);
    }

    // 表达式扫描完毕：清空栈中剩余符号
    pop(s, &e);
    token = e;
    while(token != EOS) {
        print_token(token);
        pop(s, &e);
        token = e;
    }

    printf("\n");
}

// 主函数：执行转换
int main(int argc, char const *argv[]) {
    Stack *s = initStack();
    printf("%s\n", expr);   // 输出原始中缀表达式
    postfix(s);             // 执行中缀转后缀
    return 0;
}
