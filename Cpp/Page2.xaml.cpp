//
// Page2.xaml.cpp
// Implementation of the Page2 class
//

#include "pch.h"
#include "Page2.xaml.h"

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

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

using namespace Windows::Storage;
using namespace Windows::System::Threading;
using namespace concurrency;
using namespace Windows::UI::Core;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage::Streams;
using namespace Windows::Globalization::DateTimeFormatting;
using namespace Windows::Data::Json;

Page2::Page2()
{
	InitializeComponent();
}


void testing::Page2::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	CreateFileAwait();
}
task<void> Page2::CreateFileAwait()
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

	/*Date*/
	auto date = this->addDate->Date;
	auto value = date->Value;

	Array<DateTimeFormatter^>^ dateFormatters = {
		ref new DateTimeFormatter("shortdate")
	};
	String^ results = "";
	// Generate the results.
	for (auto formatter : dateFormatters)
	{
		// value day
		results = results + formatter->Format(value);
	}
	


	outputDir->Text = "Select file: " + file->Name;
	/*outputDir->Text = "Select file: " + value.ToString("D");*/

	JsonObject^ readJson = JsonObject::Parse(data); /*เเปลง .json_string เป็น json*/

	JsonObject^ json = ref new JsonObject;

	/*กรอกค่า*/
	String^ Des = "[" + "\"" + addDes->Text + "\""  + "]";
	JsonValue^ income = JsonValue::Parse(addIn->Text);
	JsonValue^ expenses = JsonValue::Parse(addEx->Text);
	JsonValue^ description = JsonValue::Parse(Des);

	/*Array ของ Description*/
	json->Insert("Des", description);
	json->Insert("Income", income);
	json->Insert("Expenses", expenses);

	double total = income->GetNumber() - expenses->GetNumber();
	json->Insert("Total", JsonValue::CreateNumberValue(total));

	/*object ใหญ่*/
	readJson->Insert(results, json);
	/*readJson->Stringify(); เเปลงเป็น String*/


	outputDir->Text = "Select file: " + file->Name;
	String^ write = readJson->Stringify();
	WriteFileAwait(write);
}
task<void> Page2::WriteFileAwait(Platform::String^ readJson) {
	auto openPicker = ref new FileOpenPicker();
	openPicker->SuggestedStartLocation = PickerLocationId::PicturesLibrary;

	openPicker->FileTypeFilter->Append(".json");

	auto file = co_await openPicker->PickSingleFileAsync();
	if (file == nullptr)
	{

		return;
	}
	co_await FileIO::WriteTextAsync(file, readJson);
}