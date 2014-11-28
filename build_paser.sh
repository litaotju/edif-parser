#!/bin/bash 
ls
rm    edn_bison.c edn_bison.h edn_flex.c  ./*~

bison -d -o edn_bison.c edn_bison.y
echo "the bison has been exed\n"
flex -v -o edn_flex.c edn_flex.l
echo "the flex has been exed\n"
ls
gcc -Wall -o edn_parse *.c
