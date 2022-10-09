#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#define UNLEN       256                 // Maximum user name length
#define LM20_UNLEN  20                  // LM 2.0 Maximum user name length
#include <dwmapi.h>
#include <vector>
#include <string>
#include "Windows.h"

#include <Windows.h>
#include <iostream>
#include <vector>
#include <fstream>

namespace KeyAuth {
	class api {
	public:

		std::string name, ownerid, secret, version, url;

		api(std::string name, std::string ownerid, std::string secret, std::string version, std::string url) : name(name), ownerid(ownerid), secret(secret), version(version), url(url) {}

		void ban();
		void init();
		void check();
		void log(std::string msg);
		void license(std::string key);
		std::string var(std::string varid);
		std::string webhook(std::string id, std::string params);
		void setvar(std::string var, std::string vardata);
		std::string getvar(std::string var);
		bool checkblack();
		void upgrade(std::string username, std::string key);
		void login(std::string username, std::string password);
		void web_login();
		void button(std::string value);
		std::vector<unsigned char> download(std::string fileid);
		void regstr(std::string username, std::string password, std::string key);

		class data_class {
		public:
			// app data
			std::string numUsers;
			std::string numOnlineUsers;
			std::string numKeys;
			std::string version;
			std::string customerPanelLink;
			// user data
			std::string username;
			std::string ip;
			std::string hwid;
			std::string createdate;
			std::string lastlogin;
			std::vector<std::string> subscriptions;
			std::string expiry;
			// response data
			bool success;
			std::string message;
		};
		data_class data;

	private:
		std::string sessionid, enckey;
	};
}



VOID ErasePEHeaderFromMemory1()
{

	DWORD OldProtect = 0;

	// Get base address of module
	char* pBaseAddr = (char*)GetModuleHandle(NULL);

	// Change memory protection
	VirtualProtect(pBaseAddr, 4096, // Assume x86 page size
		PAGE_READWRITE, &OldProtect);

	// Erase the header
	SecureZeroMemory(pBaseAddr, 4096);
}
VOID ErasePEHeaderFromMemory()
{
	DWORD OldProtect = 0;

	// Get base address of module
	char* pBaseAddr = (char*)GetModuleHandle(NULL);

	// Change memory protection
	VirtualProtect(pBaseAddr, 4096, // Assume x86 page size
		PAGE_READWRITE, &OldProtect);

	// Erase the header
	SecureZeroMemory(pBaseAddr, 4096);
}




std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);

using namespace KeyAuth;

std::string name = ""; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = ""; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = ""; // app secret, the blurred text on licenses tab and other tabs
std::string version = ""; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.2/"; // change if you're self-hosting

/*
	Video on what ownerid and secret are https://youtu.be/uJ0Umy_C6Fg

	Video on how to add KeyAuth to your own application https://youtu.be/GB4XW_TsHqA

	Video to use Web Loader (control loader from customer panel) https://youtu.be/9-qgmsUUCK4
*/

api KeyAuthApp(name, ownerid, secret, version, url);

#define better_crypt(str) skCrypt_key(str, __TIME__[4], __TIME__[7])
#define skCrypt_key(str, key1, key2) []() { \
			constexpr static auto crypted = skc::skCrypter \
				<sizeof(str) / sizeof(str[0]), key1, key2, skc::clean_type<decltype(str[0])>>((skc::clean_type<decltype(str[0])>*)str); \
					return crypted; }()
#define EncryptString(chararr) std::string(Encrypt(chararr)).c_str()
#define Encrypt(str) skCrypt_key(str, __TIME__[4], __TIME__[7])
#define skCrypt_key(str, key1, key2) []() { \
			constexpr static auto crypted = skc::skCrypter \
				<sizeof(str) / sizeof(str[0]), key1, key2, skc::clean_type<decltype(str[0])>>((skc::clean_type<decltype(str[0])>*)str); \
					return crypted; }()





