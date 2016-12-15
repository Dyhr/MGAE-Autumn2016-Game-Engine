#pragma once

#include "Mason/Script.hpp"
#include "Mason/Scene.hpp"
#include "Mason/CircleCollider2D.h"
#include "Mason/Sprite.h"
#include <glm/glm.hpp>
#include <memory>
#include <random>
#include <time.h>

#include <iostream>

using namespace Mason;

class AsteroidSpawner :public Script
{
protected:
	AsteroidSpawner(GameObject* gameObject) : Script(gameObject)
	{
	}

	friend GameObject;
private: 
	glm::vec3 GetRandomPosition(glm::vec2 min, glm::vec2 max) {
		
		return glm::vec3(randf(min.x, max.x), randf(min.y, max.y), 0);
	}

	float randf(float min, float max) {
		srand(time(nullptr));
		return min + static_cast <float> (rand()) / static_cast <float> (RAND_MAX/(max-min));
	}
public:
	static Script* Create(GameObject* gameObject)
	{
		return new AsteroidSpawner(gameObject);
	}

	void OnStart() override
	{
		for (int i = 0; i < numbers["amount"]; i++) {
			auto go = Scene::Instantiate("Asteroid " + i);
		}
		std::cout << "Asteroid spawned: " << numbers["amount"] << std::endl;
	}

};
