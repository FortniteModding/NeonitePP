#include "../framework.h"
#include "../mods.h"
#include "../console.h"
#include "ImGui/imgui.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

typedef HRESULT (__stdcall* Present)(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT (CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

Present oPresent;
HWND window = nullptr;
WNDPROC oWndProc;
ID3D11Device* pDevice = nullptr;
ID3D11DeviceContext* pContext = nullptr;
ID3D11RenderTargetView* mainRenderTargetView;

using namespace ImGui;
using namespace NeoRoyale;

void InitImGui()
{
	CreateContext();
	ImGuiIO& io = GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_KEYUP && (wParam == 0x2D /*INSERT*/ || wParam == VK_F5 || (showMenu && wParam == VK_ESCAPE)))
	{
		showMenu = !showMenu;
		GetIO().MouseDrawCursor = showMenu;
	}
	else if (uMsg == WM_QUIT && showMenu)
	{
		//ExitProcess(0);
	}
	
	else if (GetAsyncKeyState(VK_F9)) //When button F9 is pressed
	{
		NeoPlayer.UpdatePlayerController();

	}
	else if (GetAsyncKeyState(VK_F10)) //When button F9 is pressed
	{
		NeoPlayer.Possess();
		NeoPlayer.UpdatePlayerController();

	}
	
	else if (GetAsyncKeyState(VK_F8)) //When button F8 is pressed
	{
		enum class EAthenaCustomizationCategory : uint8_t
		{
			None = 0, Glider = 1, Pickaxe = 2, Hat = 3, Backpack = 4, Character = 5, LoadingScreen = 6, BattleBus = 7, VehicleDecoration = 8, CallingCard = 9, MapMarker = 10, Dance = 11, ConsumableEmote = 12, VictoryPose = 13, SkyDiveContrail = 14, MusicPack = 15, ItemWrap = 16, PetSkin = 17, Charm = 18, RegCosmeticDef = 19, Loadout = 20, SaveLoadout = 21, MAX = 22
		};

		auto button = UE4::FindObject<UObject*>(L"AthenaCustomizationSlotButton_C /Engine/Transient.FortEngine_", false, false, 18);
		auto button1 = UE4::FindObject<UObject*>(L"AthenaCustomizationSlotButton_C /Engine/Transient.FortEngine_", false, false, 19);

		auto CustomizationType = (EAthenaCustomizationCategory*)(__int64(button) + 0xc50);
		auto CustomizationType1 = (EAthenaCustomizationCategory*)(__int64(button1) + 0xc50);


		*CustomizationType = EAthenaCustomizationCategory::VictoryPose;
		*CustomizationType1 = EAthenaCustomizationCategory::BattleBus;
	}
	
	if (showMenu)
	{
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		return TRUE;
	}

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

bool initgui = false;

static bool bIsHead;
FileBrowser fileDialog;

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!initgui)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			fileDialog.SetTypeFilters({".png"});
			InitImGui();
			initgui = true;
			Console::ExecuteConsoleCommand(XOR(L"god"));
		}

		else return oPresent(pSwapChain, SyncInterval, Flags);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	NewFrame();

	ImVec4* colors = GetStyle().Colors;
	ImGuiStyle* style = &GetStyle();

	style->WindowTitleAlign = ImVec2(0.5f, 0.5f);
	style->WindowPadding = ImVec2(15, 8);
	style->WindowRounding = 3.0f;
	style->FramePadding = ImVec2(5, 5);
	style->FrameRounding = 4.0f;
	style->ItemSpacing = ImVec2(12, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 9.0f;
	style->GrabMinSize = 5.0f;
	style->GrabRounding = 3.0f;

	colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	colors[ImGuiCol_TitleBg] = ImColor(85, 0, 255);
	colors[ImGuiCol_TitleBgCollapsed] = ImColor(85, 0, 255);
	colors[ImGuiCol_TitleBgActive] = ImColor(85, 0, 255);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(
		0.56f, 0.56f, 0.58f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(
		0.06f, 0.05f, 0.07f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImColor(85, 0, 255);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	colors[ImGuiCol_Separator] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_ResizeGripHovered] =
	ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(
		0.25f, 1.00f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	colors[ImGuiCol_ModalWindowDarkening] = ImVec4(
		1.00f, 0.98f, 0.95f, 0.73f);

	if (showMenu)
	{
		if (Begin(XOR("Neonite++"), nullptr, ImGuiWindowFlags_NoCollapse))
		{
			PushItemWidth(GetFontSize() * -12);

			if (BeginTabBar(XOR("Neonite")), ImGuiTabBarFlags_AutoSelectNewTabs)
			{
				//if (!NeoPlayer.Pawn)
				{
					if (BeginTabItem("World"))
					{
						static char Travel[1024];
						static int timeOfDay = 1;
						static int currentTimeOfDay = 1;

						if (currentTimeOfDay != timeOfDay)
						{
							UFunctions::SetTimeOfDay(timeOfDay);
							currentTimeOfDay = timeOfDay;
						}
						SliderInt(XOR("Time Of Day"), &timeOfDay, 1.000f, 24.000f, "%.01f");

						NewLine();

						SameLine(0.0f, 20.0f);


						NewLine();

						//Puts you back to the lobby, get destroyed kid
						if (Button(XOR("Lobby")))
						{
							UFunctions::Travel(FRONTEND);
							bIsStarted = false;
							bIsInit = false;
							NeoPlayer.Controller = nullptr;
							NeoPlayer.Pawn = nullptr;
							NeoPlayer.Mesh = nullptr;
							NeoPlayer.AnimInstance = nullptr;
							Bots.clear();
							gPlaylist = nullptr;
							gNeoniteLogoTexture = nullptr;
						}

						static float X = 1.0f;
						static float Y = 1.0f;
						static float Z = 1.0f;


						BeginChild(XOR("BugItGo"));
						PushItemWidth(60);
						InputFloat("X", &X);

						SameLine(0.0f, 10.0f);

						PushItemWidth(60);
						InputFloat("Y", &Y);

						SameLine(0.0f, 15.0f);

						PushItemWidth(60);
						InputFloat("Z", &Z);

						SameLine(0.0f, 18.0f);

						if (Button(XOR("Teleport")))
						{
							NeoPlayer.TeleportTo(FVector(X, Y, Z));
						}

						/*NewLine();

						if (Button("Fill level with water"))
						{
							//NeoPlayer.Summon(XOR(L"Apollo_Waterbody_Ocean_Parent_C"));
						}

						SameLine();

						if (Button("Remove water"))
						{
							Console::ExecuteConsoleCommand(XOR(L"destroyall Apollo_Waterbody_Ocean_Parent_C"));
						}*/

						EndChild();

						EndTabItem();
					}

					if (BeginTabItem("Character"))
					{
						if (Button("Fly"))
						{
							NeoPlayer.Fly(bIsFlying);
							bIsFlying = !bIsFlying;
						}

						SameLine(0.0f, 20.0f);

						if (Button("Skydive"))
						{
							//??
							NeoPlayer.StartSkydiving(0);
							NeoPlayer.StartSkydiving(0);
							NeoPlayer.StartSkydiving(0);
							NeoPlayer.StartSkydiving(0);
							NeoPlayer.StartSkydiving(2000.0f);
						}

						SameLine(0.0f, 20.0f);

						if (Button("Respawn"))
						{
							NeoPlayer.Respawn();
						}

						SameLine(0.0f, 20.0f);

						if (Button("Possess"))
						{
							NeoPlayer.Possess();
						}

						if (Button("Pick Custom Body Texture"))
						{
							fileDialog.Open();
						}

						SameLine();

						Checkbox(XOR("Head"), &bIsHead);

						NewLine();

						if (Button(XOR("First Person Camera")))
						{
							NeoPlayer.SetCameraMode(L"FirstPerson");
							NeoPlayer.HideHead(true);
						}

						SameLine();

						if (Button(XOR("Third Person Camera")))
						{
							NeoPlayer.SetCameraMode(L"FreeCam");
							NeoPlayer.HideHead(false);
						}

						NewLine();

						static int currentHealth = 100;
						static int currentShield = 100;
						static int currentMaxHealth = 100;
						static int currentMaxShield = 100;
						static float currentSpeed = 1;
						static int currentGravityScale = 1;
						static int currentFov = 80;
						static int health = 100;
						static int shield = 100;
						static int maxHealth = 100;
						static int maxShield = 100;
						static float speed = 1;
						static int gravityScale = 1;
						static int fov = 80;

						if (currentFov != fov)
						{
							std::wstring command(L"fov " + std::to_wstring(fov));
							Console::ExecuteConsoleCommand(command.c_str());
							currentFov = fov;
						}
						SliderInt(XOR("FOV"), &fov, 20, 200, "%.03f");

						NewLine();

						if (currentGravityScale != gravityScale)
						{
							NeoPlayer.SetPawnGravityScale(gravityScale);
							currentGravityScale = gravityScale;
						}
						SliderInt(XOR("Gravity Scale"), &gravityScale, -5, 5, "%.01f");

						NewLine();

						if (currentSpeed != speed)
						{
							NeoPlayer.SetMovementSpeed(speed);
							currentSpeed = speed;
						}
						SliderFloat(XOR("Speed Multiplier"), &speed, 1.0f, 5.0f, "%.1f", 10.000001f);

						NewLine();

						if (currentHealth != health)
						{
							NeoPlayer.SetHealth(health);
							currentHealth = health;
						}
						SliderInt(XOR("Health Percent"), &health, 1, 100, "%.3f");

						NewLine();

						if (currentShield != shield)
						{
							NeoPlayer.SetShield(shield);
							currentShield = shield;
						}
						SliderInt(XOR("Shield Percent"), &shield, 1, 100, "%.3f");

						NewLine();

						if (currentMaxHealth != maxHealth)
						{
							NeoPlayer.SetMaxHealth(maxHealth);
							currentMaxHealth = maxHealth;
						}
						SliderInt(XOR("Max Health"), &maxHealth, 1, 10000000, "%.3f");

						NewLine();

						if (currentMaxShield != maxShield)
						{
							NeoPlayer.SetMaxShield(maxShield);
							currentMaxShield = maxShield;
						}
						SliderInt(XOR("Max Shield"), &maxShield, 1, 10000000, "%.3f");


						EndTabItem();
					}

					if (BeginTabItem("Helpers"))
					{
						static std::wstring currentItem;
						static std::wstring currentBlueprint;
						static std::wstring currentMesh;
						static char command[1024];

						Text(XOR("Any item selected from the combos below will be copied to your clipboard, everything is generated at runtime."));

						NewLine();

						if (BeginCombo("Weapons", std::string(currentItem.begin(), currentItem.end()).c_str()))
						{
							for (auto n = 0; n < gWeapons.size(); n++)
							{
								const bool is_selected = (currentItem == gWeapons[n]);
								const std::string wid(gWeapons[n].begin(), gWeapons[n].end());
								if (Selectable(wid.c_str(), is_selected))
								{
									currentItem = gWeapons[n];
									std::string commandS = "equip " + wid;
									strcpy(command, commandS.c_str());
								}
								if (is_selected)
								{
									SetItemDefaultFocus();
								}
							}
							EndCombo();
						}

						if (BeginCombo("Blueprints", std::string(currentBlueprint.begin(), currentBlueprint.end()).c_str()))
						{
							for (auto n = 0; n < gBlueprints.size(); n++)
							{
								const bool is_selected = (currentBlueprint == gBlueprints[n]);
								const std::string blueprint(gBlueprints[n].begin(), gBlueprints[n].end());
								if (Selectable(blueprint.c_str(), is_selected))
								{
									currentBlueprint = gBlueprints[n];
									std::string commandS = "summon " + blueprint;
									strcpy(command, commandS.c_str());
								}
								if (is_selected)
								{
									SetItemDefaultFocus();
								}
							}
							EndCombo();
						}


						if (BeginCombo("Mesh", std::string(currentMesh.begin(), currentMesh.end()).c_str()))
						{
							for (auto n = 0; n < gMeshes.size(); n++)
							{
								const bool is_selected = (currentMesh == gMeshes[n]);
								const std::string mesh(gMeshes[n].begin(), gMeshes[n].end());
								if (Selectable(mesh.c_str(), is_selected))
								{
									currentMesh = gMeshes[n];
									NeoPlayer.SetSkeletalMesh(gMeshes[n].c_str());
								}
								if (is_selected)
								{
									SetItemDefaultFocus();
								}
							}
							EndCombo();
						}

						NewLine();

						Text(XOR("DICLAIMER: Changing Skeletal Mesh may cause crashes."));

						NewLine();

						InputText(XOR("NeoCommand"), command, sizeof command);

						SameLine();

						if (Button("Execute"))
						{
							std::string commandS(command);
							std::wstring coammndW(commandS.begin(), commandS.end());
							Console::ExecuteConsoleCommand(coammndW.c_str());
						}

						EndTabItem();
					}

					if (BeginTabItem(XOR("Override Skin")))
					{
						SetCursorPosY(GetCursorPosY() + 5);

						Text(XOR("NOTE: Doesn't work after jumping from bus\n(Recommendation: use battlelab)"));

						const char* overrides[] = { "None", "Thanos", "Chituari" };
						static int Item = 0;
						static int currentItem = 0;
						Combo("Skin", &Item, overrides, IM_ARRAYSIZE(overrides));

						if (currentItem != Item)
						{
							std::string OverrideName(overrides[Item]);
							NeoPlayer.SkinOverride = std::wstring(OverrideName.begin(), OverrideName.end());
							currentItem = Item;
						}

						NewLine();

						if (Button("Pick Custom Body Texture"))
						{
							fileDialog.Open();
						}

						SameLine();

						Checkbox(XOR("Head"), &bIsHead);

						EndTabItem();
					}
				}
#ifdef RiftTourGUI
			if (BeginTabItem("Rift Tour"))
			{
				Text("If you want to teleport to the Rift Tour Maps type this in the console");
				NewLine();
				Text("Main Map - streammap Buffet_P");
				Text("Cuddle Map - streammap Buffet_Part5");
				Text("Storm King Map - streammap Buffet_Part_6");
				Text("Stairs Map - streammap Buffet_Escher");
				Text("Positions Map - streammap Buffet_Shard");
				Text("Clouds Map - streammap Buffet_Clouds");

				NewLine();
				Text("Start event sequences");
				if (Button(XOR("Start Main Rift Tour Event")))
				{
					UFunctions::Play(RIFT_TOUR_EVENT_PLAYER);  
				}
				Text("This Sequence can only be started from the Main Rift Tour Map");

				if (Button(XOR("Start Rift Tour Cuddle")))
				{
					UFunctions::Play(RIFT_TOUR_CUDDLE_PLAYER);
				}		
				if (Button(XOR("Start Rift Tour Storm King")))
				{
					UFunctions::Play(RIFT_TOUR_STORMKING_PLAYER);
				}
				if (Button(XOR("Start Rift Tour Clouds")))
				{
					UFunctions::Play(RIFT_TOUR_CLOUDS_PLAYER);
				}
				if (Button(XOR("Start Rift Tour Stairs")))
				{
					UFunctions::Play(RIFT_TOUR_STAIRS_PLAYER);
				}
				if (Button(XOR("Start Rift Tour Positions")))
				{
					UFunctions::Play(RIFT_TOUR_POSITIONS_PLAYER);
				}

				NewLine();
				if (Button(XOR("Fix Camera")))
				{
					NeoPlayer.Possess();
					Console::ExecuteConsoleCommand(XOR(L"camera freecam"));
				}
				EndTabItem();

			}

#endif

#ifdef SkyFireGUI
			if (BeginTabItem("Sky Fire"))
			{

				NewLine();
				Text("Start event sequences");
				if (Button(XOR("Start Sky Fire Event")))
				{
					UFunctions::Play(MOTHERSHIP_EVENT_PLAYER);
				}
				Text("This Sequence can only be started from the Main Sky Fire Map");
				NewLine();
				Text("If you want to teleport to the Sky Fire Maps type this in the console");
				NewLine();
				Text("Main Map - streammap Kiwi_P");
				Text("Space Map - streammap Kiwi_Space");
				Text("Tubes Map - streammap Kiwi_Tubes");
				Text("ObservationHallway Map - streammap Kiwi_ObservationHallway");
				Text("Prison Blocks Map - streammap Kiwi_PrisonBlocks");
				Text("Prison Junction Map - streammap Kiwi_PrisonJunction");
				Text("Hangar Map - streammap Kiwi_Hangar");
				Text("Kevin Room Map - streammap Kiwi_KevinRoom");
				EndTabItem();

			}

#endif

				if (BeginTabItem("Help"))
				{
					SetCursorPosY(GetCursorPosY() + 5);

					Text(
						R"(
Commands
---------------------------
debugcamera - Toggles a custom version of the debug camera.
skydive | skydiving - Puts you in a skydive with deploy at 1500m above the ground.
cheatscript <WID | AGID> - Equips a weapon / pickaxe. (You can get them from the modifers tab)
setgravity <NewGravityScaleFloat> - Changes the gravity scale.
speed | setspeed <NewCharacterSpeedMultiplier> - Changes the movement speed multiplier.
setplaylist <Playlist> - Overrides the current playlist.
respawn - Respawns the player (duh)
sethealth <NewHealthFloat> - Changes your health value.
setshield <NewShieldFloat> - Changes your shield value.
setmaxhealth <NewMaxHealthFloat> - Changes your max health value.
setmaxshield <newMaxShieldFloat> - Changes your max shield value.
dump - Dumps a list of all GObjects. (output at win64 folder)
dumpbps - Dumps a list all blueprints. (output at win64 folder)
fly - Toggles flying.
enablecheats - Enables cheatmanager.
summon <BlueprintClass> - Summons a blueprint class. (You can get them from the helpers tap)
---------------------------
F3 - Back to lobby.
` (backquote key) - Open UE4 console.
<> - Argument (e.g: <NewHealthFloat> is replaced with 1.0).
| - Or.
)");


					EndTabItem();
				}


				if (BeginTabItem(XOR("About")))
				{
					SetCursorPosX(GetCursorPosX() + 50);
					SetCursorPosY(GetCursorPosY() + 5);

					Text(XOR("Kemo (@xkem0x): Creator of Neonite++"));

					SetCursorPosX(GetCursorPosX() + 50);
					SetCursorPosY(GetCursorPosY() + 5);

					Text(XOR("Sizzy: Reviving NPP"));

					SetCursorPosX(GetCursorPosX() + 50);
					SetCursorPosY(GetCursorPosY() + 5);

					Text(XOR("PeQu: General, Event related stuff, bug fixes"));

					SetCursorPosX(GetCursorPosX() + 50);
					SetCursorPosY(GetCursorPosY() + 5);

					Text(XOR("Timmy (@mawmet): General, Creator of Carbon, bug fixes"));

					SetCursorPosX(GetCursorPosX() + 50);
					SetCursorPosY(GetCursorPosY() + 5);

					EndTabItem();
				}

				if (ProdMode)
				{
					if (BeginTabItem(XOR("Prod")))
					{
						if (Button("test"))
						{
							UE4::DumpGObjects();
						}

						if (Button("Hack"))
						{
						}

						EndTabItem();
					}
				}
			}
			End();

			fileDialog.Display();

			if (fileDialog.HasSelected())
			{
				
				fileDialog.ClearSelected();
				fileDialog.Close();
			}
		}
	}

	Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, nullptr);
	ImGui_ImplDX11_RenderDrawData(GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}