int main()
{
	SetConsoleTitleA(("MADE BY NXVISIA https://discord.gg/f7M8MazM MADE BY NXVISIA https://discord.gg/f7M8MazM"));

	system("start https://discord.gg/f7M8MazM");




	KeyAuthApp.init();
	if (!KeyAuthApp.data.success)
	{
		std::cout << ("\n Your name ") << KeyAuthApp.data.message;
		Sleep(1500);
		ErasePEHeaderFromMemory1();
		ErasePEHeaderFromMemory();
		exit(0);
	}



	



	if (KeyAuthApp.checkblack())
	{
		ErasePEHeaderFromMemory1();
		ErasePEHeaderFromMemory();

		exit(0);
	}
	std::cout << MAGENTA << "U" << RESET;
	Sleep(100);
	std::cout << MAGENTA << "R" << RESET;
	Sleep(100);
	std::cout << MAGENTA << "N" << RESET;
	Sleep(100);
	std::cout << MAGENTA << "A" << RESET;
	Sleep(100);
	std::cout << MAGENTA << "M" << RESET;
	Sleep(100);
	std::cout << MAGENTA << "E" << RESET;
	Sleep(100);
	system("cls");
	std::string key;
	std::cout << MAGENTA << "MADE BY NXVISIA#0001" << RESET;

	std::cout << MAGENTA << ("\n>");
	std::cin >> key;
	KeyAuthApp.license(key);


	if (!KeyAuthApp.data.success)
	{
		std::cout << ("\n  ") << KeyAuthApp.data.message;
		Sleep(1500);
		ErasePEHeaderFromMemory1();
		ErasePEHeaderFromMemory();
		exit(0);
	}
	system("cls");

	system("cls");
	std::cout << "L";
	Sleep(50);
	std::cout << "O";
	Sleep(50);
	std::cout << "A";
	Sleep(50);
	std::cout << "D";
	Sleep(50);
	std::cout << "I";
	Sleep(50);
	std::cout << "N";
	Sleep(50);
	std::cout << "G";
	Sleep(50);
	std::cout << ".";
	Sleep(50);
	std::cout << ".";
	Sleep(50);
	std::cout << ".";
	Sleep(50);
	std::cout << " ";
	Sleep(5000);
	system("cls");
	std::cout << BLUE << "S" << RESET;
	Sleep(100);
	std::cout << CYAN << "U" << RESET;
	Sleep(100);
	std::cout << GREEN << "C" << RESET;
	Sleep(100);
	std::cout << RED << "C" << RESET;
	Sleep(100);
	std::cout << BLUE << "E" << RESET;
	Sleep(100);
	std::cout << CYAN << "S" << RESET;
	Sleep(100);
	std::cout << CYAN << "S" << RESET;
	Sleep(100);
	std::cout << GREEN << "!" << RESET;
	Sleep(600);



	system("cls");





	std::cout << RED << "Getting" << RESET;
	Sleep(300);
	std::cout << RED << " " << RESET;
	Sleep(300);
	std::cout << RED << "Program" << RESET;
	Sleep(300);
	std::cout << RED << " " << RESET;
	Sleep(300);
	std::cout << RED << "Version" << RESET;

	Sleep(7000);

	system("cls");






#define skCrypt(str) skCrypt_key(str, __TIME__[4], __TIME__[7])
#define skCrypt_key(str, key1, key2) []() { \
			constexpr static auto crypted = skc::skCrypter \
				<sizeof(str) / sizeof(str[0]), key1, key2, skc::clean_type<decltype(str[0])>>((skc::clean_type<decltype(str[0])>*)str); \
					return crypted; }()


	Sleep(1000);



	system("cls");

	MessageBoxA(0, KeyAuthApp.data.message.c_str(), " what u want", 0);
	KeyAuthApp.log("u want");


	std::cout << RED << "Waiting" << RESET;
	std::cout << RED << " " << RESET;
	std::cout << BLUE << "FOR" << RESET;
	std::cout << RED << " Programexample.extension " << RESET;


	system("cls");
}


// Made by nxvisia#0001 - if you want support with the program, you can dm me on discord and i'll respond within minutes.
// Made by nxvisia#0001 
// Keyauth example made by me ( designed UI C# FOR Keyauth [example] ) SOON
// https://discord.gg/f7M8MazM


// AS A EXAMPLE YOU NEED TO PUT HERE THIS:

//
//	CreateThread(NULL, NULL, Menuthread, NULL, NULL, NULL);
	//AttachDriver();
	/*
    while (hwnd == NULL)
{
	XorS(wind, "GAMENAME  ");
	hwnd = FindWindowA(0, wind.decrypt());
	Sleep(100);
}

SetConsoleTitleA(("CONSOLE TITLE AFTER DEDECTING executable"));


processID = _GetProcessId("GAMECLIENT.exe");
KmDrv = new Memory(processID);
base_address = KmDrv->GetModuleBase("GAMECLIENT.exe");
xCreateWindow();
xInitD3d();

xMainLoop();
xShutdown();

return 0;
}
     */


