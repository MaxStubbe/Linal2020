#include "Scene3D.h"

Scene3D::Scene3D(SDL_Renderer& renderer) : renderer_(renderer), camera_(Camera3D(Vector3D()))
{
}

Scene3D::~Scene3D()
{
	for (auto& object : objects_) {
		delete object;
	}
}

void Scene3D::add_obect(Object3D* object)
{
	objects_.push_back(object);
}

void Scene3D::draw()
{
	for (auto& object : objects_) {
		object->draw(renderer_);
	}
}

void Scene3D::update()
{
	for (auto& object : objects_) {
		object->update();
	}
}
