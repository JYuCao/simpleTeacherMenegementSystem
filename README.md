# Simple Teacher Menegement System
## Introduction
Simple Teacher Menegment System is a project based on the C language. It is a homework of softwore foundation lesson.
The program runs on the _command line_. It is divided into two versions: _sequential list_ and _linked list_,and it mainly realizes the following functions:
* Create a list with teachers' names and lessons
* Add teacher into the list
* Show the list
* Delete teacher from the list

Because of my limited level, there are many loopholes in the program writing. Including md documentation and git usage are immature. Please be tolerant.

## Directory Structure
Program is divided into two versions: _sequential list_ and _linked list_. So they are placed in two folders respectively.

```
│   .gitignore
│   README.md
│   
├───Linklist
│       Linklist.c
│       Linklist.h
│       main.c
│       makefile
│       TMS_Linklist.c
│       TMS_Linklist.h
│       
├───Sqlist
│       main.c
│       makefile
│       Sqlist.c
│       Sqlist.h
│       TMS_Sqlist.c
│       TMS_Sqlist.h
```

_Linklist.c_ and _Linklist.h_ are the code of link list. Two files prefixed with _TMS_ are the code includes functions definations and statements not about link list. Files of Sqlist is similar.

## Function demonstration
_Images use Linklist part as demo, but functions of two parts are the same._

Program can run as follows.

### Menu

When you start _run.exe_, you will see this interface.

![iamge](./img/Menu.png)

Then you can select a number to take the appropriate action.

If you select a number out of them(1-4), program will prompt your input error. Otherwise, program only take over one character and part more than one character will be truncated.

### 
