#include "gra.h"

gra::~gra()
{}
gra::gra()
{}

void gra::init(const char* title, int xpos, int ypos, int szer, int wysoko, bool pelenekran) //pentla gry
{
	int flags = 0;
	if (pelenekran)
	{
		flags = SDL_WINDOW_FULLSCREEN;

	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "subsystem initia" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, szer, wysoko, flags); //okno podajesz parametry okna
		if (window)
		{
			std::cout << "window created" << std::endl;

		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			std::cout << "window renderer" << std::endl;
		}

		dziala = true;
	}
	 else
	{
		dziala = false;


	}
}

void gra::update() //rzeczy które mają być robione podczas gdy ejst odpalone
{}
void gra::render()
{

	SDL_RenderClear(renderer);
	//TU do renderu rzeczy
	SDL_RenderPresent(renderer);



}
void gra::handleevent()
{
	SDL_Event event;
	SDL_PollEvent(&event); 
	switch (event.type)
	{
	case SDL_QUIT:
			dziala = false;// exit button w górym rogu
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
	std::cout << "game cleaned" << std::endl;

}
