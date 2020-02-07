#pragma once

#include <vector>
#include "Render.h"

struct VElements {
	unsigned int Cnt;
	unsigned int Type;
	unsigned char Normalized;

	static unsigned int GetSizeOfType(unsigned int Type) {
		switch (Type) {
			case GL_FLOAT:return 4;
			case GL_UNSIGNED_INT:return 4;
			case GL_UNSIGNED_BYTE:return 1;
		}
		ASSERT(false);
		return 0;
	}
};

class VLayout
{
private:
	std::vector<VElements>VElemnt;
	unsigned int Stride;

public:
	VLayout() :Stride(0){}

	template<typename T>
	void Push(unsigned int Cnt) {
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int Cnt) {
		VElemnt.push_back({ GL_FLOAT,Cnt,GL_FALSE});
		Stride += Cnt * VElements::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int Cnt) {
		VElemnt.push_back({ GL_UNSIGNED_INT,Cnt,GL_FALSE });
		Stride += Cnt * VElements::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int Cnt) {
		VElemnt.push_back({ GL_UNSIGNED_BYTE,Cnt,GL_TRUE });
		Stride += Cnt*VElements::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VElements>GetElements()const { return VElemnt; }
	inline unsigned int GetStride()const { return Stride; }
};

