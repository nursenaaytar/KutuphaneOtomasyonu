/****************************************************************************
**				            	SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				          BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				           PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI…...: 1.PROJE
**				ÖÐRENCÝ ADI......: NUR SENA AYTAR
**				ÖÐRENCÝ NUMARASI.: B191210075
**				DERS GRUBU.......: 2C
****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<string>
#include<clocale>
#include<ctime>

using namespace std;

void motif();

void motif2();

void ekransilme();

void secim1(string tcno, string adi, string soyadi, string uyeno, string telefon, string dogumtarihi, string gorevi, int alabilecegikitapsayisi, char cevap = 'e')
{
	ekransilme();
	motif();
	cout << endl;
	cout << "          OKUYUCU KAYDI EKLEME" << endl;
	motif();
	cout << endl;
	ofstream DosyaYaz;
	DosyaYaz.open("okuyucu.txt", ios::app | ios::in | ios::out);
	//Okuyucu kayýt iþlemindeki gerekli bilgileri kullanýcýya sorarak kaydeder, kullacýdan e yanýtýný almasý durumunda okuyucu kayýt iþlemine devam eder.
	do
	{
		cout << "\n Okuyucu TC No.......................: ";
		cin >> tcno;
		//Girilen tcno'nun hane sayýsý kontrol edilir. Eðer doðru ise kayda devam edilir.
		if (tcno.length() == 11)
		{
			cout << "\n Okuyucu Adý.........................: " << endl;
			cout << "(birinciad_ikiciad þeklinde giriniz.):";
			cin >> adi;
			cout << "\n Okuyucu Soyadý......................: ";
			cin >> soyadi;
			cout << "\n Okuyucu Üye No......................: ";
			cin >> uyeno;
			cout << "\n Okuyucu Tel No......................: ";
			cin >> telefon;
			cout << "\n Okuyucu Doðum Tarihi................: " << endl;
			cout << "(GG/AA/YYYY þeklinde giriniz.).......:";
			cin >> dogumtarihi;
			cout << "\n Okuyucu Görevi......................: ";
			cin >> gorevi;
			cout << "\n Okuyucunun Alabileceði Kitap Sayisi.: ";
			cin >> alabilecegikitapsayisi;
			DosyaYaz << "\n" << tcno << " " << adi << " " << soyadi << " " << uyeno << " " << telefon << " " << dogumtarihi << " " << gorevi << " " << alabilecegikitapsayisi;
			cout << endl;
			cout << " + Okuyucu Kayýt Ýþlemi Tamamlandý." << endl;
			cout << endl;
		}
		//Girilen tcno'nun hane sayýsýnýn hatalý olmasý durumunda çalýþýr. Girilen tcno'nun hatalý olduðu bilgisini yazdýrýr, sistemden çýkar.
		else
		{
			cout << endl;
			cout << " + Girdiðiniz TC numarasýnýn hane sayýsýný hatalýdýr." << endl;
			DosyaYaz.close();
			cout << endl;
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "Sistemden çýkýþ saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
			cout << endl << endl;
			exit(0);
		}
		cout << "Okuyucu Kayýt Ekleme iþlemine devam edecek misiniz......?(e/h) " << endl;
		cin >> cevap;
	} while (cevap == 'e');
	//Cevabýn h olmasý durumunda iþlemi bitirir ve okuyucu dosyasýný kapatýr.
	if (cevap == 'h')
	{
		DosyaYaz.close();
	}
}

void secim2(string, string, string, string, string, string, string, int, char);

void secim3(string tcno, string adi, string soyadi, string uyeno, string telefon, string dogumtarihi, string gorevi, int alabilecegikitapsayisi, char cevap, string ISBN, string odunctarihi, string donustarihi)
{
	ekransilme();
	motif();
	cout << endl;
	cout << "          OKUYUCU KAYDI SÝLME" << endl;
	motif();
	cout << endl << endl;
	string tc;
	cout << "Kaydý silinecek okuyucunun TC numarasýný giriniz :";
	cin >> tc;
	ifstream DosyaOku("okuyucu.txt");
	ofstream DosyaYaz("okuyucu.tmp");
	//Okuyucu dosyasýný baþtan sana okutur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> tcno >> adi >> soyadi >> uyeno >> telefon >> dogumtarihi >> gorevi >> alabilecegikitapsayisi;
		//Dosya okuma iþlemini durdurur.
		if (DosyaOku.eof()) break;
		//Kullanýcýnýn girdiði tc ile tcno'nun ayný olup olmadýðýný kontrol eder. Ayný ise okuyucu kaydýndaki bilgileri yazdýrýr.
		if (tc == tcno)
		{
			motif2();
			cout << "\n     Okuyucu Bilgileri \n";
			motif2();
			cout << endl;
			cout << "Okuyucu TC No....................:";
			cout << tcno << endl;
			cout << "Okuyucu Adý......................:";
			cout << adi << endl;
			cout << "Okuyucu Soyadý...................:";
			cout << soyadi << endl;
			cout << "Okuyucu Üye No...................:";
			cout << uyeno << endl;
			cout << "Okuyucu Tel No...................:";
			cout << telefon << endl;
			cout << "Okuyucu Doðum Tarihi.............:";
			cout << dogumtarihi << endl;
			cout << "Okuyucu Görevi...................:";
			cout << gorevi << endl;
			cout << "Okuyucu Alabileceði Kitap Sayýsý.:";
			cout << alabilecegikitapsayisi << endl;
			cout << endl << endl;
			cout << " + Okuyucu kaydý silindi.";
		}
		//tc ile tcno'nun farklý olmasý durumunda okuyucu dosyasýnýn sabit kalmasýný saðlar.
		else
		{
			DosyaYaz << tcno << " " << adi << " " << soyadi << " " << uyeno << " " << telefon << " " << dogumtarihi << " " << gorevi << " " << alabilecegikitapsayisi << "\n";
		}
	}
	DosyaYaz.close();
	DosyaOku.close();
	remove("okuyucu.txt");//dosyayi sildim.
	int sondosya = rename("okuyucu.tmp", "okuyucu.txt");
	cout << endl << endl;
	ifstream DosyaOku0("Odunc.txt");
	ofstream DosyaYaz0("Odunc.tmp");
	//Okuyucu kaydýnýn silinmesi durumunda kaydý silinen okuyucunun ödünç aldýðý Kitaplarý geri alýr. Odunc dosyasýný baþtan sona okutur.
	while (!(DosyaOku0.eof()))
	{
		DosyaOku0 >> tcno >> ISBN >> odunctarihi >> donustarihi;
		//Dosya okuma iþlemini durdurur.
		if (DosyaOku0.eof()) break;
		//tc ile tcno'nun ayný olup olmadýðýný kontrol eder. Ayný olmasý durumunda ödünç kitap ve okuyucu bilgilerini bastýrýr.
		if (tc == tcno)
		{
			cout << endl << endl;
			motif2();
			cout << "\n Ödünç Kitap - Okuyucu Bilgileri \n";
			motif2();
			cout << endl;
			cout << endl;
			cout << "Okuyucunun TC numarasý.:";
			cout << tcno << endl;
			cout << "ISBN...................:";
			cout << ISBN << endl;
			cout << "Ödünç Tarihi...........:";
			cout << odunctarihi << endl;
			cout << "Dönüþ Tarihi...........:";
			cout << donustarihi << endl;
			cout << endl << endl;
			cout << " + Kitap geri döndürme iþlemi tamamlandý." << endl;
		}
		//tc ile tcno'nun farklý olmasý durumunda Odunc dosyasýnýn sabit kalmasýný saðlar.
		else
		{
			DosyaYaz0 << tcno << " " << ISBN << " " << odunctarihi << " " << donustarihi << "\n";
		}
	}
	DosyaYaz0.close();
	DosyaOku0.close();
	remove("Odunc.txt");
	int sonOduncdosya = rename("Odunc.tmp", "Odunc.txt");
}

void secim4(string, string, string, string, string, string, string, string, string, string);

void secim5(string tcno, string adi, string soyadi, string uyeno, string telefon, string dogumtarihi, string gorevi, int alabilecegikitapsayisi, string ISBN, string donustarihi, string odunctarihi, char cevap, string kitapadi, string yazaradi, string yazarsoyadi, string konu, string tur, string sayfasayisi)
{
	ekransilme();
	motif();
	cout << endl;
	cout << "          KÝTAP ÖDÜNÇ ALMA" << endl;
	motif();
	cout << endl << endl;
	string isbn;
	cout << "Ödünç Alýnmak Ýstenen Kitap ISBN: ";
	cin >> isbn;
	cout << endl;
	ifstream DosyaOku("Kitaplar.txt");
	ofstream DosyaYaz("Kitaplar.txt", ios::app | ios::in | ios::out);
	ifstream dosyaoku("Odunc.txt");
	int sayac = 0;
	int sayan = 0;
	//Odunc dosyasý baþtan sona okunur
	while (!dosyaoku.eof())
	{
		dosyaoku >> ISBN >> tcno >> odunctarihi >> donustarihi;
		//Dosya okuma iþlemini durdurur.
		if (DosyaOku.eof()) break;
		//isbn ve ISBN'nin ayný olup olmadýðý kontrol edilir. Ayný ise kitap ödünç verilmez çünkü bu durum kitabýn baþka bir okuyucu tarafýndan önceden ödünç alýndýðý anlamýna gelir. Durum bilgisi ekrana yazdýrýlýr ve sistemden çýkýlýr.
		if (ISBN == isbn)
		{
			cout << " + Ödünç almak istediðiniz kitap baþka bir okuyucu tarafýndan ödünç alýnmýþtýr." << endl << " + Ödünç alma isteðiniz gerçekleþtirilemedi." << endl << endl;
			DosyaOku.close();
			DosyaYaz.close();
			dosyaoku.close();
			cout << endl;
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "Sistemden çýkýþ saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
			cout << endl << endl;
			exit(0);
		}
	}
	//Kitaplar dosyasý baþtan sona okunur.
	while (!DosyaOku.eof())
	{
		DosyaOku >> ISBN >> kitapadi >> yazaradi >> yazarsoyadi >> konu >> tur >> sayfasayisi;
		//Dosya okuma iþlemini durdurur.
		if (DosyaOku.eof()) break;
		//ISBN ile isbn'nin ayný olmasý durumunda çalýþýr. tc'si girilen okuyucunun bilgilerini bastýrýr.
		if (ISBN == isbn)
		{
			motif2();
			cout << "Kitap Bilgileri";
			motif2();
			cout << endl << endl;
			cout << "ISBN:";
			cout << ISBN << endl;
			cout << "Kitap Adý:";
			cout << kitapadi << endl;
			cout << "Yazar Adý:";
			cout << yazaradi << endl;
			cout << "Yazar Soyadý:";
			cout << yazarsoyadi << endl;
			cout << "Kitabýn Konusu:";
			cout << konu << endl;
			cout << "Kitabýn Türü:";
			cout << tur << endl;
			cout << "Kitabýn Sayfa Sayýsý:";
			cout << sayfasayisi << endl << endl;
			sayac = 1;
		}
	}
	//ISBN'si girilen kitabýn sisteme kayýtlý olmamasý durumunda çalýþýr. Kitap kaydý bulunamadýðýný yazdýrýr.
	if (sayac == 0)
	{
		cout << endl;
		cout << "Kitap kaydý bulunamamaktadýr." << endl;
		cout << endl;
		time_t now = time(0);
		tm* ltm = localtime(&now);
		cout << "Sistemden çýkýþ saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
		cout << endl << endl;
		exit(0);
	}

	cout << "Kitap ödünç almak istiyor musunuz..?(e/h)" << endl;
	cin >> cevap;
	cout << endl;
	string tc;
	cout << "Okuyucu TC No:";
	cin >> tc;
	ifstream dosyaOku("okuyucu.txt");
	ofstream dosyaYaz("okuyucu.txt", ios::app | ios::in | ios::out);
	//okuyucu dosyasýný baþtan sona okur.
	while (!dosyaOku.eof())
	{
		dosyaOku >> tcno >> adi >> soyadi >> uyeno >> telefon >> dogumtarihi >> gorevi >> alabilecegikitapsayisi;
		//Dosya okuma iþlemini durdurur.
		if (dosyaOku.eof()) break;
		//tcno ile tc'nin ayný olmasý durumunda çalýþýr. tcno'su girilen okuyucunun bilgilerini bastýrýr.
		if (tcno == tc)
		{
			cout << endl;
			motif2();
			cout << "Okuyucu Bilgileri";
			motif2();
			cout << endl << endl;
			cout << endl;
			cout << "Okuyucu TC No.......................:" << tcno << endl;
			cout << "Okuyucu Adý.........................:" << adi << endl;
			cout << "Okuyucu Soyadý......................:" << soyadi << endl;
			cout << "Okuyucu Üye No......................:" << uyeno << endl;
			cout << "Okuyucu Tel No......................:" << telefon << endl;
			cout << "Okuyucu Doðum Tarihi................:" << dogumtarihi << endl;
			cout << "Okuyucu Görevi......................:" << gorevi << endl;
			cout << "Okuyucunun Alabileceði Kitap Sayýsý.:" << alabilecegikitapsayisi << endl << endl;
			sayan = 1;
		}
	}
	//tcno'su girilen okuyucununun sisteme kayýtlý olmamasý durumunda çalýþýr. Okuyucunun kaydýný yapar.
	if (sayan == 0)
	{
		cout << endl;
		cout << "Okuyucu kaydý bulunamamaktadýr. Okuyucu kayýt iþlemi için bilgilerinizi giriniz:" << endl;
		cout << "\n Okuyucu TC No.......................: ";
		cin >> tcno;
		//tcno'nun hane sayýsý kontrol edilir. Eðer 11'e eþitse okuyucu kaydý yapýlýr.
		if (tcno.length() == 11)
		{
			cout << "\n Okuyucu Adý.........................: " << endl;
			cout << "(birinciad_ikiciad þeklinde giriniz.):";
			cin >> adi;
			cout << "\n Okuyucu Soyadý......................: ";
			cin >> soyadi;
			cout << "\n Okuyucu Üye No......................: ";
			cin >> uyeno;
			cout << "\n Okuyucu Tel No......................: ";
			cin >> telefon;
			cout << "\n Okuyucu Doðum Tarihi................: " << endl;
			cout << "(GG/AA/YYYY þeklinde giriniz.).......:";
			cin >> dogumtarihi;
			cout << "\n Okuyucu Görevi......................: ";
			cin >> gorevi;
			cout << "\n Okuyucunun Alabileceði Kitap Sayisi.: ";
			cin >> alabilecegikitapsayisi;
			cout << endl;
			dosyaYaz << "\n" << tcno << " " << adi << " " << soyadi << " " << uyeno << " " << telefon << " " << dogumtarihi << " " << gorevi << " " << alabilecegikitapsayisi;
			cout << endl;
			cout << " + Okuyucu Kayýt Ýþlemi Tamamlandý." << endl;
			cout << endl;
		}
		//Kaydý yapýlacak okuyucunun TC numarasýnýn hane sayýsýnýn yanlýþ girilmesi sonucu çalýþýr. Hatalý olduðu bilgisi ekrana yazdýrýlýr, sistemden çýkýþ saati yazdýrýlýr ve sistemden çýkýlýr.
		else
		{
			cout << endl;
			cout << " + Girdiðiniz TC numarasýnýn hane sayýsýný hatalýdýr. Okuyucu kaydýnýz yapýlamadý." << endl;
			DosyaYaz.close();
			cout << endl;
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "Sistemden çýkýþ saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
			cout << endl << endl;
			exit(0);
		}
	}
	string sayma;
	//Okuyucunun kitap almak isteyip istememe sorusuna e yanýtý vermesi durumunda çalýþýr. Okuyucu girdiði bilgilere sahip kitabý ödünç almýþ olur.
	if (cevap == 'e')
	{
		DosyaOku.close();
		DosyaYaz.close();
		dosyaOku.close();
		dosyaYaz.close();
		ofstream DosyaYaz;
		DosyaYaz.open("Odunc.txt", ios::app);
		motif2();
		cout << " Kitap Ödünç Alma ";
		motif2();
		cout << endl;
		cout << "\n Okuyucu TC No...........:";
		cin >> tcno;
		cout << "\n ISBN...................:";
		cin >> ISBN;
		cout << "\n Ödünç Tarihi...........:";
		cin >> odunctarihi;
		cout << "\n Dönuþ Tarihi...........:";
		cin >> donustarihi;
		DosyaYaz << ISBN << " " << tcno << " " << odunctarihi << " " << donustarihi << "\n";
		cout << endl;
		cout << " + Kitap Ödünç Alma Ýþleminiz Tamamlandý." << endl;
		DosyaYaz.close();
	}
	//Kaydý önceden yapýlmýþ okuyucunun kitap ödünç almasý durumunda çalýþýr.
	else
	{
		cout << " + Kitap Ödünç Alma Ýþleminiz Tamamlandý." << endl;
	}
}

void secim6(string, string, string, string);

void secim7(string ISBN, string kitapadi, string yazaradi, string yazarsoyadi, string konu, string tur, string sayfasayisi, char cevap = 'e')
{
	ekransilme();
	motif();
	cout << endl;
	cout << "          KÝTAP KAYDI EKLEME" << endl;
	motif();
	cout << endl;
	ofstream DosyaYaz;
	DosyaYaz.open("Kitaplar.txt", ios::app | ios::in | ios::out);
	//Kitap kaydý için gerekli bilgileri sorar ve aldýðý yanýtlarý kaydeder. Kayýt yapmaya devap edecek misiniz sorusuna h yanýtý verilene kadar kitap kaydý yapmaya devam eder.
	do
	{
		cout << endl;
		cout << "Lütefen kitap bilgileriniz giriniz." << endl;
		cout << endl;
		cout << "\n ISBN.................:";
		cin >> ISBN;
		//Girilen ISBN'nin hane sayýsýný kontrol eder. Doðru ise kayda devam eder.
		if (ISBN.length() == 13)
		{
			cout << "\n Kitap Ýsmi...........:" << endl;
			cout << "(birinciad_ikinciad þeklinde giriniz):";
			cin >> kitapadi;
			cout << "\n Yazar Adý............:" << endl;
			cout << "(birinciad_ikinciad þeklinde giriniz):";
			cin >> yazaradi;
			cout << "\n Yazar Soyadý.........:";
			cin >> yazarsoyadi;
			cout << "\n Kitap Konusu.........:";
			cout << "(birincikelime_ikincikelime þeklinde giriniz):";
			cin >> konu;
			cout << "\n Kitap Türü...........:";
			cin >> tur;
			cout << "\n Kitabýn Sayfa Sayýsý.:";
			cin >> sayfasayisi;
			DosyaYaz << "\n" << ISBN << " " << kitapadi << " " << yazaradi << " " << yazarsoyadi << " " << konu << " " << tur << " " << sayfasayisi;
			cout << endl;
			cout << " + Kitap  kaydý tamamlandý." << endl;
			cout << endl;
		}
		//Girilen ISBN'nin hane sayýsý hatalý ise hatalý olduðu bilgisini yazdýrýr, sistemden çýkar.
		else
		{
			cout << endl;
			cout << " + Girdiðiniz kitap ISBN hane sayýsý hatalýdýr." << endl;
			DosyaYaz.close();
			cout << endl;
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "Sistemden çýkýþ saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
			cout << endl << endl;
			exit(0);
		}
		cout << "Kitap kaydý yapmaya devam edecek misiniz ?(e/h) " << endl;
		cin >> cevap;
	} while (cevap == 'e');
	//h cevabýný almasý üzerine kaydý sonlandýrýr ve Kitaplar dosyasýný kapatýr. 
	if (cevap == 'h')
	{
		DosyaYaz.close();
	}
}

void secim8(string, string, string, string, string, string, string);

void secim9(string, string, string, string, string, string, string);

void secim10()
{
	cout << endl;
}

void secimler(int secim, string tcno, string adi, string soyadi, string uyeno, string telefon, string dogumtarihi, string gorevi, int alabilecegikitapsayisi, char cevap, string ISBN, string kitapadi, string yazaradi, string yazarsoyadi, string konu, string tur, string sayfasayisi, string odunctarihi, string donustarihi);

int main()
{
	setlocale(LC_ALL, "Turkish");
	string tcno;
	string adi;
	string soyadi;
	string uyeno;
	string telefon;
	string dogumtarihi;
	string gorevi;
	int alabilecegikitapsayisi;
	char cevap = 'e';

	string ISBN;
	string kitapadi;
	string yazaradi;
	string yazarsoyadi;
	string konu;
	string tur;
	string sayfasayisi;

	string odunctarihi;
	string donustarihi;

	string kullaniciadi;
	string sifre;
	string kullanici;
	string sifresi;

	cout << "---------GÝRÝÞ---------" << endl;
	cout << "\n Kullanici Adý.: ";
	cin >> kullanici;
	cout << "\n Þifre.........: ";
	cin >> sifresi;
	int sayac = 0;

	ifstream DosyaOku("kullanýcýlar.txt");
	//kullanýcýlar dosyasý baþtan sona okunur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> kullaniciadi >> sifre;
		//girilen kullanýcý adý ve þifresininin sistemdeki kullanýcý adý ve þifrelerine eþit olmasý durumunda sayac deðerini 1'e eþitler.
		if (kullanici == kullaniciadi && sifresi == sifre)
		{
			sayac = 1;
		}
	}
	//Kullanýcý kaydýnýn bulunduðu anlamýna gelir ve menü açýlýr, iþlemler yapýlabilir.
	if (sayac == 1)
	{
		int secim, i = 1;
		cout << endl;
		time_t now = time(0);
		tm* ltm = localtime(&now);
		cout << "Sisteme giriþ saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
		cout << "Sisteme giriþ tarihiniz : " << ltm->tm_mday << "." << 1 + ltm->tm_mon << "." << 1900 + ltm->tm_year << endl;
		cout << endl << endl;
		//Menü açýlýr ve kullanýcýdan seçim yapýlmasý istenir. Seçimlerin temsil ettiði sayýlar girilene kadar seçim yapýlmaya devam edilir.
		do
		{
			cout << "MENÜ" << endl;
			cout << "1 - Okuyucu Kaydý" << endl;
			cout << "2 - Okuyucu Kaydý Güncelleme" << endl;
			cout << "3 - Okuyucu Kaydý Silme" << endl;
			cout << "4 - Okuyucu Üzerindeki Kitaplar Listesi" << endl;
			cout << "5 - Okuyucu Kitap Ödünç Alma" << endl;
			cout << "6 - Okuyucu Kitap Geri Döndürme" << endl;
			cout << "7 - Kitap Ekleme" << endl;
			cout << "8 - Kitap Silme" << endl;
			cout << "9 - Kitap Düzeltme" << endl;
			cout << "10- Çýkýþ" << endl;
			cout << endl << endl;
			cout << "Yapmak istediðiniz iþlemin numarasýný giriniz:";
			cin >> secim;
			cout << endl << endl;
			alabilecegikitapsayisi = 0;
			secimler(secim, tcno, adi, soyadi, uyeno, telefon, dogumtarihi, gorevi, alabilecegikitapsayisi, cevap, ISBN, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi, odunctarihi, donustarihi);
			cout << endl;
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "Sistemden çýkýþ saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
			cout << endl << endl;
			exit(0);
		} while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9 && secim != 10);
	}
	//Sayacýn 1'den farklý olmasý durumunda çalýþýr. Kullanýcý kaydýnýn bulunmadýðý anlamýna gelir ve hatalý giriþ yapýldýðý bilgisini ekrana bastýrýr.
	else
	{
		cout << endl;
		cout << " ! Hatalý giriþ yaptýnýz.";
	}
	DosyaOku.close();
}

void motif()
{
	// char(166) karakterini 51 kere ekrana bastýrýr.
	for (int i = 0; i <= 50; i++)
	{
		cout << char(166);
	}
}

void motif2()
{
	//char(176) karakterini 19 kere ekrana bastýrýr.
	for (int i = 0; i <= 18; i++)
	{
		cout << char(176);
	}
}

void ekransilme()
{
	system("cls");
}

void secimler(int secim, string tcno, string adi, string soyadi, string uyeno, string telefon, string dogumtarihi, string gorevi, int alabilecegikitapsayisi, char cevap, string ISBN, string kitapadi, string yazaradi, string yazarsoyadi, string konu, string tur, string sayfasayisi, string odunctarihi, string donustarihi)
{
	//Okuyucu kayýt iþleminin seçilmesi durumunda iþlemleri gerçekleþtirir. Ýstenilen iþlem gerçekleþtirilir.
	if (secim == 1)
	{
		secim1(tcno, adi, soyadi, uyeno, telefon, dogumtarihi, gorevi, alabilecegikitapsayisi, cevap = 'e');
	}
	//Okuyucu Kayýt Güncelleme iþleminin seçilmesi durumunda iþlemleri gerçekleþtirir.	 
	if (secim == 2)
	{
		//Cevap h olana kadar okuyucu kaydý güncellemeye devam eder.		
		do
		{
			secim2(tcno, adi, soyadi, uyeno, telefon, dogumtarihi, gorevi, alabilecegikitapsayisi, cevap = 'e');
			cout << endl;
			cout << "Baþka okuyucu kaydý güncellemek istiyor musunuz? (e/h)";
			cin >> cevap;
		} while (cevap != 'h');
	}
	//Okuyucu kayýt silme isleminin seçilmesi durumunda iþlemlerini gerçekleþtirir.
	if (secim == 3)
	{
		//Cevap h olana kadar okuyucu kaydý silmeye devam eder.	
		do
		{
			secim3(tcno, adi, soyadi, uyeno, telefon, dogumtarihi, gorevi, alabilecegikitapsayisi, cevap = 'e', ISBN, odunctarihi, donustarihi);
			cout << endl;
			cout << "Baþka okuyucu kaydý silmek istiyor musunuz? (e/h)";
			cin >> cevap;
		} while (cevap != 'h');

	}
	//Okuyucu üzerindeki Kitaplar listesinin gösterilmesi için 4'e basýlmasý durumunda iþlemlerini gerçekleþtirir.
	if (secim == 4)
	{
		secim4(tcno, ISBN, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi, odunctarihi, donustarihi);
	}
	//Kitap ödünç alma iþlemi seçiminin yapýlmasý durumunda çalýþýr.
	if (secim == 5)
	{
		secim5(tcno, adi, soyadi, uyeno, telefon, dogumtarihi, gorevi, alabilecegikitapsayisi, ISBN, donustarihi, odunctarihi, cevap, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi);
	}
	//Kitap Geri döndürme iþlemi yapmak için 6'ya basýlýrsa çalýþýr.  Ýstenilen iþlem gerçekleþtirilir.
	if (secim == 6)
	{
		secim6(tcno, ISBN, odunctarihi, donustarihi);
	}
	//Kitap Ekleme iþlemi yapmak için 7'ye basýlýrsa çalýþýr.  Ýstenilen iþlem gerçekleþtirilir.
	if (secim == 7)
	{
		secim7(ISBN, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi, cevap = 'e');
	}
	// Kitap kaydý silme iþlemi yapmak için 8'e basýlmasý durumunda çalýþýr.  Ýstenilen iþlem gerçekleþtirilir.
	if (secim == 8)
	{
		//Cevap h olana kadar kitap kaydý silmeye devam eder.
		do
		{
			secim8(ISBN, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi);
			cout << endl;
			cout << "Baþka kitap kaydý silmek istiyor musunuz? (e/h)";
			cin >> cevap;
		} while (cevap != 'h');
	}
	//Kitap Kaydý Düzenleme iþlemi yapmak için 9'a basýlmasý durumunda çalýþýr. Ýstenilen iþlem gerçekleþtirilir.
	if (secim == 9)
	{
		//Cevap h olana kadar kitap kaydý düzenlemeye devam eder.
		do
		{
			secim9(ISBN, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi);
			cout << endl;
			cout << "Baþka kitap kaydý düzenlemek istiyor musunuz? (e/h)";
			cin >> cevap;
		} while (cevap != 'h');

	}
	//Çýkýþ yapýlmak amacý ile 10'a basýlmasý durumunda çalýþýr. Çýkýþ iþlemi gerçekleþtirilir.
	if (secim == 10)
	{
		secim10();
	}
}

void secim2(string tcno, string adi, string soyadi, string uyeno, string telefon, string dogumtarihi, string gorevi, int alabilecegikitapsayisi, char cevap = 'e')
{
	ekransilme();
	string tc;
	motif();
	cout << endl;
	cout << "          OKUYUCU KAYDI GÜNCELLEME" << endl;
	motif();
	cout << endl;
	ifstream DosyaOku("okuyucu.txt");
	ofstream DosyaYaz("okuyucu.tmp");
	cout << endl;
	cout << "Kaydý güncellenecek okuyucunun TC no...:";
	cin >> tc;
	int sayac = 0;
	//Okuyucu dosyasýný baþtan sona okur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> tcno >> adi >> soyadi >> uyeno >> telefon >> dogumtarihi >> gorevi >> alabilecegikitapsayisi;
		//Girilen tc ile tcno'nun ayný olup olmadýðýný kontrol eder. Ayný olmasý durumunda kaydý gücellemek için kulanýcýya bilgiler sorarak cevap alýr. Yeni bilgiler ile okuyucu dosyasýnda güncelleme yapar.
		if (tc == tcno)
		{
			cout << endl;
			motif2();
			cout << "Okuyucu Bilgileri";
			motif2();
			cout << endl;
			cout << "Okuyucu TC No.......................:" << tcno << endl;
			cout << "Okuyucu Adý.........................:" << adi << endl;
			cout << "Okuyucu Soyadý......................:" << soyadi << endl;
			cout << "Okuyucu Üye No......................:" << uyeno << endl;
			cout << "Okuyucu Tel No......................:" << telefon << endl;
			cout << "Okuyucu Doðum Tarihi................:" << dogumtarihi << endl;
			cout << "Okuyucu Görevi......................:" << gorevi << endl;
			cout << "Okuyucunun Alabileceði Kitap Sayýsý.:" << alabilecegikitapsayisi << endl << endl;
			cout << "Okuyucunun Bilgilerini Güncelleyiniz:" << endl;
			cout << "\n Okuyucu TC No.......................: ";
			cin >> tcno;
			cout << "\n Okuyucu Adý.........................: " << endl;
			cout << "(birinciad_ikiciad þeklinde giriniz.):";
			cin >> adi;
			cout << "\n Okuyucu Soyadý......................: ";
			cin >> soyadi;
			cout << "\n Okuyucu Üye No......................: ";
			cin >> uyeno;
			cout << "\n Okuyucu Tel No......................: ";
			cin >> telefon;
			cout << "\n Okuyucu Doðum Tarihi................: " << endl;
			cout << "(GG/AA/YYYY þeklinde giriniz.).......:";
			cin >> dogumtarihi;
			cout << "\n Okuyucu Görevi......................: ";
			cin >> gorevi;
			cout << "\n Okuyucunun Alabileceði Kitap Sayisi.: ";
			cin >> alabilecegikitapsayisi;
			cout << endl;
			cout << " + Okuyucu Kaydý Güncelleme Ýþlemi Tamamlandý." << endl;
			DosyaYaz << "\n" << tcno << " " << adi << " " << soyadi << " " << uyeno << " " << telefon << " " << dogumtarihi << " " << gorevi << " " << alabilecegikitapsayisi;
			sayac = 1;
		}
		//Girilen tc ile tcno'nun ayný olmamasý durumunda okuyucu dosyasýnda deðiþiklik olmamasýný saðlar.
		else
		{
			DosyaYaz << "\n" << tcno << " " << adi << " " << soyadi << " " << uyeno << " " << telefon << " " << dogumtarihi << " " << gorevi << " " << alabilecegikitapsayisi;
		}
	}
	//Girilen tc'nin tcno ile farklý olmasý durumunda okuyucu kaydýnýn bulunmadýðýný ekrana yazdýrýr.
	if (sayac == 0)
	{
		cout << "Okuyucu kaydý bulunamadý." << endl;
	}
	DosyaYaz.close();
	DosyaOku.close();
	remove("okuyucu.txt");
	int sonokuyucudosya = rename("okuyucu.tmp", "okuyucu.txt");
}

void secim4(string tcno, string ISBN, string kitapadi, string yazaradi, string yazarsoyadi, string konu, string tur, string sayfasayisi, string odunctarihi, string donustarihi)
{
	ekransilme();
	ifstream DosyaOku("Odunc.txt");
	cout << "Okuyucu TC no:";
	string tc;
	cin >> tc;
	//Odunc dosyasýný baþtan sona okur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> ISBN >> tcno >> odunctarihi >> donustarihi;
		//Dosya okuma iþlemini durdurur.
		if (DosyaOku.eof()) break;
		//tc ile tcno'nun ayný olmasý durumunda okuyucunun ödünç aldýðý Kitaplarý liste þeklinde bastýrýr.
		if (tcno == tc)
		{
			motif();
			cout << endl;
			cout << "          OKUYUCU ÜZERÝNDEKÝ KÝTAP LÝSTESÝ" << endl;
			motif();
			cout << endl << endl;
			cout << "Okuyucu TC No....:" << tcno << endl;
			cout << "ISBN.............:" << ISBN << endl;
			cout << "Ödünç Tarihi.....:" << odunctarihi << endl;
			cout << "Dönüþ Tarihi.....:" << donustarihi << endl;
			cout << endl << endl;
			string isbn;
			isbn = ISBN;
			ifstream dosyaoku("Kitaplar.txt");
			//Kitaplar dosyasýný baþtan sona okur. isbn ve ISBN'nin ayný olmasý durumunda okuyucunun ödünç aldýðý Kitaplarýn özelliklerini bastýrýr.
			while (!(dosyaoku.eof()))
			{
				dosyaoku >> ISBN >> kitapadi >> yazaradi >> yazarsoyadi >> konu >> tur >> sayfasayisi;
				//Dosya okuma iþlemini durdurur.
				if (dosyaoku.eof()) break;
				//isbn ile ISBN'nin ayný olup olmadýðýný kontrol eder. Ayný olmasý durumunda ISBN'si girilen kitabýn özelliklerini yazdýrýr.
				if (isbn == ISBN)
				{
					motif2();
					cout << "Kitap Özellikleri";
					motif2();
					cout << endl << endl;
					cout << "Kitap Adý..........:";
					cout << kitapadi << endl;
					cout << "Yazar Adý..........:";
					cout << yazaradi << endl;
					cout << "Yazar Soyadý.......:";
					cout << yazarsoyadi << endl;
					cout << "Kitap Konusu.......:";
					cout << konu << endl;
					cout << "Kitap Türü.........:";
					cout << tur << endl;
					cout << "Kitap Sayfa Sayýsý.:";
					cout << sayfasayisi << endl;
					cout << endl << endl;
				}
			}
		}
	}
	DosyaOku.close();
}

void secim6(string tcno, string ISBN, string odunctarihi, string donustarihi)
{
	ekransilme();
	motif();
	cout << endl;
	cout << "          KÝTAP GERÝ GÖNDERME" << endl;
	motif();
	cout << endl << endl;
	string isbn;
	cout << "Ödünç geri gönderilmek istenen kitap ISBN:";
	cin >> isbn;
	ifstream DosyaOku("Odunc.txt");
	ofstream DosyaYaz("Odunc.tmp");
	//Odunc dosyasý baþtan sona okunur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> ISBN >> tcno >> odunctarihi >> donustarihi;
		//Dosya okuma iþlemini durdurur.
		if (DosyaOku.eof()) break;
		//tc ile tcno'nun ayný olup olmadýðý kontrol edilir. Ayný ise önce ödünç kitap-okuyucu bilgileri bastýrýlýr, sonra kitap geri döndürme iþlemii tamamlanýr.
		if (isbn == ISBN)
		{
			cout << endl;
			motif2();
			cout << "\n Ödünç Kitap - Okuyucu Bilgileri \n";
			motif2();
			cout << endl << endl;
			cout << "Okuyucunun TC numarasý.:";
			cout << tcno << endl;
			cout << "ISBN...................:";
			cout << ISBN << endl;
			cout << "Ödünç Tarihi...........:";
			cout << odunctarihi << endl;
			cout << "Dönüþ Tarihi...........:";
			cout << donustarihi << endl;
			cout << endl;
			cout << " + Kitap geri döndürme iþlemi tamamlandý." << endl;
		}
		//tc ile tcno'nun farklý olmasý durumundaki bilgilerin deðiþtirilmemesini saðlar.
		else
		{
			DosyaYaz << ISBN << " " << tcno << " " << odunctarihi << " " << donustarihi << "\n";
		}
	}
	DosyaYaz.close();
	DosyaOku.close();
	remove("Odunc.txt");
	int sonOduncdosya = rename("Odunc.tmp", "Odunc.txt");
}

void secim8(string ISBN, string kitapadi, string yazaradi, string yazarsoyadi, string konu, string tur, string sayfasayisi)
{
	ekransilme();
	motif();
	cout << endl;
	cout << "          KÝTAP KAYDI SÝLME" << endl;
	motif();
	cout << endl << endl;
	string isbn;
	cout << "Kaydý Silinecek Kitabýn ISBN:";
	cin >> isbn;
	ifstream DosyaOku("Kitaplar.txt");
	ofstream DosyaYaz("Kitaplar.tmp");
	//Kitaplar dosyasý baþtan sona kadar okunur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> ISBN >> kitapadi >> yazaradi >> yazarsoyadi >> konu >> tur >> sayfasayisi;
		//Dosya okuma iþlemini durdurur.
		if (DosyaOku.eof()) break;
		//isbn ve ISBN'nin ayný olup olmadýðý kontrol edilir. Ayný olmasý durumunda kitabýn Kitaplar dosyasýndaki bilgileri bastýrýlýr. Sonrasýnda kitap kaydý silinir.
		if (isbn == ISBN)
		{
			cout << endl;
			motif2();
			cout << "\n Kitap Bilgileri \n";
			motif2();
			cout << endl;
			cout << "ISBN:";
			cout << ISBN << endl;
			cout << "Kitap Adý:";
			cout << kitapadi << endl;
			cout << "Yazar Adý:";
			cout << yazaradi << endl;
			cout << "Yazar Soyadý:";
			cout << yazarsoyadi << endl;
			cout << "Kitabýn Konusu:";
			cout << konu << endl;
			cout << "Kitabýn Türü:";
			cout << tur << endl;
			cout << "Kitabýn Sayfa Sayýsý:";
			cout << sayfasayisi << endl;
			cout << endl;
			cout << " + Kitap kaydý silme iþleminiz tamamlandý." << endl;
		}
		//isbn ve ISBN'nin farklý olmasý durumunda Kitaplar dosyasýnda deðiþiklik olmamasýný saðlar.
		else
		{
			DosyaYaz << ISBN << " " << kitapadi << " " << yazaradi << " " << yazarsoyadi << " " << konu << " " << tur << " " << sayfasayisi << "\n";
		}
	}
	DosyaYaz.close();
	DosyaOku.close();
	remove("Kitaplar.txt");
	int sonKitaplardosya = rename("Kitaplar.tmp", "Kitaplar.txt");
}

void secim9(string ISBN, string kitapadi, string yazaradi, string yazarsoyadi, string konu, string tur, string sayfasayisi)
{
	ekransilme();
	string isbn;
	motif();
	cout << endl;
	cout << "          KÝTAP KAYDI DÜZENLEME" << endl;
	motif();
	cout << endl << endl;
	ifstream DosyaOku("Kitaplar.txt");
	ofstream DosyaYaz("Kitaplar.tmp");
	cout << "Kaydý düzenlenecek kitabýn ISBN:";
	cin >> isbn;
	int sayac = 0;
	//Kitaplar dosyasý baþtan sona okunur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> ISBN >> kitapadi >> yazaradi >> yazarsoyadi >> konu >> tur >> sayfasayisi;
		//isbn ve ISBN'nin ayný olup olmadýðý kontrol edilir. Ayný olmasý durumunda önce kitap bilgileri ekrana yazýlýr sonra güncellenmiþ bilgiler istenir.
		if (isbn == ISBN)
		{
			cout << endl;
			motif2();
			cout << " Kitap Bilgileri ";
			motif2();
			cout << endl << endl;
			cout << "ISBN.................:" << ISBN << endl;
			cout << "Kitap Adý............:" << kitapadi << endl;
			cout << "Yazar Adý............:" << yazaradi << endl;
			cout << "Yazar Soyadý.........:" << yazarsoyadi << endl;
			cout << "Kitabýn Konusu.......:" << konu << endl;
			cout << "Kitabýn Türü.........:" << tur << endl;
			cout << "Kitabýn Sayfa Sayisi.:" << sayfasayisi << endl << endl;
			cout << "Kitabýn güncellenmiþ bilgilerini giriniz." << endl;
			cout << "\n Kitap ISBN...........:";
			cin >> ISBN;
			cout << "\n Kitap Adý............:";
			cin >> kitapadi;
			cout << "\n Yazar Adý............:";
			cin >> yazaradi;
			cout << "\n Yazar Soyadý.........:";
			cin >> yazarsoyadi;
			cout << "\n Kitabýn Konusu.......:";
			cin >> konu;
			cout << "\n Kitabýn Türü.........:";
			cin >> tur;
			cout << "\n Kitabýn Sayfa Sayisi.:";
			cin >> sayfasayisi;
			cout << endl;
			cout << "\n  + Kitap bilgileriniz güncellendi.";
			cout << endl;
			DosyaYaz << "\n" << ISBN << " " << kitapadi << " " << yazaradi << " " << yazarsoyadi << " " << konu << " " << tur << " " << sayfasayisi;//Düzenlenen dosya bilgileri yazdýrýlýr.
			sayac = 1;
		}
		//isbn ve ISBN'nin faklý olmasý durumunda dosyadaki kitap bilgilerinin deðiþmeden kalmasý saðlanýr.
		else
		{
			DosyaYaz << "\n" << ISBN << " " << kitapadi << " " << yazaradi << " " << yazarsoyadi << " " << konu << " " << tur << " " << sayfasayisi;
		}
	}
	//ISBN ve isbn'nin dosyadaki hiçbir kitapla eþleþmemesi durumunda çalýþýr. Kitap kaydý bulunamadýðý bilgisi bastýrýlýr.
	if (sayac == 0)
	{
		cout << " + Kitap kaydý bulunamadý." << endl;
	}
	DosyaYaz.close();
	DosyaOku.close();
	remove("Kitaplar.txt");
	int sonKitaplardosya = rename("Kitaplar.tmp", "Kitaplar.txt");
}