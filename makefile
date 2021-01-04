all:
	rm -f isort txtfind
	gcc -Wall -o isort -c isort.c
	gcc -Wall -o txtfind -c txtfind.c
