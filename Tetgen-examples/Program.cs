using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Tetgen_examples.Writers;
using TetgenDll;

namespace Tetgen_examples
{
    class Program
    {
        static void Main(string[] args)
        {
            var tetgen = new TetgenLibrary();
            var result = tetgen.Triangulate("Resources/sphere.stl");
            if (result)
            {
                Console.WriteLine("Triangulation is ok!");
                var points = tetgen.GetPoints();
                Console.WriteLine("Length of points: {0}", points.Length);
                var faces = tetgen.GetFaces();
                Console.WriteLine("Length of faces: {0}", faces.Length);

                ObjWriter.SaveToObj("result.obj", points, faces);
            }
            else
            {
                Console.WriteLine("File not found!");
            }
            Console.ReadLine();
        }
    }
}
