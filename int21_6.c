// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
char ccc;
char cc;
char cget(ccc);
void sputs(cc);
int main(){
	char c=255;
	sputs("input a string: ");
	while(c!=13){
		c=cget(0xff);
		if (c>31)cget(c);
	}
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}

char cget(ccc)
char ccc;
{
	char cc;
	int *c;
	c = (int * ) varn;
	*(c + 0) = ccc;
	asm	"db 0xbb,0x80,0x0,0x2e,0x8a,0x17,0xb4,0x6,0xcd,0x21,0xbb,0x80,0x0,0x2e,0x88,07";
	cc=*(c + 0);
	return cc;
}

void  sputs(cc)
char *cc;
{
	int i=0;
	for (i=0;i<8000;i++){
		cget(cc[i]);
		if (cc[i]==0)i=9000;
		if (cc[i]=='$')i=9000;
	}
	
}
