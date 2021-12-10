#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

int main() {
  //parent
  mkfifo("child", 0644);
  mkfifo("parent", 0644);

  char line[1000];

  int parent = open("parent", O_RDONLY);
  int child = open("child", O_WRONLY);

  while(1) {
    printf("Enter input: ");
    fgets(line, 1000, stdin);
    line[strlen(line) - 1] = '\0';
    printf("hello\n");
    write(child, line, sizeof(stdin));
    // sleep(3);
    read(parent, line, sizeof(stdin));
    printf("Parent got: [%s]\n", line);
  }
  return 0;
}
