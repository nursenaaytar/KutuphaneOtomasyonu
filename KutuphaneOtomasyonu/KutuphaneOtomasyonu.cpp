/****************************************************************************
**				            	SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**				          B�LG�SAYAR M�HEND�SL��� B�L�M�
**				           PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI�...: 1.PROJE
**				��RENC� ADI......: NUR SENA AYTAR
**				��RENC� NUMARASI.: B191210075
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
	//Okuyucu kay�t i�lemindeki gerekli bilgileri kullan�c�ya sorarak kaydeder, kullac�dan e yan�t�n� almas� durumunda okuyucu kay�t i�lemine devam eder.
	do
	{
		cout << "\n Okuyucu TC No.......................: ";
		cin >> tcno;
		//Girilen tcno'nun hane say�s� kontrol edilir. E�er do�ru ise kayda devam edilir.
		if (tcno.length() == 11)
		{
			cout << "\n Okuyucu Ad�.........................: " << endl;
			cout << "(birinciad_ikiciad �eklinde giriniz.):";
			cin >> adi;
			cout << "\n Okuyucu Soyad�......................: ";
			cin >> soyadi;
			cout << "\n Okuyucu �ye No......................: ";
			cin >> uyeno;
			cout << "\n Okuyucu Tel No......................: ";
			cin >> telefon;
			cout << "\n Okuyucu Do�um Tarihi................: " << endl;
			cout << "(GG/AA/YYYY �eklinde giriniz.).......:";
			cin >> dogumtarihi;
			cout << "\n Okuyucu G�revi......................: ";
			cin >> gorevi;
			cout << "\n Okuyucunun Alabilece�i Kitap Sayisi.: ";
			cin >> alabilecegikitapsayisi;
			DosyaYaz << "\n" << tcno << " " << adi << " " << soyadi << " " << uyeno << " " << telefon << " " << dogumtarihi << " " << gorevi << " " << alabilecegikitapsayisi;
			cout << endl;
			cout << " + Okuyucu Kay�t ��lemi Tamamland�." << endl;
			cout << endl;
		}
		//Girilen tcno'nun hane say�s�n�n hatal� olmas� durumunda �al���r. Girilen tcno'nun hatal� oldu�u bilgisini yazd�r�r, sistemden ��kar.
		else
		{
			cout << endl;
			cout << " + Girdi�iniz TC numaras�n�n hane say�s�n� hatal�d�r." << endl;
			DosyaYaz.close();
			cout << endl;
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "Sistemden ��k�� saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
			cout << endl << endl;
			exit(0);
		}
		cout << "Okuyucu Kay�t Ekleme i�lemine devam edecek misiniz......?(e/h) " << endl;
		cin >> cevap;
	} while (cevap == 'e');
	//Cevab�n h olmas� durumunda i�lemi bitirir ve okuyucu dosyas�n� kapat�r.
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
	cout << "          OKUYUCU KAYDI S�LME" << endl;
	motif();
	cout << endl << endl;
	string tc;
	cout << "Kayd� silinecek okuyucunun TC numaras�n� giriniz :";
	cin >> tc;
	ifstream DosyaOku("okuyucu.txt");
	ofstream DosyaYaz("okuyucu.tmp");
	//Okuyucu dosyas�n� ba�tan sana okutur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> tcno >> adi >> soyadi >> uyeno >> telefon >> dogumtarihi >> gorevi >> alabilecegikitapsayisi;
		//Dosya okuma i�lemini durdurur.
		if (DosyaOku.eof()) break;
		//Kullan�c�n�n girdi�i tc ile tcno'nun ayn� olup olmad���n� kontrol eder. Ayn� ise okuyucu kayd�ndaki bilgileri yazd�r�r.
		if (tc == tcno)
		{
			motif2();
			cout << "\n     Okuyucu Bilgileri \n";
			motif2();
			cout << endl;
			cout << "Okuyucu TC No....................:";
			cout << tcno << endl;
			cout << "Okuyucu Ad�......................:";
			cout << adi << endl;
			cout << "Okuyucu Soyad�...................:";
			cout << soyadi << endl;
			cout << "Okuyucu �ye No...................:";
			cout << uyeno << endl;
			cout << "Okuyucu Tel No...................:";
			cout << telefon << endl;
			cout << "Okuyucu Do�um Tarihi.............:";
			cout << dogumtarihi << endl;
			cout << "Okuyucu G�revi...................:";
			cout << gorevi << endl;
			cout << "Okuyucu Alabilece�i Kitap Say�s�.:";
			cout << alabilecegikitapsayisi << endl;
			cout << endl << endl;
			cout << " + Okuyucu kayd� silindi.";
		}
		//tc ile tcno'nun farkl� olmas� durumunda okuyucu dosyas�n�n sabit kalmas�n� sa�lar.
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
	//Okuyucu kayd�n�n silinmesi durumunda kayd� silinen okuyucunun �d�n� ald��� Kitaplar� geri al�r. Odunc dosyas�n� ba�tan sona okutur.
	while (!(DosyaOku0.eof()))
	{
		DosyaOku0 >> tcno >> ISBN >> odunctarihi >> donustarihi;
		//Dosya okuma i�lemini durdurur.
		if (DosyaOku0.eof()) break;
		//tc ile tcno'nun ayn� olup olmad���n� kontrol eder. Ayn� olmas� durumunda �d�n� kitap ve okuyucu bilgilerini bast�r�r.
		if (tc == tcno)
		{
			cout << endl << endl;
			motif2();
			cout << "\n �d�n� Kitap - Okuyucu Bilgileri \n";
			motif2();
			cout << endl;
			cout << endl;
			cout << "Okuyucunun TC numaras�.:";
			cout << tcno << endl;
			cout << "ISBN...................:";
			cout << ISBN << endl;
			cout << "�d�n� Tarihi...........:";
			cout << odunctarihi << endl;
			cout << "D�n�� Tarihi...........:";
			cout << donustarihi << endl;
			cout << endl << endl;
			cout << " + Kitap geri d�nd�rme i�lemi tamamland�." << endl;
		}
		//tc ile tcno'nun farkl� olmas� durumunda Odunc dosyas�n�n sabit kalmas�n� sa�lar.
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
	cout << "          K�TAP �D�N� ALMA" << endl;
	motif();
	cout << endl << endl;
	string isbn;
	cout << "�d�n� Al�nmak �stenen Kitap ISBN: ";
	cin >> isbn;
	cout << endl;
	ifstream DosyaOku("Kitaplar.txt");
	ofstream DosyaYaz("Kitaplar.txt", ios::app | ios::in | ios::out);
	ifstream dosyaoku("Odunc.txt");
	int sayac = 0;
	int sayan = 0;
	//Odunc dosyas� ba�tan sona okunur
	while (!dosyaoku.eof())
	{
		dosyaoku >> ISBN >> tcno >> odunctarihi >> donustarihi;
		//Dosya okuma i�lemini durdurur.
		if (DosyaOku.eof()) break;
		//isbn ve ISBN'nin ayn� olup olmad��� kontrol edilir. Ayn� ise kitap �d�n� verilmez ��nk� bu durum kitab�n ba�ka bir okuyucu taraf�ndan �nceden �d�n� al�nd��� anlam�na gelir. Durum bilgisi ekrana yazd�r�l�r ve sistemden ��k�l�r.
		if (ISBN == isbn)
		{
			cout << " + �d�n� almak istedi�iniz kitap ba�ka bir okuyucu taraf�ndan �d�n� al�nm��t�r." << endl << " + �d�n� alma iste�iniz ger�ekle�tirilemedi." << endl << endl;
			DosyaOku.close();
			DosyaYaz.close();
			dosyaoku.close();
			cout << endl;
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "Sistemden ��k�� saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
			cout << endl << endl;
			exit(0);
		}
	}
	//Kitaplar dosyas� ba�tan sona okunur.
	while (!DosyaOku.eof())
	{
		DosyaOku >> ISBN >> kitapadi >> yazaradi >> yazarsoyadi >> konu >> tur >> sayfasayisi;
		//Dosya okuma i�lemini durdurur.
		if (DosyaOku.eof()) break;
		//ISBN ile isbn'nin ayn� olmas� durumunda �al���r. tc'si girilen okuyucunun bilgilerini bast�r�r.
		if (ISBN == isbn)
		{
			motif2();
			cout << "Kitap Bilgileri";
			motif2();
			cout << endl << endl;
			cout << "ISBN:";
			cout << ISBN << endl;
			cout << "Kitap Ad�:";
			cout << kitapadi << endl;
			cout << "Yazar Ad�:";
			cout << yazaradi << endl;
			cout << "Yazar Soyad�:";
			cout << yazarsoyadi << endl;
			cout << "Kitab�n Konusu:";
			cout << konu << endl;
			cout << "Kitab�n T�r�:";
			cout << tur << endl;
			cout << "Kitab�n Sayfa Say�s�:";
			cout << sayfasayisi << endl << endl;
			sayac = 1;
		}
	}
	//ISBN'si girilen kitab�n sisteme kay�tl� olmamas� durumunda �al���r. Kitap kayd� bulunamad���n� yazd�r�r.
	if (sayac == 0)
	{
		cout << endl;
		cout << "Kitap kayd� bulunamamaktad�r." << endl;
		cout << endl;
		time_t now = time(0);
		tm* ltm = localtime(&now);
		cout << "Sistemden ��k�� saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
		cout << endl << endl;
		exit(0);
	}

	cout << "Kitap �d�n� almak istiyor musunuz..?(e/h)" << endl;
	cin >> cevap;
	cout << endl;
	string tc;
	cout << "Okuyucu TC No:";
	cin >> tc;
	ifstream dosyaOku("okuyucu.txt");
	ofstream dosyaYaz("okuyucu.txt", ios::app | ios::in | ios::out);
	//okuyucu dosyas�n� ba�tan sona okur.
	while (!dosyaOku.eof())
	{
		dosyaOku >> tcno >> adi >> soyadi >> uyeno >> telefon >> dogumtarihi >> gorevi >> alabilecegikitapsayisi;
		//Dosya okuma i�lemini durdurur.
		if (dosyaOku.eof()) break;
		//tcno ile tc'nin ayn� olmas� durumunda �al���r. tcno'su girilen okuyucunun bilgilerini bast�r�r.
		if (tcno == tc)
		{
			cout << endl;
			motif2();
			cout << "Okuyucu Bilgileri";
			motif2();
			cout << endl << endl;
			cout << endl;
			cout << "Okuyucu TC No.......................:" << tcno << endl;
			cout << "Okuyucu Ad�.........................:" << adi << endl;
			cout << "Okuyucu Soyad�......................:" << soyadi << endl;
			cout << "Okuyucu �ye No......................:" << uyeno << endl;
			cout << "Okuyucu Tel No......................:" << telefon << endl;
			cout << "Okuyucu Do�um Tarihi................:" << dogumtarihi << endl;
			cout << "Okuyucu G�revi......................:" << gorevi << endl;
			cout << "Okuyucunun Alabilece�i Kitap Say�s�.:" << alabilecegikitapsayisi << endl << endl;
			sayan = 1;
		}
	}
	//tcno'su girilen okuyucununun sisteme kay�tl� olmamas� durumunda �al���r. Okuyucunun kayd�n� yapar.
	if (sayan == 0)
	{
		cout << endl;
		cout << "Okuyucu kayd� bulunamamaktad�r. Okuyucu kay�t i�lemi i�in bilgilerinizi giriniz:" << endl;
		cout << "\n Okuyucu TC No.......................: ";
		cin >> tcno;
		//tcno'nun hane say�s� kontrol edilir. E�er 11'e e�itse okuyucu kayd� yap�l�r.
		if (tcno.length() == 11)
		{
			cout << "\n Okuyucu Ad�.........................: " << endl;
			cout << "(birinciad_ikiciad �eklinde giriniz.):";
			cin >> adi;
			cout << "\n Okuyucu Soyad�......................: ";
			cin >> soyadi;
			cout << "\n Okuyucu �ye No......................: ";
			cin >> uyeno;
			cout << "\n Okuyucu Tel No......................: ";
			cin >> telefon;
			cout << "\n Okuyucu Do�um Tarihi................: " << endl;
			cout << "(GG/AA/YYYY �eklinde giriniz.).......:";
			cin >> dogumtarihi;
			cout << "\n Okuyucu G�revi......................: ";
			cin >> gorevi;
			cout << "\n Okuyucunun Alabilece�i Kitap Sayisi.: ";
			cin >> alabilecegikitapsayisi;
			cout << endl;
			dosyaYaz << "\n" << tcno << " " << adi << " " << soyadi << " " << uyeno << " " << telefon << " " << dogumtarihi << " " << gorevi << " " << alabilecegikitapsayisi;
			cout << endl;
			cout << " + Okuyucu Kay�t ��lemi Tamamland�." << endl;
			cout << endl;
		}
		//Kayd� yap�lacak okuyucunun TC numaras�n�n hane say�s�n�n yanl�� girilmesi sonucu �al���r. Hatal� oldu�u bilgisi ekrana yazd�r�l�r, sistemden ��k�� saati yazd�r�l�r ve sistemden ��k�l�r.
		else
		{
			cout << endl;
			cout << " + Girdi�iniz TC numaras�n�n hane say�s�n� hatal�d�r. Okuyucu kayd�n�z yap�lamad�." << endl;
			DosyaYaz.close();
			cout << endl;
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "Sistemden ��k�� saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
			cout << endl << endl;
			exit(0);
		}
	}
	string sayma;
	//Okuyucunun kitap almak isteyip istememe sorusuna e yan�t� vermesi durumunda �al���r. Okuyucu girdi�i bilgilere sahip kitab� �d�n� alm�� olur.
	if (cevap == 'e')
	{
		DosyaOku.close();
		DosyaYaz.close();
		dosyaOku.close();
		dosyaYaz.close();
		ofstream DosyaYaz;
		DosyaYaz.open("Odunc.txt", ios::app);
		motif2();
		cout << " Kitap �d�n� Alma ";
		motif2();
		cout << endl;
		cout << "\n Okuyucu TC No...........:";
		cin >> tcno;
		cout << "\n ISBN...................:";
		cin >> ISBN;
		cout << "\n �d�n� Tarihi...........:";
		cin >> odunctarihi;
		cout << "\n D�nu� Tarihi...........:";
		cin >> donustarihi;
		DosyaYaz << ISBN << " " << tcno << " " << odunctarihi << " " << donustarihi << "\n";
		cout << endl;
		cout << " + Kitap �d�n� Alma ��leminiz Tamamland�." << endl;
		DosyaYaz.close();
	}
	//Kayd� �nceden yap�lm�� okuyucunun kitap �d�n� almas� durumunda �al���r.
	else
	{
		cout << " + Kitap �d�n� Alma ��leminiz Tamamland�." << endl;
	}
}

void secim6(string, string, string, string);

void secim7(string ISBN, string kitapadi, string yazaradi, string yazarsoyadi, string konu, string tur, string sayfasayisi, char cevap = 'e')
{
	ekransilme();
	motif();
	cout << endl;
	cout << "          K�TAP KAYDI EKLEME" << endl;
	motif();
	cout << endl;
	ofstream DosyaYaz;
	DosyaYaz.open("Kitaplar.txt", ios::app | ios::in | ios::out);
	//Kitap kayd� i�in gerekli bilgileri sorar ve ald��� yan�tlar� kaydeder. Kay�t yapmaya devap edecek misiniz sorusuna h yan�t� verilene kadar kitap kayd� yapmaya devam eder.
	do
	{
		cout << endl;
		cout << "L�tefen kitap bilgileriniz giriniz." << endl;
		cout << endl;
		cout << "\n ISBN.................:";
		cin >> ISBN;
		//Girilen ISBN'nin hane say�s�n� kontrol eder. Do�ru ise kayda devam eder.
		if (ISBN.length() == 13)
		{
			cout << "\n Kitap �smi...........:" << endl;
			cout << "(birinciad_ikinciad �eklinde giriniz):";
			cin >> kitapadi;
			cout << "\n Yazar Ad�............:" << endl;
			cout << "(birinciad_ikinciad �eklinde giriniz):";
			cin >> yazaradi;
			cout << "\n Yazar Soyad�.........:";
			cin >> yazarsoyadi;
			cout << "\n Kitap Konusu.........:";
			cout << "(birincikelime_ikincikelime �eklinde giriniz):";
			cin >> konu;
			cout << "\n Kitap T�r�...........:";
			cin >> tur;
			cout << "\n Kitab�n Sayfa Say�s�.:";
			cin >> sayfasayisi;
			DosyaYaz << "\n" << ISBN << " " << kitapadi << " " << yazaradi << " " << yazarsoyadi << " " << konu << " " << tur << " " << sayfasayisi;
			cout << endl;
			cout << " + Kitap  kayd� tamamland�." << endl;
			cout << endl;
		}
		//Girilen ISBN'nin hane say�s� hatal� ise hatal� oldu�u bilgisini yazd�r�r, sistemden ��kar.
		else
		{
			cout << endl;
			cout << " + Girdi�iniz kitap ISBN hane say�s� hatal�d�r." << endl;
			DosyaYaz.close();
			cout << endl;
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "Sistemden ��k�� saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
			cout << endl << endl;
			exit(0);
		}
		cout << "Kitap kayd� yapmaya devam edecek misiniz ?(e/h) " << endl;
		cin >> cevap;
	} while (cevap == 'e');
	//h cevab�n� almas� �zerine kayd� sonland�r�r ve Kitaplar dosyas�n� kapat�r. 
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

	cout << "---------G�R��---------" << endl;
	cout << "\n Kullanici Ad�.: ";
	cin >> kullanici;
	cout << "\n �ifre.........: ";
	cin >> sifresi;
	int sayac = 0;

	ifstream DosyaOku("kullan�c�lar.txt");
	//kullan�c�lar dosyas� ba�tan sona okunur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> kullaniciadi >> sifre;
		//girilen kullan�c� ad� ve �ifresininin sistemdeki kullan�c� ad� ve �ifrelerine e�it olmas� durumunda sayac de�erini 1'e e�itler.
		if (kullanici == kullaniciadi && sifresi == sifre)
		{
			sayac = 1;
		}
	}
	//Kullan�c� kayd�n�n bulundu�u anlam�na gelir ve men� a��l�r, i�lemler yap�labilir.
	if (sayac == 1)
	{
		int secim, i = 1;
		cout << endl;
		time_t now = time(0);
		tm* ltm = localtime(&now);
		cout << "Sisteme giri� saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
		cout << "Sisteme giri� tarihiniz : " << ltm->tm_mday << "." << 1 + ltm->tm_mon << "." << 1900 + ltm->tm_year << endl;
		cout << endl << endl;
		//Men� a��l�r ve kullan�c�dan se�im yap�lmas� istenir. Se�imlerin temsil etti�i say�lar girilene kadar se�im yap�lmaya devam edilir.
		do
		{
			cout << "MEN�" << endl;
			cout << "1 - Okuyucu Kayd�" << endl;
			cout << "2 - Okuyucu Kayd� G�ncelleme" << endl;
			cout << "3 - Okuyucu Kayd� Silme" << endl;
			cout << "4 - Okuyucu �zerindeki Kitaplar Listesi" << endl;
			cout << "5 - Okuyucu Kitap �d�n� Alma" << endl;
			cout << "6 - Okuyucu Kitap Geri D�nd�rme" << endl;
			cout << "7 - Kitap Ekleme" << endl;
			cout << "8 - Kitap Silme" << endl;
			cout << "9 - Kitap D�zeltme" << endl;
			cout << "10- ��k��" << endl;
			cout << endl << endl;
			cout << "Yapmak istedi�iniz i�lemin numaras�n� giriniz:";
			cin >> secim;
			cout << endl << endl;
			alabilecegikitapsayisi = 0;
			secimler(secim, tcno, adi, soyadi, uyeno, telefon, dogumtarihi, gorevi, alabilecegikitapsayisi, cevap, ISBN, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi, odunctarihi, donustarihi);
			cout << endl;
			time_t now = time(0);
			tm* ltm = localtime(&now);
			cout << "Sistemden ��k�� saatiniz  : " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
			cout << endl << endl;
			exit(0);
		} while (secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9 && secim != 10);
	}
	//Sayac�n 1'den farkl� olmas� durumunda �al���r. Kullan�c� kayd�n�n bulunmad��� anlam�na gelir ve hatal� giri� yap�ld��� bilgisini ekrana bast�r�r.
	else
	{
		cout << endl;
		cout << " ! Hatal� giri� yapt�n�z.";
	}
	DosyaOku.close();
}

void motif()
{
	// char(166) karakterini 51 kere ekrana bast�r�r.
	for (int i = 0; i <= 50; i++)
	{
		cout << char(166);
	}
}

void motif2()
{
	//char(176) karakterini 19 kere ekrana bast�r�r.
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
	//Okuyucu kay�t i�leminin se�ilmesi durumunda i�lemleri ger�ekle�tirir. �stenilen i�lem ger�ekle�tirilir.
	if (secim == 1)
	{
		secim1(tcno, adi, soyadi, uyeno, telefon, dogumtarihi, gorevi, alabilecegikitapsayisi, cevap = 'e');
	}
	//Okuyucu Kay�t G�ncelleme i�leminin se�ilmesi durumunda i�lemleri ger�ekle�tirir.	 
	if (secim == 2)
	{
		//Cevap h olana kadar okuyucu kayd� g�ncellemeye devam eder.		
		do
		{
			secim2(tcno, adi, soyadi, uyeno, telefon, dogumtarihi, gorevi, alabilecegikitapsayisi, cevap = 'e');
			cout << endl;
			cout << "Ba�ka okuyucu kayd� g�ncellemek istiyor musunuz? (e/h)";
			cin >> cevap;
		} while (cevap != 'h');
	}
	//Okuyucu kay�t silme isleminin se�ilmesi durumunda i�lemlerini ger�ekle�tirir.
	if (secim == 3)
	{
		//Cevap h olana kadar okuyucu kayd� silmeye devam eder.	
		do
		{
			secim3(tcno, adi, soyadi, uyeno, telefon, dogumtarihi, gorevi, alabilecegikitapsayisi, cevap = 'e', ISBN, odunctarihi, donustarihi);
			cout << endl;
			cout << "Ba�ka okuyucu kayd� silmek istiyor musunuz? (e/h)";
			cin >> cevap;
		} while (cevap != 'h');

	}
	//Okuyucu �zerindeki Kitaplar listesinin g�sterilmesi i�in 4'e bas�lmas� durumunda i�lemlerini ger�ekle�tirir.
	if (secim == 4)
	{
		secim4(tcno, ISBN, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi, odunctarihi, donustarihi);
	}
	//Kitap �d�n� alma i�lemi se�iminin yap�lmas� durumunda �al���r.
	if (secim == 5)
	{
		secim5(tcno, adi, soyadi, uyeno, telefon, dogumtarihi, gorevi, alabilecegikitapsayisi, ISBN, donustarihi, odunctarihi, cevap, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi);
	}
	//Kitap Geri d�nd�rme i�lemi yapmak i�in 6'ya bas�l�rsa �al���r.  �stenilen i�lem ger�ekle�tirilir.
	if (secim == 6)
	{
		secim6(tcno, ISBN, odunctarihi, donustarihi);
	}
	//Kitap Ekleme i�lemi yapmak i�in 7'ye bas�l�rsa �al���r.  �stenilen i�lem ger�ekle�tirilir.
	if (secim == 7)
	{
		secim7(ISBN, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi, cevap = 'e');
	}
	// Kitap kayd� silme i�lemi yapmak i�in 8'e bas�lmas� durumunda �al���r.  �stenilen i�lem ger�ekle�tirilir.
	if (secim == 8)
	{
		//Cevap h olana kadar kitap kayd� silmeye devam eder.
		do
		{
			secim8(ISBN, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi);
			cout << endl;
			cout << "Ba�ka kitap kayd� silmek istiyor musunuz? (e/h)";
			cin >> cevap;
		} while (cevap != 'h');
	}
	//Kitap Kayd� D�zenleme i�lemi yapmak i�in 9'a bas�lmas� durumunda �al���r. �stenilen i�lem ger�ekle�tirilir.
	if (secim == 9)
	{
		//Cevap h olana kadar kitap kayd� d�zenlemeye devam eder.
		do
		{
			secim9(ISBN, kitapadi, yazaradi, yazarsoyadi, konu, tur, sayfasayisi);
			cout << endl;
			cout << "Ba�ka kitap kayd� d�zenlemek istiyor musunuz? (e/h)";
			cin >> cevap;
		} while (cevap != 'h');

	}
	//��k�� yap�lmak amac� ile 10'a bas�lmas� durumunda �al���r. ��k�� i�lemi ger�ekle�tirilir.
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
	cout << "          OKUYUCU KAYDI G�NCELLEME" << endl;
	motif();
	cout << endl;
	ifstream DosyaOku("okuyucu.txt");
	ofstream DosyaYaz("okuyucu.tmp");
	cout << endl;
	cout << "Kayd� g�ncellenecek okuyucunun TC no...:";
	cin >> tc;
	int sayac = 0;
	//Okuyucu dosyas�n� ba�tan sona okur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> tcno >> adi >> soyadi >> uyeno >> telefon >> dogumtarihi >> gorevi >> alabilecegikitapsayisi;
		//Girilen tc ile tcno'nun ayn� olup olmad���n� kontrol eder. Ayn� olmas� durumunda kayd� g�cellemek i�in kulan�c�ya bilgiler sorarak cevap al�r. Yeni bilgiler ile okuyucu dosyas�nda g�ncelleme yapar.
		if (tc == tcno)
		{
			cout << endl;
			motif2();
			cout << "Okuyucu Bilgileri";
			motif2();
			cout << endl;
			cout << "Okuyucu TC No.......................:" << tcno << endl;
			cout << "Okuyucu Ad�.........................:" << adi << endl;
			cout << "Okuyucu Soyad�......................:" << soyadi << endl;
			cout << "Okuyucu �ye No......................:" << uyeno << endl;
			cout << "Okuyucu Tel No......................:" << telefon << endl;
			cout << "Okuyucu Do�um Tarihi................:" << dogumtarihi << endl;
			cout << "Okuyucu G�revi......................:" << gorevi << endl;
			cout << "Okuyucunun Alabilece�i Kitap Say�s�.:" << alabilecegikitapsayisi << endl << endl;
			cout << "Okuyucunun Bilgilerini G�ncelleyiniz:" << endl;
			cout << "\n Okuyucu TC No.......................: ";
			cin >> tcno;
			cout << "\n Okuyucu Ad�.........................: " << endl;
			cout << "(birinciad_ikiciad �eklinde giriniz.):";
			cin >> adi;
			cout << "\n Okuyucu Soyad�......................: ";
			cin >> soyadi;
			cout << "\n Okuyucu �ye No......................: ";
			cin >> uyeno;
			cout << "\n Okuyucu Tel No......................: ";
			cin >> telefon;
			cout << "\n Okuyucu Do�um Tarihi................: " << endl;
			cout << "(GG/AA/YYYY �eklinde giriniz.).......:";
			cin >> dogumtarihi;
			cout << "\n Okuyucu G�revi......................: ";
			cin >> gorevi;
			cout << "\n Okuyucunun Alabilece�i Kitap Sayisi.: ";
			cin >> alabilecegikitapsayisi;
			cout << endl;
			cout << " + Okuyucu Kayd� G�ncelleme ��lemi Tamamland�." << endl;
			DosyaYaz << "\n" << tcno << " " << adi << " " << soyadi << " " << uyeno << " " << telefon << " " << dogumtarihi << " " << gorevi << " " << alabilecegikitapsayisi;
			sayac = 1;
		}
		//Girilen tc ile tcno'nun ayn� olmamas� durumunda okuyucu dosyas�nda de�i�iklik olmamas�n� sa�lar.
		else
		{
			DosyaYaz << "\n" << tcno << " " << adi << " " << soyadi << " " << uyeno << " " << telefon << " " << dogumtarihi << " " << gorevi << " " << alabilecegikitapsayisi;
		}
	}
	//Girilen tc'nin tcno ile farkl� olmas� durumunda okuyucu kayd�n�n bulunmad���n� ekrana yazd�r�r.
	if (sayac == 0)
	{
		cout << "Okuyucu kayd� bulunamad�." << endl;
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
	//Odunc dosyas�n� ba�tan sona okur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> ISBN >> tcno >> odunctarihi >> donustarihi;
		//Dosya okuma i�lemini durdurur.
		if (DosyaOku.eof()) break;
		//tc ile tcno'nun ayn� olmas� durumunda okuyucunun �d�n� ald��� Kitaplar� liste �eklinde bast�r�r.
		if (tcno == tc)
		{
			motif();
			cout << endl;
			cout << "          OKUYUCU �ZER�NDEK� K�TAP L�STES�" << endl;
			motif();
			cout << endl << endl;
			cout << "Okuyucu TC No....:" << tcno << endl;
			cout << "ISBN.............:" << ISBN << endl;
			cout << "�d�n� Tarihi.....:" << odunctarihi << endl;
			cout << "D�n�� Tarihi.....:" << donustarihi << endl;
			cout << endl << endl;
			string isbn;
			isbn = ISBN;
			ifstream dosyaoku("Kitaplar.txt");
			//Kitaplar dosyas�n� ba�tan sona okur. isbn ve ISBN'nin ayn� olmas� durumunda okuyucunun �d�n� ald��� Kitaplar�n �zelliklerini bast�r�r.
			while (!(dosyaoku.eof()))
			{
				dosyaoku >> ISBN >> kitapadi >> yazaradi >> yazarsoyadi >> konu >> tur >> sayfasayisi;
				//Dosya okuma i�lemini durdurur.
				if (dosyaoku.eof()) break;
				//isbn ile ISBN'nin ayn� olup olmad���n� kontrol eder. Ayn� olmas� durumunda ISBN'si girilen kitab�n �zelliklerini yazd�r�r.
				if (isbn == ISBN)
				{
					motif2();
					cout << "Kitap �zellikleri";
					motif2();
					cout << endl << endl;
					cout << "Kitap Ad�..........:";
					cout << kitapadi << endl;
					cout << "Yazar Ad�..........:";
					cout << yazaradi << endl;
					cout << "Yazar Soyad�.......:";
					cout << yazarsoyadi << endl;
					cout << "Kitap Konusu.......:";
					cout << konu << endl;
					cout << "Kitap T�r�.........:";
					cout << tur << endl;
					cout << "Kitap Sayfa Say�s�.:";
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
	cout << "          K�TAP GER� G�NDERME" << endl;
	motif();
	cout << endl << endl;
	string isbn;
	cout << "�d�n� geri g�nderilmek istenen kitap ISBN:";
	cin >> isbn;
	ifstream DosyaOku("Odunc.txt");
	ofstream DosyaYaz("Odunc.tmp");
	//Odunc dosyas� ba�tan sona okunur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> ISBN >> tcno >> odunctarihi >> donustarihi;
		//Dosya okuma i�lemini durdurur.
		if (DosyaOku.eof()) break;
		//tc ile tcno'nun ayn� olup olmad��� kontrol edilir. Ayn� ise �nce �d�n� kitap-okuyucu bilgileri bast�r�l�r, sonra kitap geri d�nd�rme i�lemii tamamlan�r.
		if (isbn == ISBN)
		{
			cout << endl;
			motif2();
			cout << "\n �d�n� Kitap - Okuyucu Bilgileri \n";
			motif2();
			cout << endl << endl;
			cout << "Okuyucunun TC numaras�.:";
			cout << tcno << endl;
			cout << "ISBN...................:";
			cout << ISBN << endl;
			cout << "�d�n� Tarihi...........:";
			cout << odunctarihi << endl;
			cout << "D�n�� Tarihi...........:";
			cout << donustarihi << endl;
			cout << endl;
			cout << " + Kitap geri d�nd�rme i�lemi tamamland�." << endl;
		}
		//tc ile tcno'nun farkl� olmas� durumundaki bilgilerin de�i�tirilmemesini sa�lar.
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
	cout << "          K�TAP KAYDI S�LME" << endl;
	motif();
	cout << endl << endl;
	string isbn;
	cout << "Kayd� Silinecek Kitab�n ISBN:";
	cin >> isbn;
	ifstream DosyaOku("Kitaplar.txt");
	ofstream DosyaYaz("Kitaplar.tmp");
	//Kitaplar dosyas� ba�tan sona kadar okunur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> ISBN >> kitapadi >> yazaradi >> yazarsoyadi >> konu >> tur >> sayfasayisi;
		//Dosya okuma i�lemini durdurur.
		if (DosyaOku.eof()) break;
		//isbn ve ISBN'nin ayn� olup olmad��� kontrol edilir. Ayn� olmas� durumunda kitab�n Kitaplar dosyas�ndaki bilgileri bast�r�l�r. Sonras�nda kitap kayd� silinir.
		if (isbn == ISBN)
		{
			cout << endl;
			motif2();
			cout << "\n Kitap Bilgileri \n";
			motif2();
			cout << endl;
			cout << "ISBN:";
			cout << ISBN << endl;
			cout << "Kitap Ad�:";
			cout << kitapadi << endl;
			cout << "Yazar Ad�:";
			cout << yazaradi << endl;
			cout << "Yazar Soyad�:";
			cout << yazarsoyadi << endl;
			cout << "Kitab�n Konusu:";
			cout << konu << endl;
			cout << "Kitab�n T�r�:";
			cout << tur << endl;
			cout << "Kitab�n Sayfa Say�s�:";
			cout << sayfasayisi << endl;
			cout << endl;
			cout << " + Kitap kayd� silme i�leminiz tamamland�." << endl;
		}
		//isbn ve ISBN'nin farkl� olmas� durumunda Kitaplar dosyas�nda de�i�iklik olmamas�n� sa�lar.
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
	cout << "          K�TAP KAYDI D�ZENLEME" << endl;
	motif();
	cout << endl << endl;
	ifstream DosyaOku("Kitaplar.txt");
	ofstream DosyaYaz("Kitaplar.tmp");
	cout << "Kayd� d�zenlenecek kitab�n ISBN:";
	cin >> isbn;
	int sayac = 0;
	//Kitaplar dosyas� ba�tan sona okunur.
	while (!(DosyaOku.eof()))
	{
		DosyaOku >> ISBN >> kitapadi >> yazaradi >> yazarsoyadi >> konu >> tur >> sayfasayisi;
		//isbn ve ISBN'nin ayn� olup olmad��� kontrol edilir. Ayn� olmas� durumunda �nce kitap bilgileri ekrana yaz�l�r sonra g�ncellenmi� bilgiler istenir.
		if (isbn == ISBN)
		{
			cout << endl;
			motif2();
			cout << " Kitap Bilgileri ";
			motif2();
			cout << endl << endl;
			cout << "ISBN.................:" << ISBN << endl;
			cout << "Kitap Ad�............:" << kitapadi << endl;
			cout << "Yazar Ad�............:" << yazaradi << endl;
			cout << "Yazar Soyad�.........:" << yazarsoyadi << endl;
			cout << "Kitab�n Konusu.......:" << konu << endl;
			cout << "Kitab�n T�r�.........:" << tur << endl;
			cout << "Kitab�n Sayfa Sayisi.:" << sayfasayisi << endl << endl;
			cout << "Kitab�n g�ncellenmi� bilgilerini giriniz." << endl;
			cout << "\n Kitap ISBN...........:";
			cin >> ISBN;
			cout << "\n Kitap Ad�............:";
			cin >> kitapadi;
			cout << "\n Yazar Ad�............:";
			cin >> yazaradi;
			cout << "\n Yazar Soyad�.........:";
			cin >> yazarsoyadi;
			cout << "\n Kitab�n Konusu.......:";
			cin >> konu;
			cout << "\n Kitab�n T�r�.........:";
			cin >> tur;
			cout << "\n Kitab�n Sayfa Sayisi.:";
			cin >> sayfasayisi;
			cout << endl;
			cout << "\n  + Kitap bilgileriniz g�ncellendi.";
			cout << endl;
			DosyaYaz << "\n" << ISBN << " " << kitapadi << " " << yazaradi << " " << yazarsoyadi << " " << konu << " " << tur << " " << sayfasayisi;//D�zenlenen dosya bilgileri yazd�r�l�r.
			sayac = 1;
		}
		//isbn ve ISBN'nin fakl� olmas� durumunda dosyadaki kitap bilgilerinin de�i�meden kalmas� sa�lan�r.
		else
		{
			DosyaYaz << "\n" << ISBN << " " << kitapadi << " " << yazaradi << " " << yazarsoyadi << " " << konu << " " << tur << " " << sayfasayisi;
		}
	}
	//ISBN ve isbn'nin dosyadaki hi�bir kitapla e�le�memesi durumunda �al���r. Kitap kayd� bulunamad��� bilgisi bast�r�l�r.
	if (sayac == 0)
	{
		cout << " + Kitap kayd� bulunamad�." << endl;
	}
	DosyaYaz.close();
	DosyaOku.close();
	remove("Kitaplar.txt");
	int sonKitaplardosya = rename("Kitaplar.tmp", "Kitaplar.txt");
}