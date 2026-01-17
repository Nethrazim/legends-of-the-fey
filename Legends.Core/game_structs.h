#pragma once

struct TextureData
{
	int w, h, comp;
	unsigned char* data = nullptr;
};

struct VertexUV
{
	float x, y, z, u, v, nx, ny, nz;
};