module;

#include <_macros/Namespaces.hxx>

export module dxfw.App;

import FatPound;
import std;

export namespace dxfw
{
    class App final
    {
        using WndClassEx = FATSPACE_WIN32::IWindow::ClassEx;

    public:
        explicit App(const std::wstring& filename);
        explicit App(const std::string&  filename);

        explicit App();
        explicit App(const App&)     = delete;
        explicit App(App&&) noexcept = delete;

        auto operator = (const App&)     -> App& = delete;
        auto operator = (App&&) noexcept -> App& = delete;
        ~App() noexcept                          = default;


    public:
        void Run();


    protected:


    private:
        void DoFrame_() noexcept;

        
    private:
        inline static std::size_t s_game_id_{};


    private:
        std::unique_ptr<FATSPACE_UTILITY::Surface> m_pSurface_;

        FATSPACE_WIN32::WindowEx m_wnd_;
        FATSPACE_D3D11::Graphics<true> m_gfx_;

        FATSPACE_UTILITY::Timer m_timer_;
    };
}