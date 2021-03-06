#pragma once
#include "SceneNode.hpp"
#include "Aircraft.hpp"
#include "SpriteNode.h"
#include "CommandQueue.hpp"
#include "Command.hpp"

class World
{
public:
	explicit							World(Game* game);
	void								update(const GameTimer& gt);
	void								draw();
	CommandQueue&						getCommandQueue();

	//void								loadTextures();
	void								buildScene();
private:
	CommandQueue						mCommandQueue;


#pragma region step 3
	void								adaptPlayerPosition();
	void								adaptPlayerVelocity();
#pragma endregion

private:
	enum class Layer
	{
		Background,
		Air
	};


private:
	Game* mGame;

	SceneNode* mSceneGraph;
	std::array<SceneNode*, 2>	mSceneLayers;

	XMFLOAT4							mWorldBounds;
	XMFLOAT2		    				mSpawnPosition;
	float								mScrollSpeed;
	Aircraft* mPlayerAircraft;
	SpriteNode* mBackground;
	Aircraft* mEnemy;
};
