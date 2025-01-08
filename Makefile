all: a b
a: a.c
  gcc -Wall -Wextra -o a a.c
b: b.c
	gcc -Wall -Wextra -o b b.c
