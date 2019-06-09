#pragma once

namespace TetgenDll
{
	public ref class Polygon
	{
	private:
		array<int>^ indexes;

	public:
		array<int>^ GetIndexes() { return indexes; }
		void SetIndexes(array<int>^& indexes) { this->indexes = indexes; }
	};
}
