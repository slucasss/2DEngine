#pragma once
#include "Scene.inl"


class SceneManager {

	static SceneManager* Instance;

	std::vector<Scene*> m_scenes;

	Scene* CurrentScene = nullptr;
public:

	static SceneManager* GetInstance();

	void AddScene(Scene* s);

	void SetCurrentScene(Scene* scene);
	void SetCurrentScene(int i);
	Scene* GetCurrentScene();

};