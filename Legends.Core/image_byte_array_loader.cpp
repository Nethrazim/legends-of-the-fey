#include "image_byte_array_loader.h"
#include <iostream>
#include "game_structs.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


TextureData* LegendsCore::Assets::ImageByteArrayLoader::loadImageByteArray(std::string file)
{
	if (imgDimensions)
		return imgDimensions;

	imgDimensions = new TextureData();

	imgDimensions->data = stbi_load(file.c_str(), &imgDimensions->w, &imgDimensions->h, &imgDimensions->comp, 0);
	if (!imgDimensions->data)
	{
		std::cerr << "Failed to load texture\n";
		delete imgDimensions->data;
		imgDimensions->data = nullptr;
		delete imgDimensions;
		return nullptr;
	}

	return imgDimensions;
}