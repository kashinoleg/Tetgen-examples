#include "pch.h"
#include "TetgenLibrary.h"
#include "tetgen.h"

using namespace TetgenDll;
using namespace System;
using namespace System::Runtime::InteropServices;

bool TetgenLibrary::Triangulate(String^ file)
{
	tetgenio input;
	tetgenio output;

	char* name = (char*)Marshal::StringToHGlobalAnsi(file).ToPointer();
	auto result = input.load_stl(name);
	Marshal::FreeHGlobal((IntPtr)name);
	auto cmd = _strdup("pq1.414a0.1");
	tetrahedralize(cmd, &input, &output);

	auto pointsSize = output.numberofpoints;
	points = gcnew array<Point3D^>(pointsSize);

	for (int i = 0; i < pointsSize; i++)
	{
		auto point = gcnew Point3D();
		point->SetX(output.pointlist[i * 3]);
		point->SetY(output.pointlist[i * 3 + 1]);
		point->SetZ(output.pointlist[i * 3 + 2]);
		points[i] = point;
	}

	auto faceSize = output.numberoftrifaces;
	faces = gcnew array<Face^>(faceSize);
	for (int i = 0; i < faceSize; i++)
	{
		auto face = gcnew Face();
		auto polygons = gcnew array<Polygon^>(1);

		auto polygon = gcnew Polygon();
		auto indexes = gcnew array<int>(3);
		indexes[0] = output.trifacelist[i * 3];
		indexes[1] = output.trifacelist[i * 3 + 1];
		indexes[2] = output.trifacelist[i * 3 + 2];

		polygon->SetIndexes(indexes);
		polygons[0] = polygon;

		face->SetPolygons(polygons);
		faces[i] = face;
	}
	return result;
}
