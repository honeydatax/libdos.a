// need file libdos.c to be compile in directory
//bcc -x -i -L -Md hello.c -o HELLO.COM
#define varn 0x0080
#define smallG 0x13
#define VIDEO 0xA000
#define stdout 0 
#define lpt 2 
#define com1 3 
#define blue 1
#define brish 8
#define black 0
#define white 15
struct win{
	int x;
	int y;
	int w;
	int h;
	int color;
};
int VID;
int ii;
void screens(n);
int getptr();
void backs(address,count,color);
void refresh(address,count,addr2);
void hline(hlinex,hliney,hlinex1,hliney1,color);
void rect(rectx,recty,rectx1,recty1,color);
void vline(vlinex,vliney,vlinex1,vliney1,color);
void drawWindows(x,y,w,h,color);

int main(){
	int n;
	int x=10;
	int y=10;
	int x1=150;
	int y1=100;
	int color=2;
	int unsigned size=320*200; 
	char c[80];
	struct win w[8];
	VID=getptr()+0X2000;
	screens(smallG);
	backs(VID,(int)size,blue);
	for (n=0;n<8;n++){
		w[n].x=n*10+10;
		w[n].y=n*10+10;
		w[n].w=150;
		w[n].h=50;
		w[n].color=white;
		
	}
	for (n=0;n<8;n++){
			drawWindows(w[n].x,w[n].y,w[n].w,w[n].h,w[n].color);
	}

	refresh(VIDEO,size,VID);
		asm	"db 0xb4,0,0xcd,0x21";
		
	return 0;
}



void screens(n)
int n;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = n;


	asm	"db 0x1E,0x56,0x8C,0xC8,0x8E,0xD8,0xBE,0x80,0x00,0x2E,0x8A,0x04,0xB4,0x00,0xCD,0x10,0x5E,0x1F";
}



int getptr()
{
	int *c;
	c = (int * ) varn;

	asm	"db 0x8C,0xC8,0x2E,0xA3,0x80,0x0";
	return *(c + 0);
}

void backs(address,count,color)
int address;
int count;
int color;
{
	int *c;
	c = (int * ) varn;
	*(c + 0)=address;
	*(c + 1)=count;
	*(c + 2)=color;
	asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x0E,0x82,0x00,0x8B,0x16,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x89,0xD7,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	
}


void refresh(address,count,addr2)
int address;
int count;
int addr2;
{
	int *c;
	c = (int * ) varn;
	*(c + 0)=address;
	*(c + 1)=count;
	*(c + 2)=addr2;
	asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x1E,0x84,0x00,0x8B,0x0E,0x82,0x00,0xA1,0x80,0x00,0x50,0x07,0x53,0x1F,0x31,0xD2,0x89,0xD6,0x89,0xD7,0x90,0xFC,0xF3,0xA4,0x07,0x1F";
	
}

void hline(hlinex,hliney,hlinex1,hliney1,color)
int hlinex;
int hliney;
int hlinex1;
int hliney1;
int color;
{
	int ir;
	int xx;
	int yy;
	int xx1;
	int yy1;
	int xxx;
	int yyy;
	int xxa;
	int *c;
	c = (int * ) varn;
	xx=hlinex;
	yy=hliney;
	xx1=hlinex1;
	yy1=hliney1;
	if (xx>319)xx=319;
	if (xx1>319)xx1=319;
	if (yy>199)yy=199;
	if (yy1>199)yy1=199;
	if (xx<0)xx=0;
	if (xx1<0)xx1=0;
	if (yy<0)yy=0;
	if (yy1<0)yy1=0;
	if (xx<=xx1 && yy==yy1){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		xxx=yy*320+xx;
		*(c + 0)=VID;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=color;
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x3E,0x82,0x00,0x8B,0x16,0x86,0x00,0x8B,0x0E,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x90,0xFC,0xF3,0xAA,0x07,0x1F";
	}
}

void rect(rectx,recty,rectx1,recty1,color)
int rectx;
int recty;
int rectx1;
int recty1;
int color;
{
	int r;
	int ir;
	int xx;
	int yy;
	int nx;
	int ny;
	int xx1;
	int yy1;
	int xxx;
	int yyy;
	int xxa;
	int *c;
	int gg=0;
	c = (int * ) varn;
	xx=rectx;
	yy=recty;
	xx1=rectx1;
	yy1=recty1;
	if (xx>319)xx=319;
	if (xx1>319)xx1=319;
	if (yy>199)yy=199;
	if (yy1>199)yy1=199;
	if (xx<0)xx=0;
	if (xx1<0)xx1=0;
	if (yy<0)yy=0;
	if (yy1<0)yy1=0;
	if (xx<=xx1 && yy<=yy1){
		xxa=xx1-xx;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		xxx=yy*320+xx;
		nx=320-xxa;
		*(c + 0)=VID;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=nx;
		*(c + 4)=yyy;
		*(c + 5)=color;
	}	
	if (xx<=xx1 && yy<=yy1){
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x3E,0x82,0x00,0x8B,0x36,0x86,0x00,0x8B";
		asm "db 0x16,0x8A,0x00,0x8B,0x1E,0x88,0x00,0x8B,0x0E,0x84,0x00,0xA1,0x80,0x00";
		asm "db 0x50,0x07,0x88,0xD0,0x31,0xD2,0x51,0x90,0x59,0x51,0x90,0xFC,0xF3,0xAA";
		asm "db 0xF8,0x01,0xF7,0x4B,0x39,0xD3,0x75,0xF1,0x58,0x07,0x1F";
	}		
	
}

void vline(vlinex,vliney,vlinex1,vliney1,color)
int vlinex;
int vliney;
int vlinex1;
int vliney1;
int color;
{
	int ir;
	int xx;
	int yy;
	int xx1;
	int yy1;
	int xxx;
	int yyy;
	int xxa;
	int *c;
	c = (int * ) varn;
	xx=vlinex;
	yy=vliney;
	xx1=vlinex1;
	yy1=vliney1;
	if (xx>319)xx=319;
	if (xx1>319)xx1=319;
	if (yy>199)yy=199;
	if (yy1>199)yy1=199;
	if (xx<0)xx=0;
	if (xx1<0)xx1=0;
	if (yy<0)yy=0;
	if (yy1<0)yy1=0;
	if (xx==xx1 && yy<=yy1){
		xxa=yy1-yy;
		if (xxa<1)xxa=1;
		yyy=yy1-yy;
		xxx=yy*320+xx;
		*(c + 0)=VID;
		*(c + 1)=xxx;
		*(c + 2)=xxa;
		*(c + 3)=color;
		*(c + 4)=320;
	}
	if (xx==xx1 && yy<=yy1){
		asm	"db 0x1E,0x06,0x0E,0x1F,0x8B,0x36,0x88,0x00,0x8B,0x16,0x86,0x00,0x8B,0x3E,0x82,0x00,0x8B,0x0E,0x84,0x00,0xA1,0x80,0x00,0x50,0x07,0x88,0xD0,0x31,0xD2,0x90,0x26,0x88,0x05,0xF8,0x01,0xF7,0x49,0x83,0xF9,0x00,0x75,0xF3,0x07,0x1F";
	}
}


void drawWindows(x,y,w,h,color){
	rect(x,y,x+w,y+h,color);
	hline(x,y,x+w,y,black);
	vline(x+w,y,x+w,y+h,black);
	hline(x,y+h,x+w,y+h,black);
	vline(x,y,x,y+h,black);
}
