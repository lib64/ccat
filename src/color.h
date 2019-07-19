#ifndef COLOR_H
#define COLOR_H

#include <string>

typedef enum {

  BLACK_FG = 30,
  RED_FG,
  GREEN_FG,
  YELLOW_FG,
  BLUE_FG,
  MAGENTA_FG,
  CYAN_FG,
  WHITE_FG,
  BLACK_BG = 40,
  RED_BG,
  GREEN_BG,
  YELLOW_BG,
  BLUE_BG,
  MAGENTA_BG,
  CYAN_BG,
  WHITE_BG,
  GRAY_FG = 90,
  BRIGHT_RED_FG,
  BRIGHT_GREEN_FG,
  BRIGHT_YELLOW_FG,
  BRIGHT_BLUE_FG,
  BRIGHT_MAGENTA_FG,
  BRIGHT_CYAN_FG,
  BRIGHT_WHITE_FG,
  GRAY_BG = 100,
  BRIGHT_RED_BG,
  BRIGHT_GREEN_BG,
  BRIGHT_YELLOW_BG,
  BRIGHT_BLUE_BG,
  BRIGHT_MAGENTA_BG,
  BRIGHT_CYAN_BG,

} Color;

Color color_fg_from_str(const std::string &str);
Color color_bg_from_str(const std::string &str);

std::string color_to_ansi(Color c);

#endif // COLOR_H