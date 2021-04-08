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
#define RIGTH	64
#define LEFT	79
#define UP		76
#define DOWN	67
#define CLICK	80


int ii;
void sputs(cc);
int comport(ports);
void sstr(i,s);

int main(){
	int x=0;
	int y=0;
	int x1=0;
	int y1=0;
	int clicks=0;
	int n=0;
	int nn=0;
	int b=0;
	char c[80];
	char *cc=" $";
	char *ccc="\r\n";
	while(n!=27){
		nn=comport(COM1);
		nn=nn & 0xff;
		if(nn==UP){
			y--;
		}

		if(nn==DOWN){
			y++;
		}
		if(nn==LEFT){
			x--;
		}
		if(nn==RIGTH){
			x++;
		}
		if(nn==CLICK){
			clicks=1;
		}
		if (x<0)x=0;
		if (y<0)y=0;
		if (x>639)x=639;
		if (y>479)y=479;
		
		if (x/8!=x1 || y/8!=y1){
			y1=y/8;
			x1=x/8;
			sstr(x1,c);
			c[6]='$';
			sputs(c);
			sputs(cc);
			sstr(y1,c);
			c[6]='$';
			sputs(c);
			sputs(ccc);

		}


	}
		
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
