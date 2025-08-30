#定义变量
#src=sub.o add.o mult.o div.o main.o
#在src这个文本字符串里将.c后缀，修改为.o后缀
src=$(wildcard ./*.c)
objs=$(patsubst %.c, %.o, $(src))
target=app
$(target):$(objs)
	$(CC) $(objs) -o $(target)
%.o:%.c
	$(CC) -c $< -o $@

#定义clean是一个尾目标。表示clean不需要生成文件
.PHONY:clean
clean:
	rm $(objs) -f
