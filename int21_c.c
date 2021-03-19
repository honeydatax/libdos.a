// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
char ccc;
char cc;
char cgetc();
void sputc(cc);
void sputs(cc);
void sleeps(l);
char keyclear();
int main(){
	char c=255;
	sputs("input a string: $");
	sleeps(10);
	keyclear();
	while(c!=13){
		c=cgetc();
		if(c>31)sputc(c);
	}


		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}

char keyclear()
{
	char *c;
	char cc;
	asm	"db 0xb4,0x0c,0xcd,0x21,0xbb,0x80,0x0,0x2e,0x88,07";
	c = (char * ) varn;
	cc=*(c + 0);
	return cc;
}


char cgetc()
{
	char *c;
	char cc;
	asm	"db 0xb4,0x07,0xcd,0x21,0xbb,0x80,0x0,0x2e,0x88,07";
	c = (char * ) varn;
	cc=*(c + 0);
	return cc;
}

void sputc(cc)
char cc;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = cc;

	asm	"db 0xbb,0x80,0x0,0x8a,0x47,0x0,0xbb,0x7,0x0,0xb4,0x0e,0xcd,0x10";
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


void sleeps(l)
int l;
{
	int l1;
	int l2;
	int l3;
	for (l1=0;l1<l;l1++){
		for (l2=0;l2<256;l2++){
			for (l3=0;l3<256;l3++){
			}
		}
	}
	
}
