//io.cpp
//输入输出相关组件

#include "luogu-solve.h"

// 用于输出分隔线的函数
// 参数 str 为输出的文本，double_line 为是否需要双重分隔线
void line(const char *str, bool double_line /*= false*/) {
    if (!double_line)
        printf("\n\n------%s------\n\n", str);
    else {
        int len;
        for (len = 0; len < 64; len++)
            if (str[len] == 0)
                break;
        printf("\n\n");
        for (int i = 0; i < len + 12; i++)
            putchar('-');
        printf("\n------%s------\n", str);
        for (int i = 0; i < len + 12; i++)
            putchar('-');
        printf("\n\n");
    }
}

// 清除输入缓冲区的函数，避免残留字符影响输入读取
void clear_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); // 读取直到换行符或 EOF
}

// 从指定文件流读取字符串并在读到指定字符时停止（字符串不包含指定字符）
void get_string(char *str,const char stop,FILE *fp){
	char ch;
	while(true){
		ch=fgetc(fp);
		if(ch==stop || ch==EOF)
			break;
		*str=ch;
		*str++;
	}
	*str=0;
}
