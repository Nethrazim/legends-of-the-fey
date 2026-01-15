#pragma once

namespace GameObjects
{
	class GameObject;

	class GameObjectRenderer
	{
	private:
		GameObject* _gameObject;
	
	public:
		GameObjectRenderer();
		void setGameObjectInstance(GameObject* gameObject);

		void render();
	};
};