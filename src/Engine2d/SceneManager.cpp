#include "SceneManager.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager* SceneManager::GetInstance() {
	if (Instance == nullptr) {
		Instance = new SceneManager;
	}
	return Instance;
}

void SceneManager::AddScene(Scene* s){
	m_scenes.push_back(s);
}

void SceneManager::SetCurrentScene(Scene* scene){
	CurrentScene = scene;
}

void SceneManager::SetCurrentScene(int i) {
	CurrentScene = m_scenes[i];
}
Scene* SceneManager::GetCurrentScene(){
	return CurrentScene;
}