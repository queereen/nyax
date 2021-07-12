#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i=0;

void nyai(char*code){
  for (int j = 0; j < strlen(code); j++) {
    switch (code[j]) {
      case 'n':
	i--;
	if (i<0){
		i=128;
	}
	break;
      case 'y':
        i++;
	if (i>128){
		i=0;
	}
        break;
      case 'a':
        putchar(i);
	break;
      case '~':
        i = 0;
        break;
      default:
        continue;
    }
  }
  putchar('\n');
}

int main(int argc, char *argv[]) {
  if (argc == 1)
  {
	char input[257400];
 	printf("Nya~ interactive interpreter\n");
	while(1){	
		printf("\n>>> "); fgets(input, 257400, stdin); 
		nyai(input);
		i=0;
	}
  }
  else if (argc==2)
  {
    FILE *file_ptr;
    char *buffer;
    long size;

    file_ptr = fopen(argv[1], "r");
    if (file_ptr == NULL)
    {
      fprintf(stderr, "Could not open %s file\n", argv[1]);
      return 1;
    }

    fseek(file_ptr, 0L, SEEK_END);
    size = ftell(file_ptr);
    rewind(file_ptr);

    buffer = calloc(1, size + 1);

    fread(buffer, size, 1, file_ptr);
    fclose(file_ptr);

    nyai(buffer);

    free(buffer);
  } else {
  	fprintf(stderr, "Usage: %s [file]\n", argv[0]);
  	return 1;
  }
  return 0;
}

