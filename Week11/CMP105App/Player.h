#pragma once
#include "Framework/GameObject.h"
#include "Framework/GameState.h"
#include <string>
class Player :public GameObject
{
public:
	Player();
	~Player();

	void setWindow(sf::RenderWindow* win) { window = win; };

	virtual void handleInput(float dt);
	virtual void update(float dt);

protected:
	sf::RenderWindow* window;
	float speed;
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	bool jumped;
	bool jumped2;
};
