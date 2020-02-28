/*
 * scene.h
 *
 *  Created on: 2017-4-2
 *      Author: a
 */

#ifndef SCENE_H_
#define SCENE_H_

#include "../node/terrainNode.h"
#include "../node/waterNode.h"
#include "../node/animationNode.h"
#include "../node/instanceNode.h"
#include "../sky/sky.h"

struct MeshObject {
	Mesh* mesh;
	Object* object;
	MeshObject(Mesh* m, Object* o) :mesh(m), object(o) {}
};

class Scene {
public:
	std::vector<MeshObject*> meshes;
	std::vector<Animation*> anims;
public:
	std::map<Animation*, uint> animCount;
private:
	std::map<Mesh*, uint> meshCount;
	bool inited;
private:
	void initNodes();
public:
	float time;
	Camera* mainCamera;
	Camera* reflectCamera;
	Sky* skyBox;
	WaterNode* water;
	TerrainNode* terrainNode;
	Node* staticRoot;
	Node* billboardRoot;
	Node* animationRoot;
	StaticNode* textureNode; // Use it to draw texture for debugging
	std::vector<Node*> boundingNodes; // Used for debugging
public:
	Scene();
	~Scene();
	void createReflectCamera();
	void createSky();
	void createWater(const vec3& position, const vec3& size);
	void createTerrain(const vec3& position, const vec3& size);
	void updateVisualTerrain(int bx, int bz, int sizex, int sizez);
	void updateNodes();
	void flushNodes();
	void updateReflectCamera();
	void addObject(Object* object);
	uint queryMeshCount(Mesh* mesh);
	void finishInit() { inited = true; }
	bool isInited() { return inited; }
	void act(float dTime) { time = dTime * 0.025; }
public: // Just for debugging
	void createNodeAABB(Node* node);
	void clearAllAABB();
};


#endif /* SCENE_H_ */
