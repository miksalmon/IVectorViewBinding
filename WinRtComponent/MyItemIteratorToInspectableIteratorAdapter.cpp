#include "pch.h"
#include "MyItemIteratorToInspectableIteratorAdapter.h"
#if __has_include("MyItemIteratorToInspectableIteratorAdapter.g.cpp")
#include "MyItemIteratorToInspectableIteratorAdapter.g.cpp"
#endif

namespace winrt::WinRtComponent::implementation
{
    MyItemIteratorToInspectableIteratorAdapter::MyItemIteratorToInspectableIteratorAdapter(IIterator<WinRtComponent::IMyItem> source)
        : m_source(source)
    {
    }

    IInspectable MyItemIteratorToInspectableIteratorAdapter::Current() const
    {
        return m_source.Current();
    }

    bool MyItemIteratorToInspectableIteratorAdapter::HasCurrent() const
    {
        return m_source.HasCurrent();
    }

    bool MyItemIteratorToInspectableIteratorAdapter::MoveNext()
    {
        return m_source.MoveNext();
    }

    uint32_t MyItemIteratorToInspectableIteratorAdapter::GetMany(array_view<IInspectable> values)
    {
        auto myItems = std::vector<WinRtComponent::IMyItem>(values.size());

        auto count = m_source.GetMany(myItems);

        for (uint32_t i = 0; i < count; ++i)
        {
            values[i] = myItems[i];
        }

        return count;
    }
}
