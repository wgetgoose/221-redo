substring.c:
	gcc -Wall -Wextra -Werror substring.c -o substring
sets.o:
	gcc -Wall -Wextra -Werror sets.c -c sets.o
sets:
	gcc -Wall -Wextra -Werror sets.c -o sets
intersection: sets.o
	gcc -Wall -Wextra -Werror intersection.c sets.o -o intersection
clean:
	rm -r substring intersection sets.o sets
