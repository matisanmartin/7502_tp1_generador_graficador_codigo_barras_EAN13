#! /bin/bash

gcc -Wall -ansi -pedantic -o tp1_parte1 tp1_parte1.c
gcc -Wall -ansi -pedantic -o tp1_parte2 tp1_parte2.c


while read line
do 
   echo -e "$line\n"
   ./tp1_parte1 | ./tp1_parte2 > codigo.pbm
done < codigos.txt
