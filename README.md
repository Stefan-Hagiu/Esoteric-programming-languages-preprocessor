### Esoteric-programming-languages-preprocessor

# Introduction

Recently, I have been reading about esoteric programming languages. These programming languages are not intended to be used to build actual software; they are rather built as a joke and used by hackers and hobbyists. 

One thing that I saw people do all the time when using these programming languages, is working with actual functions (like those we see in C++, except for having no arguments and not being recursive) by writing pieces of code in multiple files and later putting everything together by hand, resulting in a two-fold problem: 

1) It is a very long and complicated process which usually results in bugs which are very hard to detect and fix. 

2) After detecting the problem and modifying the source file, the programmer has to modify all instances of said function, which can result in a number of problems: having to re-assemble everything, forgetting to modify an instance and losing valuable time essentially doing useless work.

The reason for doing so is that the programming languages they use don't actually support working with functions. Using an existing preprocessor is certainly impossible, because of their limitations. For example, the C preprocessor is not compatible with programming languages which use '#' as a keyword. It is also very hard to use with multiple-line functions. 

This is why I decided to build my own preprocessor, which can be used to process code in any programming language.

# What does it actually do?

As I stated in the introduction, the purpose of this program is to automate the hardest part of making applications in esoteric programming languages: assembling all the function-like pieces of code. By defining functions in a certain way (see next section) and using this preprocessor, you can avoid the problems previously stated.

# How can I use it?

Formatting the source file is easy:

-The execution will start at the function named "main"

-Each function will begin with a function definition char and the function name (without the whitespace character). For example, if my function definition char is *, the function "main" should start with: *main

-To end the function, simply insert the function definition char again. A completed function should look like this:   *main //code *

-To call a function, you need to write the function name between 2 function body chars. Let's use & as an example. If I wanted to call the "doSomething" function inside the main function, I would write the following code:  *main &doSomething& *

-The order in which functions are defined is not important. If the function "doSomething" from the last example were to be defined after the function "main", the precompiler would still work properly.

At startup, the program requires 4 inputs from the user: the function definition char, the function body char, the input file and the output file.

To compile, open a terminal window, go where the program folder is located and type the following 2 instructions:

1) g++ -c *.cpp

2) g++ *.o -o a.out

 Alternatively, you can use an IDE, such as Code::Blocks or Xcode.

# Completed example

Given the following input: (* & input.txt output.txt) and the file:

*cc

text2
*


*main

text1

&aa&

text4
*


*aa

&cc&

text3

&cc&
*


The program will write the following code in output.txt:

text1
text2
text3
text2
text4

# Am I allowed to use this program?

Yes, you are free to use this program for anything you would like. If you do an interesting application using my program and would want me to post a link to said application (preferably on GitHub), I also encourage you to contact me at hagiu.stefan@yahoo.com
