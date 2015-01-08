#include <math.h>

class vec2_t
{
private: float x,y;
public:
	vec2_t() : x(0),y(0) {}
	vec2_t(float xc, float yc) : x(xc),y(yc) { } 
	vec2_t(float (&axis)[2]) : x(axis[0]),y(axis[1]) { }

	//-vec2_t, invert
	vec2_t& operator- ()
		{ return vec2_t(-x,-y); }
	
	vec2_t& operator++ ()
	{ 
		++x,++y;
		return *this;
	}
	
	vec2_t& operator++ (int unused)
	{ 
		vec2_t result = *this; 
		operator++();
		return result;
	}
	
	vec2_t& operator-- ()
	{ 
		--x,--y;
		return *this;
	}
	
	vec2_t& operator-- (int unused)
	{ 
		vec2_t result = *this; 
		operator--();
		return result;
	}

#pragma region vec2_t input
	vec2_t& operator- (vec2_t &vec)
	{ return vec2_t(x-vec.x,y-vec.y); }

	vec2_t& operator+ (vec2_t &vec)
	{ return vec2_t(x+vec.x,y+vec.y); }
	
	vec2_t& operator* (vec2_t &vec)
	{ 
		return vec2_t(x*vec.x,y*vec.y);
	}
	
	vec2_t& operator/ (vec2_t &vec)
	{ 
		return vec2_t(x/vec.x,y/vec.y);
	}

	vec2_t& operator= (vec2_t &vec)
	{ 
		x = vec.x;
		y = vec.y;
		return *this;
	}

	bool operator== (vec2_t &vec)
	{ 
		return x == vec.x && y == vec.y;
	}

	bool operator!= (vec2_t &vec)
	{ 
		return x != vec.x && y != vec.y;
	}

	bool operator> (vec2_t &vec)
	{ 
		return x > vec.x && y > vec.y;
	}

	bool operator< (vec2_t &vec)
	{ 
		return x < vec.x && y < vec.y;
	}

	bool operator>= (vec2_t &vec)
	{ 
		return x >= vec.x && y >= vec.y;
	}

	bool operator<= (vec2_t &vec)
	{ 
		return x <= vec.x && y <= vec.y;
	}

	vec2_t& operator+= (vec2_t &vec)
	{ 
		x += vec.x, y += vec.y;
		return *this;
	}

	vec2_t& operator-= (vec2_t &vec)
	{ 
		x -= vec.x, y -= vec.y;
		return *this;
	}

	vec2_t& operator*= (vec2_t &vec)
	{ 
		x *= vec.x, y *= vec.y;
		return *this;
	}

	vec2_t& operator/= (vec2_t &vec)
	{ 
		x /= vec.x, y /= vec.y;
		return *this;
	}
#pragma endregion

#pragma region float input
	vec2_t& operator- (float vec)
	{ return vec2_t(x-vec,y-vec); }

	vec2_t& operator+ (float vec)
	{ return vec2_t(x+vec,y+vec); }
	
	vec2_t& operator* (float vec)
	{ 
		return vec2_t(x*vec,y*vec);
	}
	
	vec2_t& operator/ (float vec)
	{ 
		return vec2_t(x/vec,y/vec);
	}

	vec2_t& operator= (float vec)
	{ 
		x = vec;
		y = vec;
		return *this;
	}

	bool operator== (float vec)
	{ 
		return x == vec && y == vec;
	}

	bool operator!= (float vec)
	{ 
		return x != vec && y != vec;
	}

	bool operator> (float vec)
	{ 
		return x > vec && y > vec;
	}

	bool operator< (float vec)
	{ 
		return x < vec && y < vec;
	}

	bool operator>= (float vec)
	{ 
		return x >= vec && y >= vec;
	}

	bool operator<= (float vec)
	{ 
		return x <= vec && y <= vec;
	}

	vec2_t& operator+= (float vec)
	{ 
		x += vec, y += vec;
		return *this;
	}

	vec2_t& operator-= (float vec)
	{ 
		x -= vec, y -= vec;
		return *this;
	}

