## 1. 开发环境安装
```bash
sudo apt install gcc g++ make vim git net-tools openssh-server -y
```
2.github仓库连接
密匙可以重新创建，也可以从旧的Ubuntu复制

3.Linux 命令一般由三部分组成：
command 命令；
options 选项；
parameter 参数；
其中
rm -r 删除目录（不管是否为空）

rmdir	删除空目录,不能删非空目录吗

touch 修改文件时间，否则就创造文件

chgrp 改变文件所属用户组
chowm 改变文件的所有者
假如外设权限（比如串口）是这样:
crw-rw---- 1 root dialout 4, 64  3月 20 10:00 /dev/ttyUSB0
其中你会发现
主人（root）：rw- 读写
组（dialout）：rw- 读写
其他人：--- 啥也不能干
你现在是用户,显然你不属于 dialout 组,而你属于其他组，而且你还不是主人所以你的运行程序打开/dev/ttyUSB0的时候你会发现权限不足,那么现在你就有两种办法:
一是让这个串口设备属于你自己的用户组,
sudo chgrp study(我的用户名) /dev/ttyUSB0
另一种就是把你自己加入/dev/ttyUSB0所属于的组,也就是让你成为 dialout 组的成员.
sudo usermod -aG dialout study
那么你可能想知道有哪些组和用户呢？下面有两条指令
cut -d: -f1 /etc/passwd #查看用户
cut -d: -f1 /etc/group  #查看组
其中嵌入式开发者需要记住
组名	作用	使用场景
dialout	串口权限组	/dev/ttyUSB0 /dev/ttyS0 串口通信必用
plugdev	热插拔外设组	USB 设备、U 盘、外接硬件
gpio	GPIO 引脚组	控制开发板 IO 口高低电平
i2c	I2C 总线组	读写 I2C 传感器
spi	SPI 总线组	SPI 外设通信
video	视频设备组	摄像头、显示屏
audio	音频组	喇叭、麦克风
disk	磁盘存储组	读写硬盘、SD 卡
chmod [-R] xyz 文件或目录
xyz：代表权限的数值，如 770。
-R：以递归方式进行修改，比如修改某个目录下所有文件的属性。
范例：chmod 777 .bashrc
使用 u、g、o 三个字母代表 user、group、others 3 中身份。此外 a 代表
all，即所有身份。
范例：
chmod u=rwx,go=rx .bashrc
也可以增加或去除某种权限，“+”表示添加权限，“-”表示去除权限：
chmod a+w .bashrc
chmod a-x .bashrc

grep "关键词" 文件名
p你必须记住的 2 个参数
1) -i 不区分大小写
grep -i "root" /etc/passwd
ROOT、Root、root 都能搜到
2) -n 显示行号
grep -n "study" /etc/passwd
-r
3) -r 递归查找
= 不只搜当前目录，连里面所有子文件夹、孙子文件夹一起搜
grep只搜索文件内容，find搜索文件名和文件夹名

tar
仅打包归档，文件大小几乎不变，多用于整理目录
gzip(-z)
压缩速度快，压缩率中等，嵌入式、服务器通用首选,速度快、兼容性好，日常首选
bzip2(-j)
压缩率更高，文件更小，速度慢，源码包常用,压缩体积更小，速度慢

 -l(list) 列出压缩文件的内容。
 -k(keep) 在压缩或解压时，保留输入文件。
 -d(decompress) 将压缩文件进行解压缩。
 
 
 tar 常用选项：
-c(create)：表示创建用来生成文件包 。
-x(extract )：表示提取，从文件包中提取文件。
-t(list)：可以查看压缩的文件。
-z(gzip)：使用 gzip 方式进行处理，它与”c“结合就表示压缩，与”x“结合就表示解压缩。
-j(bzip2)：使用 bzip2 方式进行处理，它与”c“结合就表示压缩，与”x“结合就表示解压缩。
-v(verbose)：详细报告 tar 处理的信息。
-f(file)：必须放在所有选项最后,表示文件，后面接着一个文件名。 -C <指定目录> 解压到指定目录。
