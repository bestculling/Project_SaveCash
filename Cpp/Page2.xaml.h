//
// Page2.xaml.h
// Declaration of the Page2 class
//

#pragma once

#include "Page2.g.h"

#include <codecvt>
#include <string>
#include <mutex>

namespace testing
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Page2 sealed
	{
	public:
		Page2();
	private:
		Concurrency::task<void> CreateFileAwait();
		Concurrency::task<void> WriteFileAwait(Platform::String^ readJson);

		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
