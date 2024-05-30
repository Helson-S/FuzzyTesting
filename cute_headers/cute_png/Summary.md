# Summary

Hi~，I did some fuzzy testing and found some bugs/vulnerabilities on cute_png v1.05. I hope these findings will help improve software quality.



All of the bugs/vulnerabilities trigger no assertion before bug/vulnerability. Only one bug/vulnerability triggers assertion after stack overflow. This means that these bugs/vulnerabilities are unexpected behaviors of the program. A sheet for it is shown below.



cute_headers: https://github.com/RandyGaul/cute_headers



| Dictionary Name                            | Assertion raised during execution | Assertion raised before bug/vulnerability? | Assertion raised after bug/vulnerability?  |
| ------------------------------------------ | --------------------------------- | ------------------------------------------ | ------------------------------------------ |
| heapof-r1-cp_load_png_mem-cute_png-1104c14 | No                                | No                                         | No                                         |
| heapof-r1-cp_load_png_mem-cute_png-1105c15 | No                                | No                                         | No                                         |
| heapof-r1-cp_load_png_mem-cute_png-1132c14 | No                                | No                                         | No                                         |
| heapof-r1-cp_make32-cute_png-948c10        | No                                | No                                         | No                                         |
| heapof-r1-cp_unfilter-cute_png-1017c11     | No                                | No                                         | No                                         |
| heapof-r1-cp_unfilter-cute_png-1019c11     | No                                | No                                         | No                                         |
| heapof-r4-cp_chunk-cute_png-956c7          | No                                | No                                         | No                                         |
| heapof-r4-cp_find-cute_png-979c8           | No                                | No                                         | No                                         |
| heapof-r8-cp_load_png_mem-cute_png-1099c2  | No                                | No                                         | No                                         |
| heapof-r65280-cp_stored-cute_png-543c2     | No                                | No                                         | No                                         |
| heapof-w1-cp_block-cute_png-623c12         | No                                | No                                         | No                                         |
| heapof-w16-cp_block-cute_png-644c37        | No                                | No                                         | No                                         |
| heapof-w98-cp_block-5c0-cute_png-642c5     | No                                | No                                         | No                                         |
| segv-none-cp_make32-cute_png-948c10        | No                                | No                                         | No                                         |
| stkof-w1-cp_dynamic-cute_png-601c71        | Yes                               | No                                         | Yes                                        |
| stkof-w133-cp_dynamic-cute_png-603         | No                                | No                                         | No(Infinite Loop or Stack smashing dected) |
| uaf-none-cp_make32-cute_png-948c10         | No                                | No                                         | No                                         |