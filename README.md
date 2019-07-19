# ccat
colorized cat utillity with regex pattern matching

### Help:
```bash
ccat

--help             Print Help
--regex <str>      Pattern Matching
--fg    <str>      Set the foreground color
--bg    <str>      Set the background color

Examples:
  ccat -b blue -r "root" /etc/passwd | head -n 10
  ps aux | ccat -b red -r "root" | head -n 10
  echo "bright-red text!" | ccat -f "bright-red"
  ccat -f "red" -r "gets" file.c
```

### Example 1:
![example 1](images/example1.png)
### Example 2
![example 2](images/example2.png)
