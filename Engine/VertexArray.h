#pragma once

#include "Vertex.h"
#include "VLayout.h"

class VertexArray
{
private:
	unsigned int ID;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const Vertex& VB,const VLayout& Layout);
	void Bind()const;
	void Unbind()const;
};

