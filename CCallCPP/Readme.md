##编译
//hello.o 用C方式编译C库hello,c代码中期望使用C++库world类中的静态方法,又不希望参杂任何C++代码
> gcc -c hello.c

//world.o
> g++ -c world.cpp   用C++方式编译World类，纯C++语法

//tmp.c中需要用c的函数包装c++的方法，用C++方式编译
> g++ -c tmp.cpp

##链接
g++ -o main main.c hello/hello.o world/world.o tmp.o

//运行
> ./main
