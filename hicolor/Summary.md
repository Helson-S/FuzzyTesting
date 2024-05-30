# Summary

Hi~，I did some fuzzy testing and found some bugs/vulnerabilities on hicolor v0.5.0. I hope these findings will help improve software quality.



These bugs/vulnerabilities are mainly caused by unsafe component cute_png.h v1.05. According to my analysis, Because the compilation environment of hicolor is inconsistent with the official compilation environment of cute_png.h v1.05, not all bugs in cute_png.h affect hicolor. The bugs/vulnerabilities listed below can truly affect hicolor v0.5.0.



All of the bugs/vulnerablities are triggered with no assertion raised. This means that these bugs/vulnerabilities are unexpected behaviors of the program. 



hicolor:  https://github.com/dbohdan/hicolor

cute_headers: https://github.com/RandyGaul/cute_headers
