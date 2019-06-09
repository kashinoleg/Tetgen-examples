#pragma once
#include "Polygon.h"

namespace TetgenDll
{
	public ref class Face
	{
	private:
		array<Polygon^>^ polygons;

	public:
		array<Polygon^>^ GetPolygons() { return polygons; }
		void SetPolygons(array<Polygon^>^& polygons) { this->polygons = polygons; }
	};
}
