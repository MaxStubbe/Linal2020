#include "pch.h"
#include "CppUnitTest.h"
#include "../LinearAlga_opdr1/Vector3D.cpp"
#include "../LinearAlga_opdr1/Vector2D.cpp"
#include "../LinearAlga_opdr1//Matrix3D.cpp"
#include "../LinearAlga_opdr1//Matrix2D.cpp"
#include "../LinearAlga_opdr1/Basic_Matrices.cpp"
#include "../LinearAlga_opdr1/BoundingBox3D.cpp"
//#include "../LinearAlga_opdr1/Cube3D.cpp"
//#include "../LinearAlga_opdr1/Camera3D.cpp"
//#include "../LinearAlga_opdr1/Object3D.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinearAlgaTest
{
	TEST_CLASS(Vector_Tests)
	{
	public:
		TEST_METHOD(Vector_Compare)
		{
			Vector3D v1 = Vector3D(1, 1, 1);
			Vector3D v2 = Vector3D(1, 1, 1);
			Assert::IsTrue(v1 == v2);
		}
		
		TEST_METHOD(Vector_Add)
		{
			Vector3D v1 = Vector3D(1, 1, 1);
			Vector3D v2 = Vector3D(2, 2, 2);
			Vector3D v3 = Vector3D(3, 3, 3);
			Vector3D v4 = v1 + v2;
			Assert::IsTrue(v4 == v3);
		}

		TEST_METHOD(Vector_Subtract)
		{
			Vector3D v1 = Vector3D(1, 1, 1);
			Vector3D v2 = Vector3D(2, 2, 2);
			Vector3D v3 = Vector3D(3, 3, 3);
			Vector3D v4 = v3 - v2;
			Assert::IsTrue(v4 == v1);
		}

		TEST_METHOD(Vector_Multiply)
		{
			Vector3D v1 = Vector3D(1, 1, 1);
			Vector3D v2 = Vector3D(3, 3, 3);
			Vector3D v3 = v1 * 3;
			Assert::IsTrue(v3 == v2);
		}

		TEST_METHOD(Vector_Divide)
		{
			Vector3D v1 = Vector3D(1, 1, 1);
			Vector3D v2 = Vector3D(3, 3, 3);
			Vector3D v3 = v2 / 3;
			Assert::IsTrue(v3 == v1);
		}

		TEST_METHOD(Vector_Dot)
		{
			Vector3D v1 = Vector3D(1, 2, 3);
			Vector3D v2 = Vector3D(3, 2, 1);
			float d = v1.dot_product(v2);
			Assert::IsTrue(d == 10.0f);
		}

		TEST_METHOD(Vector_Cross)
		{
			Vector3D v1 = Vector3D(1, 2, 3);
			Vector3D v2 = Vector3D(3, 2, 1);
			Vector3D v3 = Vector3D(-4,8,-4);
			Vector3D v4 = v1.cross_product(v2);
			Assert::IsTrue(v3 == v4);
		}

		TEST_METHOD(Vector_Magnitude)
		{
			Vector3D v1 = Vector3D(3, 4, 5);
			float m = v1.magnitude();
			float n = sqrt(50);
			Assert::IsTrue(m == n);
		}

		TEST_METHOD(Vector_Normalize)
		{
			Vector3D v1 = Vector3D(2, 0, 0);
			Vector3D v2 = Vector3D(1, 0, 0);
			Vector3D v3 = v1.normalize();
			Assert::IsTrue(v3 == v2);
		}
	};

	TEST_CLASS(Matrix_Tests)
	{
	public:

		TEST_METHOD(Matrix_Compare)
		{
			float matrix[4][4] = {
				{1,0,0,0},
				{0,1,0,0},
				{0,0,1,0},
				{0,0,0,1}
			};
			Assert::IsTrue(Matrix3D(matrix) == Matrix3D());
		}

		TEST_METHOD(Matrix_Add)
		{
			float matrix[4][4] = {
				{2,0,0,0},
				{0,2,0,0},
				{0,0,2,0},
				{0,0,0,2}
			};
			Assert::IsTrue((Matrix3D() + Matrix3D()) == Matrix3D(matrix));
		}

		TEST_METHOD(Matrix_Subtract)
		{
			float matrix[4][4] = {
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
			};
			Assert::IsTrue((Matrix3D() - Matrix3D()) == Matrix3D(matrix));
		}

		TEST_METHOD(Matrix_Multiplication)
		{
			float matrix[4][4] = {
				{1,2,3,4},
				{2,3,4,1},
				{3,4,1,2},
				{4,1,2,3}
			};
			float matrix2[4][4] = {
				{4,3,2,1},
				{1,4,3,2},
				{2,1,4,3},
				{3,2,1,4}
			};
			float matrix3[4][4] = {
				{24,22,24,30},
				{22,24,30,24},
				{24,30,24,22},
				{30,24,22,24}
			};

			Assert::IsTrue((Matrix3D(matrix) * Matrix3D(matrix2)) == Matrix3D(matrix3));
		}

		TEST_METHOD(Matrix_Divide)
		{
			float matrix[4][4] = {
				{2,0,0,0},
				{0,2,0,0},
				{0,0,2,0},
				{0,0,0,2}
			};
			Assert::IsTrue((Matrix3D(matrix) / 2) == Matrix3D());
		}

		TEST_METHOD(Matrix_Multiply)
		{
			float matrix[4][4] = {
				{2,0,0,0},
				{0,2,0,0},
				{0,0,2,0},
				{0,0,0,2}
			};
			Assert::IsTrue((Matrix3D() * 2) == Matrix3D(matrix));
		}
	};


	TEST_CLASS(Collision_Tests)
	{
	public:

		TEST_METHOD(Collision_1)
		{
			BoundingBox3D col_1;
			BoundingBox3D col_2;
			col_1.set_collider(Vector3D(),1);
			col_2.set_collider(Vector3D(0.5,0.5,0.5), 1);
			Assert::IsTrue(col_1.collides_with(col_2));
		}

		TEST_METHOD(Collision_2)
		{
			BoundingBox3D col_1;
			BoundingBox3D col_2;
			col_1.set_collider(Vector3D(), 1);
			col_2.set_collider(Vector3D(2.5, 2.5, 2.5), 1);
			Assert::IsTrue(!col_1.collides_with(col_2));
		}

		/*TEST_METHOD(Collision_3)
		{
			Camera3D cam = Camera3D(Vector3D());
			Cube3D col_1 = Cube3D(cam, Vector3D(),1);
			Cube3D col_2 = Cube3D(cam, Vector3D(0.5,0.5,0.5), 1);
			col_1.update();
			col_2.update();
			Assert::IsTrue(col_1.collides_with(col_2));
		}*/

	};
}
