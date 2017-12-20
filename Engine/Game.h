#pragma once

#include "FrameTimer.h"
#include "MainWindow.h"

#include "GameComponentFactory.h"
#include "PhysicsManager.h"

#include "GameLevel.h"
#include "GameCamera.h"
#include "GameLevelManager.h"
#include "ProjectileManagerComponent.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void Update();

	~Game();

private:
	void InitaliseLevel();
	void InitaliseBackground(LevelData& levelData);
	void InitaliseImportantObjects(LevelData& levelData);
	void InitaliseObjects(LevelData& levelData);
	void InitaliseGUI();

	void CacheSpecificComponents();

	void ComposeFrame();
	void UpdateModel();

private:
	MainWindow& wnd;

	GameCamera*									_camera;

	GameObject*									_player;

	FrameTimer									_frameTimer;
	PhysicsManager								_physicsManager;
	GameLevel									_gameLevel;
	
	std::vector<GameObject*>					_gameObjects;
	std::map<GameObject*,DamageableComponent*>  _damageableGameObjects;
};