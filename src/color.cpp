#include "color.h"

#include <iostream>

Color color_fg_from_str(const std::string &str) {
  Color c;
  if (str == "black") {
    c = BLACK_FG;
  } else if (str == "red") {
    c = RED_FG;
  } else if (str == "green") {
    c = GREEN_FG;
  } else if (str == "yellow") {
    c = YELLOW_FG;
  } else if (str == "blue") {
    c = BLUE_FG;
  } else if (str == "magenta") {
    c = MAGENTA_FG;
  } else if (str == "cyan") {
    c = CYAN_FG;
  } else if (str == "white") {
    c = WHITE_FG;
  } else if (str == "gray") {
    c = GRAY_FG;
  } else if (str == "bright-red") {
    c = BRIGHT_RED_FG;
  } else if (str == "bright-green") {
    c = BRIGHT_GREEN_FG;
  } else if (str == "bright-yellow") {
    c = BRIGHT_YELLOW_FG;
  } else if (str == "bright-blue") {
    c = BRIGHT_BLUE_FG;
  } else if (str == "bright-magenta") {
    c = BRIGHT_MAGENTA_FG;
  } else if (str == "bright-cyan") {
    c = BRIGHT_CYAN_FG;
  } else {
    std::cout << "error - bad color in color_fg_from_str" << std::endl;
  }
  return c;
}

Color color_bg_from_str(const std::string &str) {
  Color c;
  if (str == "black") {
    c = BLACK_BG;
  } else if (str == "red") {
    c = RED_BG;
  } else if (str == "green") {
    c = GREEN_BG;
  } else if (str == "yellow") {
    c = YELLOW_BG;
  } else if (str == "blue") {
    c = BLUE_BG;
  } else if (str == "magenta") {
    c = MAGENTA_BG;
  } else if (str == "cyan") {
    c = CYAN_BG;
  } else if (str == "white") {
    c = WHITE_BG;
  } else if (str == "gray") {
    c = GRAY_BG;
  } else if (str == "bright-red") {
    c = BRIGHT_RED_BG;
  } else if (str == "bright-green") {
    c = BRIGHT_GREEN_BG;
  } else if (str == "bright-yellow") {
    c = BRIGHT_YELLOW_BG;
  } else if (str == "bright-blue") {
    c = BRIGHT_BLUE_BG;
  } else if (str == "bright-magenta") {
    c = BRIGHT_MAGENTA_BG;
  } else if (str == "bright-cyan") {
    c = BRIGHT_CYAN_BG;
  } else {
    std::cout << "error - bad color:" << str << std::endl;
    exit(1);
  }
  return c;
}

std::string color_to_ansi(Color c) {
  std::string s = "\e[" + std::to_string(c) + "m";
  return s;
}