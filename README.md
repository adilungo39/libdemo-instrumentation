# libdemo.so Dynamic Instrumentation (LD_PRELOAD)

> EN: Observe-only LD_PRELOAD instrumentation for a self-owned libdemo.so: interpose `demo_add`, log args/latency to CSV, plot histogram; includes GitHub Actions CI.  
> ZH: 使用 LD_PRELOAD 对自有 libdemo.so 进行“仅观测”插桩：拦截 `demo_add`，记录参数与延迟到 CSV 并绘制直方图，内置 GitHub Actions CI。

[![CI](https://img.shields.io/github/actions/workflow/status/adilungo39/libdemo-instrumentation/ci.yml?branch=main&label=CI)](https://github.com/adilungo39/libdemo-instrumentation/actions)
[![License](https://img.shields.io/github/license/adilungo39/libdemo-instrumentation)](https://github.com/adilungo39/libdemo-instrumentation/blob/main/LICENSE)
![Platform](https://img.shields.io/badge/platform-Linux-blue)
![C Standard](https://img.shields.io/badge/C-gnu99-blue)
![Python](https://img.shields.io/badge/Python-3.10%2B-3776AB)

## Requirements
- Linux (glibc), gcc, Python 3 with pandas and matplotlib

## Build
