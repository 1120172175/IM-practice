#! /bin/bash
gcc -o  menu menu.c userinfo_display.c `pkg-config --cflags --libs gtk+-2.0`
./menu
