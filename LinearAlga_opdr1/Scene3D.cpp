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

void Scene3D::add_object(Object3D* object)
{
	if (looping) {
		objectsToAdd_.push_back(object);
	}
	else {
		objects_.push_back(object);
	}
}

void Scene3D::delete_object(Object3D* object)
{
	if (looping) {
		objectsToDelete_.push_back(object);
	}
	else{
		for (int i = 0; i < objects_.size(); i++) {
			if (object == objects_[i]) {
				objects_.erase(objects_.begin() + i);
			}
		}
	}
	
}

void Scene3D::draw()
{
	for (auto& object : objects_) {
		object->draw(renderer_);
	}
}

void Scene3D::update()
{
	looping = true;
	for (auto& object : objects_) {
		object->update();
	}
	for (auto& object1 : objects_) {
		for (auto& object2 : objects_) {
			if (object1 != object2)
				if (object1->collides_with(*object2))
					object1->on_collision();
		}
	}
	looping = false;

	
	for (int i = 0; i < objectsToAdd_.size(); i++) {
		add_object(objectsToAdd_[i]);
	}
	objectsToAdd_.clear();
	
	for (int i = 0; i < objectsToDelete_.size(); i++) {
		delete_object(objectsToDelete_[i]);
	}
	objectsToDelete_.clear();
	
	
}
