// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
char getdrive();
void sputc(cc);
void sputs(cc);
int main(){
	char c=255;
	sputs("current drive:\r\n$");
	sputc(getdrive()+'A');
	sputs(":\r\n$");
	asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}

char getdrive()
{
	int *c;
	char cc;
	asm	"db 0xb4,0x19,0xcd,0x21,0xbb,0x80,0x0,0x2e,0x88,07";
	c = (int * ) varn;
	cc=(char) *(c + 0);
	return cc;
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

void sputc(cc)
char cc;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = cc;

	asm	"db 0xbb,0x80,0x0,0x8a,0x47,0x0,0xbb,0x7,0x0,0xb4,0x0e,0xcd,0x10";
}
