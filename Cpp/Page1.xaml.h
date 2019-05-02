//
// Page1.xaml.h
// Declaration of the Page1 class
//

#pragma once

#include "Page1.g.h"

#include <codecvt>
#include <string>
#include <mutex>

namespace testing
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Page1 sealed
	{
	public:
		Page1();
	private:
		Concurrency::task<void> SaveFileAwait();

		void SaveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Myframepage1_Navigated(Platform::Object^ sender, Windows::UI::Xaml::Navigation::NavigationEventArgs^ e);
		void TextBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e);
	};
}
