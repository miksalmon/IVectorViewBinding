#if WINDOWS_UWP
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using WinRtComponent;
#else
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System;
using WinRtComponent;
#endif

namespace IVectorViewBinding;

public sealed partial class MainPage : Page
{
    // Defining this as MyItemCollection instead of IMyItemCollection fixes the binding issue
    public IMyItemCollection MyCollection { get; } = new MyItemCollection();

    public MainPage()
    {
        this.InitializeComponent();
    }
}