	vec2_t& operator*= (float vec)
	{ 
		x *= vec, y *= vec;
		return *this;
	}

	vec2_t& operator/= (float vec)
	{ 
		x /= vec, y /= vec;
		return *this;
	}
#pragma endregion

#pragma region float(*)[2] input
	vec2_t& operator- (float (&vec)[2])
	{ return vec2_t(x-vec[0],y-vec[1]); }

	vec2_t& operator+ (float (&vec)[2])
	{ return vec2_t(x+vec[0],y+vec[1]); }
	
	vec2_t& operator* (float (&vec)[2])
	{ 
		return vec2_t(x*vec[0],y*vec[1]);
	}
	
	vec2_t& operator/ (float (&vec)[2])
	{ 
		return vec2_t(x/vec[0],y/vec[1]);
	}

	vec2_t& operator= (float (&vec)[2])
	{ 
		x = vec[0];
		y = vec[1];
		return *this;
	}

	bool operator== (float (&vec)[2])
	{ 
		return x == vec[0] && y == vec[1];
	}

	bool operator!= (float (&vec)[2])
	{ 
		return x != vec[0] && y != vec[1];
	}

	bool operator> (float (&vec)[2])
	{ 
		return x > vec[0] && y > vec[1];
	}

	bool operator< (float (&vec)[2])
	{ 
		return x < vec[0] && y < vec[1];
	}

	bool operator>= (float (&vec)[2])
	{ 
		return x >= vec[0] && y >= vec[1];
	}

	bool operator<= (float (&vec)[2])
	{ 
		return x <= vec[0] && y <= vec[1];
	}

	vec2_t& operator+= (float (&vec)[2])
	{ 
		x += vec[0], y += vec[1];
		return *this;
	}

	vec2_t& operator-= (float (&vec)[2])
	{ 
		x -= vec[0], y -= vec[1];
		return *this;
	}

	vec2_t& operator*= (float (&vec)[2])
	{ 
		x *= vec[0], y *= vec[1];
		return *this;
	}

	vec2_t& operator/= (float (&vec)[2])
	{ 
		x /= vec[0], y /= vec[1];
		return *this;
	}
#pragma endregion

	float operator[] (int xc)
	{ 
		return *(float*)((int)this + xc*4);
	}

	vec2_t& Normalize()
	{
		float length = Length();
		*this /= length;
		return *this;
	}

	float Length()
	{
		return sqrt(x*x + y*y);
	}

	float LengthSq()
	{
		return (x*x + y*y);
	}

	float Distance (vec2_t &vec)
	{ 
		return sqrt(DistanceEx(vec));
	}

	float DistanceEx (vec2_t &vec)
	{ 
		float newX = x - vec.x;
		float newY = y - vec.y;
		return (newX * newX + newY * newY);
	}

	float Distance (float (&vec)[2])
	{ 
		return sqrt(DistanceEx(vec));
	}

	float DistanceEx (float (&vec)[2])
	{ 
		float newX = x - vec[0];
		float newY = y - vec[1];
		return (newX * newX + newY * newY);
	}
};

class vec3_t
{
private: float x,y,z;
public:
	vec3_t() : x(0),y(0),z(0) {}
	vec3_t(float xc, float yc, float zc) : x(xc),y(yc),z(zc) { } 
	vec3_t(float (&axis)[3]) : x(axis[0]),y(axis[1]),z(axis[2]) { } 

	//-vec3_t, invert
	vec3_t& operator- ()
		{ return vec3_t(-x,-y,-z); }
	
	vec3_t& operator++ ()
	{ 
		++x,++y,++z;
		return *this;
	}
	
	vec3_t& operator++ (int unused)
	{ 
		vec3_t result = *this; 
		++x,++y,++z;
		return result;
	}
	
	vec3_t& operator-- ()
	{ 
		--x,--y,--z;
		return *this;
	}
	
	vec3_t& operator-- (int unused)
	{ 
		vec3_t result = *this; 
		--x,--y,--z;
		return result;
	}

#pragma region vec3_t input
	vec3_t& operator- (vec3_t &vec)
	{ return vec3_t(x-vec.x,y-vec.y,z-vec.z); }

