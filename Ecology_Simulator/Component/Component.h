#pragma once

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Entity/Entity.h"
#include "../Simulation/TextureManager.h"

/**
 * Interface for all components.
 */
class Component {};

// Test classes, NOT for usage 
// Note that they do not adhere to ECS principles (C should not have behaviour, for example)
class A : public Component {
	using Component::Component;
};
class B : public Component {
	using Component::Component;
};
class C : public Component {
	using Component::Component;
public:
	char c;
	inline C(char ch = 'a');
	inline const void hello() const;
};
inline C::C(char ch) {
	this->c = ch;
}
inline const void C::hello() const {
	std::cout << "Hello, " << c << std::endl;
}


class PhysicalComponent : public Component {
public:
	/**
	 * Construct a position component (used to position an entity on screen).
	 * 
	 * @param pos 2D vector coordinate of form (x, y)
	 * @param width of sprite
	 * @param height of sprite
	 * @param rotation in degrees
	 * @param velocity of entity
	 */
	PhysicalComponent(glm::vec2 pos, float rotation, float velocity, float width, float height)
		: pos(pos), rotation(rotation), velocity(velocity), width(width), height(height) {}
	glm::vec2 pos;
	float width;
	float height;
	float rotation;
	float velocity;
};

class VertexComponent : public Component {
public:
	/**
	 * Construct a vertex component (used to render vertices of an entity).
	 * 
	 * @param numVertices the number of vertices
	 * @param VBO ID of associated vertex buffer object
	 * @param VAO ID of associated vertex array object
	 */
	VertexComponent(int numVertices, unsigned int VBO, unsigned int VAO) 
		: numVertices(numVertices), VBO(VBO), VAO(VAO) {}
	int numVertices;
	unsigned int VBO;
	unsigned int VAO;
};

class SpriteComponent : public Component {
public:
	/**
	 * Construct a sprite component (used to render texture of an entity).
	 * 
	 * @param Texture type for entity
	 */
	SpriteComponent(Texture texture) 
		: texture(texture) {}
	Texture texture;
};

class LivingComponent : public Component {
public:

	/** 
	 * Species type (used by Targetting and Collision systems for feeding and breeding).
	 * Species are ordered in an ascending food chain, e.g. GRASS is at the bottom, FOX is at the top,
	 * thus listed first and last respectively.
	 */
	enum Species { GRASS, LEMMING, FOX };

	/**
	 * Construct a living component (used to monitor energy level of an entity).
	 * 
	 * @param species type entity represents
	 * @param energy to start with
	 */
	LivingComponent(Species species, float energy) 
		: species(species), energy(energy) {}
	const Species species;
	float energy;
};

class BehaviourComponent : public Component {
public:
	/**
	 * Construct a behaviour component (used in targetting system).
	 * 
	 * @param saturated level of energy at which an entities hunger is considered saturated thus will try to breed instead of eat
	 * @param range in which the entity can detect other entities
	 * @param fov field of view in which an entity can detect other entities (in degrees)
	 */
	BehaviourComponent(float saturated, float range, float fov)
		: saturated(saturated), range(range), fov(fov) {}
	float saturated;
	float range;
	float fov;
};