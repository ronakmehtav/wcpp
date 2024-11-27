#include <cstdio>

#define CHAR_FLAG_CHAR 'c'
#define WORD_FLAG_CHAR 'w'
#define LINE_FLAG_CHAR 'l'

bool CHAR_FLAG = false;
bool WORD_FLAG = false;
bool LINE_FLAG = false;

/**
*
* Command Struct [App][ Read flags] [Read Files].
* Run >> ./wc_cpp -w [file Name ...]
* Run >> ./wc_cpp -w -l [file Name ...]
* Run >> ./wc_cpp -wl [file Name ...]
+*/
int main(int argc, char* argv[]){
	// understanding ptr and ++argv
	// printf("Hello, World!\n");
	// printf("Pointer %p\n",(argv + 1));
	// printf("Char %c\n",*(argv + 1)[0]);
	// printf("String %s\n",*(argv + 1));
	// printf("Pointer %p\n", (argv + 2));
	// printf("Char %c\n",*(argv + 2)[0]);
	// printf("String %s\n",*(argv + 2));
	int c = 0;
	// printf("argc :%d\n",argc);
	while( --argc > 0 && (*++argv)[0] == '-') {
		while((c = *++argv[0]) != '\0'){
			switch (c) {
				case WORD_FLAG_CHAR:
					WORD_FLAG = true;
					break;
				case LINE_FLAG_CHAR:
					LINE_FLAG = true;
					break;
				case CHAR_FLAG_CHAR:
					CHAR_FLAG = true;
					break;
				default:
					printf("Unknown flag passed %c\nplease pass a correct flag\n",c);
					return 0;
					break;
			}
		}
	}

	if( argc < 1 ) {
		printf("Usage: ./wc_cpp -wl [file Name ...]");
	} else {
		char* filename = *argv;

		// printf("argc :%d\n",argc);
		// printf("File name: %s\n", filename);
		// printf("reading files\n");
		int word_count,char_count, line_count, ch = 0;
		FILE *file; 
		file = fopen(filename, "r");
		if (file == NULL){
			perror("Error opening file \n");
			return 1;
		}
		
		while ((ch = fgetc(file)) != EOF) {
			if(CHAR_FLAG) ++char_count;
			if(WORD_FLAG && (ch == ' ' || ch == '\t' )) ++word_count;
			if(LINE_FLAG && ch == '\n') ++line_count;
		}

		if(CHAR_FLAG) printf(" CHAR Count: %d\n",char_count);
		if(WORD_FLAG) printf(" Word Count: %d\n",word_count);
		if(LINE_FLAG) printf(" Line Count: %d\n",line_count);
	}
}


