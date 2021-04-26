
#### grep trick:

grep -A<N> print the N lines after what you find with grep

#### disassembly

'objdump' dumps the assembly

```
$ objdump --x86-asm-syntax=intel -D a.out | grep -A20 main.:
```

