install:
	gcc -o pyroname pyroname.c
	-mv ./pyroname /usr/bin/
	-rm ./pyroname.c

