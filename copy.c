// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
char ccc;
char cc;
void sputs(cc);
void scopy(s1,s2);
int main(){
	char ss[80];
	scopy(ss,"hello world\r\n$");
	sputs(ss);
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}
void scopy(s1,s2)
char *s1;
char *s2;
{
	char cc=0;
	int counter=0;
	do{
		s1[counter]=s2[counter];
		cc=s2[counter];
		counter++;
	}while(cc!=0);
	
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

