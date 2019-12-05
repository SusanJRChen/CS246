# Shell
# Shell Commands

**cat** - prints out the content of a file or combine multiple files to standard output
* ```cat file1.txt``` prints out file1.txt
* ```cat file1.txt file2.txt``` combines both files
* ```cat``` / ```cat -``` takes in keyboard input and outputs it (ctrl-D ends it)
* ```man cat``` provides info about cat command

**head** - displays first few (10) lines of a file
* ```-n [# of lines]``` / ```- [# of lines]``` to specify number of lines

**tail** - displays last few (10) lines of a file
* ```-n [# of lines]``` / ```- [# of lines]``` to specify number of lines

**ls** - lists the contents of the current directory
* ```ls -a``` lists all contents including hidden files (files that start with '.')
* ```ls -l``` lists the contents of a directory in a long listing format (```ls -l [filename]``` displays info for a file in long listing format)

**pwd** - shows the current working directory

**cd** - change directory
* ```cd``` / ```cd ~``` home directory
* ```cd [directory]``` specified directory
* ```cd ..``` parent directory
* ```cd /``` root directory
* ```cd -``` previous directory
* **Absolute directories** begins with ```/```
* **Relative directories** begins with ```./```
  * ```./``` (current)
  * ```../``` (parent)
  * ```~/``` (home)

**exit** - terminates the shell session

**echo** - write arguments, seperated by spaces and terminated with a newline

**rm** - remove
