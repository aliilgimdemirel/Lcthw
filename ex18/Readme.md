# Pointers to Functions

## What we learn;

### From the book:
* Write it: `type nameOfFunction(parameters)`
* Wrap it: `type` **`(*`**` nameOfFunction`**)**`(parameters)`
* Rename it: `type (* `**`funcPTRname`**`)(parameters)`
* Add it: **`typedef`** `type (* funcPTRname)(parameters)`

## other findings;
### Xcredit 3
Passing in the wrong function is sort of a disaster because the compiler does not even give an Error!

> `test_sorting(numbers, count, die);`

The line above generated the following error:
> ex18.c:114:31: warning: passing argument 3 of ‘test_sorting’ from incompatible pointer type [-Wincompatible-pointer-types]
>  test_sorting(numbers, count, die);                               
> ex18.c:77:6: note: expected ‘compare_cb {aka int (*)(int,  int)}’ but argument is of type ‘void (*)(const char *)’
> void test_sorting(int *numbers, int count, compare_cb cmp)

Only a warning and a note!


### Xcredit 4

> `test_sorting(numbers, count, NULL);`

results as:

> 42		`for (i = 0; i < count; i++) {`
> 
> (gdb) n
> 
> 43			`for (j = 0; j < count - 1; j++) {`
> 
> (gdb)
> 
> 44			`	if( cmp( target[j], target[j + 1] ) > 0) {`
> 
> (gdb) n
> 
> Program received signal SIGSEGV, Segmentation fault.
> 
> 0x0000000000000000 in ?? ()

### Xcredit 5

implemented selection_sort without linked-lists, and with added max/min position selection via a pointer to function. it was entertaining.
