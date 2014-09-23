该项目文件包括5个：linktable.c    linktable.h   menu.c   menu.h  testmenu.c
linktable.c  与 linktable.h 为链表模块化
menu.c 与 menu.h 为菜单模块化
testmenu.c为主文件

使用指南：将该压缩包下5个文件存放于同一文件夹下

编译指令： gcc linktable.c linktable.h menu.c menu.h testmenu.c -o test
运行指令： ./test

功能描述：help 显示菜单（运行./test之后输入help指令即可显示初始化的菜单，包括5个命令）
        add  增减菜单命令
        del  删除菜单命令
        version 显示版本信息
        exit 退出

注意增加的菜单命令 名字name不超过char[20] 命令描述不超过char[40],在增加菜单命令后输入help指令即可看到更新后的菜单，查看更改是否成功。

如有其他任何不明白之处欢迎联系：QQ：244872839
非常感谢！^_^
 
           


