## 生成字库

1. 下载 https://processing.org/download/ 并安装

2. 运行此目录下的 `get_all_unicodes_in_src.py` 脚本，生成 `unicodes.txt` 文件

3. 将 `unicodes.txt` 文件中的内容贴到 lib\TFT_eSPI\Tools\Create_Smooth_Font\Create_font\Create_font.pde 的 `specificUnicodes` 数组中

4. 运行 `Create_font.pde`，生成 `font.h` 文件
