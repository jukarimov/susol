#!/bin/bash
# Remove dos trailing crap ^M

if test "$1" == ""; then
for i in *.c; do 
	xxd $i | sed 's/0d0a/200a/g' | \
			sed 's/0d  /20  /g' | \
			sed 's/0d 0a/20 0a/g' | \
			sed 's/0d 20/20 20/g' > $i.tmp;
	xxd -r $i.tmp > $i; 
done
rm *.tmp
fi

if test "$1" != ""; then
for i in *.c; do 
	xxd $1 | sed 's/0d0a/200a/g' | \
			sed 's/0d  /20  /g' | \
			sed 's/0d 0a/20 0a/g' | \
			sed 's/0d 20/20 20/g' > $1.tmp;
	xxd -r $1.tmp > $1; 
done
rm *.tmp
fi

