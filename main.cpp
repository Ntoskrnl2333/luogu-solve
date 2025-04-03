//main.cpp
//主组件

#include "luogu-solve.h"

// 定义用于存储各类信息的字符串缓冲区
char pn[1024];   // 用于存储问题编号（Problem Number）
char cr1[1024];  // 存储编译命令
char cr2[1024];  // 存储运行命令
char cg[1024];   // 存储带有调试信息的编译命令
char es[1024];   // 存储编辑命令
char rs[1024];   // 存储查看源文件命令
char fn[1024];   // 用于存储文件名
char bt[1024];   // 存储开始时间的字符串形式
char et[1024];   // 存储结束时间的字符串形式
char gc[1024];   // 存储调试命令
char swp[1024];  // 用于存储交换文件名
char del[1024];	 // 存储删除交换文件命令

char f[102400];   // 用于存储源文件内容的缓冲区（最大100KB）

FILE *fp;        // 文件指针，用于读写源文件
time_t btt;      // 记录开始时间的时间戳
time_t ett;      // 记录结束时间的时间戳

int ds;          // 记录总时长的秒数
int dm;          // 记录总时长的分钟数
int p;           // 用于在读取问题编号或源文件时的字符位置


int main() {
    // 获取问题编号
    printf("Problem Number: ");
    p = 0;
    while ((pn[p] = getchar()) != '\n') p++;
    pn[p] = 0;

    init();

    // 启动 Vim 编辑器进行代码编辑
    system(es);

    // 菜单循环
    while (true) {
        line("Menu", true);  // 显示菜单
        printf("Next Step:\n  1.Compile and run\n  2.Only run\n  3.Edit source file\n  4.Debug with gdb\n  5.Drop to bash\n  6.Ready to submit\n Your answer:");
        int x;
    LABEL_READ:
        // 读取用户输入的选项
        int rtn = scanf("%d", &x);
        if (rtn != 1) {
            clear_buffer();  // 清空错误输入
            goto LABEL_READ;  // 重新读取输入
        }
	
	char *tmp;
        // 根据用户选择执行相应操作
        switch (x) {
            case 1:  // 编译并运行
                line("Compiling");
                if (system(cr1))  // 执行编译命令，如果编译失败，退出编译部分
                    break;
                line("Running");
		tmp=new char[1024];
                sprintf(tmp,"Program exited with value %d",system(cr2)); //执行可执行文件
		line(tmp);
		delete[] tmp;
                break;
            case 2:  // 只运行
                line("Running");
		tmp=new char[1024];
                sprintf(tmp,"Program exited with value %d",system(cr2));
		line(tmp);
		delete[] tmp;
                break;
            case 3:  // 编辑源文件
                system(es);
                break;
            case 4:  // 使用 gdb 进行调试
                line("Compiling with debug information");
                if(system(cg))

                line("GDB -- Use 'quit' to exit GDB");
                system(gc);
                break;
            case 5:  // 进入 Bash 终端
                line("Bash -- Use \"exit\" or Ctrl-D to back to menu");
                system("bash");  // 启动 Bash 终端
                break;
            case 6:  // 准备提交
                // 记录结束时间和时长
                ett = time(NULL);
                sprintf(et, "%s", ctime(&ett));
                ds = ett - btt;
                dm = ds / 60;
                ds -= dm * 60;

                // 打开源文件并写入提交信息
                fp = fopen(fn, "r");
                if (fp == NULL) {
                    printf("\n\n  !!! Failed to open %s !!!", fn);
                    break;
                }
                p = 0;
                while (fscanf(fp, "%c", f + p) != EOF) p++;  // 读取文件内容
                fclose(fp);

                // 重新写入文件，附加时间信息
                fp = fopen(fn, "w");
                fprintf(fp, "//time:%s//  -- %s//duration: %dmin(s) %dsec(s)\n\n%s", bt, et, dm, ds, f);
                fclose(fp);

                // 显示结果
                line("Result");
                system(rs);
                system(del); // 正常退出时删除 swap 文件
                return 0;  // 退出程序
        }
    }
    return 0;
}

