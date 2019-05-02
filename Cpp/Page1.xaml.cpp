//
// Page1.xaml.cpp
// Implementation of the Page1 class
//

#include "pch.h"
#include "Page1.xaml.h"


/*co_await*/
#include <experimental\resumable>
#include <pplawait.h>

/*Create task*/
#include <ppltasks.h>

using namespace testing;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

using namespace Windows::Storage;
using namespace Windows::System::Threading;
using namespace concurrency;
using namespace Windows::UI::Core;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage::Streams;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

Page1::Page1()
{
	InitializeComponent();
}

void testing::Page1::SaveButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	SaveFileAwait();
}

task<void> Page1::SaveFileAwait()
{
	auto savePicker = ref new FileSavePicker();
	savePicker->SuggestedStartLocation = PickerLocationId::PicturesLibrary;

	auto extensions = ref new Platform::Collections::Vector<String^>();
	extensions->Append(".json");
	savePicker->FileTypeChoices->Insert("JSON", extensions);
	savePicker->SuggestedFileName = this->inputName->Text;

	auto file = co_await savePicker->PickSaveFileAsync();
	if (file == nullptr)
	{
		this->outputName->Text = "Operation cancelled";
		return;
	}
	co_await FileIO::WriteTextAsync(file, L"{\"Name\":" + "\"" + inputName->Text + "\"" + "}");
	this->outputName->Text = "Saved file: " + file->Path;
}

void testing::Page1::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


void testing::Page1::Myframepage1_Navigated(Platform::Object^ sender, Windows::UI::Xaml::Navigation::NavigationEventArgs^ e)
{

}


void testing::Page1::TextBox_TextChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::TextChangedEventArgs^ e)
{

}
