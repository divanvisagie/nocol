#include <string.h>

const char *log_prefixes[] = {
    "DEBUG", "INFO", "WARN", "ERROR", "FATAL", "BREAK"
};

char* get_from_prefix(char *buffer) {
  for (int i = 0; i < sizeof(log_prefixes) / sizeof(log_prefixes[0]); i++) {
    char *substr = strstr(buffer, log_prefixes[i]);
    if (substr != NULL) {
      return substr;
    }
  }
  return buffer;
}

void strip_colors(char *input) {
  char *src = input;
  char *dst = input;
  while (*src) {
    if (*src == '\033' || *src == '\x1b') {
      src++;
      if (*src == '[') {
        src++;
        while (*src && ((*src >= '0' && *src <= '9') || *src == ';')) {
          src++;
        }
        if (*src) {
          src++;
        }
      }
    } else if (*src == '\r') {
      src++;
    } else {
      *dst++ = *src++;
    }
  }
  *dst = '\0';
}
