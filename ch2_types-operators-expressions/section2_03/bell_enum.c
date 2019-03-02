#include <stdio.h>

int main() {
	enum escapes { BELL='\a', TAB='\t' };
	char bell[2];
	bell[0] = BELL;
	bell[1] = '\0';
	printf("%s", bell);
return 0;
}
