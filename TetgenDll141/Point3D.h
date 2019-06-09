#pragma once

namespace TetgenDll
{
	public ref class Point3D
	{
	private:
		double x;
		double y;
		double z;

	public:
		double GetX() { return x; }
		void SetX(double& x) { this->x = x; }
		double GetY() { return y; }
		void SetY(double& y) { this->y = y; }
		double GetZ() { return z; }
		void SetZ(double& z) { this->z = z; }
	};
}