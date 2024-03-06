# Chapter 3

Sv39: 27 entry + 12 offset = 39 bits. Top 25 bits should not be used.


PPN: Physical Page Number. 44 bits.

PTE: Page Table Entry. PPN + flags (10 bits).

Details: 27 bits virtual address -> 9 bits VPN2, 9 bits VPN1, 9 bits VPN0. 3-level page table **tree**.

> Why 9 bits? Because PTE is stored in 8 Bytes. 9 bits means 512 entries, so the size of page table is exactly 512 * 8 Byte= 4KB. It's well-designed.

![1709693424612](image/xv6/1709693424612.png)

satp: Supervisor Address Translation and Protection. PPN in satp is the physical base address of page table.

![Reader-Page-110](image/xv6/1709694307413.png)

