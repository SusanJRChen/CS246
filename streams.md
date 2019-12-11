# Streams
**Stream** - an object that transports and formats characters of fixed width.

## Stream Libraries
* ```istream``` input stream
* ```ostream``` output stream
* ```iostream``` both input and output stream. Has the following children libraries: ```ifstream```, ```ofstream```, ```fstrean```, ```istringstream```, ```ostringstream```, ```stringstream```

## Stream Operators
* Insert Operator ```<<```
* Extractor Operator ```>>```
* Parse information expected by destination object according to its type

# Console I/O
1. ```cout``` - outputs text to **stdout**. Used with **inserter operator** ```<<```. Allows for chaining of strings/variables by adding inserters and the additional strings/variables to the right side. ```endl``` represents a newline
2. ```cin``` - input from **stdin** and stores input value into specified variable. Used with **extractor operator** ```>>```. Only reads up to a whitespace character (space, tab, newline)
3. ```cerr``` - output to **stderr**. Allows a way to distinguish normal output and error messages. Works in the same way as ```cout```.

## Formatting Ouput
The output format can also be formatted. For example, if we wanted all floats to be represented with 2 decimal places, we can add the statements:
```cpp
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
```
Any following ```cout``` statements that follow will output floats rounded to 2 decimal places

# File I/O
Similar to console I/O, programs can do file I/O to perform reading and writing to files.

## Opening a text file
```cpp
#include <fstream>
using namespace std;

ifstream inputStream;
inputStream.open("player.txt"); // or ifstream in("player.txt");
assure(inputStream, "player.txt");  // ensures that file is successfully opened
inputStream >> score >> firstName >> lastName;
```

## Input Operations
* ```cin.get(char & ch)``` puts the next input character in the variable ch. Returns an integer value, which is 0 if it encountered a problem (e.g. end of file)
* ```cin.getline(char * buffer, int length)``` reads characters into the string buffer until it reaches the length specified or a newline character. Stores a null character ('\0') after the last character read.
* ```cin.read(char * buffer, int n)``` reads n bytes (or until the end of file) from the stream into the buffer.
* ```cin.ignore(int n)``` removes the next n characters (or until end of file) from the input stream. If no argument is given, skips until the next newline character.
* ```cin.clear(iostate state)``` sets the stream's error state flag to specified state (```goodbit``` by default, which clears error flags)
* ```cin.fail()``` returns true if the last ```cin``` command failed (e.g. if entered value does not fit variable). We can reset the stream after an error:
```cpp
if (cin.fail()) {
    cin.clear(); // clears error flags
    cin.ignore(); // ignores "bad" character
}
```
* ```cin.bad()``` returns true if the ```badbit``` error state flag is set
* ```cin.eof()``` returns true if the ```eofbit``` error state flag is set
* ```cin.fail()``` returns true if the ```badbit``` and/or ```failbit``` error state flag is set
* ```cin.good()``` returns true if none of the error state flags are set

## Stream Error State Flags
Error state flags are used to keep track of the stream's state
* ```eofbit``` end-of-file is reached
* ```failbit``` end-of-file is reached
* ```badbit``` end-of-file is reached
* ```goodbit``` end-of-file is reached

# String <=> Integer
**stringstream** - can be used to convert string to and from integers.

## String to Integer
```cpp
#include <sstream>
#include <string>
using namespace std;

string s = "42 30";
istringstream iss (s);
int x, y;
iss >> x >> y;
```

## Integer to String
```cpp
ostringstream oss;
oss << 23 << "+" << 124;
string s = oss.str();
```
