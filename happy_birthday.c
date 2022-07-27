#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define RED "\x1b[1;31m"
#define GREEN "\x1b[1;32m"
#define CLEAR "\x1b[0m"

char* H[] = {
  " _    _ ",
	"| |  | |",
	"| |__| |",
	"|  __  |",
	"| |  | |",
	"|_|  |_|",
	NULL,
};

char* A[] = {
	"     __     ",
	"    /  \\    ",
	"   / /\\ \\   ",
	"  / /__\\ \\  ",
	" / /    \\ \\ ",
	"/_/      \\_\\",
	NULL,
};

char* P[] = {
	" ____   ",
	"|  _  \\ ",
	"| |_| | ",
  "|  ___/ ",
	"| |     ",
	"|_|     ",
	NULL,
};

char* Y[] = {
	"__    __  ",
	"\\ \\  / /",
	" \\ \\/ / ",
	"  \\  /   ",
  "   | |    ",
  "   |_|    ",
	NULL,
};

char* B[] = {
	" _____  ",
	"|  _  \\ ",
	"| |_| | ",
	"|  _  | ",
	"| |_| | ",
	"|_____/ ",
	NULL,
};

char* D[] = {
	" ______ ",
	"|  __  \\",
	"| |  \\ |",
	"| |  | |",
	"| |__/ |",
	"|______/",
	NULL,
};

char* C[] = {
	" _____ ",
	"/  ___|",
	"| /    ",
	"| |    ",
	"| \\__  ",
	"\\____| ",
	NULL,
};

char* W[] = {
	" _         _ ",
	"| |   _   | |",
	"\\ \\  / \\  / /",
	" | |/   \\| | ",
	" \\   / \\  /  ",
	"  |_|   |_|  ",
	NULL,
};

char* N[] = {
	" _   _",
	"| \\ | |",
	"|  \\| |",
	"| \\ | |",
	"| |\\  |",
	"|_| \\_|",
	NULL,
};

char* frisbee0[] = {
	"         __-----------_      ",
	"   _----     . . . .    ---",
	"  -        .          .   --",
	"  -_         .         .     -",
	"    -------_    . . . . _ -----",
	"            ------------    ",
	NULL,
};

char* frisbee1[] = {
	"           -------------      ",
	"   ___-----      . . . . ---",
	"  -         .         .   --",
	"  -        .         .     -",
	"   -----   . . . .   -----",
	"        ------------      ",
	NULL,
};

char* frisbee2[] = {
	"        __-------------      ",
	"   __---     .  . . . ---",
	"  -         .        .   --",
	"  -          .      .     -",
	"   --__    . . .     -----",
	"       -- ------------      ",
	NULL,
};

void print(char*** message) {
	int all_empty = 0;

	while (!all_empty) {
		all_empty = 1;
		for (char*** letter = message; *letter != NULL; letter++)
			if (**letter != NULL) {
				fputs(**letter, stdout);
				putchar(' ');
				all_empty = 0;

				*letter = *letter + 1;
			} else
				for (int i = 0; i < strlen(*(*letter - 1)) + 1; i++)
					putchar(' ');
		
		putchar('\n');
	}
}

int main() {

	int frame = 0;
	
	while (1) {
		fputs("\x1b[2J", stdout);

		fputs(GREEN, stdout);
		
		char** top[] = { H, A, P, P, Y, NULL };
		print(top);

		char** bottom[] = { B, D, A, Y, NULL };
		print(bottom);

		char** name[] = { C, H, A, W, N, NULL };
		print(name);
		
		fputs(CLEAR, stdout);
		fputs(RED, stdout);
		
		char** frisbee_[] = { frame == 0 ? frisbee0 : frame == 1 ? frisbee1 : frisbee2, NULL };
		print(frisbee_);

		fputs(CLEAR, stdout);

		frame = (frame + 1) % 3;

		usleep(1000000);
	}
}
