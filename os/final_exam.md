# 20 + 22 + 30 + 13 + 15

## 15. 设计题 6 选 1

- 云 hypervisor 不可信: 避免 hypervisor 看到内存. CVM(confidential virtual machine). intel/AMD (TDX)(SEE) CPU 加密引擎. 密钥加密(内存热插拔也是安全的) (physical load 满了)(迁移问题？)  TrustZone (页表级加密)。 搞定迁移问题
- Secure Boot. (驱动不可信，写死的硬件检查，在 ROM 上厂商写死验证签名，Trust Chain CPU 至少是可信的) 如果发现内核镜像已经被破坏，如何快速恢复。(Linux Secure Boot?) (硬件可信)
- Thread. 内核线程 当作 进程(共享内存访问，但是保证隔离性，比如错误隔离)
- App safety. (背景 栈溢出攻击) 防止除了给定接口以外的方法读取栈空间。
- FS meta 信息 (云上 大规模文件系统)。反复更新元数据，需要加锁，避免元数据大锁。
- Page-Table 页表翻译并行化?

都别动硬件。

## 20. 第一题 传统

虚拟机页表 (EPT, Extended Page Table) 怎么翻译 (传统 GVA -> GPA -> HPA 需要 $n^2$ 数量级)，如何做的

网络包如何从 net -> host -> VM. (net 中断 -> 进入中断队列 -> host处理到一半发现自己不是要处理的中断 -> 直接往虚拟机的 EFlags 写, 告诉虚拟机在内存的哪一段，简而言之就是往虚拟机发一个外部中断)

VM (如何查询虚拟机里面的中断) (比如 Windows 要安装一个驱动，结果厂家只提供了 Linux 的接口，你开了个虚拟机，如何让虚拟机告诉 Windows 啊我接受到了一个中断) (虚拟机 RPC).

## 13. 第四题 并发

signal 信号量(semaphore P V) mutex (signal 可以实现 mutex 吗)

看起来很水

## 22.第二题 IO

MMIO  DMA(往某些地址写东西)

(from JYY):

- 总线 (PCI-E) 是 IO 设备的虚拟化，把一堆外部 IO 设别抽象为一个设备。总线识别传入的地址，并且判断并且分配到 内存/设备。
- CPU 接收到中断后，去设备 IO 那边读取数据 (较慢)
- DMA 属于是主动帮你把数据从 CPU <-> device 之间完成交换，这样在下次中断的时候，数据可能已经在更快访问的内存里了。

(still from JYY): 计算机里面充满了 CPU

- CPU: 大核 + 小核 + 超小核
- DMA: 执行了 memcpy() 的 CPU
- 打印机: 解析执行 PCL/PostScript 的 CPU
- 网卡: 分拣以太网 packet (frame) 的 CPU

## 30.  FS

管理硬盘数据

- 背景
- 各种文件系统

为应用的读写服务。

硬盘 ~ 块设备。块设备。被认为是一个连续可以存储数据的设备。(实际读取过程中是 IO)

一切设计更具需求

- 早期 FAT, EXT2 (不支持热插拔，运行中不能拔出)
- 文件系统不能自己不一致: 日志 (journal) (transaction，没写完就认为作废)
- 不需要再运行的时候写入(只要读): 只读文件系统 (文件系统不支持改，但是可以改下面的块设备)
- 利用多个存储设备: ZFS BTRFS

除了硬件 RAID，是否可以文件系统 RAID (ZFS ?)

File Allocation Table (两个备份)

- -1 表示空闲
- 0 表示结束。
- 整数表示后面的内容所在的簇
- 文件在 file allocation table 中是一个链表

根文件夹，其他文件(目录也是文件的斯)

问题：碎片化，效率低，长文件名支持差 (可以用 bitmap 啥的优化 :)

GPT (General partition table). MBR. 磁盘分区相关 (SB + FAT * 2 备份 ? 不会画图，建议看回放)

- Super Block
- block bitmap
- inode bitmap
- inode 表
- 数据 (目录也是文件)

小文件优化: 直接存在 inode 节点 (512B) 里面。

- 每个 inode 对应了一个文件
- 内部包含了元数据及数据位置
- 硬链接是两个目录项指向同一个 inode (所以 inode 是 ref count)
- 硬链接不支持目录(否则会爆)

Master File Table(有备份): 一个数据库，自己管理自己。

一切都是文件。

- 日志(journal)
- 透明压缩
- 稀疏文件 (inode 表中间为空)

为应用读写服务。

VFS

- 为不同类型的文件系统提供统一接口 (intermediate representation)
- 支持多文件系统
- 挂载(挂到现有 VFS 的一个目录里面，目录里面的文件会暂时无法访问)
- 利用文件系统的自由性，我们可以创造出好用接口 (procfs 什么的)

Page Cache

- 缓存文件内容
- 由 kernel 统一管理
- 映射 mmap 的内存
- Lazy Write Back
