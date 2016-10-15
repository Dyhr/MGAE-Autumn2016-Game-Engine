#include "PhysicsBody2D.hpp"

#include <algorithm>

PhysicsBody2D::~PhysicsBody2D() {
	auto vec = &Physics::instance->bodies2D;
	vec->erase(remove(vec->begin(),vec->end(),this), vec->end());
}

PhysicsBody2D::PhysicsBody2D(GameObject* gameObject) : Component(gameObject) {
	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	body = Physics::instance->world.CreateBody(&bd);
	Physics::instance->bodies2D.push_back(this);
}