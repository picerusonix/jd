#include "gra.h"
#include <iostream>
gra* Gra = nullptr;



int main(int argc, const char* argv[])
{
	Gra = new gra(); //nowa gra
	Gra->init("silnik", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false); //okno
		
	while(Gra->running()){
		Gra->handleevent();
		Gra->update();
		Gra->render();


	}

	Gra->clear(); //czysci gre


	return 0;
}
