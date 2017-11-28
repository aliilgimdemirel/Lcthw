# The Stack, Scope and Globals

## Handy man_make.sh
This particular exercise required manuel compiling of the binaries. So I have put a little shell script for that which;
> for 0 does `make clean`
> and 
> for x >= 0 does `make`

## What we learn;
[This](http://en.cppreference.com/w/c/language/storage_duration) is what we learn in this exercise in essence.

### Storage duration
This headline's all content is from en.cppreference.com

Every object has a property called storage duration, which limits the object lifetime. There are four kinds of storage duration in C: 
* automatic storage duration. 
The storage is allocated when the block in which the object was declared is entered and deallocated when it is exited by any means (goto, return, reaching the end). One exception is the VLAs; their storage is allocated when the declaration is executed, not on block entry, and deallocated when the declaration goes out of scope, not than when the block is exited (since C99). If the block is entered recursively, a new allocation is performed for every recursion level. All function parameters and non-static block-scope objects have this storage duration, as well as compound literals used at block scope. 

* static storage duration. 
The storage duration is the entire execution of the program, and the value stored in the object is initialized only once, prior to main function. All objects declared static and all objects with either internal or external linkage that aren't declared _Thread_local (since C11) have this storage duration. 

* thread storage duration. 
The storage duration is the entire execution of the thread in which it was created, and the value stored in the object is initialized when the thread is started. Each thread has its own, distinct, object. If the thread that executes the expression that accesses this object is not (since C11) the thread that executed its initialization, the behavior is implementation-defined. All objects declared _Thread_local have this storage duration. 

* allocated storage duration. 
The storage is allocated and deallocated on request, using dynamic memory allocation functions. 

### Linkage
Linkage refers to the ability of an identifier (variable or function) to be referred to in other scopes. If a variable or function with the same identifier is declared in several scopes, but cannot be referred to from all of them, then several instances of the variable are generated. The following linkages are recognized:

* no linkage. 
The identifier can be referred to only from the scope it is in. All function parameters and all non-extern block-scope variables (including the ones declared static) have this linkage. 

* internal linkage. 
The identifier can be referred to from all scopes in the current translation unit. All static file-scope identifiers (both functions and variables) have this linkage. 

* external linkage. 
The identifier can be referred to from any other translation units in the entire program. All non-static functions, all extern variables (unless earlier declared static), and all file-scope non-static variables have this linkage


## From the book:
* "Where variables are created, exist and die."
* "The real purpose of this exercise, though, is to learn where the hell things live in C."

## Breakit
At first I could not make sense out of update\_ratio function's output. Then I put another **static** inside scope\_demo() to be sure after reading what it is doing. all was clear. the following will be the new version of scope\_demo and its output.

```
void scope_demo(int count)
{
    log_info("count is: %d", count);

    if (count > 10) {
        static int count = 5; // BAD! BUGS!

        log_info("count is in this scope is %d", count);
        count += 50 ; // BAD! BUGS!
        log_info("count is in this scope is %d", count);
    }

    log_info("count is at exit: %d", count);

    count = 3000;

    log_info("count after assign: %d", count);
}
```
```
[INFO] (ex22_main.c:10:scope_demo) count is: 4
[INFO] (ex22_main.c:20:scope_demo) count is at exit: 4
[INFO] (ex22_main.c:24:scope_demo) count after assign: 3000
[INFO] (ex22_main.c:10:scope_demo) count is: 80
[INFO] (ex22_main.c:15:scope_demo) count is in this scope is 5
[INFO] (ex22_main.c:17:scope_demo) count is in this scope is 55
[INFO] (ex22_main.c:20:scope_demo) count is at exit: 80
[INFO] (ex22_main.c:24:scope_demo) count after assign: 3000
[INFO] (ex22_main.c:10:scope_demo) count is: 100
[INFO] (ex22_main.c:15:scope_demo) count is in this scope is 55
[INFO] (ex22_main.c:17:scope_demo) count is in this scope is 105
[INFO] (ex22_main.c:20:scope_demo) count is at exit: 100
[INFO] (ex22_main.c:24:scope_demo) count after assign: 3000
[INFO] (ex22_main.c:10:scope_demo) count is: 200
[INFO] (ex22_main.c:15:scope_demo) count is in this scope is 105
[INFO] (ex22_main.c:17:scope_demo) count is in this scope is 155
[INFO] (ex22_main.c:20:scope_demo) count is at exit: 200
[INFO] (ex22_main.c:24:scope_demo) count after assign: 3000
```
> To repeate the cpp reference again: **the value stored in the object is initialized only once, prior to main function.**

### Xcredit 3

### Xcredit 4


### Xcredit 5
* For the first edition, [this site](http://www.network-theory.co.uk/docs/gccintro/gccintro_16.html) helped a lot for the Makefile. 
* Then [this one](https://www.cs.bu.edu/teaching/cpp/writing-makefiles/) was a lot detailed and helped me improve my second edition which I am satisfied with and will not further improve.
* Lastly [this site](https://www.cs.umd.edu/class/fall2002/cmsc214/Tutorial/makefile.html) was also very nice in case the ones above were not to your satisfaction. 

### New VI tricks
Now that we started to work with multiple files I've started using;

* MUltiple tabs in VI
    * As a result, opening those multiple times each time I close my PC would be a pain learn how to save my session and load it afterwards.
	* Here is the [article](https://medium.freecodecamp.org/learn-linux-vim-basic-features-19134461ab85) that helped me and the commands are as the following;
	* <table>
<tr><td>Tabs and Management</td></tr>
<tr><td>:split filename </td><td>- split window horizontally and load filename</td></tr>
<tr><td>:vsplit file </td><td>     - vertical split and open file</td></tr>
<tr><td>ctrl-w up arrow </td><td>  - move cursor up a window</td></tr>
<tr><td>ctrl-w ctrl-w </td><td>    - move cursor to another window (cycle)</td></tr>
<tr><td>ctrl-w _ </td><td>         - maximize current window vertically</td></tr>
<tr><td>ctrl-w | </td><td>         - maximize current window horizontally</td></tr>
<tr><td>ctrl-w = </td><td>         - make all equal size</td></tr>
<tr><td>:sview file </td><td>      - same as split, but readonly</td></tr>
<tr><td>:close </td><td>           - close current window</td></tr>
<tr><td>CTRL-W [N] - </td><td>	Decrease current window height by N (default 1)</td></tr>
<tr><td>CTRL-W [N] + </td><td>	Increase current window height by N (default 1)</td></tr>
<tr><td>CTRL-W [N] < </td><td>	Decrease current window width by N (default 1)</td></tr>
<tr><td>CTRL-W [N] > </td><td>	Increase current window width by N (default 1)</td></tr>
<tr><td>Session Save/Load</td></tr>
<tr><td>:mksession header-files-work.vim </td><td> Saves the session</td></tr>
<tr><td>$ vim -S header-files-work.vim   </td><td> Loads it from terminal</td></tr>
<tr><td>:source header-files-work.vim    </td><td> Loads it from inside VI</td></tr>
</table>
