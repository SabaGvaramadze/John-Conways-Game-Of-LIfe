#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

int neighbours_alive(bool *world,int pos,size_t WIDTH){
	int res=0;
	if(world[pos+WIDTH-1]){
		res++;
	}
	if(world[pos+WIDTH+1]){
		res++;
	}
	if(world[pos+WIDTH]){
		res++;
	}
	if(world[pos-1]){
		res++;
	}
	if(world[pos+1]){
		res++;
	}
	if(world[pos-WIDTH-1]){
		res++;
	}
	if(world[pos-WIDTH+1]){
		res++;
	}
	if(world[pos-WIDTH]){
		res++;
	}
	return res;
}

void draw_world(bool *world,size_t WIDTH,size_t HEIGHT){
	string output="";
	output+='\n';
	for(int i=1;i<HEIGHT-1;i++){
		output+='|';
		for(int j=1;j<WIDTH-1;j++){
			if(world[i*WIDTH+j])output+='#';
			else output+=' ';
		}
		output+="|\n";
	}
	for(int i=0;i<WIDTH-1;i++){
		output+='_';
	}
	cout <<output;
}


int main(int argc,char **argv){
	size_t sleepTime=100;
	if(argc>3){
		sleepTime = stoi(argv[3]);
	}
	const size_t WIDTH = stoi(argv[1]);
	const size_t HEIGHT = stoi(argv[2]);
	bool *world = (bool*)malloc(WIDTH*HEIGHT);
	memset(world,0,WIDTH*HEIGHT);
	bool *worldMove = (bool*)malloc(WIDTH*HEIGHT);
	memset(worldMove,0,WIDTH*HEIGHT);
	srand(time(0));
	system("cls");
	int randoms=WIDTH*HEIGHT/3;
	while(randoms--){
		world[(rand()%HEIGHT-1)*WIDTH + rand()%WIDTH-1] = 1;
	} while(true){ 
		system("cls");
		draw_world(world,WIDTH,HEIGHT);
		for(int i=1;i<HEIGHT-1;i++){
			for(int j=1;j<WIDTH-1;j++){
				int NA = neighbours_alive(world,i*WIDTH+j,WIDTH);
				if(NA == 0){
					worldMove[i*WIDTH+j] = 0;
				}
				else if(NA == 1){
					worldMove[i*WIDTH+j] = 0;
				}
				else if(NA == 3){
					worldMove[i*WIDTH+j] = 1;
				}
				else if(NA > 3){
					worldMove[i*WIDTH+j] = 0;
				}

			}
		}
		memcpy(world,worldMove,HEIGHT*WIDTH);
	}
}
