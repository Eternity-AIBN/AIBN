#include "types.h"
#include "lib.h"
int uEntry(void) {
	int fd = 0;
	int i = 0;
	char tmp = 0;

	//ls("/"); 
	//ls("/boot/"); 
	//ls("/dev/");
	//ls("/usr/"); 

	printf("create /usr/test and write alphabets to it\n");
	fd = open("/usr/test", O_READ | O_WRITE | O_CREATE); 
	for (i = 0; i < 512; i ++) { 
		tmp = (char)(i % 26 + 'A');
		write(fd, (uint8_t*)&tmp, 1);
		//printf("%c",tmp);
	}
	/*printf("\nread:");
	for (i = 0; i < 512; i ++) { 
		read(fd, (uint8_t*)&tmp, 1);
		printf("%c",tmp);
	} */
	close(fd);
	/* fd = open("/usr/test", O_READ | O_WRITE);
	printf("\nread %d:",fd);
	for (i = 0; i < 26; i ++) { 
		read(fd, (uint8_t*)&tmp, 1);
		printf("%c",tmp);
	}*/
	//ls("/usr/"); 
	cat("/usr/test"); 
	exit();
	return 0;
}