
#include "color.h"

#include <cstdio>
#include <fstream>
#include <getopt.h>
#include <iterator>
#include <regex>
#include <string>
#include <vector>

void help() {
  printf("recat - cat with regular expressions and color\n\n"
         "Usage: recat [OPTION]... [FILE]...\n\n"
         "With no FILE, read standard input.\n\n"
         "--help   -h         Print Help\n"
         "--regex  -r  <str>  Pattern Matching\n"
         "--fg     -f  <str>  Set the foreground color\n"
         "--bg     -b  <str>  Set the background color\n\n"
         "Examples:\n"
         "  recat -b blue -r root /etc/passwd | head -n 10\n"
         "  ps aux | recat -b red -r root | head -n 10\n"
         "  echo \"bright-cyan text!\" | recat -f bright-cyan\n"
         "  recat -f red -r gets file.c\n");

  exit(1);
}

int main(int argc, char *argv[]) {

  bool fg_flag = false;
  bool bg_flag = false;
  bool regex_flag = false;
  bool has_stdin = true;
  std::string fg_string;
  std::string bg_string;
  std::string regex_string;
  std::vector<std::string> files;

  int c;

  while (1) {
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"foreground", required_argument, 0, 'f'},
        {"background", required_argument, 0, 'b'},
        {"regex", required_argument, 0, 'r'},
        {0, 0, 0, 0}};

    int option_index = 0;

    c = getopt_long(argc, argv, "hf:b:r:", long_options, &option_index);

    if (c == -1) {
      break;
    }

    switch (c) {
    case 'h':
      help();
      break;

    case 'f':
      fg_flag = true;
      fg_string = optarg;
      break;

    case 'b':
      bg_flag = true;
      bg_string = optarg;
      break;

    case 'r':
      regex_flag = true;
      regex_string = optarg;
      break;

    case '?':
      help();
      exit(1);

    default:;
    }
  }

  for (int index = optind; index < argc; index++) {
    has_stdin = false;
    std::string fname = argv[index];
    files.push_back(fname);
  }

  Color fg_color;
  Color bg_color;

  std::string fg_ansi = color_to_ansi(fg_color);
  std::string bg_ansi = color_to_ansi(bg_color);

  if (fg_flag) {
    fg_color = color_fg_from_str(fg_string);
    fg_ansi = color_to_ansi(fg_color);
  } else {
    fg_ansi = "";
  }

  if (bg_flag) {
    bg_color = color_bg_from_str(bg_string);
    bg_ansi = color_to_ansi(bg_color);
  } else {
    bg_ansi = "";
  }

  std::string line;

  if (has_stdin) {
    c = 0;
    while ((c = getchar()) != EOF) {

      if (c != '\n') {
        line += c;
        continue;
      }

      if (!regex_flag) {
        printf("%s", line.c_str());
      } else {

        std::regex r(regex_string);
        std::string rep = fg_ansi + bg_ansi + "$&\e[0m";
        std::string res = std::regex_replace(line, r, rep.c_str());

        printf("%s\n", res.c_str());
      }

      line = "";
    }
  } else {

    for (size_t i = 0; i < files.size(); i++) {

      std::ifstream infile(files[i]);

      if (!infile) {
        printf("error opening %s\n", files[i].c_str());
        exit(1);
      }

      char ch;
      while ((infile.get(ch))) {

        if (ch != '\n') {
          line += ch;
          continue;
        }

        if (!regex_flag) {
          printf("%s%s%s%s", fg_ansi.c_str(), bg_ansi.c_str(), line.c_str(),
                 "\e[0m\n");
        } else {

          std::regex r(regex_string);
          std::string rep = fg_ansi + bg_ansi + "$&\e[0m";
          std::string res = std::regex_replace(line, r, rep.c_str());

          printf("%s\n", res.c_str());
        }

        line = "";
      }
      infile.close();
    }
  }

  return 0;
}
