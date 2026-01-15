https://learnopengl.com/Getting-started/Hello-Triangle
https://learnopengl.com/Getting-started/Shaders
https://learnopengl.com/Getting-started/Textures
https://learnopengl.com/Getting-started/Textures
https://learnopengl.com/Getting-started/Transformations


TODO : 
*	Bad: Calling glGetUniformLocation every frame.
*	Good: Cache uniform locations after program link and reuse them.
*	Restructure GameObjects namespace and convert it to vec3
*	Restructure GameSystem and Window Manager

render()
//
	//SDL_SetRenderTarget(GameLoop::renderer, nullptr);
	/*
	if (shouldRenderRight()) {
		if (sourceRect.x + offsetX < 3000)
		{
			sourceRect.x += offsetX;
		}
	};
	
	if (shouldRenderLeft()) {
		if (sourceRect.x - offsetX > 0)
		{
			sourceRect.x -= offsetX;
		}
	};

	if (shouldRenderBottom()) {
		if ((sourceRect.y + offsetY) < 2000)
		{
			sourceRect.y += offsetY;
		}
	}

	if (shouldRenderTop()) {
		if ((sourceRect.y - offsetY) > 0)
		{
			sourceRect.y -= offsetY;
		}
	}
	*/
	//SDL_RenderCopy(GameLoop::renderer, SceneManager::currentScene()->sceneTexture, &sourceRect, nullptr);
	//SDL_RenderPresent(renderer);


	//scene renderer
		//SDL_SetRenderTarget(GameLoop::renderer, sceneTexture);
	//SDL_SetRenderDrawColor(GameLoop::renderer, 0, 0, 0, 255);
	//SDL_RenderClear(GameLoop::renderer);

	
	//SDL_SetRenderTarget(GameLoop::renderer, sceneTexture);
	//SDL_SetRenderDrawColor(GameLoop::renderer, 0, 0, 0, 255);
	//SDL_RenderClear(GameLoop::renderer);


	if (false)
	{
		int xAnchor = 0;
		int yAnchor = 0;
		int step = 64;
		for (int i = 0; i < tileMap->wTiles; ++i)
		{
			xAnchor = i * step;
			for (int j = 0; j < tileMap->hTiles; ++j)
			{
				yAnchor = j * step;
				
				SDL_Rect rect = {
					xAnchor,
					yAnchor,
					step,
					step
				};

				SDL_RenderCopy(GameLoop::renderer, tileMap->sprite.texture, NULL, &rect);
			}
		}
	}

		for (std::map<std::string, SceneLayer*>::iterator it = layers.begin(); it != layers.end(); ++it)
	{
		for (std::vector<GameObject*>::iterator jit = it->second->layer.begin(); jit != it->second->layer.end(); ++jit)
		{
			if ((*jit)->meshRenderer->active)
			{
				(*jit)->meshRenderer->render(800, 600, WindowManager::getWindow(), context_);
			}
			else
			{
				SDL_Rect rect = {
				static_cast<int>((*jit)->transform.getX()),
				static_cast<int>((*jit)->transform.getY()),
				(*jit)->sprite.width,
				(*jit)->sprite.height
				};

				SDL_RenderCopy(GameLoop::renderer, (*jit)->sprite.texture, NULL, &rect);
			}
		}
	}