// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
char ccc;
char cc;
void sstr(i,s);
void sputc(cc);
void sputs(cc);
int main(){
	char s[80];
	sstr(12345,s);
	sputs(s);
	sputs("\r\n\r\n");
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
void sstr(i,s)
int i;
char *s;
{
	int n=0;
	int i10=10;
	int start=10000;
	int state=0;
	int sss=0;
	int remain=0;
	char *cursor;
	char cc;
	sss=i;
	cursor=s;
	
	for (n=0;n<5;n++){
		state=sss/start;
		remain=sss-(state*start);
		sss=remain;
		cc=(char) state+'0';
		cursor[0]=cc;
		start=start/i10;
		cursor++;
		if (n==2){
			cursor[0]='.';
			cursor++;
		}
	}
	cursor[0]=0;
}

void sputs(cc)
char *cc;
{
		int i=0;
while(cc[i]!=0){
		sputc(cc[i]);
		i++;
}
}
