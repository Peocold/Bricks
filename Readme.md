# Bricks

> 一个简单的打砖块小游戏，拿来cmake练手

## 规则
1. wasd控制飞机位置，j发弹
2. 砖块接触子弹或被飞机接住会消失，砖块落到底游戏结束
3. 按p暂停，空格继续/再来一局，esc退出

## 快速安装并运行
在项目文件夹下进入终端，输入
```bash
mkdir build && cd build
cmake ..
make
cmake -DCMAKE_INSTALL_PREFIX=/tmp ..
make install
```
安装完毕，运行
```bash
cd /tmp/bricks/bin && ./bricks
```