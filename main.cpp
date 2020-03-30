#include "gra.h"
#define SDL_MAIN_HANDLED
gra* Gra = nullptr;

int main(int argc, char** argv)
{
	Gra = new gra();
	Gra->init("silnik", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 600, false);
		
	while(Gra->running())
	{
		Gra->handleevent();
		Gra->update();
		Gra->render();


	}

	Gra->clear();


	return 0;
}
