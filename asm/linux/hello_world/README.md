
# compiling `.c` file to assembly
- `-S`
- `-O`
- `-fno-asynchronous-unwind-tables`
- `-fcf-protection=none`
```bash
    gcc -S -O -fno-asynchronous-unwind-tables -fcf-protection=none return_2.c
    gcc -S -O -fno-asynchronous-unwind-tables -fcf-protection=none hello_world.c
```

# Generate/Print preprossing file
- `-P`
- `-E'

```bash
   gcc -P -E hello_world.c 
   gcc -P -E return_2.c 
```
