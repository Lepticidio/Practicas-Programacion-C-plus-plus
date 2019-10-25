
#define LITE_GFX_IMPLEMENTATION

#include <litegfx.h>
#include <glfw3.h>
#include <iostream>
#include <Vec2.h>

using namespace std;


Vec2 abs(Vec2 const& obj)
{
	Vec2 res;
	res.x = abs(obj.x);
	res.y = abs(obj.y);
	return res;
}


ostream& operator<<(ostream& os, const Vec2& v)
{
	os << '(';
	os << v.x;
	os << ',';
	os << v.y;
	os << ')';


	return os;
}

void CheckVec2Methods()
{

	Vec2 v1 = Vec2(1, 2);
	Vec2 v2 = Vec2(3, 4);
	Vec2 v3 = Vec2(-4, 3);
	Vec2 v4 = Vec2(-4000, 3005);
	Vec2 v5 = Vec2(8, 4);
	std::cout << v2 << " + " << 4 << " = " << v2 + 4 << std::endl;
	std::cout << v2 << " + " << v1 << " = " << v2 + v1 << std::endl;
	std::cout << v2 << " - " << 4 << " = " << v2 - 4 << std::endl;
	std::cout << v2 << " - " << v1 << " = " << v2 - v1 << std::endl;
	std::cout << v2 << " * " << 4 << " = " << v2 * 4 << std::endl;
	std::cout << v2 << " * " << v1 << " = " << v2 * v1 << std::endl;
	std::cout << v2 << " / " << 4 << " = " << v2 / 4 << std::endl;
	std::cout << v2 << " / " << v1 << " = " << v2 / v1 << std::endl;
	std::cout << v3 << " Abs: " << abs(v3) << std::endl;
	std::cout << v2 << " Length: " << v2.Length() << std::endl;
	std::cout << v2 << " Normalized: " << v2.Normalize() << std::endl;
	std::cout << "Dot product of " << v2 << " and " << v1 << " = " << v2.Dot(v1) << std::endl;
	std::cout << "Angle of " << v2 << " and " << v1 << " = " << v2.Angle(v1) << std::endl;
	std::cout << "Angle of " << v2 << " and " << v3 << " = " << v2.Angle(v3) << std::endl;
	std::cout << "Angle of " << v2 << " and " << v4 << " = " << v2.Angle(v4) << std::endl;
	std::cout << "Angle of " << v2 << " and " << -v2 << " = " << v2.Angle(-v2) << std::endl;
	std::cout << "Distance of " << v2 << " and " << v5 << " = " << v2.Distance(v5) << std::endl;
}



int main() {
	
	// Uncomment below line to check in console that all Vec2 methods work properly
	//CheckVec2Methods();




    return 0;
}
