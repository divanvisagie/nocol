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
