# Final 2

## Page Table

too easy

## Virtualization

```plaintext
    App
------------
  sv  |  sv
------------   <--- Windows style: sv may be Windows, WSA, WSL ......
 Hypervisor
------------
  Hardware
```

```plaintext
     |
-----| APP
 VM  |
------------   <--- Linuxs style
   Kernel
------------
  Hardware
```

## Signal

```c
kill(pid, n)            /* send a signal to given pid */
raise(n)                /* = kill(getpid(), n)  */
signal(n, sighandler)   /* register a signal handler. if signal n arrives,  */ 
```

## What the fuck

EPT?

GVA -> GPA -> HPA

EXT2/4