	vec3_t& operator+ (vec3_t &vec)
	{ return vec3_t(x+vec.x,y+vec.y,z+vec.z); }
	
	vec3_t& operator* (vec3_t &vec)
	{ 
		return vec3_t(x*vec.x,y*vec.y,z*vec.z);
	}
	
	vec3_t& operator/ (vec3_t &vec)
	{ 
		return vec3_t(x/vec.x,y/vec.y,z/vec.z);
	}

	vec3_t& operator= (vec3_t &vec)
	{ 
		x = vec.x;
		y = vec.y;
		z = vec.z;
		return *this;
	}

	bool operator== (vec3_t &vec)
	{ 
		return x == vec.x && y == vec.y && z == vec.z;
	}

	bool operator!= (vec3_t &vec)
	{ 
		return x != vec.x && y != vec.y && z != vec.z;
	}

	bool operator> (vec3_t &vec)
	{ 
		return x > vec.x && y > vec.y && z > vec.z;
	}

	bool operator< (vec3_t &vec)
	{ 
		return x < vec.x && y < vec.y && z < vec.z;
	}

	bool operator>= (vec3_t &vec)
	{ 
		return x >= vec.x && y >= vec.y && z >= vec.z;
	}

	bool operator<= (vec3_t &vec)
	{ 
		return x <= vec.x && y <= vec.y && z <= vec.z;
	}

	vec3_t& operator+= (vec3_t &vec)
	{ 
		x += vec.x, y += vec.y, z += vec.z;
		return *this;
	}

	vec3_t& operator-= (vec3_t &vec)
	{ 
		x -= vec.x, y -= vec.y, z -= vec.z;
		return *this;
	}

	vec3_t& operator*= (vec3_t &vec)
	{ 
		x *= vec.x, y *= vec.y, z *= vec.z;
		return *this;
	}

	vec3_t& operator/= (vec3_t &vec)
	{ 
		x /= vec.x, y /= vec.y, z /= vec.z;
		return *this;
	}
#pragma endregion

#pragma region float input
	vec3_t& operator- (float vec)
	{ return vec3_t(x-vec,y-vec,z-vec); }

	vec3_t& operator+ (float vec)
	{ return vec3_t(x+vec,y+vec,z+vec); }
	
	vec3_t& operator* (float vec)
	{ 
		return vec3_t(x*vec,y*vec,z*vec);
	}
	
	vec3_t& operator/ (float vec)
	{ 
		return vec3_t(x/vec,y/vec,z/vec);
	}

	vec3_t& operator= (float vec)
	{ 
		x = vec;
		y = vec;
		z = vec;
		return *this;
	}

	bool operator== (float vec)
	{ 
		return x == vec && y == vec && z == vec;
	}

	bool operator!= (float vec)
	{ 
		return x != vec && y != vec && z != vec;
	}

	bool operator> (float vec)
	{ 
		return x > vec && y > vec && z > vec;
	}

	bool operator< (float vec)
	{ 
		return x < vec && y < vec && z < vec;
	}

	bool operator>= (float vec)
	{ 
		return x >= vec && y >= vec && z >= vec;
	}

	bool operator<= (float vec)
	{ 
		return x <= vec && y <= vec && z <= vec;
	}

	vec3_t& operator+= (float vec)
	{ 
		x += vec, y += vec, z += vec;
		return *this;
	}

	vec3_t& operator-= (float vec)
	{ 
		x -= vec, y -= vec, z -= vec;
		return *this;
	}

	vec3_t& operator*= (float vec)
	{ 
		x *= vec, y *= vec, z *= vec;
		return *this;
	}

	vec3_t& operator/= (float vec)
	{ 
		x /= vec, y /= vec, z /= vec;
		return *this;
	}
#pragma endregion

#pragma region float(*)[3] input
	vec3_t& operator- (float (&vec)[3])
	{ return vec3_t(x-vec[0],y-vec[1],z-vec[2]); }

