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
    char ret[10]="\n";
    if (swap_fp) {
        printf("Swap file(%s) exists. Do you want to restore the progress in it? (y/n)",swp);
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
	get_string(bt,'\n',swap_fp);
	strcat(bt,ret);
        if (fscanf(swap_fp, "%ld",btt) != 1) {
		printf("!!! The format of %s is not correct !!!\n",swp);
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

