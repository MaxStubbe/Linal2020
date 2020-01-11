#include "pch.h"
#include "CppUnitTest.h"
//#include "../LinearAlga_opdr1/Vector3D.h"
#include "../LinearAlga_opdr1/Vector3D.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinearAlgaTest
{
	TEST_CLASS(LinearAlgaTest)
	{
	public:
		
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
}
