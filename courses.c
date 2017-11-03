#include <stdio.h>
#include <string.h>

// 此处 courses 数据不要做任何改动
// courses 变量名不许修改
char *courses[] = {"C","C++","PHP","ASP","ASP.NET","C#","JAVA","BASIC","PASCAL","COBOL"};

void sort(char*p[], int n) {      //  传入的是指向char类型的指针数组，要加*
    char *tmp;
    int i, j, k;
    for (i = 0; i < n; ++ i) {
        k = i;
        for (j = i; j < n; ++ j) {
            if (
               // TODO:
		strcmp(p[k],p[j]) > 0
                ) {
                k = j;           //使下标移到最小的那一个值上
            }
        }
        if (k != i) {                       //发生了一次变化就需要执行交换操作
            tmp = p[k];
            p[k] = p[i];
            p[i] = tmp;
        }
    }
}

int main() {
    int n = sizeof(courses)/sizeof(char*);              //sizeof的用法与strlen的用法区别
    sort(courses, n);
    int i;
    for (i = 0; i < n; ++ i) {
        printf("%s\n" ,courses[i]);              //注意字符串本身就以字符数组的首地址表示，此处不需要加*
    }
    return 0;
}
