# The Stack, Scope and Globals

## Handy man_make.sh
This particular exercise required manuel compiling of the binaries. So I have put a little shell script for that which;
> for 0 does `make clean`
> and 
> for x >= 0 does `make`

## What we learn;

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


### From the book:
* "Where variables are created, exist and die."
* "The real purpose of this exercise, though, is to learn where the hell things live in C."

## other findings;
### Xcredit 3

### Xcredit 4


### Xcredit 5
* For the first edition, [this site](http://www.network-theory.co.uk/docs/gccintro/gccintro_16.html) helped a lot for the Makefile. 
* Then [this one](https://www.cs.bu.edu/teaching/cpp/writing-makefiles/) was a lot detailed and helped me improve my second edition which I am satisfied with and will not further improve.