	vec3_t& operator+ (float (&vec)[3])
	{ return vec3_t(x+vec[0],y+vec[1],z+vec[2]); }
	
	vec3_t& operator* (float (&vec)[3])
	{ 
		return vec3_t(x*vec[0],y*vec[1],z*vec[2]);
	}
	
	vec3_t& operator/ (float (&vec)[3])
	{ 
		return vec3_t(x/vec[0],y/vec[1],z/vec[2]);
	}

	vec3_t& operator= (float (&vec)[3])
	{ 
		x = vec[0];
		y = vec[1];
		z = vec[2];
		return *this;
	}

	bool operator== (float (&vec)[3])
	{ 
		return x == vec[0] && y == vec[1] && z == vec[2];
	}

	bool operator!= (float (&vec)[3])
	{ 
		return x != vec[0] && y != vec[1] && z != vec[2];
	}

	bool operator> (float (&vec)[3])
	{ 
		return x > vec[0] && y > vec[1] && z > vec[2];
	}

	bool operator< (float (&vec)[3])
	{ 
		return x < vec[0] && y < vec[1] && z < vec[2];
	}

	bool operator>= (float (&vec)[3])
	{ 
		return x >= vec[0] && y >= vec[1] && z >= vec[2];
	}

	bool operator<= (float (&vec)[3])
	{ 
		return x <= vec[0] && y <= vec[1] && z <= vec[2];
	}

	vec3_t& operator+= (float (&vec)[3])
	{ 
		x += vec[0], y += vec[1], z += vec[2];
		return *this;
	}

	vec3_t& operator-= (float (&vec)[3])
	{ 
		x -= vec[0], y -= vec[1], z -= vec[2];
		return *this;
	}

	vec3_t& operator*= (float (&vec)[3])
	{ 
		x *= vec[0], y *= vec[1], z *= vec[2];
		return *this;
	}

	vec3_t& operator/= (float (&vec)[3])
	{ 
		x /= vec[0], y /= vec[1], z /= vec[2];
		return *this;
	}
#pragma endregion

	float operator[] (int xc)
		{ return *(float*)((int)this + (xc*4));}

	vec3_t& Normalize()
	{
		float length = Length();
		*this /= length;
		return *this;
	}

	float Length()
	{
		return sqrt(x*x + y*y + z*z);
	}

	float LengthSq()
	{
		return (x*x + y*y + z*z);
	}

	float Distance (vec3_t &vec)
	{ 
		return sqrt(DistanceEx(vec));
	}

	float DistanceEx (vec3_t &vec)
	{ 
		float newX = x - vec.x;
		float newY = y - vec.y;
		float newZ = z - vec.z;
		return (newX * newX + newY * newY + newZ * newZ);
	}

	float Distance (float (&vec)[3])
	{ 
		return sqrt(DistanceEx(vec));
	}

	float DistanceEx (float (&vec)[3])
	{ 
		float newX = x - vec[0];
		float newY = y - vec[1];
		float newZ = z - vec[2];
		return (newX * newX + newY * newY + newZ * newZ);
	}
};

class vec4_t
{
private: float x,y,z,a;
public:
	vec4_t() : x(0),y(0),z(0),a(0) {}
	vec4_t(float xc, float yc, float zc, float ac) : x(xc),y(yc),z(zc),a(ac) { } 
	vec4_t(float (&axis)[4]) : x(axis[0]),y(axis[1]),z(axis[2]),a(axis[3]) { } 

	//-vec3_t, invert
	vec4_t& operator- ()
		{ return vec4_t(-x,-y,-z,-a); }
	
	vec4_t& operator++ ()
	{ 
		++x,++y,++z,++a;
		return *this;
	}
	
	vec4_t& operator++ (int unused)
	{ 
		vec4_t result(*this); 
		operator++();
		return result;
	}
	
	vec4_t& operator-- ()
	{ 
		--x,--y,--z;
		return *this;
	}
	
