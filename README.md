# 点阵图形编辑器

### 介绍

这个程序适用于编辑由MAX7219驱动的8*8点阵显示器的图形，输出结果为字符数组的格式，例如：

```c++
char lattice[]={8,8,
                    B00011100,
                    B00100010,
                    B01000010,
                    B10000100,
                    B10000100,
                    B01000010,
                    B00100010,
                    B00011100};
```



### 操作说明

使用方向键（↑↓←→）控制光标移动

按下回车将光标所在的灰色点变为红色 (点亮)

按下空格将光标所在的红色点变为灰色 (不点亮)

按下"c"键将结果保存到剪贴板

输出的默认字符数组名称为“lattice”，想改变名称，需要在“点阵图形编辑器.exe”的同一文件夹下放置一个名为“name.txt”的文本文档，里面写入你希望改成的名称，名称中不能含有空格或特殊字符，空格应用”_"代替。若“name.txt“为空，则输出名称仍为”lattice“

### Arduino操作

在输出结果后，将其粘贴到Arduino程序文档中，再使用：

```
m_name.writeSprite(0, 0, lattice_name);
```

就可以显示图形了。

以下为一个完整的示例：

```c++
#include <MaxMatrix.h> //8*8点阵头文件

char lattice[]={8,8,
                    B00011100,
                    B00100010,
                    B01000010,
                    B10000100,
                    B10000100,
                    B01000010,
                    B00100010,
                    B00011100};

char lattice[] = {1,8,B10000001};

int DIN = 7;   // DIN pin of MAX7219 module
int CLK = 6;   // CLK pin of MAX7219 module
int CS = 5;    // CS pin of MAX7219 module
MaxMatrix m(DIN, CS, CLK, 1); 
                
void setup()
{
    m.init(); // MAX7219 初始化
    m.setIntensity(0);
}

void loop()
{
      m.setIntensity(2);
      m.writeSprite(0, 0, lattice);
}
```

