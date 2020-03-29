#ifndef gra_h
#define gra_h
#include "SDL.h"
#include <iostream>

class gra {
public:
	gra();
	~gra();


	void init(const char* title, int xpos, int ypos, int szer, int wysoko, bool pelenekran);  //okno

	void update();   
	void render();  
	void clear();  //czyści okno
	void handleevent();
	bool running() { return dziala; } //sprawdza czy jest odpalone
	


private:

	bool dziala;
	SDL_Window* window;
	SDL_Renderer* renderer;




};



#endif
