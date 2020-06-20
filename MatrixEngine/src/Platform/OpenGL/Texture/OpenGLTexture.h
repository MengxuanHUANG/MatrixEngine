#pragma once

#include "MatrixEngine/RenderSystem/Texture/Texture.h"

namespace MatrixEngine
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(const std::string& path);
		OpenGLTexture2D(uint32_t width, uint32_t height);
		~OpenGLTexture2D();

		virtual uint32_t GetWidth() const override { return m_Width; }
		virtual uint32_t GetHeight() const override { return m_Height; }
		virtual std::string GetPath() const override { return m_Path; }

		virtual bool IsDataLoad() const override;

		virtual void SetData(void* data, uint32_t size) override;

		virtual void Bind(uint32_t slot = 0)const override;

	private:
		uint32_t m_Width, m_Height;
		uint32_t m_RendererID;
		std::string m_Path;
		GLenum m_InternalFormat, m_DataFormat;
		bool m_DataLoadSuccess;
	};
}