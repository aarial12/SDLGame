#pragma once

#include <math.h>

class Vector2D {

public:

	Vector2D(float x, float y) : m_x(x), m_y(y) {}

	float getX() { return m_x; }
	float getY() { return m_y; }

	float setX(float x) { return m_x = x; }
	float setY(float y) { return m_y = y; }

	float lenght() { return sqrt(m_x * m_x + m_y * m_y); }

	Vector2D operator+(const Vector2D& v2) const {
		return Vector2D(m_x + v2.m_x, m_y + v2.m_y);
	}

	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) {
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;

		return v1;
	}

	Vector2D operator*(float scalar) {
		return Vector2D(m_x * scalar, m_y * scalar);
	}

	Vector2D& operator*=(float scalar) {
		m_x *= scalar;
		m_y *= scalar;

		return *this;
	}

	Vector2D operator-(const Vector2D& v2) const{
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}

	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2){
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;
		return v1;
	}

	Vector2D operator/(float scalar){
		return Vector2D(m_x / scalar, m_y / scalar);
	}

	Vector2D& operator/=(float scalar){
		m_x /= scalar;
		m_y /= scalar;
		return *this;
	}

	

private:

	float m_x;
	float m_y;

};
