#include "ExampleLayer.h"

#include "imgui/imgui.h"
#include<glm/gtc/matrix_transform.hpp>

#include<glm/gtc/type_ptr.hpp>

ExampleLayer::ExampleLayer()
	:Layer("Sandbox2D"), m_CameraController((2048.0f / 1080.0f), true), m_NextFilepath("assets/textures/test_texture.png")
{
}

void ExampleLayer::OnAttach()
{
	m_Texture = MatrixEngine::Texture2D::Create("assets/textures/Checkerboard.png");
}

void ExampleLayer::OnDetach()
{

}

void ExampleLayer::OnUpdate(MatrixEngine::Timestep timestep)
{
	if (!m_Texture_2)
	{
		m_Texture_2 = MatrixEngine::Texture2D::Create(m_NextFilepath);
	}
	else
	{
		std::string nextPath = m_NextFilepath;
		std::string path = m_Texture_2->GetPath();
		const char* currentFilepath = path.c_str();
		if (nextPath != m_Texture_2->GetPath())
		{
			m_Texture_2 = MatrixEngine::Texture2D::Create(nextPath);
		}
	}
	//Updata Camera

	m_CameraController.OnUpdata(timestep);

	//Set BackGround Color
	MatrixEngine::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	MatrixEngine::RenderCommand::Clear();

	//Start a new Scene
	MatrixEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());

	MatrixEngine::Renderer2D::DrawQuad({ 0.0f, 0.0f }, { m_SquareSize.x, m_SquareSize.y }, m_Rotation, m_Texture_2);
	//MatrixEngine::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
	MatrixEngine::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 5.0f, 5.0f }, 0.0f, m_Texture, 10.0f);

	//End the Scene
	MatrixEngine::Renderer2D::EndScene();

}

void ExampleLayer::OnImGuiRender(float timestep)
{
	ImGui::Begin("Settings");
	ImGui::SetWindowFontScale(2.0f);
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));



	for (auto& result : m_ProfileResults)
	{
		char label[50];
		strcpy(label, result.Name);
		strcat(label, "  %.3fms");
		ImGui::Text(label, result.Time);
	}
	m_ProfileResults.clear();

	if ((m_Count++) % 10);
	else
	{
		std::stringstream ss;
		ss << "fps: " << 1.0f / timestep;
		m_FPS = ss.str();
		m_Count = 1;
	}

	ImGui::Text(m_FPS.c_str());
	ImGui::End();

	ImGui::Begin("Image");
	ImGui::SetWindowFontScale(2.0f);

	ImGui::InputText("URL", m_NextFilepath, 100);
	ImGui::InputFloat("Size-X", &m_SquareSize.x, 0.1f);
	ImGui::InputFloat("Size-Y", &m_SquareSize.y, 0.1f);
	ImGui::InputFloat("Rotation", &m_Rotation, 1.0f);

	ImGui::End();
}

void ExampleLayer::OnEvent(MatrixEngine::Event& event)
{
	m_CameraController.OnEvent(event);
}