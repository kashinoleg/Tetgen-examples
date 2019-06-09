#pragma once
#include "Point3D.h"
#include "Face.h"

namespace TetgenDll
{
	public ref class TetgenLibrary
	{
	private:
		array<Point3D^>^ points;
		array<Face^>^ faces;
	public:
		array<Point3D^>^ GetPoints() { return points; }
		array<Face^>^ GetFaces() { return faces; }

		bool Triangulate(System::String^ file);
	};
}
