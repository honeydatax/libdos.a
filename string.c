// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
char ccc;
char cc;
void sputc(cc);
void sputs(cc);
int main(){
	sputs("hello world\r\n$");
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}

void sputs(cc)
char *cc;
{
	int *c;
	int i;
	c = (int * ) varn;
	*(c + 0) = cc;

	asm	"db 0xbb,0x80,0x0,0x2e,0x8b,0x17,0xb4,0x09,0xcd,0x21";
}

