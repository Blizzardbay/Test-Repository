#include "engine_control\engine_control.h"

static pw::st::Actor* m_thing = nullptr;
static pw::st::Actor* m_thing2 = nullptr;

static std::vector<pw::st::Actor*> models;

static glm::vec2 velocity = glm::vec2(1.0f, 1.0f);

static pw::st::Actor* v_backaround = nullptr;

static constexpr int v_total_models = 800;
static constexpr int v_reset_chance = 30;
static float v_low_speed = 0.5f;
static float v_high_speed = 1.0f;
//#define OLD 

float loops = 16.0f;
static bool forward = true;
static pw::cm::Engine_Timer f(1000, false, true);

void pw::co::Engine_Control::Pre_Load() {
	pw::cm::Engine_Constant::Set_FPS_Info(1000, true);

	pw::st::Model* square_model;

	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;
	float a = 0.0f;

	const float step = loops / v_total_models;

	for (int i = 0; i < v_total_models; i++) {
		square_model = pw::Engine_Memory::Allocate<pw::st::Model, bool>((pw::st::Geometry_Types)(5),
			pw::co::File_Loader::Load_Texture_File(L"White.png", false, false, true),
			glm::vec2(0.f,
				0.f),
			0.0f, glm::vec2(1.f,1.f),
			glm::vec4(1.f, 1.f, 1.f, 1.f));

		models.push_back(pw::Engine_Memory::Allocate<pw::st::Actor, bool>(square_model));
	}
}			
//void pw::co::Engine_Control::Pre_Load() {
	
//}
void pw::co::Engine_Control::Initialize_Game() {
}																				
void pw::co::Engine_Control::Before_Queue() {
	
}	

void pw::co::Engine_Control::After_Queue() {
	/*
	for (auto i = models.begin(); i != models.end(); i++) {
		if (std::get<0>(*i)->Model()->Position().x + std::get<0>(*i)->Model()->Size().x >= pw::cm::Engine_Constant::Window_Width() + 100) {
			std::get<1>(*i).x = -std::get<1>(*i).x * (std::get<2>(*i) == true ? v_high_speed : v_low_speed);
			std::get<2>(*i) == true ? std::get<2>(*i) = false : std::get<2>(*i) = true;
#ifndef OLD
			if (std::rand() % v_reset_chance + 1 == 1) {
				std::get<0>(*i)->Model()->Set_Position(glm::vec2(pw::cm::Engine_Constant::Hafe_Window_Width(),
					pw::cm::Engine_Constant::Hafe_Window_Height()));
			}
#endif
		}
		else {
			if (std::get<0>(*i)->Model()->Position().x <= -100) {
				std::get<1>(*i).x = -std::get<1>(*i).x * (std::get<2>(*i) == true ? v_high_speed : v_low_speed);
				std::get<2>(*i) == true ? std::get<2>(*i) = false : std::get<2>(*i) = true;
#ifndef OLD
				if (std::rand() % v_reset_chance + 1 == 1) {
					std::get<0>(*i)->Model()->Set_Position(glm::vec2(pw::cm::Engine_Constant::Hafe_Window_Width(),
						pw::cm::Engine_Constant::Hafe_Window_Height()));
				}
#endif
			}
		}
		if (std::get<0>(*i)->Model()->Position().y >= pw::cm::Engine_Constant::Window_Height() + 100) {
			std::get<1>(*i).y = -std::get<1>(*i).y * (std::get<2>(*i) == true ? v_high_speed : v_low_speed);
			std::get<2>(*i) == true ? std::get<2>(*i) = false : std::get<2>(*i) = true;
#ifndef OLD
			if (std::rand() % v_reset_chance + 1 == 1) {
				std::get<0>(*i)->Model()->Set_Position(glm::vec2(pw::cm::Engine_Constant::Hafe_Window_Width(),
					pw::cm::Engine_Constant::Hafe_Window_Height()));
			}
#endif
		}
		else {
			if (std::get<0>(*i)->Model()->Position().y - std::get<0>(*i)->Model()->Size().y <= -100) {
				std::get<1>(*i).y = -std::get<1>(*i).y * (std::get<2>(*i) == true ? v_high_speed : v_low_speed);
				std::get<2>(*i) == true ? std::get<2>(*i) = false : std::get<2>(*i) = true;
#ifndef OLD
				if (std::rand() % v_reset_chance + 1 == 1) {
					std::get<0>(*i)->Model()->Set_Position(glm::vec2(pw::cm::Engine_Constant::Hafe_Window_Width(),
						pw::cm::Engine_Constant::Hafe_Window_Height()));
				}
#endif
			}
		}
#ifndef OLD
		if (std::rand() % (int)(glm::pow(v_reset_chance, 7)) + 1 == 1) {
			std::get<0>(*i)->Model()->Set_Position(glm::vec2(pw::cm::Engine_Constant::Hafe_Window_Width(),
				pw::cm::Engine_Constant::Hafe_Window_Height()));
		}
#endif
#ifdef OLD
		if (std::rand() % v_reset_chance + 1 == 1) {
			std::get<0>(*i)->Model()->Set_Position(glm::vec2(pw::cm::Engine_Constant::Hafe_Window_Width(),
				pw::cm::Engine_Constant::Hafe_Window_Height()));
		}
#endif
		std::get<0>(*i)->Model()->Set_Position(glm::vec2(std::get<0>(*i)->Model()->Position().x + std::get<1>(*i).x,
			std::get<0>(*i)->Model()->Position().y + std::get<1>(*i).y));

		if (std::get<0>(*i)->Model()->Rotation() < 361.0f) {
			std::get<0>(*i)->Model()->Set_Rotation(std::get<0>(*i)->Model()->Rotation() + (std::rand() % 3 + 1));
		}
		else {
			std::get<0>(*i)->Model()->Set_Rotation(0.0f);
		}
	}

	v_backaround->Render();
	*/

	const float step = loops / v_total_models;

	for (auto i = models.begin(); i != models.end(); i++) {
		(*i)->Render();
	}

	for (int i = 0; i < v_total_models; i++) {
		models.at(i)->Model()->Set_Position(glm::vec2((glm::clamp<float>(step * i, 0.f, loops) / loops) * pw::cm::Engine_Constant::Window_Width() - 0.5,
			(((tan(step * i * glm::pi<float>()) + 1) / 2.0f) * pw::cm::Engine_Constant::Window_Height() + 0.5)));
	}
	if (loops >= 32) {
		forward = false;
	}
	if (loops <= pow(2, -5)) {
		forward = true;
	}
	if (pw::cm::Engine_Constant::FPS_Average() != 0.f) {
		float g = 1.f / pw::cm::Engine_Constant::FPS_Average();
		if (forward) {
			loops += g;
		}
		else {
			loops -= g;
		}
	}
	
	
}				

//void pw::co::Engine_Control::After_Queue() {

//}
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





USE_PISTONWORKS_ENGINE(1080, 720, false);