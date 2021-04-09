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
void locate(xx,yy);
void cursors(y1,y2);

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
	cursors(0,7);
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
		if (x>79)x=79;
		if (y>24)y=24;
		
		if (x!=x1 || y!=y1){
			y1=y;
			x1=x;
			locate(x1,y1);
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

void locate(xx,yy)
int xx;
int yy;
{
	int *c;
	int i;
	c = (int * ) varn;
	*(c + 0) = xx;
	*(c + 1) = yy;

	asm	"db 0x1E,0x56,0x8C,0xC8,0x8E,0xD8,0xBE,0x80,0x00,0x2E,0x8A,0x14,0x46,0x46,0x2E,0x8A,0x34,0xB0,0x00,0xB4,0x02,0xCD,0x10,0x5E,0x1F";
}


void cursors(y1,y2)
int y1;
int y2;
{
	int *c;
	int i;
	c = (int * ) varn;
	*(c + 0) = y2;
	*(c + 1) = y1;

	asm	"db 0x1E,0x56,0x8C,0xC8,0x8E,0xD8,0xBE,0x80,0x00,0x2E,0x8A,0x0C,0x46,0x46,0x2E,0x8A,0x2C,0xB0,0x00,0xB4,0x01,0xCD,0x10,0x5E,0x1F";
}





