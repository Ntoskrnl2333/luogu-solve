//util.cpp
//公用组件

#include "luogu-solve.h"

void strcat(char *dst,char const *src){
        while(*dst!=0)
                dst++;
        while(*src!=0){
                *dst=*src;
                dst++,src++;
        }
        *dst=0;
}

// 将整数转换为序数表示（例如 1 -> "1st", 2 -> "2nd"）
void num2times(int n, char *s) {
    sprintf(s, "%d", n);
    int last_digit = n % 10;
    int last_two_digits = n % 100;
    if (last_two_digits >= 11 && last_two_digits <= 13) {
        strcat(s, "th");
    } else if (last_digit == 1) {
        strcat(s, "st");
    } else if (last_digit == 2) {
        strcat(s, "nd");
    } else if (last_digit == 3) {
        strcat(s, "rd");
    } else {
        strcat(s, "th");
    }
}
