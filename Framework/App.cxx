module;

#include <_macros/Namespaces.hxx>

#define SCREEN_WIDTH    800U
#define SCREEN_HEIGHT   600U

module dxfw.App;

using FATSPACE_UTILITY::Surface;
using FATSPACE_UTILITY::SizePack;

namespace dxfw
{
    App::App(const std::wstring& filename)
        :
        m_pSurface_(std::make_unique<Surface>(filename)),
        m_wnd_(std::make_shared<WndClassEx>(L"fat->pound WindowClassEx: " + std::to_wstring(s_game_id_++)), L"FatPound DirectX11 Framework " + std::to_wstring(s_game_id_), m_pSurface_->GetSizePack()),
        m_gfx_(m_wnd_.GetHandle(), std::move(m_pSurface_), L"VSFrameBuffer.cso", L"PSFrameBuffer.cso")
    {

    }
    App::App(const std::string& filename)
        :
        App(FATSPACE_UTILITY::To_WString(filename))
    {

    }
    App::App()
        :
        m_wnd_(std::make_shared<WndClassEx>(L"fat->pound WindowClassEx: " + std::to_wstring(s_game_id_++)), L"FatPound DirectX11 Framework " + std::to_wstring(s_game_id_), SizePack{ SCREEN_WIDTH, SCREEN_HEIGHT }),
        m_gfx_(m_wnd_.GetHandle(), SizePack{ SCREEN_WIDTH, SCREEN_HEIGHT }, L"VSFrameBuffer.cso", L"PSFrameBuffer.cso")
    {
        
    }


    void App::Run()
    {
        while (not m_wnd_.IsClosing())
        {
            m_gfx_.BeginFrame<>();
            DoFrame_();
            m_gfx_.EndFrame<>();
        }
    }
    void App::DoFrame_() noexcept
    {
        // m_timer_.Start();

        m_gfx_.CopySurfaceToSysbuffer();

        // m_timer_.Stop();
    }
}