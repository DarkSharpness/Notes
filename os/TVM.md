# TVM

解决: 深度学习部署到各种硬件上

## 背景

深度学习的模型非常 nb, 我们需要大量的高效的 deep learning 程序，这就需要一个高效的 deep learning 编译器，帮我们把程序真正的、高效的跑在各种硬件上，比如 CPU、GPU、TPU 、FPGA 等等。

概念:

- 计算图 Computation Graph
- Kernel
- 算子融合 Operator fusion
- Shared/Global Memory

## 传统方案

计算图作为 IR (intermediate representation) 来实施优化。劣势在于太 high-level 了，无法做出一些硬件相关的优化。

而大部分框架只会 focus on 非常少的一部分 GPU 设备，并且用 highly engineered 并且 vendor-specific 的算子库。这些 operator library 需要人工 tuning 过于专用化，不具有可迁移性。

一些 balance:

- 一些图上优化产生的算子，可能不在当前的算子库里面。
- 使用了一些算子，但是这些算子是还没被优化过的。

## 摘要

> We built TVM, a compiler that takes a high-level specification of a deep learning program from existing frameworks and generates low-level optimized code for a diverse set of hardware back-ends.

介绍的 challenge:

1. 利用特定的硬件 feature 和 抽象
   - 给定 input operator 描述去优化，优化有很多种的选择
   - 加速器需要精细控制，甚至需要利用流水线机制去隐藏内存访问的延迟
2. 优化的搜索空间巨大
   - 挑战在于不能手调 (tuning) operator, 而可调的配置很多 (循环倾斜、缓存、展开等等)
   - cost model 难以精确地建立，硬件只会越来越复杂。

解决的方法:

- 新的张量表达式的语言
- 自动程序优化的框架，使用基于 ML 的 cost model 去 guide 优化器。
- 最 top-level 处，引入了一个 graph rewriter 去充分利用 算子 level 的优化。

贡献:

- 找出 major optimization challenges
- 引入了全新的 schedule primitives (调度原语?), 可以带来好处(cross-thread memory reuse, novel hardware intrinsics, and latency hiding)
- 提出并且实现了 TVM 这个基于 ML 的优化系统
- 端到端，允许从那些 high-level 的框架(比如 TensorFlow, MXNet, PyTorch) 到各种后端。

## 优化计算图

- 算子融合——这样就不用把中间结果存到 memory 里面了
- 数据 layout 转换 (比如行/列哪个优先, 即column/row major)

## 生成张量操作

> decoupling descriptions from computation rules (or schedule optimizations)

- An index formula expression language. Build a schedule by incrementally applying basic transformations (schedule primitives) that preserve the program’s logical equivalence.
- Nested Parallelism + Cooperation. Parallelism = Divide the computation. Share-nothing = working thread do not look at its sibling. Cooperative = groups of threads cooperatively fetch the data they need and place it into shared memory(fast,small, cache-like) space.
- Tensorization (analogous to vectorization for SIMD architectures but has significant difference) (行为 behavior 和生成 hardware intrinsics 分离, 为的是更好的可拓展性)
- Explict Memory Latency Hiding. Overlapping memory operations with computation to maximize utilization of memory and compute resources. (主要是 TPU 这种加速器, 一般把细粒度的同步交给 software 去做).

## 自动优化

在已经有很多的调度原语之后, 需要找到一个好的优化方案 (operator implementation), 针对 DL model 的每一层.

- 调度空间指定
- ML-based cost model. Schedule explorer proposes configurations. For each configuration, a ML model predicts the execution time on given hardware. Model 会用一些 runtime 时候测量的数据, 甚至可能不需要用户主动提供硬件相关的信息.

选择 Schedule Explorer 基于的 ML model 时候的考虑: quality, speed.
