#include "engine_control\engine_control.h"

static pw::st::Actor* m_thing = nullptr;
static pw::st::Actor* m_thing2 = nullptr;

/*static std::vector<std::tuple<pw::st::Actor*, glm::vec2>> models;

static glm::vec2 velocity = glm::vec2(1.0f, 1.0f);

void pw::co::Engine_Control::Pre_Load() {
	pw::cm::Engine_Constant::Set_FPS_Info(1000, true);

	for (int i = 0; i < 200; i++) {
		pw::st::Model* square_model = pw::Engine_Memory::Allocate<pw::st::Model, bool>((pw::st::Geometry_Types)((rand() % 5 + 1)),
			pw::co::File_Loader::Load_Texture_File(L"White.png", false, false, true),
			glm::vec2(pw::cm::Engine_Constant::Hafe_Window_Width(),
				pw::cm::Engine_Constant::Hafe_Window_Height()),
			0.0f, glm::vec2((rand() % 5 + 32), (rand() % 5 + 32)),
			glm::vec4(((rand() % 255 + 1) / 255.0f), ((rand() % 255 + 1) / 255.0f), ((rand() % 255 + 1) / 255.0f), 1.0f));

		models.push_back(std::make_tuple(pw::Engine_Memory::Allocate<pw::st::Actor, bool>(square_model),
			glm::vec2(((rand() % 20 + 1)), ((rand() % 20 + 1)))));
	}
}			*/	
void pw::co::Engine_Control::Pre_Load() {
	
}
void pw::co::Engine_Control::Initialize_Game() {
}																				
void pw::co::Engine_Control::Before_Queue() {
	
}	
/*
void pw::co::Engine_Control::After_Queue() {
	for (auto i = models.begin(); i != models.end(); i++) {
		if (std::get<0>(*i)->Model()->Position().x + std::get<0>(*i)->Model()->Size().x >= pw::cm::Engine_Constant::Window_Width()) {
			std::get<1>(*i).x = -std::get<1>(*i).x;
		}
		if (std::get<0>(*i)->Model()->Position().x <= 0) {
			std::get<1>(*i).x = -std::get<1>(*i).x;
		}
		if (std::get<0>(*i)->Model()->Position().y >= pw::cm::Engine_Constant::Window_Height()) {
			std::get<1>(*i).y = -std::get<1>(*i).y;
		}
		if (std::get<0>(*i)->Model()->Position().y - std::get<0>(*i)->Model()->Size().y <= 0) {
			std::get<1>(*i).y = -std::get<1>(*i).y;
		}
		std::get<0>(*i)->Model()->Set_Position(glm::vec2(std::get<0>(*i)->Model()->Position().x + std::get<1>(*i).x,
			std::get<0>(*i)->Model()->Position().y + std::get<1>(*i).y));
	}

	
	

	for (auto i = models.begin(); i != models.end(); i++) {
		std::get<0>(*i)->Render();
	}
}				
*/
void pw::co::Engine_Control::After_Queue() {

}
void pw::co::Engine_Control::Release_Game() {

}																				
void pw::co::Engine_Control::Pre_Scene_Load(const std::wstring& p_scene) {

}																				
void pw::co::Engine_Control::Pre_Scene_Change(const std::wstring& p_scene) {

}																				
void pw::co::Engine_Control::Pre_Scene_Removal(const std::wstring& p_scene) {

}																				
void pw::co::Engine_Control::Post_Scene_Load(const std::wstring& p_scene) {

}																				
void pw::co::Engine_Control::Post_Scene_Change(const std::wstring& p_scene) {

}																				
void pw::co::Engine_Control::Post_Scene_Removal(const std::wstring& p_scene) {
	
}





USE_PISTONWORKS_ENGINE(800, 600, true);