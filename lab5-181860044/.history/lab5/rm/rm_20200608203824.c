#include "lib.h"
#include "types.h"

int main(void) {
	char ch[100];
	scanf("%100s",ch);
	remove(ch); 
	exit();
	return 0;
}
