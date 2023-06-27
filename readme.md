# IVectorViewBinding Readme

This is a repro app showcasing a binding failure using the Community Toolkit's Ancestor attached property to bind a WinRT component. 

Notes:
- This is a regression from UWP where this type of binding worked correctly. 
- Binding to the same type in a less complex scenario using **TemplateBinding** works correctly.
- Changing the defining type of the data source to the concrete type instead of the interface seems to solve the binding issue. See comment in MainPage.xaml.cs.

### Repro steps

1. Change project to x64
2. Run IVectorViewBinding.WinAppSDK in Debug
3. See there are binding errors in output or in XAML Binding Failures window in VS

The binding that fails is the one in /Themes/Generic.xaml line 56. The source data is in MainPage.xaml.cs line 17.