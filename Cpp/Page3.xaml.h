//
// Page3.xaml.h
// Declaration of the Page3 class
//

#pragma once

#include "Page3.g.h"

#include <codecvt>
#include <string>
#include <mutex>

namespace testing
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Page3 sealed
	{
	public:
		Page3();
	private:

		Concurrency::task<void> CreateFileAwait();
		void findData(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