	vec4_t& operator-- (int unused)
	{ 
		vec4_t result(*this); 
		operator--();
		return result;
	}

#pragma region vec4_t input
	vec4_t& operator- (vec4_t &vec)
	{ return vec4_t(x-vec.x,y-vec.y,z-vec.z,a-vec.a); }

	vec4_t& operator+ (vec4_t &vec)
	{ return vec4_t(x+vec.x,y+vec.y,z+vec.z,a+vec.a); }
	
	vec4_t& operator* (vec4_t &vec)
	{ 
		return vec4_t(x*vec.x,y*vec.y,z*vec.z,a*vec.a);
	}
	
	vec4_t& operator/ (vec4_t &vec)
	{ 
		return vec4_t(x/vec.x,y/vec.y,z/vec.z,a/vec.a);
	}

	vec4_t& operator= (vec4_t &vec)
	{ 
		x = vec.x;
		y = vec.y;
		z = vec.z;
		a = vec.a;
		return *this;
	}

	bool operator== (vec4_t &vec)
	{ 
		return x == vec.x && y == vec.y && z == vec.z && a == vec.a;
	}

	bool operator!= (vec4_t &vec)
	{ 
		return x != vec.x && y != vec.y && z != vec.z && a != vec.a;
	}

	bool operator> (vec4_t &vec)
	{ 
		return x > vec.x && y > vec.y && z > vec.z && a > vec.a;
	}

	bool operator< (vec4_t &vec)
	{ 
		return x < vec.x && y < vec.y && z < vec.z && a < vec.a;
	}

	bool operator>= (vec4_t &vec)
	{ 
		return x >= vec.x && y >= vec.y && z >= vec.z && a >= vec.a;
	}

	bool operator<= (vec4_t &vec)
	{ 
		return x <= vec.x && y <= vec.y && z <= vec.z && a <= vec.a;
	}

	vec4_t& operator+= (vec4_t &vec)
	{ 
		x += vec.x, y += vec.y, z += vec.z, a += vec.a;
		return *this;
	}

	vec4_t& operator-= (vec4_t &vec)
	{ 
		x -= vec.x, y -= vec.y, z -= vec.z, a -= vec.a;
		return *this;
	}

	vec4_t& operator*= (vec4_t &vec)
	{ 
		x *= vec.x, y *= vec.y, z *= vec.z, a *= vec.a;
		return *this;
	}

	vec4_t& operator/= (vec4_t &vec)
	{ 
		x /= vec.x, y /= vec.y, z /= vec.z, a /= vec.a;
		return *this;
	}
#pragma endregion

#pragma region float input
	vec4_t& operator- (float vec)
	{ return vec4_t(x-vec,y-vec,z-vec,a-vec); }

	vec4_t& operator+ (float vec)
	{ return vec4_t(x+vec,y+vec,z+vec,a+vec); }
	
	vec4_t& operator* (float vec)
	{ 
		return vec4_t(x*vec,y*vec,z*vec,a*vec);
	}
	
	vec4_t& operator/ (float vec)
	{ 
		return vec4_t(x/vec,y/vec,z/vec,a/vec);
	}

	vec4_t& operator= (float vec)
	{ 
		x = vec;
		y = vec;
		z = vec;
		a = vec;
		return *this;
	}

	bool operator== (float vec)
	{ 
		return x == vec && y == vec && z == vec && a == vec;
	}

	bool operator!= (float vec)
	{ 
		return x != vec && y != vec && z != vec && a != vec;
	}

	bool operator> (float vec)
	{ 
		return x > vec && y > vec && z > vec && a > vec;
	}

	bool operator< (float vec)
	{ 
		return x < vec && y < vec && z < vec && a < vec;
	}

	bool operator>= (float vec)
	{ 
		return x >= vec && y >= vec && z >= vec && a >= vec;
	}

	bool operator<= (float vec)
	{ 
		return x <= vec && y <= vec && z <= vec && a <= vec;
	}

	vec4_t& operator+= (float vec)
	{ 
		x += vec, y += vec, z += vec, a += vec;
		return *this;
	}

