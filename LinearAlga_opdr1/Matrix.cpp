#include "Matrix.h"
#include "Vector2D.h"

Matrix::Matrix(std::vector<float> x, std::vector<float> y)
{
	this->rows = 2;
	this->collumns = x.size();
	this->x = x;
	this->y = y;
	this->matrix = { x,y };
}

Matrix::Matrix(std::vector<float> x, std::vector<float> y, std::vector<float> z)
{
	this->rows = 3;
	this->collumns = x.size();
	this->x = x;
	this->y = y;
	this->z = z;
	this->matrix = { x,y,z };
}

Matrix::Matrix(std::vector<float> x, std::vector<float> y, std::vector<float> z, std::vector<float> w)
{
	this->rows = 4;
	this->collumns = x.size();
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
	this->matrix = { x,y,z,w };
}

Matrix Matrix::operator+(const Matrix& other)
{
	if (this->rows == other.rows) {

		if (rows >= 2) {
			std::vector<float> newX;
			std::vector<float> newY;

			for (std::size_t i = 0; i < x.size(); ++i) {
				newX.push_back(x[i] + other.x[i]);
			}
			for (std::size_t i = 0; i < y.size(); ++i) {
				newY.push_back(y[i] + other.y[i]);
			}
			if (rows > 2) {
				std::vector<float> newZ;

				for (std::size_t i = 0; i < z.size(); ++i) {
					newZ.push_back(z[i] + other.z[i]);
				}

				if (rows > 3) {
					std::vector<float> newW;

					for (std::size_t i = 0; i < w.size(); ++i) {
						newW.push_back(w[i] + other.w[i]);
					}
					return Matrix(newX, newY, newZ, newW);
				}
				else {
					return Matrix(newX, newY, newZ);
				}
			}
			else {
				return Matrix(newX,newY);
			}
		}
	}
}

Matrix Matrix::operator-(const Matrix& other)
{
	if (this->rows == other.rows) {

		if (rows >= 2) {
			std::vector<float> newX;
			std::vector<float> newY;

			for (std::size_t i = 0; i < x.size(); ++i) {
				newX.push_back(x[i] - other.x[i]);
			}
			for (std::size_t i = 0; i < y.size(); ++i) {
				newY.push_back(y[i] - other.y[i]);
			}
			if (rows > 2) {
				std::vector<float> newZ;

				for (std::size_t i = 0; i < z.size(); ++i) {
					newZ.push_back(z[i] - other.z[i]);
				}
				if (rows > 3) {
					std::vector<float> newW;

					for (std::size_t i = 0; i < w.size(); ++i) {
						newW.push_back(w[i] - other.w[i]);
					}
					return Matrix(newX, newY, newZ, newW);
				}
				else {
					return Matrix(newX, newY, newZ);
				}
			}
			else {
				return Matrix(newX, newY);
			}
		}
	}
}

Matrix Matrix::operator*(const Matrix& other)
{
	std::vector<float> newX;
	std::vector<float> newY;
	std::vector<float> newZ;
	std::vector<float> newW;
	float tempx = 0;
	float tempy = 0;
	float tempz = 0;
	float tempw = 0;

	//if (rows == other.collumns) {
		for (std::size_t column = 0; column < other.collumns; ++column) {
			for (std::size_t i = 0; i < other.rows; ++i) {
				tempx += (x[i] * other.matrix[i][column]);
				tempy += (y[i] * other.matrix[i][column]);
				if (rows > 2) {
					tempz += (z[i] * other.matrix[i][column]);
					if (rows > 3) {
						tempw += (w[i] * other.matrix[i][column]);
					}
				}
			}
			newX.push_back(tempx);
			newY.push_back(tempy);
			tempx = 0;
			tempy = 0;
			if (rows > 2) {
				newZ.push_back(tempz);
				tempz = 0;
				if (rows > 3) {
					newW.push_back(tempw);
					tempw = 0;
				}
			}
		}
		if (rows > 3) {
			return Matrix(newX, newY, newZ, newW);
		}
		else if (rows > 2) {
			return Matrix(newX, newY, newZ);
		}
		else {
			return Matrix(newX, newY);
		}
	//}
	/*else {
		throw "Matrixs can't multiply";
	}*/
}

Vector2D Matrix::operator*(const Vector2D& other)
{
	int X;
	int Y;
	this;
	X = (x[0] * other.x) + (x[1] * other.y);
	Y = (y[0] * other.x) + (y[1] * other.y);
	if (collumns == 3) {
		X += (x[2] * other.x);
		Y += (y[2] * other.x);
		if (collumns == 4) {
			X += (x[3] * other.x);
			Y += (y[3] * other.x);
		}
	}
	return Vector2D(X, Y);
}
