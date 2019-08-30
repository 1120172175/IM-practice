#! /bin/bash
gcc -o  main main.c menu.c `pkg-config --cflags --libs gtk+-2.0`
./main
