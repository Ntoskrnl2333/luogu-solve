# luogu-solve

A basic CLI C++ IDE on linux **with a timer**

一个基础的Linux控制台C++ IDE，并且**带有一个计时器**

---
### 功能
- 一键编译运行或运行
- 自动显示程序返回值
- 一键打开编辑器
- 一键打开GDB进行调试
- 一键打开bash
- 自动计时
- 自动在文件头部写入编辑起止时间和时长
- 自动保存开始时间到硬盘防止意外

---
### 运行

```bash
make
luogu-solve
```
生成的可执行文件`luogu-solve`会自动借助`sudo`放进`/usr/local/bin/`里，若不想这么做就运行以下命令来只编译可执行文件。
```bash
make luogu-solve
```

---
### 交换文件

交换文件名为 ***{题目编号}.swp***。

交换文件为一个*ASCII*文本文档，第一行为开始时间的可读格式的日期和时间信息，第二行是十进制的开始时间的UNIX时间戳。
##### 示例：
```
Wed Apr  2 21:18:06 2025
1743599886
```

---
### 待办

启动GDB时有UI会莫名其妙地消失

---
#### 其他

之所以叫这个名字主要是因为这个IDE一开始是为了洛谷刷题用的。

这个IDE有几个早期版本没有保存，且有一些奇怪的变量名因历史包袱难以修改，如：

- char *cr1*[1024] (**compile** and **run** 1) //***编译***命令
- char *cr2*[1024] (**compile** and **run** 2) //***运行***命令
