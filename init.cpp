//init.cpp
//初始化组件

#include "luogu-solve.h"

void init(){
	// 准备编译、执行、编辑和查看源文件的命令
    sprintf(cr1, "g++ \"%s.cpp\" -o \"%s\" -std=c++14 -O2", pn, pn);  // 编译命令
    sprintf(cr2, "./\"%s\"", pn);  // 运行可执行文件的命令
    sprintf(es, "vim \"%s.cpp\"", pn);  // 编辑源文件的命令
    sprintf(rs, "cat \"%s.cpp\"", pn);  // 查看源文件的命令
    sprintf(fn, "%s.cpp", pn);  // 文件名
    sprintf(cg, "g++ \"%s.cpp\" -o \"%s\" -std=c++14 -g", pn, pn);
    sprintf(gc, "gdb %s", pn);
    sprintf(swp, "%s.swp",pn);
    sprintf(del, "rm %s.swp",pn);

    // 记录起始时间
    if(!load_swap(bt, &btt)){  // 启动时加载swap文件中的bt和btt信息
        btt = time(NULL);
        sprintf(bt, "%s", ctime(&btt));
        store_swap(bt, btt);// 存储bt和btt到swap文件
    }
}
