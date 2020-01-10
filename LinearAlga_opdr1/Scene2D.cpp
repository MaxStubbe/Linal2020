#include "Scene2D.h"

Scene2D::Scene2D(SDL_Renderer& renderer) : renderer_(renderer), camera_(Camera2D(Vector2D())) { }

Scene2D::~Scene2D()
{
	for (auto& object : objects_) {
		delete object;
	}
}

void Scene2D::add_obect(Object2D* object)
{
	objects_.push_back(object);
}


void Scene2D::draw()
{
	for (auto& object : objects_) {
		object->draw(renderer_);
	}
}

void Scene2D::update()
{
	for (auto& object : objects_) {
		object->update();
	}
}
