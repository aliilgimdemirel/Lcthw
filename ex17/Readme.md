# Heap and Stack Memory Allocation

## What we learn;
* Structs
* malloc / free
* assert
* strdup (string duplicate)


###From the book:


## other findings;
### Xcredit1For
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

