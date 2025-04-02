//swap.cpp
//交换文件相关组件

#include "luogu-solve.h"

void store_swap(const char *bt, time_t btt) {
    FILE *swap_fp = fopen(swp, "w");
    if (swap_fp) {
        fprintf(swap_fp, "%s", bt);  // 存储开始时间的字符串形式
        fprintf(swap_fp, "%ld", btt);  // 存储开始时间的时间戳
        fclose(swap_fp);
    }
}

bool load_swap(char *bt, time_t *btt) {
    FILE *swap_fp = fopen(swp, "r");
    bool success=true;
    if (swap_fp) {
        printf("Swap file(%s) exists. Do you want to restore the pregress in it? (y/n)",swp);
        char *tmp=new char[1024];
    LABEL_READ:
        scanf("%s",tmp);
        if(tmp[0]=='y' || tmp[0]=='Y')
                goto LABEL_RESTORE;
        else if(tmp[0]=='n' || tmp[0]=='N')
                goto LABEL_NORESTORE;
        else
                goto LABEL_READ;
    LABEL_RESTORE:
        if (fscanf(swap_fp, "%1023s", bt) != 1 || fscanf(swap_fp, "%ld", btt) != 1) {
            success=false;
        }
    LABEL_NORESTORE:
        delete[] tmp;
        fclose(swap_fp);
    }
    else
        success=false;
    return success;
}

