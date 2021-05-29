/****************************************************************
**									SAKARYA UNIVERSITESI
**						BILGISAYAR VE BILISIM BILIMLERI FAKULTESI
**							BILGISAYAR MUHENDISLIGI BOLUMU
**								PROGRAMLAMAYA GIRIS DERSI
**
**					ODEV NUMARASI: 1
**					OGRENCI ADI: IBRAHIM MERT ASLAY
**					OGRENCI NUMARASI: B191210043
**					DERS GRUBU: A
****************************************************************
*/

#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;

struct urunbilgileri {
	string urunAdi;
	string urunNo;
	string birim;
	string birimFiyati;
	string markasi;
}urun;

struct projebilgileri {
	string projeAdi;
	string projeNo;
	string yurutucuFirma;
	string projeSorumlusu;
	string projeKontroloru;
}proje;

struct hakedisIslemleri {
	string hakedisTarih;
	string projeNo;
	string kullanilanUrun;
	string kullanilanUrunAdedi;
	string kullanilanUrunFiyati;
}hakedis;

int main()
{
	int secim;
	do
	{
		system("cls");
		cout << "1-URUN ISLEMLERI" << endl;
		cout << "2-PROJE ISLEMLERI" << endl;
		cout << "3-HAKEDIS ISLEMLERI" << endl;
		cout << "0-CIKIS" << endl;
		cout << endl << "Seciminizi giriniz: ";
		cin >> secim;

		if (secim == 0)
		{
			cout << "Programdan cikiliyor." << endl;
		}
	
		else if (secim == 1)
		{
			int secim2;
			system("cls");
			cout << "1-Urun Ekle" << endl;
			cout << "2-Urun Sil" << endl;
			cout << "3-Urun Ara" << endl;
			cout << "4-Tum Urunleri Raporla" << endl;
			cout << "0-Bir Onceki Menuye Don" << endl;
			cout << "Seciminizi giriniz:";
			cin >> secim2;

		
			if (secim2 == 1)
			{
				system("cls");
				string gecici;
				ofstream UrunEkle("Urunler.txt", ios::app);
				cout << "Eklenecek urunun adini giriniz: ";
				cin >> urun.urunAdi;
				cout << "Eklenecek urunun numarasini giriniz: ";
				cin >> gecici;
				ifstream UrunEkle2("Urunler.txt");
				while (!(UrunEkle2.eof()))
				{
					UrunEkle2 >> urun.urunAdi >> urun.urunNo >> urun.birim >> urun.birimFiyati >> urun.markasi;
					if (urun.urunNo == gecici)
					{
						cout << "Ayni urun no'su tekrar kullanilamaz." << endl;
						exit(1);
					}
				}
				cout << "Eklenecek urun kac birim, giriniz: ";
				cin >> urun.birim;
				cout << "Eklenecek urunun birim fiyatini giriniz: ";
				cin >> urun.birimFiyati;
				cout << "Eklenecek urunun markasini giriniz: ";
				cin >> urun.markasi;
				UrunEkle << endl << urun.urunAdi << endl << gecici << endl << urun.birim << endl << urun.birimFiyati << endl << urun.markasi;
				cout << "Urun eklenmistir." << endl;
				cout << "Bir tusa basin.";
				system("pause");
				UrunEkle.close();
			}
			
			else if (secim2 == 2)
			{
				system("cls");
				cout << "Silinecek urunun numarasini giriniz: ";
				string silinecek;
				cin >> silinecek;
				ifstream UrunEkle("Urunler.txt");
				ofstream UrunEkle2("Urunler2.txt");
				while (!(UrunEkle.eof()))
				{
					UrunEkle >> urun.urunAdi >> urun.urunNo >> urun.birim >> urun.birimFiyati >> urun.markasi;
					if (silinecek == urun.urunNo)
					{
						cout << "Urun silinmistir. " << endl;
						system("pause");
					}
					else
					{
						UrunEkle2 << endl << urun.urunAdi << endl << urun.urunNo << endl << urun.birim << endl << urun.birimFiyati << endl << urun.markasi;
					}
				}
				UrunEkle.close();
				UrunEkle2.close();
				remove("Urunler.txt");
				rename("Urunler2.txt", "Urunler.txt");
				exit(1);
			}
			
			else if (secim2 == 3)
			{
				system("cls");
				string aranacak_urun;
				cout << "Aranacak urunun numarasini giriniz: ";
				cin >> aranacak_urun;
				ifstream UrunEkle("Urunler.txt");
				while (!(UrunEkle.eof()))
				{
					UrunEkle >> urun.urunAdi >> urun.urunNo >> urun.birim >> urun.birimFiyati >> urun.markasi;
					if (urun.urunNo == aranacak_urun)
					{
						cout << "Urun adi:" << urun.urunAdi << endl;
						cout << "Urun no:" << urun.urunNo << endl;
						cout << "Urun birimi:" << urun.birim << endl;
						cout << "Urun birim fiyati:" << urun.birimFiyati << endl;
						cout << "Urun markasi:" << urun.markasi << endl;
						cout << "---------------------------" << endl;
					}
				}
				system("pause");
			}
		
			else if (secim2 == 0)
			{

			}

			else if (secim2 == 4)
			{
				system("cls");
				ifstream UrunEkle("Urunler.txt");
				while (!(UrunEkle.eof()))
				{
					UrunEkle >> urun.urunAdi >> urun.urunNo >> urun.birim >> urun.birimFiyati >> urun.markasi;
					cout << "Urun adi:" << urun.urunAdi << endl;
					cout << "Urun no:" << urun.urunNo << endl;
					cout << "Urun birimi:" << urun.birim << endl;
					cout << "Urun birim fiyati:" << urun.birimFiyati << endl;
					cout << "Urun markasi:" << urun.markasi << endl;
					cout << "---------------------------" << endl;
				}
				system("pause");
			}

			else
			{
				cout << "Yanlis giris yaptiniz. Ana menuye donmek icin bir tusa basiniz." << endl;
				system("pause");
			}

		} 

		else if (secim == 2)
		{
			int secim2;
			system("cls");
			cout << "1-Proje Ekle" << endl;
			cout << "2-Proje Sil" << endl;
			cout << "3-Proje Ara" << endl;
			cout << "4-Projeleri Raporla" << endl;
			cout << "0-Bir Onceki Menuye Don" << endl;
			cout << "Seciminizi giriniz:";
			cin >> secim2;

			
			if (secim2 == 1) 
			{
				system("cls");
				string gecici;
				string gecici2;
				ofstream ProjeEkle("Projeler.txt", ios::app);
				cout << "Eklenecek projenin adini giriniz: ";
				cin >> gecici2;
				cout << "Eklenecek projenin numarasini giriniz: ";
				cin >> gecici;
				ifstream ProjeEkle2("Projeler.txt");
				while (!(ProjeEkle2.eof()))
				{
					ProjeEkle2 >> proje.projeAdi >> proje.projeNo >> proje.yurutucuFirma >> proje.projeSorumlusu >> proje.projeKontroloru;
					if (proje.projeNo == gecici)
					{
						cout << "Ayni proje no'su tekrar kullanilamaz." << endl;
						exit(1);
					}
				}
				cout << "Eklenecek projenin yurutucu firmasini giriniz: ";
				cin >> proje.yurutucuFirma;
				cout << "Eklenecek projenin proje sorumlusunu giriniz: ";
				cin >> proje.projeSorumlusu;
				cout << "Eklenecek projenin proje kontrolorunu giriniz: ";
				cin >> proje.projeKontroloru;
				ProjeEkle << endl << gecici2 << endl << gecici << endl << proje.yurutucuFirma << endl << proje.projeSorumlusu << endl << proje.projeKontroloru;
				cout << "Proje eklenmistir." << endl;
				cout << "Bir tusa basiniz.";
				system("pause");
				ProjeEkle.close();
			}
			else if (secim2 == 2)
			{
				system("cls");
				cout << "Silinecek projenin numarasini giriniz: ";
				string silinecek;
				cin >> silinecek;
				ifstream ProjeEkle("Projeler.txt");
				ofstream ProjeEkle2("Projeler2.txt");
				while (!(ProjeEkle.eof()))
				{
					ProjeEkle >> proje.projeAdi >> proje.projeNo >> proje.yurutucuFirma >> proje.projeSorumlusu >> proje.projeKontroloru;
					if (silinecek == proje.projeNo)
					{
						cout << "Proje silinmistir. " << endl;
						system("pause");
					}
					else
					{
						ProjeEkle2 << endl << proje.projeAdi << endl << proje.projeNo << endl << proje.yurutucuFirma << endl << proje.projeSorumlusu << endl << proje.projeKontroloru;
					}
				}
				ProjeEkle.close();
				ProjeEkle2.close();
				remove("Projeler.txt");
				rename("Projeler2.txt", "Projeler.txt");
				exit(1);
			}
			else if (secim2 == 3)
			{
				system("cls");
				string aranacak_proje;
				cout << "Aranacak projenin numarasini giriniz: ";
				cin >> aranacak_proje;
				ifstream ProjeEkle("Projeler.txt");
				while (!(ProjeEkle.eof()))
				{
					ProjeEkle >> proje.projeAdi >> proje.projeNo >> proje.yurutucuFirma >> proje.projeSorumlusu >> proje.projeKontroloru;
					if (proje.projeNo == aranacak_proje)
					{
						cout << "Proje Adi:" << proje.projeAdi << endl;
						cout << "Proje No:" << proje.projeNo << endl;
						cout << "Proje Yurutucu Firma:" << proje.yurutucuFirma << endl;
						cout << "Proje Sorumlusu:" << proje.projeSorumlusu << endl;
						cout << "Proje Kontroloru:" << proje.projeKontroloru << endl;
						cout << "---------------------------" << endl;
					}
				}
				system("pause");
			}
			else if (secim2 == 4)
			{
				system("cls");
				ifstream ProjeEkle("Projeler.txt");
				while (!(ProjeEkle.eof()))
				{
					ProjeEkle >> proje.projeAdi >> proje.projeNo >> proje.yurutucuFirma >> proje.projeSorumlusu >> proje.projeKontroloru;
					cout << "Proje adi:" << proje.projeAdi << endl;
					cout << "Proje no:" << proje.projeNo << endl;
					cout << "Proje yurutucu firma:" << proje.yurutucuFirma << endl;
					cout << "Proje sorumlusu:" << proje.projeSorumlusu << endl;
					cout << "Proje kontroloru:" << proje.projeKontroloru << endl;
					cout << "---------------------------" << endl;
				}
				system("pause");
			}
			else if (secim2 == 0)
			{

			}
			else
			{
				cout << "Yanlis giris yaptiniz. Ana menuye donmek icin bir tusa basiniz." << endl;
				system("pause");
			}

		} 

		else if (secim == 3)
		{
			int secim2;
			int toplam = 0;
			system("cls");
			cout << "1-Bir Projeye Hakedis Ver" << endl;
			cout << "2-Hakedis Verilmis Projeye Urun Ekle" << endl;
			cout << "3-Hakedis Verilmis Projeden Urun Sil" << endl;
			cout << "4-Hakedis Verilmis Projenin Urunlerini Listele " << endl;
			cout << "5-Kayitli Projelerin Belirtilen Donem Icin Hakkedis Tutarlarini Raporlama" << endl;
			cout << "0-Bir Onceki Menuye Don" << endl;
			cin >> secim2;
			if (secim2 == 0)
			{

			}

			else if (secim2 == 1)
			{
				system("cls");
				int sayac = 0;
				ofstream HakedisEkle("Hakedisler.txt", ios::app);
				cout << "Hakedis eklenecek proje numarasini giriniz: ";
				cin >> hakedis.projeNo;
				ifstream ProjeEkle("Projeler.txt");
				while (!(ProjeEkle.eof()))
				{
					ProjeEkle >>proje.projeAdi >> proje.projeNo >> proje.yurutucuFirma >> proje.projeSorumlusu >> proje.projeKontroloru;
					if (proje.projeNo == hakedis.projeNo)
					{
						sayac++;
					}
				}
				if (sayac == 0)
				{
					cout << "Boyle bir proje kayitli olmadigindan hakedis verilemez." << endl;
					exit(1);
				}
				cout << "Hakedis ekleme tarihi giriniz: ";
				cin >> hakedis.hakedisTarih;
				HakedisEkle << endl << hakedis.projeNo << endl << hakedis.hakedisTarih;
				cout << "Hakedis eklenmistir." << endl;
				cout << "Bir tusa basin.";
				system("pause");
				HakedisEkle.close();
			}

			else if (secim2 == 2)
			{
				system("cls");
				int sayac = 0;
				ofstream HakedisliProjeEkle("HakedisliProjeler.txt", ios::app);
				cout << "Urun eklenecek proje numarasini giriniz: ";
				cin >> hakedis.projeNo;
				string gecici1 = hakedis.projeNo;
				string gecici2;
				ifstream HakedisEkle("Hakedisler.txt");
				while (!(HakedisEkle.eof()))
				{
					HakedisEkle >> hakedis.projeNo >> hakedis.hakedisTarih;
					if (gecici1 == hakedis.projeNo)
					{
						sayac++;
						gecici2 = hakedis.hakedisTarih;
					}
				}
				if (sayac == 0)
				{
					cout << "Boyle bir proje, hakedisli listede kayitli olmadigindan urun eklenemez." << endl;
					exit(1);
				}
				cout << "Kullanilacak Urunu Giriniz: ";
				cin >> hakedis.kullanilanUrun;
				cout << "Kullanilacak Urun Adedini Giriniz: ";
				cin >> hakedis.kullanilanUrunAdedi;
				cout << "Kullanilacak Urun Birim Fiyatini Giriniz: ";
				cin >> hakedis.kullanilanUrunFiyati;
				HakedisliProjeEkle << endl << gecici1 << endl << gecici2 << endl << hakedis.kullanilanUrun << endl << hakedis.kullanilanUrunAdedi << endl << hakedis.kullanilanUrunFiyati;
				cout << "Hakedisli Projeye Urun Eklenmistir." << endl;
				cout << "Bir tusa basin.";
				system("pause");
				HakedisEkle.close();
			}
			else if (secim2 == 3)
			{
				system("cls");
				int sayac = 0;
				cout << "Urun silinecek proje numarasini giriniz: ";
				cin >> hakedis.projeNo;
				string gecici1 = hakedis.projeNo;
				string gecici2;
				ifstream HakedisEkle("Hakedisler.txt");
				while (!(HakedisEkle.eof()))
				{
					HakedisEkle >> hakedis.projeNo >> hakedis.hakedisTarih;
					if (gecici1 == hakedis.projeNo)
					{
						sayac++;
						gecici2 = hakedis.hakedisTarih;
					}
				}
				if (sayac == 0)
				{
					cout << "Boyle bir proje, hakedisli listede kayitli olmadigindan islem yapilamaz." << endl;
					exit(1);
				}

				cout << "Silinecek urunun adini giriniz: ";
				string silinecek;
				cin >> silinecek;
				ifstream HakEdilmisProjeEkle("HakedisliProjeler.txt");
				ofstream HakEdilmisProjeEkle2("HakedisliProjeler2.txt");
				while (!(HakEdilmisProjeEkle.eof()))
				{
					HakEdilmisProjeEkle >> hakedis.projeNo >> hakedis.hakedisTarih >> hakedis.kullanilanUrun >> hakedis.kullanilanUrunAdedi>> hakedis.kullanilanUrunFiyati;
					if (silinecek == hakedis.kullanilanUrun)
					{
						cout << "Urun silinmistir. " << endl;
						system("pause");
					}
					else
					{
						HakEdilmisProjeEkle2 << endl << hakedis.projeNo << endl << hakedis.hakedisTarih << endl << hakedis.kullanilanUrun << endl << hakedis.kullanilanUrunAdedi << endl << hakedis.kullanilanUrunFiyati;
					}
				}
				HakEdilmisProjeEkle.close();
				HakEdilmisProjeEkle2.close();
				remove("HakedisliProjeler.txt");
				rename("HakedisliProjeler2.txt", "HakedisliProjeler.txt");
				exit(1);

			}
			else if (secim2 == 4)
			{
				system("cls");
				cout << "Urunleri listelenecek projenin numarasini giriniz:";
				string proje_no;
				cin >> proje_no;
				ifstream HakedisliProjeEkle("HakedisliProjeler.txt");
				int toplam_tutar = 0;
				while (!(HakedisliProjeEkle.eof()))
				{
					HakedisliProjeEkle >> hakedis.projeNo >> hakedis.hakedisTarih >> hakedis.kullanilanUrun >> hakedis.kullanilanUrunAdedi >> hakedis.kullanilanUrunFiyati;
					if (proje_no == hakedis.projeNo)
					{
						cout << "Kullanilan Urun:" << hakedis.kullanilanUrun << endl;
						cout << "Kullanilan Urun Adedi:" << hakedis.kullanilanUrunAdedi << endl;
						cout << "Kullanilan Urun Fiyati:" << hakedis.kullanilanUrunFiyati << endl;
						toplam_tutar += stoi(hakedis.kullanilanUrunAdedi)*stoi(hakedis.kullanilanUrunFiyati);
					}
				}
				cout << "Toplam tutar:" << toplam_tutar << endl;
				system("pause");
			}
			else if (secim2 == 5)
			{
				system("cls");
				cout << "Tarih giriniz:";
				string tarih;
				cin >> tarih;
				ifstream HakedisliProjeEkle("HakedisliProjeler.txt");
				int toplam_tutar = 0;
				while (!(HakedisliProjeEkle.eof()))
				{
					HakedisliProjeEkle >> hakedis.projeNo >> hakedis.hakedisTarih >> hakedis.kullanilanUrun >> hakedis.kullanilanUrunAdedi >> hakedis.kullanilanUrunFiyati;
					if (hakedis.hakedisTarih == tarih)
					{
						cout << "Hakedisli Proje Tarihi:" << hakedis.hakedisTarih << endl;
						cout << "Hakedisli Projedeki Urun Tutari:" << stoi(hakedis.kullanilanUrunAdedi)*stoi(hakedis.kullanilanUrunFiyati) << endl;
						toplam_tutar += stoi(hakedis.kullanilanUrunAdedi)*stoi(hakedis.kullanilanUrunFiyati);
					}
				}
				cout << "Bu tarihteki hakedisli projelerin toplam tutari:" << toplam_tutar << endl;
				system("pause");
			}
			else if (secim == 0)
			{

			}
			else
			{
				cout << "Yanlis giris yaptiniz. Ana menuye donmek icin bir tusa basiniz." << endl;
				system("pause");
			}
		}

		else 
		{
			cout << "Yanlis giris yaptiniz. Ana menuye donmek icin bir tusa basiniz." << endl;
			system("pause");
		}

	} while (secim != 0);

	return 0;
}