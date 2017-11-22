# Heap and Stack Memory Allocation

## What we learn;
* Structs
* malloc / free
* assert
* strdup (string duplicate)


###From the book:


## other findings;
### Xcredit 1
we need to change whole bunch of lines in a particular fashion. VI/VIM and regex is quite handy for such a task. But my first attempt took me too long. A friend of mine sent me this [page](https://regex101.com/) to check out a regular expression and what it is doing. If I had such a thing in the begining, I could have saved a couple of hours :D.
### Xcredit2
* `%s/^\(.*\)\(\/\/ debug\)$/\/\/ \1\2`
>Above is a handy way of commenting out your `//` debug flag

* `%s/^\(\/\/\)\( \/\/\)\(.*\)\(\/\/ debug\)$/\1\3\4`
>If you've put extra _//_ by mistake etc. at the beginning, this is to remove them

* `%s/^\(\/\/\)\(.*\)\(\/\/ debug\)$/\2\3`
>RMV leading `//`s so you can debug again

* `%s/\(.*\)\(\/\/ debug\)$/\/\/\1\2`
>PUT leading `//`s

* If you are trying to find out reasons of *seg. faults* via *printf()'s* then do now forget to put \\n's to the printf statement. My guess is that seg.fault promt ereases everything on that line ?
### Xcredit 4
[This](http://www.catb.org/esr/structure-packing/) site has a lot of information on the topic. Goes along with [structure_declaration](http://en.cppreference.com/w/c/language/struct) and [bitfields](http://en.cppreference.com/w/cpp/language/bit_field).
### Xcredit 8
First I've done the task as a global variable with no file I/O.
Then upgraded it to be with FIle I/O and where I needed for practice was shining like stars.
* First I forgot to log my stackPtr.
* Then realized the faulty way I was trying to do it. I was trying to store literally a ptr whree each time the program opens It becomes redundant or rather irrelevant, even nonsensicle. Then started to save my position in the stack and write/read it to the same file.
* The array definition and mem.allocation was also important for me. As it seems, the subject was not fully understood by me at the time I started this piece of code.
    * No wonder why array names act as an adress. You can just assign a space to it and it can wonder in that space by its type size. I guess an exercise with a 2D array should make the subject matter secure. 
