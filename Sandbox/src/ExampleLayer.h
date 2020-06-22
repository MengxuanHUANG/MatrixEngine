#pragma once
#include<MatrixEngine.h>

class ExampleLayer : public MatrixEngine::Layer
{
public:
	ExampleLayer();
	~ExampleLayer() = default;
	void OnAttach() override;
	void OnDetach() override;
	void OnUpdate(MatrixEngine::Timestep timestep) override;
	void OnImGuiRender(float timestep) override;
	void OnEvent(MatrixEngine::Event& event) override;
	bool OnKeyPressedEvent(MatrixEngine::KeyPressedEvent& event);

private:
	MatrixEngine::OrthographicCameraController m_CameraController;
	MatrixEngine::Ref<MatrixEngine::VertexArray> m_VertexArray;
	MatrixEngine::Ref<MatrixEngine::Shader> m_Shader;

	MatrixEngine::Ref<MatrixEngine::Texture2D> m_Texture;
	MatrixEngine::Ref<MatrixEngine::Texture2D> m_Texture_2;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	
	glm::vec3 m_SquarePosition = { 0.0f, 0.0f, 0.0f };
	glm::vec3 m_SquareSize = { 1.0f, 1.0f, 1.0f };
	glm::vec3 m_Rotation = { 0.0f, 0.0f, 0.0f };

	glm::vec3 m_CameraRotation = { 0.0f, 0.0f, 0.0f };
	glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };

	std::string m_FPS;
	unsigned int m_Count = 0;

	struct ProfileResult
	{
		const char* Name;
		float Time;
	};

	std::vector<ProfileResult> m_ProfileResults;
	char m_NextFilepath[100];
};