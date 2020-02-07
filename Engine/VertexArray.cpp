#include "VertexArray.h"
#include "Render.h"

VertexArray::VertexArray()
{
	GLCALL(glGenVertexArrays(1, &ID));
}

VertexArray::~VertexArray()
{
	GLCALL(glDeleteVertexArrays(1, &ID));
}

void VertexArray::AddBuffer(const Vertex& VB, const VLayout& Layout)
{
	Bind();
	VB.Bind();
	const auto& Elemnt = Layout.GetElements();
	unsigned int Offset = 0;

	for (unsigned int i = 0; i < Elemnt.size();i++) {
		const auto& Elem = Elemnt[i];
		GLCALL(glEnableVertexAttribArray(i));
		GLCALL(glVertexAttribPointer(
			i, Elem.Cnt, Elem.Type, Elem.Normalized, Layout.GetStride(), (const void*)Offset));
		Offset += Elem.Cnt * VElements::GetSizeOfType(Elem.Type);
	}
}

void VertexArray::Bind() const
{
	GLCALL(glBindVertexArray(ID));
}

void VertexArray::Unbind() const
{
	GLCALL(glBindVertexArray(0));
}
