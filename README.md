# ESP01SBlinker
ESP01s通过点灯科技接入小爱同学

使用Platform IO编译烧录

1.安装对应的串口驱动 这里安装wch的CH340SER（自行百度）

2.在Microsoft Visual Studio Code中安装Platform IO插件

3.在左侧导航栏中点击Platform IO图标

4.在右侧选择Open Project

[![Iv3dS0.png](https://z3.ax1x.com/2021/11/21/Iv3dS0.png)](https://imgtu.com/i/Iv3dS0)

5.根据目录找到本项目文件夹，选择开发板

[![Iv3ImD.png](https://z3.ax1x.com/2021/11/21/Iv3ImD.png)](https://imgtu.com/i/Iv3ImD)

ESP01S选择Adafruit HUZZAH ESP8266

6.在platformio.ini中修改串口号，windows在设备管理器查看，Mac中终端执行命令

```shell
ls -l /dev/cu.*
```

7.编辑src目录下main.cpp，根据实际情况修改line6、7、8中对应的字段

8.点击左下角对号编译，编译成功后点击向左箭头烧录固件

