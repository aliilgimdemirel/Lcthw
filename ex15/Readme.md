# Pointers, Dreaded pointers 

## What we learn;
The lexicon
>* type *ptr A pointer of type named ptr
>* *ptr The value of whatever ptr is pointed at
>* *(ptr + i) The value of (whatever ptr is pointed at plus i)
>* &thing The address of thing
>* type *ptr = &thing A pointer of type named ptr set to the address of thing
>* ptr++ Increment where ptr points


From the book:
>### Practical Pointer Usage
>Pass large Blocks of memory to functions with a pointer, so you don't have to pass the whole thing to them.

Important thing about this is that when using a pointer the pointed object's are not also passed. This is though only the side effect of its usage logic;

## other findings;
* passing an array to a function e.g.(char \*name[]) you must also provide the size of the array otherwise it is lost. [More into this in stackoverflow](https://stackoverflow.com/questions/1975128/why-isnt-the-size-of-an-array-parameter-the-same-as-within-main).
* An array's name is its address also. And as a result when you want to create a pointer to that array you do not need to put the & sign because the name is already its address.

