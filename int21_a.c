// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
char ccc;
char cc;
char cget();
char *sgets(c);
void sputc(cc);
void sputs(cc);
int main(){
	char *c;
	sputs("input a string: $");
	c=sgets(9);
	sputs("\r\n$");
	c=c+2;
	sputs(c);
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}

char *sgets(cc)
char cc;
{
	char *c;
	char *ccc;
	char i;
	c = (char * ) varn;
	*(c + 0) = cc;
	
	asm	"db 0xba,0x80,0x0,0xb4,0x0a,0xcd,0x21";
	i=*(c + 1);
	i=i+2;
	*(c + i)='$';
	ccc=c;
	return ccc;
}




char cget()
{
	char *c;
	char cc;
	asm	"db 0xb4,0x01,0xcd,0x21,0xbb,0x80,0x0,0x2e,0x88,07";
	c = (char * ) varn;
	cc=*(c + 0);
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
