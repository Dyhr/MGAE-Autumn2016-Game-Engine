﻿#include "Mason/BoxCollider2D.hpp"


using namespace Mason;
/** @class BoxCollider2D
* @brief creates a Collider2D with rectangular-shape properties.
* overrides the virtual class Collider2D
*/

void BoxCollider2D::setCenter(float x, float y)
{
	center = b2Vec2(x / Physics::instance->phScale, y / Physics::instance->phScale);
	polyShape.SetAsBox(size.x, size.y, center, 0);
}

void BoxCollider2D::setSize(float width, float height)
{
	size = b2Vec2((width / 2) / Physics::instance->phScale, (height / 2) / Physics::instance->phScale);
	polyShape.SetAsBox(size.x, size.y, center, 0);
}

BoxCollider2D::BoxCollider2D(std::shared_ptr<GameObject> gameObject) : Collider2D(gameObject)
{
	shape = &polyShape;
	setCenter(0, 0);
	setSize(1, 1);
}