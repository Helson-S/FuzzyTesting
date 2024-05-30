# Description

Heap-buffer-flow bug/vulnerability caused by write access found in function cp_block() at line 623 of vendor/cute_png.h v1.05. What's more, sample11.png provided as attack vector causes double-free heap memory corruption in function cp_load_png() at line 1216 of vendor/cute_png.h v1.05.



Affected version: hicolor v0.5.0



# Reproduction

Environment:



Operating system version: Ubuntu 22.04



Linux kernel version: Linux pc 5.19.0-41-generic #42~22.04.1-Ubuntu SMP PREEMPT_DYNAMIC Tue Apr 18 17:40:00 UTC 2 x86_64 x86_64 x86_64 GNU/Linux



Compiler version: gcc version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)



Compile hicolor with ASAN and run the following command in bash shell:

```shell
hicolor encode -a ./poc/sample11.png ./output.hic && rm -f ./output.hic
```



# Screen-shot

## heap-buffer-overflow

![image-20240530185401405](vulDescription.assets/image-20240530185401405.png)



```shell
=================================================================
==4008==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x7f29059fecac at pc 0x556dcedc0df0 bp 0x7ffc9c6d8b00 sp 0x7ffc9c6d8af0
WRITE of size 1 at 0x7f29059fecac thread T0
    #0 0x556dcedc0def in cp_block vendor/cute_png.h:623
    #1 0x556dcedca95f in cp_inflate vendor/cute_png.h:697
    #2 0x556dcedd2b69 in cp_load_png_mem vendor/cute_png.h:1178
    #3 0x556dcedd5adf in cp_load_png vendor/cute_png.h:1215
    #4 0x556dcedd5adf in png_to_hicolor /home/helson/samba_local/share/publishing/draft/hicolor/compile_asan/hicolor/cli.c:106
    #5 0x556dcedbdeff in main /home/helson/samba_local/share/publishing/draft/hicolor/compile_asan/hicolor/cli.c:558
    #6 0x7f2909029d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #7 0x7f2909029e3f in __libc_start_main_impl ../csu/libc-start.c:392
    #8 0x556dcedbe094 in _start (/home/helson/samba_local/share/publishing/draft/hicolor/compile_asan/hicolor/hicolor+0x5094)

0x7f29059fecac is located 0 bytes to the right of 1094828-byte region [0x7f29058f3800,0x7f29059fecac)
allocated by thread T0 here:
    #0 0x7f29094b4887 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x556dcedd2752 in cp_load_png_mem vendor/cute_png.h:1127
    #2 0x7ffc9c6d900f  ([stack]+0x1e00f)
    #3 0x8000000000000005  (<unknown module>)

SUMMARY: AddressSanitizer: heap-buffer-overflow vendor/cute_png.h:623 in cp_block
Shadow bytes around the buggy address:
  0x0fe5a0b37d40: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0fe5a0b37d50: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0fe5a0b37d60: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0fe5a0b37d70: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0fe5a0b37d80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0fe5a0b37d90: 00 00 00 00 00[04]fa fa fa fa fa fa fa fa fa fa
  0x0fe5a0b37da0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0fe5a0b37db0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0fe5a0b37dc0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0fe5a0b37dd0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0fe5a0b37de0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==4008==ABORTING

```





## double-free heap memory corruption

![image-20240530185451914](vulDescription.assets/image-20240530185451914.png)



![image-20240530185539214](vulDescription.assets/image-20240530185539214.png)
