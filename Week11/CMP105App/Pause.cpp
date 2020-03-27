#include "Pause.h"

Pause::Pause(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");

	bg.setSize(sf::Vector2f(window->getSize()));
	bg.setFillColor(sf::Color(0,0,0,125));
	bg.setPosition(0, 0);
}

Pause::~Pause()
{

}

// handle user input
void Pause::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		gameState->setCurrentState(State::LEVEL);
	}
}

// Update game objects
void Pause::update(float dt)
{
	
}

// Render level
void Pause::render()
{

	window->draw(bg);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Pause::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Pause::endDraw()
{
	window->display();
}

void Pause::reset()
{
	
}