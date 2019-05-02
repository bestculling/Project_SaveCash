//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "Page1.xaml.h"
#include "Page2.xaml.h"
#include "Page3.xaml.h"

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
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using  namespace Windows::UI::ViewManagement;


// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
	ApplicationView^ appView = ApplicationView::GetForCurrentView();

	// Change the application view title text
	appView->Title = "SaveCash";
	
}


void testing::MainPage::ListBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	
}


void testing::MainPage::HamburgerButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	MySplitView->IsPaneOpen = !MySplitView->IsPaneOpen;
}


void testing::MainPage::BackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	if (Myframe->CanGoBack)
	{
		Myframe->GoBack();
	}
}


void testing::MainPage::GraphButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Myframe->Navigate(TypeName(Page3::typeid));
}

void testing::MainPage::HistoryButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Myframe->Navigate(TypeName(Page2::typeid));
}


void testing::MainPage::CreateButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Myframe->Navigate(TypeName(Page1::typeid));
}
