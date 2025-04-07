#include <cstdio>
#include <cstdlib>
#include <ctime>

#ifndef _LUOGU_SOLVE_
#define _LUOGU_SOLVE_

extern void strcat(char *dst,char const *src);
extern void num2times(int n,char *s); // 将整数转换为序数表示（例如 1 -> "1st", 2 -> "2nd"）
extern void line(const char *str,bool double_line=false); // 用于输出分隔线的函数,参数 str 为输出的文本，double_line 为是否需要双重分隔线
extern void clear_buffer(); // 清除输入缓冲区的函数，避免残留字符影响输入读取
extern bool load_swap(char *bt,time_t *btt);
extern void store_swap(const char *bt,time_t btt);
extern void init(); //初始化
extern void get_string(char *str,const char stop='\n',FILE *fp=stdin); // 从指定文件流读取字符串并在读到指定字符时停止（字符串不包含指定字符）
extern int main();

// 定义用于存储各类信息的字符串缓冲区
extern char pn[1024];   // 用于存储问题编号（Problem Number）
extern char cr1[1024];  // 存储编译命令
extern char cr2[1024];  // 存储运行命令
extern char cg[1024];   // 存储带有调试信息的编译命令
extern char es[1024];   // 存储编辑命令
extern char rs[1024];   // 存储查看源文件命令
extern char fn[1024];   // 用于存储文件名
extern char bt[1024];   // 存储开始时间的字符串形式
extern char et[1024];   // 存储结束时间的字符串形式
extern char gc[1024];   // 存储调试命令
extern char swp[1024];  // 用于存储交换文件名
extern char del[1024];  // 存储删除交换文件命令

extern char f[102400];  // 用于存储源文件内容的缓冲区（最大100KB）

extern FILE *fp;        // 文件指针，用于读写源文件
extern time_t btt;      // 记录开始时间的时间戳
extern time_t ett;      // 记录结束时间的时间戳

extern int ds;          // 记录总时长的秒数
extern int dm;          // 记录总时长的分钟数

#endif //_LUOGU_SOLVE_

