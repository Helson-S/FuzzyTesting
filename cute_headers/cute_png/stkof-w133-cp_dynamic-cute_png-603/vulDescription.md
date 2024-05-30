# Description

stack-buffer-overflow bug/vulnerability caused by write access found in function cp_dynamic() at line 603 of cute_png.h v1.05. It will lead to control flow hijacking. Exploit demo is available in ./src/exploit_demo.c



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
./exploit_demo
```



# Screen-shot

![image-20240530011956991](vulDescription.assets/image-20240530011956991.png)



```shell
=================================================================
==3976==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7ffe1d3e27b0 at pc 0x55cae413ed96 bp 0x7ffe1d3e24b0 sp 0x7ffe1d3e24a0
WRITE of size 1 at 0x7ffe1d3e27b0 thread T0
    #0 0x55cae413ed95 in cp_dynamic /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/stkof-w133-cp_dynamic-cute_png-603/src/cute_png.h:603
    #1 0x55cae4147737 in cp_inflate /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/stkof-w133-cp_dynamic-cute_png-603/src/cute_png.h:697
    #2 0x55cae414f9b9 in cp_load_png_mem /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/stkof-w133-cp_dynamic-cute_png-603/src/cute_png.h:1178
    #3 0x55cae4150a01 in cp_load_png /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/stkof-w133-cp_dynamic-cute_png-603/src/cute_png.h:1215
    #4 0x55cae413a614 in main /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/stkof-w133-cp_dynamic-cute_png-603/src/poc_demo.c:8
    #5 0x7fea7f029d8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #6 0x7fea7f029e3f in __libc_start_main_impl ../csu/libc-start.c:392
    #7 0x55cae413a6f4 in _start (/home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/stkof-w133-cp_dynamic-cute_png-603/src/poc_demo+0x36f4)

Address 0x7ffe1d3e27b0 is located in stack of thread T0 at offset 704 in frame
    #0 0x55cae413dc0f in cp_dynamic /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/stkof-w133-cp_dynamic-cute_png-603/src/cute_png.h:581

  This frame has 5 object(s):
    [32, 96) 'codes' (line 487)
    [128, 192) 'first' (line 487)
    [224, 288) 'counts' (line 487)
    [320, 339) 'lenlens' (line 583)
    [384, 704) 'lens' (line 594) <== Memory access at offset 704 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow /home/helson/samba_local/share/publishing/draft/cute_headers/cute_png/stkof-w133-cp_dynamic-cute_png-603/src/cute_png.h:603 in cp_dynamic
Shadow bytes around the buggy address:
  0x100043a744a0: f1 f1 f8 f8 f8 f8 f8 f8 f8 f8 f2 f2 f2 f2 f8 f8
  0x100043a744b0: f8 f8 f8 f8 f8 f8 f2 f2 f2 f2 f8 f8 f8 f8 f8 f8
  0x100043a744c0: f8 f8 f2 f2 f2 f2 00 00 03 f2 f2 f2 f2 f2 00 00
  0x100043a744d0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100043a744e0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x100043a744f0: 00 00 00 00 00 00[f3]f3 f3 f3 f3 f3 f3 f3 00 00
  0x100043a74500: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100043a74510: 00 00 00 00 00 00 f1 f1 f1 f1 00 00 00 00 00 00
  0x100043a74520: 00 00 f2 f2 f2 f2 00 00 00 00 00 00 00 00 f2 f2
  0x100043a74530: f2 f2 00 00 00 00 00 00 00 00 f2 f2 f2 f2 00 00
  0x100043a74540: 00 00 00 00 00 00 f2 f2 f2 f2 00 00 00 00 00 00
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
==3976==ABORTING

```

