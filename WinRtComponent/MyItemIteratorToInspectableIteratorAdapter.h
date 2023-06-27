#pragma once

#include "MyItemIteratorToInspectableIteratorAdapter.g.h"

namespace winrt::WinRtComponent::implementation
{
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::Foundation::Collections;

    //
    // Adapter between IIterator<IMyItem> and IIterator<IInspectable>
    //
    struct MyItemIteratorToInspectableIteratorAdapter : MyItemIteratorToInspectableIteratorAdapterT<MyItemIteratorToInspectableIteratorAdapter>
    {
        MyItemIteratorToInspectableIteratorAdapter(IIterator<WinRtComponent::IMyItem> source);

        // IIterator methods
        IInspectable Current() const;
        bool HasCurrent() const;
        bool MoveNext();
        uint32_t GetMany(array_view<IInspectable> values);

    private:
        IIterator<WinRtComponent::IMyItem> m_source;
    };
}

namespace winrt::WinRtComponent::factory_implementation
{
    struct MyItemIteratorToInspectableIteratorAdapter : MyItemIteratorToInspectableIteratorAdapterT<MyItemIteratorToInspectableIteratorAdapter, implementation::MyItemIteratorToInspectableIteratorAdapter>
    {
    };
}
