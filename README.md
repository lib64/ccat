# recat
cat utillity with regular expressions and color.

### Help:
```
recat - cat with regular expressions and color

Usage: recat [OPTION]... [FILE]...

With no FILE, read standard input.

--help   -h         Print Help
--regex  -r  <str>  Pattern Matching
--fg     -f  <str>  Set the foreground color
--bg     -b  <str>  Set the background color

Examples:
  recat -b blue -r root /etc/passwd | head -n 10
  ps aux | recat -b red -r root | head -n 10
  echo "bright-cyan text!" | recat -f bright-cyan
  recat -f red -r gets file.c
```

### Example 1:
![example 1](images/example1.png)
### Example 2
![example 2](images/example2.png)
### Example 3
![example 3](images/example3.png)
### Example 4
![example 4](images/example4.png)
