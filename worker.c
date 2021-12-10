#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

#define READ 0
#define WRITE 1

int main() {
  //child
  char line[1000];

  int parent = open("parent", O_WRONLY);
  int child = open("child", O_RDONLY);

  while (read(child, line, sizeof(line))) {
    // printf("HELLO\n");
    int len = strlen(line);
    char line1[len];
    for (int i = 0; i < len; i ++) {
      line1[len - 1 - i] = line[i];
    }
    line1[len] = '\0';
    write(parent, line1, sizeof(line1));
  }

  return 0;
}
