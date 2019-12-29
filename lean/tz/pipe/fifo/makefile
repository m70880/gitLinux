.PHONY:out
out:reader write
reader:reader.c
	gcc $^ -o $@ -g
write:write.c
	gcc $^ -o $@ -g
clean:
	rm reader write
