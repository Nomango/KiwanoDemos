// Copyright (C) 2019 Nomango

#include "MainStage.h"

using namespace kiwano;

class ImGuiApp
	: public Application
{
public:
	ImGuiApp()
	{
		// 添加 ImGui 组件
		Use(&ImGuiModule::Instance());

		// 创建窗口
		Window::Instance().Create(L"ImGui Demo", 1280, 800);
	}

	void OnReady() override
	{
		ImGuiStagePtr scene = new ImGuiStage;
		Director::Instance().EnterStage(scene);
	}
};

int WINAPI wWinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PWSTR, _In_ int)
{
	try
	{
		ImGuiApp app;
		app.Run();
	}
	catch (std::exception& e)
	{
		::MessageBoxA(nullptr, e.what(), "An exception has occurred!", MB_ICONERROR | MB_OK);
	}
	return 0;
}
