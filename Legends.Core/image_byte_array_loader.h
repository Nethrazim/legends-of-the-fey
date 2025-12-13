#pragma once
#include <string>

struct TextureData;

namespace LegendsCore
{
	namespace Assets
	{
		class ImageByteArrayLoader
		{
		public:
			TextureData* loadImageByteArray(std::string file);
		};
	}
}