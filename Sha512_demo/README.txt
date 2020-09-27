使用 sha512_1.c  测试可能需要升级openssl, 可用命令查看版本：openssl version  
我使用的升级版本为：‘OpenSSL 1.1.1c  28 May 2019’

编译
gcc sha512_1.c   -L/usr/local/lib  -lssl  -lcrypto -o 512
(-L/usr/local/lib: 使用的动态链接库的位置，具体根据自己实际情况更改)

gcc sha512_2.c -lssl 或者 gcc sha512_3.c -lssl

执行（t1是文件名）
./a.out  t1