	vec4_t& operator-= (float vec)
	{ 
		x -= vec, y -= vec, z -= vec, a -= vec;
		return *this;
	}

	vec4_t& operator*= (float vec)
	{ 
		x *= vec, y *= vec, z *= vec, a *= vec;
		return *this;
	}

	vec4_t& operator/= (float vec)
	{ 
		x /= vec, y /= vec, z /= vec, a /= vec;
		return *this;
	}
#pragma endregion

#pragma region float(*)[3] input
	vec4_t& operator- (float (&vec)[4])
	{ return vec4_t(x-vec[0],y-vec[1],z-vec[2],a-vec[3]); }

	vec4_t& operator+ (float (&vec)[4])
	{ return vec4_t(x+vec[0],y+vec[1],z+vec[2],a+vec[3]); }
	
	vec4_t& operator* (float (&vec)[4])
	{ 
		return vec4_t(x*vec[0],y*vec[1],z*vec[2],a*vec[3]);
	}
	
	vec4_t& operator/ (float (&vec)[4])
	{ 
		return vec4_t(x/vec[0],y/vec[1],z/vec[2],a/vec[3]);
	}

	vec4_t& operator= (float (&vec)[4])
	{ 
		x = vec[0];
		y = vec[1];
		z = vec[2];
		a = vec[3];
		return *this;
	}

	bool operator== (float (&vec)[4])
	{ 
		return x == vec[0] && y == vec[1] && z == vec[2] && a == vec[3];
	}

	bool operator!= (float (&vec)[4])
	{ 
		return x != vec[0] && y != vec[1] && z != vec[2] && a != vec[3];
	}

	bool operator> (float (&vec)[4])
	{ 
		return x > vec[0] && y > vec[1] && z > vec[2] && a > vec[3];
	}

	bool operator< (float (&vec)[4])
	{ 
		return x < vec[0] && y < vec[1] && z < vec[2] && z < vec[3];
	}

	bool operator>= (float (&vec)[4])
	{ 
		return x >= vec[0] && y >= vec[1] && z >= vec[2] && a >= vec[3];
	}

	bool operator<= (float (&vec)[4])
	{ 
		return x <= vec[0] && y <= vec[1] && z <= vec[2] && a <= vec[3];
	}

	vec4_t& operator+= (float (&vec)[4])
	{ 
		x += vec[0], y += vec[1], z += vec[2], a += vec[3];
		return *this;
	}

	vec4_t& operator-= (float (&vec)[4])
	{ 
		x -= vec[0], y -= vec[1], z -= vec[2], a -= vec[3];
		return *this;
	}

	vec4_t& operator*= (float (&vec)[4])
	{ 
		x *= vec[0], y *= vec[1], z *= vec[2], a *= vec[3];
		return *this;
	}

	vec4_t& operator/= (float (&vec)[4])
	{ 
		x /= vec[0], y /= vec[1], z /= vec[2], a /= vec[3];
		return *this;
	}
#pragma endregion

	float& operator[] (int xc)
		{ return *(float*)((int)this + (xc*4)); }
	
	vec4_t& Normalize()
	{
		float length = Length();
		*this /= length;
		return *this;
	}

	float Length()
	{
		return sqrt(x*x + y*y + z*z);
	}

	float LengthSq()
	{
		return (x*x + y*y + z*z);
	}

	float Distance (vec4_t &vec)
	{ 
		return sqrt(DistanceEx(vec));
	}

	float DistanceEx (vec4_t &vec)
	{ 
		float newX = x - vec.x;
		float newY = y - vec.y;
		float newZ = z - vec.z;
		float newA = a - vec.a;
		return (newX * newX + newY * newY + newZ * newZ + newA * newA);
	}

	float Distance (float (&vec)[4])
	{ 
		return sqrt(DistanceEx(vec));
	}

	float DistanceEx (float (&vec)[4])
	{ 
		float newX = x - vec[0];
		float newY = y - vec[1];
		float newZ = z - vec[2];
		float newA = a - vec[3];
		return (newX * newX + newY * newY + newZ * newZ + newA * newA);
	}
};
