#include "pch.h"

#include "MyItemCollection.h"
#include "MyItem.g.cpp"
#include "MyItemCollection.g.cpp"

namespace winrt::WinRtComponent::implementation
{
	// MyItem
	MyItem::MyItem()
	{
	}

	// MyItemCollection

	uint32_t MyItemCollection::GetMany(uint32_t startIndex, winrt::array_view<IInspectable> items)
	{
		auto maxOutputItems = std::max(0U, Size() - startIndex);

		auto myItems = std::vector<WinRtComponent::IMyItem>(maxOutputItems);

		auto count = vector_base<MyItemCollection, WinRtComponent::IMyItem>::GetMany(startIndex, myItems);

		for (uint32_t i = 0; i < count; ++i)
		{
			items[i] = myItems[i];
		}

		return count;
	}

	Windows::Foundation::Collections::IIterator<Windows::Foundation::IInspectable> MyItemCollection::First()
	{
		return MyItemIteratorToInspectableIteratorAdapter(vector_base<MyItemCollection, WinRtComponent::IMyItem>::First());
	}

	int32_t MyItemCollection::IndexOf(WinRtComponent::IMyItem const& value)
	{
		uint32_t result;
		if (IndexOf(value, result))
		{
			return result;
		}
		return -1;
	}

	bool MyItemCollection::IndexOf(IInspectable const& value, uint32_t& index)
	{
		auto item = value.as<winrt::WinRtComponent::IMyItem>();
		if (item != nullptr)
		{
			return vector_base<MyItemCollection, winrt::WinRtComponent::IMyItem>::IndexOf(item, index);
		}
		return false;
	}

	void MyItemCollection::OnCollectionChanged(
		winrt::Microsoft::UI::Xaml::Interop::NotifyCollectionChangedAction const& action,
		winrt::Windows::Foundation::IInspectable const& oldItem,
		winrt::Windows::Foundation::IInspectable const& newItem,
		int32_t const oldIndex, int32_t
		const newIndex)

	{
		WinRtComponent::BindableVector oldItems;
		if (oldItem != nullptr)
		{
			oldItems.Append(oldItem);
		}

		WinRtComponent::BindableVector newItems;
		if (newItem != nullptr)
		{
			newItems.Append(newItem);
		}

		m_collectionChanged(*this, 
			winrt::Microsoft::UI::Xaml::Interop::NotifyCollectionChangedEventArgs(
				action, 
				newItems, 
				oldItems, 
				newIndex, 
				oldIndex));
	}
}
