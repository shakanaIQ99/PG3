#include <stdio.h>
#include<iostream>
#include<list>

using namespace std;


int main()
{
	bool Inset = true;
	list<const char*>YamanoteStation =
	{
		"Tokyo","Yurakucho","Shimbashi","Hamamatsucho","Tamachi",
		"Shinagawa","Osaki","Gotanda","Meguro","Ebisu","Shibuya",
		"Harajuku","Yoyogi","Shinjuku","Shin-Okubo","Takadanobaba",
		"Mejiro","Ikebukuro","Otuka","Sugamo","Komagome","Tabata",
		"Nippori","Uguisudani","Ueno","Okachimachi","Akihabara","Kanda"
	};


	cout << "YamanoteStation1970" << "\n";

	for (list<const char*>::iterator itr = YamanoteStation.begin(); itr != YamanoteStation.end(); ++itr)
	{
		cout << *itr << "\n";
	}

	cout << "YamanoteStation1971" << "\n";


	for (list<const char*>::iterator itr = YamanoteStation.begin(); itr != YamanoteStation.end(); ++itr)
	{
		if (*itr == "Nippori" && Inset)
		{
			itr = YamanoteStation.insert(itr, "Nisi-Nippori");
			Inset = false;
		}
		cout << *itr << "\n";

	}

	cout << "YamanoteStation2020" << "\n";

	Inset = true;

	for (list<const char*>::iterator itr = YamanoteStation.begin(); itr != YamanoteStation.end(); ++itr)
	{
		if (*itr == "Shinagawa" && Inset)
		{
			itr = YamanoteStation.insert(itr, "Takanawa-Gateway");
			Inset = false;
		}
		cout << *itr << "\n";

	}

	return 0;
}