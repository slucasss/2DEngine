#include <iostream>
#include "Engine2d/Engine2d.h"
#include "main.h"

#include "SpriteTest.h"
#include "TextTest.h"
#include "RectangleTest.h"
#include "CircleTest.h"
#include "ButtonQuit.h"
#include "ButtonPlay.h"

#include "Player.h"
#include "Platforme1.h"
#include "Ground.h"
#include "Background.h"
#include "CircleTest2.h"
#include "Background2.h"

//saumon engine

int main(){
	bool isOpen = true;

	Application* app = Application::GetInstance();
	app->Init("Saumon Engine 1.0" , "../../src/Assets/SaumonEngine.jpeg" , false);

	Scene* scene1 = new Scene;
	scene1->CreateEntity<Background>(Vector2f(100, 0));

	scene1->CreateEntity<Player>(Vector2f(100, 0));
	scene1->CreateEntity<Platforme1>(Vector2f(300, 430 - 32));
	scene1->CreateEntity<Platforme1>(Vector2f(332, 430 - 32));
	scene1->CreateEntity<Platforme1>(Vector2f(364, 430 - 32));
	scene1->CreateEntity<Platforme1>(Vector2f(398, 430-64));

	scene1->CreateEntity<Ground>(Vector2f(0, 430));



	Scene* scene2 = new Scene;
	scene2->CreateEntity<CircleTest>(Vector2f(100, 0));
	

	Scene* scene3 = new Scene;
	scene3->CreateEntity<ButtonPlay>(Vector2f(150, 100));

	Scene* scene4 = new Scene;
	scene4->CreateEntity<TextTest>(Vector2f(150, 100));
	scene4->CreateEntity<SpriteTest>(Vector2f(500, 100));
	scene4->CreateEntity<RectangleTest>(Vector2f(600, 100));

	Scene* scene5 = new Scene;
	scene5->CreateEntity<Background2>(Vector2f(100, 0));
	scene5->CreateEntity<CircleTest2>(Vector2f(100, 100));

	SceneManager* sm = SceneManager::GetInstance();

	sm->AddScene(scene3);
	sm->AddScene(scene4);
	sm->AddScene(scene2);
	sm->AddScene(scene5);
	sm->AddScene(scene1);


	sm->SetCurrentScene(scene3);


	app->Loop();

}