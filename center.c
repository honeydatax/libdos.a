// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
char ccc;
char cc;
void sputc(cc);
void sputs(cc);
void scenter(cc,ii);
int main(){
	char *c="-------------------------------------------------------";
	int i=0;
	for(i=0;i<16;i++){
		scenter(c,i*2);
		sputs("\r\n",2);
	}
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}

void sputc(cc)
char cc;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = cc;

	asm	"db 0xbb,0x80,0x0,0x2e,0x8a,0x17,0xb4,0x02,0xcd,0x21";
}

void sputs(cc,ii)
char *cc;
int ii;
{
		int i=0;
		for(i=0;i<ii;i++)sputc(cc[i]);
		

}
void scenter(cc,ii)
char *cc;
int ii;
{
		int i=0;
		int iii=ii/2;
		int iiii=40-iii;
		for(i=0;i<iiii;i++)sputc(' ');
		sputs(cc,ii);
		
}
