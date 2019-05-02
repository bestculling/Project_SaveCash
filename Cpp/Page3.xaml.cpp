//
// Page3.xaml.cpp
// Implementation of the Page3 class
//

#include "pch.h"
#include "Page3.xaml.h"

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
using namespace Windows::Globalization::DateTimeFormatting;
using namespace Windows::Data::Json;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

Page3::Page3()
{
	InitializeComponent();
}


void testing::Page3::findData(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	CreateFileAwait();
}

task<void> Page3::CreateFileAwait()
{
	auto openPicker = ref new FileOpenPicker();
	openPicker->SuggestedStartLocation = PickerLocationId::PicturesLibrary;

	openPicker->FileTypeFilter->Append(".json");

	auto file = co_await openPicker->PickSingleFileAsync();
	if (file == nullptr)
	{

		return;
	}
	String^ data = co_await FileIO::ReadTextAsync(file);
	outputDir->Text = "Select file: " + file->Name;

	this->outputData->Text = data;
}