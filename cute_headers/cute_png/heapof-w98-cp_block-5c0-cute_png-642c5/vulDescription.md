# Description

Heap-buffer-flow bug/vulnerability caused by write access found in function cp_block() at line 642 of cute_png.h v1.05.



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

![image-20240527234842953](vulDescription.assets/image-20240527234842953.png)



```shell
=================================================================
==4492==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x621000002580 at pc 0x7f2594c39c23 bp 0x7ffed748cce0 sp 0x7ffed748c488
WRITE of size 98 at 0x621000002580 thread T0
    #0 0x7f2594c39c22 in __interceptor_memset ../../../../src/libsanitizer/sanitizer_common/sanitizer_common_interceptors.inc:799
    #1 0x55f882b57cb0 in cp_block /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w98-cp_block-5c0-cute_png-642c5/src/cute_png.h:642
    #2 0x55f882b5828c in cp_inflate /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w98-cp_block-5c0-cute_png-642c5/src/cute_png.h:696
    #3 0x55f882b5c2ce in cp_load_png_mem /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w98-cp_block-5c0-cute_png-642c5/src/cute_png.h:1178
    #4 0x55f882b5c8a6 in cp_load_png /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w98-cp_block-5c0-cute_png-642c5/src/cute_png.h:1215
    #5 0x55f882b62542 in main /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w98-cp_block-5c0-cute_png-642c5/src/poc_demo.c:8
    #6 0x7f2594829d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #7 0x7f2594829e3f in __libc_start_main_impl ../csu/libc-start.c:392
    #8 0x55f882b55584 in _start (/home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w98-cp_block-5c0-cute_png-642c5/src/poc_demo+0x3584)

0x621000002580 is located 0 bytes to the right of 4224-byte region [0x621000001500,0x621000002580)
allocated by thread T0 here:
    #0 0x7f2594cb4887 in __interceptor_malloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:145
    #1 0x55f882b5bc7e in cp_load_png_mem /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w98-cp_block-5c0-cute_png-642c5/src/cute_png.h:1127
    #2 0x55f882b5c8a6 in cp_load_png /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w98-cp_block-5c0-cute_png-642c5/src/cute_png.h:1215
    #3 0x55f882b62542 in main /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/heapof-w98-cp_block-5c0-cute_png-642c5/src/poc_demo.c:8
    #4 0x7f2594829d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58

SUMMARY: AddressSanitizer: heap-buffer-overflow ../../../../src/libsanitizer/sanitizer_common/sanitizer_common_interceptors.inc:799 in __interceptor_memset
Shadow bytes around the buggy address:
  0x0c427fff8460: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c427fff8470: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c427fff8480: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c427fff8490: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c427fff84a0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c427fff84b0:[fa]fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c427fff84c0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c427fff84d0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c427fff84e0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c427fff84f0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c427fff8500: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
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
==4492==ABORTING

```

