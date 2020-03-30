#include "gra.h"
#define SDL_MAIN_HANDLED

SDL_Texture* gracztekstura;
SDL_Rect srcR, destR;

gra::~gra()
{}
gra::gra()
{}

void gra::init(const char* title, int xpos, int ypos, int szer, int wysoko, bool pelenekran)
{
	int flags = 0;
	if (pelenekran)
	{
		flags = SDL_WINDOW_FULLSCREEN;

	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		
		window = SDL_CreateWindow(title, xpos, ypos, szer, wysoko, flags);
		
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 25, 25, 10, 10);
			
		}

		dziala = true;
	}
	 else
	{
		dziala = false;


	}
	SDL_Surface* tmpSurface = IMG_Load("zasoby/ruch2.png");
	gracztekstura = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void gra::update()
{
	licznik++;
	destR.h = 32;
	destR.w = 32;


	std::cout << licznik << std::endl;


}
void gra::render()
{

	SDL_RenderClear(renderer);
	//TU do renderu rzeczy
	SDL_RenderCopy(renderer, gracztekstura, NULL, &destR);
	SDL_RenderPresent(renderer);



}
void gra::handleevent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
			dziala = false;
			break;
	default:
		break;
	}


}

void gra::clear()
{

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	

}

