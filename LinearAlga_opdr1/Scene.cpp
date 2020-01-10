#include "Scene.h"

Scene::Scene(SDL_Renderer& renderer) : renderer_(renderer), camera_(Camera2D(Vector2D())) { }

Scene::~Scene()
{
	for (auto& object : objects_) {
		delete object;
	}
}

void Scene::add_obect(Object2D* object)
{
	objects_.push_back(object);
}


void Scene::draw()
{
	for (auto& object : objects_) {
		object->draw(renderer_);
	}
}

void Scene::update()
{
	for (auto& object : objects_) {
		object->update();
	}
}
