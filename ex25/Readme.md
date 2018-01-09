# Input, Output, Files 


## What we learn;

* fgets()  
reads  in  at  most  one  less than size characters from stream and stores them into the buffer pointed to by s.  Reading stops after an EOF or a newline.  If a newline is read, it is
stored into the buffer.  A terminating null byte ('\0') is stored after the last character in the buffer.

### Xcredit 2
There is not very much difference.
**scanf** assumes stdin as input. 
(-) Has no concept of BUFFER size.
(+) Can read with format.

### Xcredit 3
> initializing as the following:
```
char str[10] = "abcdefghj";
```

> Then lets read in somethings into str via fgets. After that lets check what's inside.
```
in = fgets(str, 9 , stdin);

bayt = str;

for (i = 0; i < 10 ; i++) {
    printf("%d'th byte of our input: %d\n", i, *bayt++);
}

```
> The output is as follows:
```
How much do you make an hour? 12
0'th byte of our input: 49
1'th byte of our input: 50
2'th byte of our input: 10 << This is where the "\n" is placed by input
3'th byte of our input: 0 << This is where the "\0" is placed by fgets
4'th byte of our input: 101
5'th byte of our input: 102
6'th byte of our input: 103
7'th byte of our input: 104
8'th byte of our input: 106
9'th byte of our input: 0 << This is where the "\0" is placed by init
----- RESULTS -----
First Name: 
Last Name: 
Age: 0
Eyes: Blue
Income: 12.000000
```
> Why ? check out [above]()
 


### Xcredit 4
# TODO
After having my Laptop die on me and me repairing it then returning to the process back, I find the function in Xcredit2 > replace_scanf adequate for the task of this Xcredit.
Maybe in the future I'll touch this but as of now, it is really a minor thing.

