
#include "Mason/Script.hpp"
#include <iostream>
#include "Mason/SpriteRenderer.h"
#include "Mason/Scene.hpp"
#include "Mason/Engine.hpp"

using namespace Mason;

class DangerousCollisions :public Script
{
	bool done = false;
protected:
	DangerousCollisions(GameObject* gameObject) : Script(gameObject)
	{
	}

	friend GameObject;

public:
	void OnCollisionEnter(GameObject* other) override
	{
		/*auto spr = other->getComponent<SpriteRenderer>()->sprite;
		auto tex = spr->getTexture();
		spr->setTexture();*/
	
			auto tr = other->getComponent<Transform>();
			auto scale = tr->getScale();
			tr->setScale(glm::vec3(scale.x*2, scale.y*2,scale.z));
		
	}
	/*void OnCollisionExit(GameObject* other) override
	{
		
	}*/

	
};