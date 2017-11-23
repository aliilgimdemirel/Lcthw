# Pointers to Functions

## What we learn;
* Structs
* malloc / free
* assert
* strdup (string duplicate)


###From the book:
* Write it: type nameOfFunction(parameters)
* Wrap it: `type` **`(*`**` nameOfFunction`**)**`(parameters)`
* Rename it: `type (* `**`funcPTRname`**`)(parameters)`
* Add it: **`typedef`** `type (* funcPTRname)(parameters)`

## other findings;
### Xcredit 3
Passing in the wrong function is sort of a disaster bcz the compiler does not given an Error !

>'test_sorting(numbers, count, die);'
The line above generated the following error: 
>ex18.c:114:31: warning: passing argument 3 of ‘test_sorting’ from incompatible pointer type [-Wincompatible-pointer-types]
>  test_sorting(numbers, count, die);                               
>ex18.c:77:6: note: expected ‘compare_cb {aka int (*)(int,  int)}’ but argument is of type ‘void (*)(const char *)’
> void test_sorting(int *numbers, int count, compare_cb cmp)
Only a warning and a note!
