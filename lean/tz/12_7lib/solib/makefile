outd:test.c libadd.so
	gcc $^ -o $@
libadd.so:add.c
	gcc add.c -shared -fPIC -o libadd.so
clean:
	rm libadd.so outd
