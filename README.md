# SHELL PROJECT - OUR SIMPLE SHELL - SOLEO PROJECT
## Description

A Unix shell is a command-line interpreter designed to read commands typed by a user and execute appropriate programs in response to those commands. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.

## Soleo project - Synopsis
This is our implementation of a UNIX command-line interpreter designed to read some commands typed by a user and execute programs. Soleo can read and parses input arguments and execute the correct program.


       .---.
      /     \
      \.@-@./  --I´m a baby.
      /`\_/`\
     //  _  \\
     | \     )|_
    /'\_'>  <_/ \
    \__/'---'\__/

## How to use?
All the files in the repository have to be compiled on an Ubuntu 14.04 LTS with:

    gcc -Wall -Werror -Wextra -pedantic soleo.h *.c -o soleo

When you compiled, please run the program with:

     ./soleo

To exit, run:

   Soleo $ exit

#### Building environment
You could build this program in another environment or O.S., but, could present problems with external libraries needed for this program-function:

 -   Compiled under gcc 4.8.4 with the above flags to prevent warning
 -   Ubuntu 14.04
 -   You coul use the Betty style format to beauty and format your code

## Functions List

|Function name|Description  |
|--|--|
|soleo.h|Header with all the proptotypes|
|_sfree|Function  to free double pointers|
|_split_string|Function to split an array in tokens|
|_strdup|Function that duplicate an array|
|_strcmp|Function to compare two string|

## Output example
Run ls program in Soleo

    $ ./soleo
    Soleo $:ls
    README.md soleo.h sfree.c mini_shell.c soleo
    split_string.c
    Soleo $:

## Authors
- Leonardo Valencia [GitHub: @4ions](https://github.com/4ions)
- Andrés Sotelo [GitHub: @ANDRESOTELO](https://github.com/ANDRESOTELO)

## Holberton School Data-Time
- November 26 - 2020
- Cohort 13

### Holberton School CH13 rules.
