# Specs

The following situations will be counted as SLOC:

- Normal lines of code (also a simple `{` or `}` will be counted): `code`
- `Code and then // the line comment`
- `Some code and a beginning /* block comment on the same line (...) */`
- `Block comments ending on the same line /* like so */`

Handling the following correctly, i.e. not counting it toward the total line
count:
- `// Normal line comment`
- `/* Begin of the block comment,`
  `ignoring everything until the end is encountered */`
- Block comments on the same line by themselves `/* like this */`
- A single block comment start `/*` or end `*/` does not count towards the
  comment lines

It would be interesting to also get the total number of comment lines.



# Example

The following block of code has 4 lines of code and 5 comments spread out over 7 lines.

```c++
/*
   This is some code
   that is used for important stuff
*/
double main_function(int thing, double other){
    // Now do stuff here
    double this = thing * other; /* Just checking */
    return this;
    /* Everything should be fine */
}
/* More unnecessary comment things
   that really aren't that important anyway.
*/
```

# Known Bugs

There is currently one known bug: When you include a start of a block comment
inside ticks or apostrophes `"/*"`, it will interpret everything up to the next
comment closing sign `*/` as part of a block comment.
