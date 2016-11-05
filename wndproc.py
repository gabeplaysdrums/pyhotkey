import ctypes
import wx

from ctypes import c_long, c_int

# grab the functions we need - unicode/not doesn't really matter
# for this demo
SetWindowLong = ctypes.windll.user32.SetWindowLongW
CallWindowProc = ctypes.windll.user32.CallWindowProcW


# a function type for the wndprc so ctypes can wrap it
WndProcType = ctypes.WINFUNCTYPE(c_int, c_long, c_int, c_int, c_int)

# constants
GWL_WNDPROC = -4

class TestFrame(wx.Frame):
    def __init__(self, parent):
        wx.Frame.__init__(self, parent)
        # need to hold a reference to WINFUNCTYPE wrappers,
        # so they don't get GCed
        self.newWndProc = WndProcType(self.MyWndProc)
        self.oldWndProc = SetWindowLong(
            self.GetHandle(),
            GWL_WNDPROC,
            self.newWndProc
        )
        
    
    def MyWndProc(self, hWnd, msg, wParam, lParam):
        print(msg,wParam,lParam)
        return CallWindowProc(
            self.oldWndProc,
            hWnd,
            msg,
            wParam,
            lParam
        )
        
app =wx.App(False)
f = TestFrame(None)
f.Show()
app.MainLoop()