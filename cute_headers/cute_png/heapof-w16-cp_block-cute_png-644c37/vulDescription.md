# Description

Heap-buffer-flow bug/vulnerability caused by write access found in function cp_block() at line 644 of cute_png.h v1.05. What's more, sample12.png provided as attack vector causes unmap invalid pointer memory corruption in function cp_load_png_mem() at line 1189 of cute_png.h v1.05.



Affected version: cute_png v1.05



# Reproduction

Environment:



Operating system version: Ubuntu 22.04



Linux kernel version: Linux pc 5.19.0-41-generic #42~22.04.1-Ubuntu SMP PREEMPT_DYNAMIC Tue Apr 18 17:40:00 UTC 2 x86_64 x86_64 x86_64 GNU/Linux



Compiler version: gcc version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)



Run the following command in bash shell:

```shell
#!/bin/bash 
pushd src
make
./poc_demo
```



# Screen-shot

## heap-buffer-overflow

![image-20240527234608807](vulDescription.assets/image-20240527234608807.png)



```shell
=================================================================
==4468==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x61900000047c at pc 0x55a1b8343d3e bp 0x7ffc646c1640 sp 0x7ffc646c1630
WRITE of size 1 at 0x61900000047c thread T0
    #0 0x55a1b8343d3d in cp_block /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w16-cp_block-cute_png-644c37/src/cute_png.h:644
    #1 0x55a1b834428c in cp_inflate /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w16-cp_block-cute_png-644c37/src/cute_png.h:696
    #2 0x55a1b83482ce in cp_load_png_mem /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w16-cp_block-cute_png-644c37/src/cute_png.h:1178
    #3 0x55a1b83488a6 in cp_load_png /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w16-cp_block-cute_png-644c37/src/cute_png.h:1215
    #4 0x55a1b834e542 in main /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w16-cp_block-cute_png-644c37/src/poc_demo.c:8
    #5 0x7fe942c29d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #6 0x7fe942c29e3f in __libc_start_main_impl ../csu/libc-start.c:392
    #7 0x55a1b8341584 in _start (/home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w16-cp_block-cute_png-644c37/src/poc_demo+0x3584)

0x61900000047c is located 0 bytes to the right of 1020-byte region [0x619000000080,0x61900000047c)
allocated by thread T0 here:
    #0 0x7fe9430b4887 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x55a1b8347c7e in cp_load_png_mem /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w16-cp_block-cute_png-644c37/src/cute_png.h:1127
    #2 0x55a1b83488a6 in cp_load_png /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w16-cp_block-cute_png-644c37/src/cute_png.h:1215
    #3 0x55a1b834e542 in main /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w16-cp_block-cute_png-644c37/src/poc_demo.c:8
    #4 0x7fe942c29d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

SUMMARY: AddressSanitizer: heap-buffer-overflow /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w16-cp_block-cute_png-644c37/src/cute_png.h:644 in cp_block
Shadow bytes around the buggy address:
  0x0c327fff8030: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c327fff8040: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c327fff8050: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c327fff8060: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c327fff8070: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c327fff8080: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00[04]
  0x0c327fff8090: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c327fff80a0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c327fff80b0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c327fff80c0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c327fff80d0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
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
==4468==ABORTING

```





## unmap invalid pointer

![image-20240529153300073](vulDescription.assets/image-20240529153300073.png)



![image-20240529153334319](vulDescription.assets/image-20240529153334319.png)



