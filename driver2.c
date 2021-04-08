// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
#define stdout 0 
#define lpt 2 
#define com1 3 
#define COM1 0
#define COM2 1
#define COM3 2
#define COM4 3

int ii;
void sputs(cc);
int comport(ports);
char cget();
void sstr(i,s);

int main(){

	int n=0;
	int nn=0;
	int b=0;
	char c[80];
	char *cc=" $";
	while(n!=27){
		nn=comport(COM1);
		if (nn!=b && nn!=0){
			sstr(nn & 0xff,c);
			c[8]='$';
			sputs(c);
			sputs(cc);
		}
		b=nn;
		
	}

		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}

int comport(ports)
int ports;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = ports;

	asm	"db 0x1E,0x56,0x8C,0xC8,0x8E,0xD8,0xBE,0x80,0x00,0x2E,0x8B,0x14,0xB4,0x02,0xCD,0x14,0xBE,0x80,0x00,0x2E,0x89,0x04,0x5E,0x1F";
	return *(c + 0);


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

char cget()
{
	char *c;
	char cc;
	asm	"db 0xb4,0x01,0xcd,0x21,0xbb,0x80,0x0,0x2e,0x88,07";
	c = (char * ) varn;
	cc=*(c + 0);
	return cc;
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
	int boo=0;
	char *cursor;
	char cc;
	sss=i;
	cursor=s;
	
	for (n=0;n<5;n++){
		if(n>3)boo=1;
		state=sss/start;
		remain=sss-(state*start);
		sss=remain;
		cc=(char) state+'0';
		if(cc!='0')boo=1;
		if(boo==1)cursor[0]=cc;
		start=start/i10;
		if(boo==1)cursor++;
	}
	cursor[0]=0;
}
