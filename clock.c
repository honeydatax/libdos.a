// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
int min;
int sec;
int secc;
void sstr(i,s);
void sputc(cc);
void sputs(cc);
int gettime();
int main(){
	char s[80];
	secc=255;
   while(s[0]=255){
	sstr(gettime(),s);
	sputs(s);
	sputs(":");
	sstr(min,s);
	sputs(s);
	sputs(":");
	sstr(sec,s);
	sputs(s);
	sputs("\r\n");
	gettime();
	while(sec==secc){
		gettime();
	} 
	secc=sec;
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


int gettime()
{
	int *c;
	char mint;
	char secs;
	char hors;
	c = (int * ) varn;
	asm	"db 0xB4,0x2C,0xCD,0x21,0xBB,0x80,0x00,0x2E,0x88,0x2F,0x43,0x43,0x2E,0x88,0x0F,0x43,0x43,0x2E,0x88,0x37";
	hors=*(c + 0);
	mint=*(c + 1);
	secs=*(c + 2);
	sec=(int) secs;
	min=(int) mint;
	return (int) hors;
}
