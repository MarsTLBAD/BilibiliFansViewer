# B站粉丝数显示器 使用说明
### 作者：迷茫的嘉鸿
#### 1.如果是直接使用，使用前请先将主程序和wget放在一个单独的文件夹里。
#### 2.如果是从源代码编译生成，不要直接在编译器里调试运行，否则会显示找不到wget。请将生成的exe文件拿出来与wget放在一个单独的文件夹里，然后再运行。
#### 3.工作文件夹里尽量不要放其他文件，尤其是stat和upstat开头的文件，否则会被程序当做旧API文件误删【相应代码：system("del stat*");】。  
#### 4.v1.0版本只能用于实时显示粉丝数，v1.3版本可以实时显示粉丝数和点赞数，并将数据记录到同一目录下的record.txt中。  
#### 5.所有程序完全开源，大家可随意使用或改造。Wget源代码可在其官网找到。  
***
# Bilibili Fans Viewer Instructions
### Author: Jiahong
#### 1. If it is used directly, please put the main program and wget in a separate folder before using it.
#### 2. If it is compiled from source code, do not debug and run directly in the compiler, otherwise it will show that wget cannot be found. Please take out the generated exe file and wget in a separate folder, and then run it.
#### 3. Try not to put other files in the working folder, especially the files starting with stat and upstat, otherwise it will be mistakenly deleted by the program as the old API file [corresponding code: system ("del stat *");].
#### 4. Version 1.0 can only be used to display the number of fans in real time, and version 1.3 can display the number of fans and likes in real time, and record the data in record.txt in the same directory.
#### 5. All programs are completely open source, everyone can use or modify at will. Wget source code can be found on its official website.
