# Strings
There are 2 types of strings:
1. **C-strings** - array of (char) ending with a null character ```(\0)```. e.g. Literals ```"Hello World!"```
2. **string** - a class that offers greater functionality and checks for error conditions. Uses templates. Requires ```<string>``` class.

# Standard Class String
```cpp
#include <string>

int main() {
    std::string s1, s2, s3;
    s1 = "ab"; // Assignment
    s2 = "cd";
    s3 = s1 + s2; // Concatenation. "abcd"
}
```

# String Operations
* ```str.length()``` returns length of a string
* ```str.at(int i)``` returns reference to char at position ```i```. performs a range check on ```i``` and throws an error if invalid position.
* ```str[i]``` returns reference to char at position ```i```. Undefined behaviour if ```i``` is beyond length of string.
* ```string str("string")``` creates a string object with value ```"string"```
* ```str.empty()``` returns true if empty string

* ```str1 == str2 str1 != str2``` checks if strings are equal/not equal
* ```str1 > str2``` compares strings in lexographical order (how it would be found in a dictionary)
* ```str1.find(str2)``` returns index of first occurrence of str2 in str1

# Escape Sequences
**Escape sequences** - allow us to extend the character set, such as using double quotes in our string rather than the terminating the string. Denoted by the backslash ```\``` followed by the escape sequence char. Here are some of them:
* ```\n``` new line
* ```\\``` backslash
* ```\"``` double quote

# Raw String Literals
Avoids escape sequences by interpreting everything in brackets literally. e.g. ```string s = R"(\t\\t\n)"; ```is equal to ```\t\\t\n```, which is useful for pathnames.
