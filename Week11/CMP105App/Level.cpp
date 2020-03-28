#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	audio->playMusicbyName("cantina");

	audio->addSound("sfx/getover.ogg", "getoverhere");
	audio->addSound("sfx/smb_jump-small.ogg", "jump");

	texture.loadFromFile("gfx/MushroomTrans.png");
	player.setTexture(&texture);
	player.setPosition(0, 0);
	player.setSize(sf::Vector2f(100, 100));
	player.setInput(input);
	player.setWindow(window);
	player.setAudio(audio);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	player.handleInput(dt);

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		gameState->setCurrentState(State::PAUSE);
	}
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	if (player.getPosition().x + player.getSize().x <= 0 || player.getPosition().x >= window->getSize().x)
	{
		reset();
		gameState->setCurrentState(State::MENU);
	}
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(player);

	if (gameState->getCurrentState() != State::PAUSE)
	{
		endDraw();
	}
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}

void Level::reset()
{
	player.setPosition(0, 0);
}