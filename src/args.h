
typedef struct {
  bool help;
  bool strip_prefix;
} Args;

Args* parse_args(int argc, char **argv);
