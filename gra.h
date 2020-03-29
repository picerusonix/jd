#ifndef gra_h
#define gra_h
#include "SDL.h"
#include <iostream>

class gra {
public:
	gra();
	~gra();


	void init(const char* title, int xpos, int ypos, int szer, int wysoko, bool pelenekran);

	void update();
	void render();
	void clear();
	void handleevent();
	bool running() { return dziala; }
	


private:

	bool dziala;
	SDL_Window* window;
	SDL_Renderer* renderer;




};



#endif
