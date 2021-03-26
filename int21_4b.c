// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
char ccc;
char cc;
void execs(cc);
int main(){
	char c=255;
	execs("EXEC\0");
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}


void execs(cc)
char *cc;
{
	int *c;
	int i;
	c = (int * ) varn;
	*(c + 0) = cc;

	asm	"db 0xbb,0x80,0x0,0x2e,0x8B,0x17,0x8C,0xC8,0x8E,0xD8,0xB0,0x00,0xb4,0x4B,0xcd,0x21";
}

