# 编译配置命令

**配置编译目标为 ESP32：**

```bash
idf.py set-target esp32
```

**打开 menuconfig：**

```bash
idf.py menuconfig
```

**选择板子：**

```
Xiaozhi Assistant -> Board Type -> M5Stack Core M5go

```

**修改 flash 大小：**

```
Serial flasher config -> Flash size -> 16 MB
```

**修改分区表：**

```
```

**编译：**

```bash
idf.py build
```