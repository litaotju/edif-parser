#!/bin/bash 
ls

bison --w=all -d -o edn_bison.c edn_bison.y
echo "the bison has been exed\n"
flex -v -o edn_flex.c edn_flex.l
echo "the flex has been exed\n"
ls
gcc -o edn_lexer edn_flex.c edn_main.c -lfl

 ./edn_lexer ./test_dir/and_2bits.edn
