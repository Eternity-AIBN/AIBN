#include "types.h"
#include "lib.h"
/*int uEntry(void) {
	int fd = 0;
	int i = 0;
	char tmp = 0;

	ls("/"); 
	ls("/boot/"); 
	ls("/dev/");
	ls("/usr/"); 

	printf("create /usr/test and write alphabets to it\n");
	fd = open("/usr/test", O_READ | O_WRITE | O_CREATE); 
	for (i = 0; i < 26; i ++) { 
		tmp = (char)(i % 26 + 'A');
		write(fd, (uint8_t*)&tmp, 1);
	}
	close(fd);
	ls("/usr/"); 
	cat("/usr/test"); 
	exit();
	return 0;
} */


int uEntry(void) {
	char ch[10];
	printf("Input: ls <destPathName>\n       cat <destPathName>\n       open <destPathName>\n");
	//int ret = 0;
	while(1){
		if(getpid()==1){
			fork();
			if(getpid() == 2){
				while(1){
					scanf("%10s", ch);
					if(strCmp(ch,"ls",2)==0){
						exec("/usr/ls", 0);
					}
					else if(strCmp(ch,"cat",3)==0){
						exec("/usr/cat", 0);
					}
					else if(strCmp(ch,"open",4)==0){
						exec("/usr/open", 0);
					}
					else if(strCmp(ch,"rm",2)==0){
						exec("/usr/rm", 0);
					}
				}
				
			}
		}	
	}
	
	exit();
	return 0;
}