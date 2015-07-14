#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "States.h"
#include "ResourceManager.h"

class GameObject: public sf::Sprite
{
public:
	virtual void Draw(sf::RenderWindow &window)
	{
	}
	virtual void Update(sf::RenderWindow &window)
	{
	}
	virtual void Collision(GameObject go)
	{
	}

	void Load(std::string filename)
	{
		texture.loadFromFile(filename);
		this->setTexture(texture);
	}

	bool CheckCollision(GameObject go)
	{
		return this->getGlobalBounds().intersects(go.getGlobalBounds());
	}

	std::vector<GameObject> GameObjects; //Stocam fiecare gameObject (poate sa fie modificat in vector de pointers)

	sf::Vector2f velocity;
private:
	sf::Texture texture;
};

#endif

