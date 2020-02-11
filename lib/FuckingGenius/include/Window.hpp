#ifndef DEF_WINDOW
#define DEF_WINDOW

#include "Types/TypeStyle.hpp"
#include "Types/KeyTypes.hpp"
#include "FGExcept.hpp"

#if defined(LINUX)
	#include <X11/Xlib.h>
#endif

#define None NULL

typedef unsigned int uint;

#if defined(WINDOWS)
	typedef HWND FGWin;
	typedef HINSTANCE FGHandler;
	typedef LPCTSTR FGTitle;
	/*struct GuiInfo
	{
		HINSTANCE window;
	};*/
#elif defined(LINUX)
	typedef Window FGWin;
	typedef unsigned char FGHandler;
	typedef char const* FGTitle;
	/*struct GuiInfo
	{
		int window;
	};*/
#endif

class FGWindow
{
	public:
		// Third argument, "FGWin& win", is useless as fuck, now
		// ... I guess
		FGWindow(int style, FGTitle winName = "");
		FGWindow(FGWindow const& src);
		~FGWindow();
		
		inline uint getWindowCount() const { return m_windowCount; }
		
		#if defined(WINDOWS)
			inline MSG getMessage() const { return m_message; }
		#elif defined(LINUX)
			inline bool getMessage() const { return true; }
		#endif
		
		void showThisFuckingWindow();
		void updateWindow();
	
	private:
		FGTitle m_winName;
		FGHandler/*&*/ m_handler;
		FGWin/*&*/ m_mainWindow;
		int m_style;
		#if defined(WINDOWS)
			HWND m_window;
			MSG m_message;
			WNDCLASS m_winClass;
		#elif defined(LINUX)
			Display*  m_displayer;
			int m_screen;
		#endif
		static uint m_windowCount;
};

#endif // DEF_WINDOW
