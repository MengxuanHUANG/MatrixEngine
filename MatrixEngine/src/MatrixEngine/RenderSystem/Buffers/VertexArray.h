#pragma once

#include "Buffer.h"

namespace MatrixEngine
{
	class VertexArray
	{
	public:
		~VertexArray() {}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
		
		virtual void AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) = 0;
		virtual void AddIndexBuffer(const Ref<IndexBuffer>& indexBuffer) = 0;
		
		virtual const std::vector<Ref<VertexBuffer> >& GetVertexBuffer() const = 0;
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const = 0;

		static Ref<VertexArray> Create();
	};
}