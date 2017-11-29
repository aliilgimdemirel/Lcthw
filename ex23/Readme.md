# Duff's Device

## What we learn;

### Xcredit 2
In Tom Duff's case, he was using ptr 'to' pointing at an I/O device. The usage here is for another purpose that's why it would not work.

### Xcredit 3
If it weren't for [this one](https://stackoverflow.com/a/20602642) I would have spent couple more hours on this one.

The gist of it is, as the following(according to me that is)
1. you can not have **#if** inside **#define** [because](https://stackoverflow.com/a/1262077) & macros can not have self-referencing by the same reason(recursive behaviour).
2. case statements can not have variable cases. 
3. Because of the rule in 1 and case statements' rules, My verdict is that, one cannot make an parametrized duff's device via C-preprocessor MACROS. 


### Xcredit 4

### Xcredit 5


