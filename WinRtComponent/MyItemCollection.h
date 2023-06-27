#pragma once

#include "MyItem.g.h"
#include "MyItemCollection.g.h"

namespace winrt::WinRtComponent::implementation
{
    struct MyItem : MyItemT<MyItem>
    {
        MyItem();

        winrt::hstring Name() { return m_name; }
        void Name(winrt::hstring const& val) { m_name = val; }

        // INotifyPropertyChanged interface
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler) {
            return m_propertyChanged.add(handler);
        }
        void PropertyChanged(winrt::event_token const& token) {
            m_propertyChanged.remove(token);
        }

    private:
        winrt::hstring m_name{ L"" };
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };

    struct MyItemCollection : MyItemCollectionT<MyItemCollection>, 
        winrt::vector_base<MyItemCollection, winrt::WinRtComponent::IMyItem>
    {
        MyItemCollection() = default;
        
        // For IVectorView<IInspectable> compatibility
        uint32_t GetMany(uint32_t startIndex, winrt::array_view<IInspectable> items);
        int32_t IndexOf(WinRtComponent::IMyItem const& value);
        bool IndexOf(IInspectable const& value, uint32_t& index);
        Windows::Foundation::Collections::IIterator<Windows::Foundation::IInspectable> First();

        auto& get_container() const noexcept
        {
            return m_items;
        }

        auto& get_container() noexcept
        {
            return m_items;
        }

        winrt::event_token CollectionChanged(winrt::Microsoft::UI::Xaml::Interop::NotifyCollectionChangedEventHandler const& handler) { return m_collectionChanged.add(handler); }
        void CollectionChanged(winrt::event_token const& token) { m_collectionChanged.remove(token); }

    private:
        void OnCollectionChanged(
            winrt::Microsoft::UI::Xaml::Interop::NotifyCollectionChangedAction const& action, 
            winrt::Windows::Foundation::IInspectable const& oldItem, 
            winrt::Windows::Foundation::IInspectable const& newItem,
            int32_t const oldIndex, int32_t 
            const newIndex);

        std::vector<winrt::WinRtComponent::IMyItem> m_items;
        winrt::event<winrt::Microsoft::UI::Xaml::Interop::NotifyCollectionChangedEventHandler> m_collectionChanged;
    };
}

namespace winrt::WinRtComponent::factory_implementation
{
    struct MyItem : MyItemT<MyItem, implementation::MyItem>
    {
    };

    struct MyItemCollection : MyItemCollectionT<MyItemCollection, implementation::MyItemCollection>
    {
    };
}

