#include <stdio.h>

#include <stdio.h>
void go_south_east(int *lat) {
	*lat = *lat + 1;
}

void modify_string(char *str) {
	str[3] = 'a';
}

int main() {

	char *msg = "asdfasdfasdf"; // constant memory
	printf("msg %s\n", msg);

	printf("address of msg %p\n", msg);


	msg = "sdfgsdfgsdfg"; // also constant memory

	printf("address of msg %p\n", msg);

	char newmsg[] = {'s', 'd', 'f', 'g','s', 'd', 'f', 'g','s', 'd', 'f', 'g'};

	msg = newmsg;

	printf("address of msg %p\n", msg);

	// modify_string(msg);
	printf("msg after modifying %s\n", msg);


	msg = "asdfasdfasdf"; // constant memory does it go to the same memory?
	printf("address of msg %p\n", msg);

	int lat = 32; // created at address 0x01
	//
	// printf("lat = %d\n", lat); // 32
	// 
	// int *latp = &lat; // latp = 0x01 ; address of latp 0x02
	//
	// printf("address of lat = %p\n", latp);
	//
	// int **latpp = &latp; // latpp = 0x02
	//
	// printf("latpp value %p &latp %p\n", latpp, &latp);
	//
	// printf("address of latp = %p\n", latpp);


	go_south_east(&lat);
}


