#include "Player.h"

Player::Player()
{
	window = nullptr;
	setPosition(0, 0);
	setSize(sf::Vector2f(75, 75));
	speed = 300.f;
	scale = 200.f;
	gravity = sf::Vector2f(0, 9.8) * scale;
	stepVelocity = sf::Vector2f(0, 0);
	jumped = false;
	jumped2 = false;
}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	//Move Right
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		velocity.x += speed;
	}
	//Move Left
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		velocity.x -= speed;
	}
	//Jump
	if (input->isKeyDown(sf::Keyboard::Up))
	{
		input->setKeyUp(sf::Keyboard::Up);
		if (jumped == false)
		{
			audio->playSoundbyName("jump");
			stepVelocity.y = -1000;
			jumped = true;
		}
	}
	//Double Jump
	if (!input->isKeyDown(sf::Keyboard::Up) && jumped == true && jumped2 == false)
	{
		jumped = false;
		jumped2 = true;
	}
	if (input->isKeyDown(sf::Keyboard::Num1))
	{
		audio->playSoundbyName("getoverhere");
	}
}

void Player::update(float dt)
{
	//Gravity
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);
	//Floor collision
	if (getPosition().y + getSize().y >= window->getSize().y)
	{
		jumped = false;
		jumped2 = false;
		setPosition(getPosition().x, window->getSize().y - getSize().y);
		stepVelocity = sf::Vector2f(0, 0);
	}
	//Other Movement
	move(velocity * dt);
	velocity = sf::Vector2f(0, 0);
}