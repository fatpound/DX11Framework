/*            */
//  fatpound* //
/*            */

#include <_macros/Namespaces.hxx>
#include <Win32_/FatWin.hpp>

import FatPound;
import std;

int APIENTRY wWinMain(
    [[maybe_unused]] _In_     HINSTANCE hInst,
    [[maybe_unused]] _In_opt_ HINSTANCE hPrevInst,
    [[maybe_unused]] _In_     LPWSTR    lpCmdLine,
    [[maybe_unused]] _In_     int       nShowCmd)
{
    try
    {
        return 0;
    }
    catch (const std::exception& ex)
    {
        MessageBox(nullptr, FATSPACE_UTILITY::To_WString(ex.what()).c_str(), L"Error!", MB_OK bitor MB_ICONERROR);
    }
    catch (...)
    {
        MessageBox(nullptr, L"Non-STD Exception was thrown!", L"Error...", MB_OK bitor MB_ICONERROR);
    }

    return -1;
}