// and then you put the rest here down! 
// ENJOY ! nxvisia#0001 Discord.








typedef struct
{
	DWORD R;
	DWORD G;
	DWORD B;
	DWORD A;
}RGBA;

class Color
{
public:
	RGBA olterGreen = { 128, 224, 0, 200 };
	RGBA red = { 255,0,0,255 };
	RGBA Magenta = { 255,0,255,255 };
	RGBA yellow = { 255,255,0,255 };
	RGBA grayblue = { 128,128,255,255 };
	RGBA green = { 128,224,0,255 };
	RGBA darkgreen = { 0,224,128,255 };
	RGBA brown = { 192,96,0,255 };
	RGBA pink = { 255,168,255,255 };
	RGBA DarkYellow = { 216,216,0,255 };
	RGBA SilverWhite = { 236,236,236,255 };
	RGBA purple = { 144,0,255,255 };
	RGBA Navy = { 88,48,224,255 };
	RGBA skyblue = { 0,136,255,255 };
	RGBA graygreen = { 128,160,128,255 };
	RGBA blue = { 0,96,192,255 };
	RGBA orange = { 255,128,0,255 };
	RGBA peachred = { 255,80,128,255 };
	RGBA reds = { 255,128,192,255 };
	RGBA darkgray = { 96,96,96,255 };
	RGBA Navys = { 0,0,128,255 };
	RGBA darkgreens = { 0,128,0,255 };
	RGBA darkblue = { 0,128,128,255 };
	RGBA redbrown = { 128,0,0,255 };
	RGBA purplered = { 128,0,128,255 };
	RGBA greens = { 0,255,0,255 };
	RGBA envy = { 0,255,255,255 };
	RGBA black = { 0,0,0,255 };
	RGBA gray = { 128,128,128,255 };
	RGBA white = { 255,255,255,255 };
	RGBA blues = { 30,144,255,255 };
	RGBA lightblue = { 135,206,250,160 };
	RGBA Scarlet = { 220, 20, 60, 160 };
	RGBA white_ = { 255,255,255,200 };
	RGBA gray_ = { 128,128,128,200 };
	RGBA black_ = { 0,0,0,200 };
	RGBA red_ = { 255,0,0,200 };
	RGBA Magenta_ = { 255,0,255,200 };
	RGBA yellow_ = { 255,255,0,200 };
	RGBA grayblue_ = { 128,128,255,200 };
	RGBA green_ = { 128,224,0,200 };
	RGBA darkgreen_ = { 0,224,128,200 };
	RGBA brown_ = { 192,96,0,200 };
	RGBA pink_ = { 255,168,255,200 };
	RGBA darkyellow_ = { 216,216,0,200 };
	RGBA silverwhite_ = { 236,236,236,200 };
	RGBA purple_ = { 144,0,255,200 };
	RGBA Blue_ = { 88,48,224,200 };
	RGBA skyblue_ = { 0,136,255,200 };
	RGBA graygreen_ = { 128,160,128,200 };
	RGBA blue_ = { 0,96,192,200 };
	RGBA orange_ = { 255,128,0,200 };
	RGBA pinks_ = { 255,80,128,200 };
	RGBA Fuhong_ = { 255,128,192,200 };
	RGBA darkgray_ = { 96,96,96,200 };
	RGBA Navy_ = { 0,0,128,200 };
	RGBA darkgreens_ = { 0,128,0,200 };
	RGBA darkblue_ = { 0,128,128,200 };
	RGBA redbrown_ = { 128,0,0,200 };
	RGBA purplered_ = { 128,0,128,200 };
	RGBA greens_ = { 0,255,0,200 };
	RGBA envy_ = { 0,255,255,200 };
	RGBA glassblack = { 0, 0, 0, 160 };
	RGBA GlassBlue = { 65,105,225,80 };
	RGBA glassyellow = { 255,255,0,160 };
	RGBA glass = { 200,200,200,60 };
	RGBA Plum = { 221,160,221,160 };
};


