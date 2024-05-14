// Start
#include <iostream>
#include <windows.h> // t�rkce karakter
#include <conio.h> // gtch() icin
#include <vector>
#include <string>
# include <iomanip> // setprecision kula�m� i�in



// system("cls"); // Konsol ekran�n� temizle

using namespace std;


class Hayvan // hayvan ekleme
{
   
private:
    string isim;
    string tur;
    int yas;
    string renk;
public:
    Hayvan(string isim, string tur, int yas,string renk)
    { setlocale(LC_ALL, "Turkish");
        setlocale(LC_ALL, "Turkish");
        this->tur = tur;
        this->isim = isim;
        this->yas = yas;
        this->renk = renk;
    }

    string getTur() { return tur; }
    void setTur(string yeniTur) {tur = yeniTur;}

    string getIsim() {return isim;}
    void setIsim(string yeniIs�m){isim = yeniIs�m;}

    int getYas() {return yas;}
    void setYas(int yeniYas) {yas = yeniYas;}

    string getRenk(){return renk;}
    void setRenk(string yeniRenk) { renk = yeniRenk; }
};

class HayvanatBahcesi 
{
    
private:
    vector<Hayvan> hayvanlar;
public:
    void hayvanEkle(Hayvan hayvan)
    {
        setlocale(LC_ALL, "Turkish");
        hayvanlar.push_back(hayvan);
    }

    void hayvanlariGoruntule() // hayvanlar� goruntuleme
    {
        setlocale(LC_ALL, "Turkish");
        int gosterX = 50, gosterY = 3;
        if (hayvanlar.empty())
        {
            COORD besle = { 1,9 };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), besle);
            cout << "Hayvanat bah�esinde hi� hayvan bulunmamaktad�r." << endl;
        }
        else
        { 
         
          COORD goster0 = { gosterX,gosterY-1 };
          SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), goster0);
          cout << "Hayvanat bah�esindeki t�m hayvanlar:" << endl;
          COORD goster = { gosterX,gosterY +1 };
          SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), goster);
          cout << "T�R�  ";
          COORD isimkordinat = { gosterX+15,gosterY + 1 };
          SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), isimkordinat);    cout<< "�SM�  ";
          COORD yasKonum = { gosterX+30,gosterY +1 };
          SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), yasKonum);    cout << "YA�I  ";
          COORD renkKonum = { gosterX+45,gosterY+1 };
          SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), renkKonum); cout << "RENG�  ";
          gosterY = 5;
          for (int i = 0; i < hayvanlar.size(); i++)
          {
              Hayvan hayvan = hayvanlar[i];
              COORD goster1 = { gosterX-4,gosterY+i };
              SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), goster1);    cout<<i+1<<" : " << hayvan.getTur();
             
              COORD goster2 = { gosterX+15,gosterY +i };
              SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), goster2);      cout << hayvan.getIsim();
            
              COORD goster3 = { gosterX+30,gosterY +i };
              SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), goster3);      cout << hayvan.getYas();
             
              COORD goster4 = { gosterX+45,gosterY + i };
              SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), goster4);      cout << hayvan.getRenk();
             
              cout << endl;
             
          }

        }
    }
    void hayvanDuzenle(int index)
    {
        setlocale(LC_ALL, "Turkish");
        int gosterX = 2, gosterY = 10;


        string yeniIsim, yeniTur, Yenirenk,yeniRenk;
        int yeniYas;
        for (int i = 0; i < hayvanlar.size()+2; i++)
        {
            COORD ekle1 = { gosterX-1,gosterY + i };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle1);
            cout << "                                       " << endl;
        }

      
        COORD goster2 = { gosterX,gosterY + 1 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), goster2);
        cout << "Yeni t�r� girin: ";
        cin >> yeniTur;
        COORD duzenle3 = { gosterX,gosterY + 2 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), duzenle3);
        cout << "Yeni ismi girin: ";
        cin >> yeniIsim;
        COORD duzenle4 = { gosterX,gosterY + 3 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), duzenle4);
        cout << "Yeni ya��n� girin: ";
        cin >> yeniYas;
        COORD duzenle5 = { gosterX,gosterY + 4 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), duzenle5);
        cout << "Yeni rengini girin : ";
        cin >> yeniRenk;
        COORD duzenle6 = { gosterX,gosterY + 5 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), duzenle6);

        if (index >= 0 && index < hayvanlar.size())
        {
            Hayvan& hayvan = hayvanlar[index];
            hayvan.setTur(yeniTur);
            hayvan.setIsim(yeniIsim);
            hayvan.setYas(yeniYas);
            hayvan.setRenk(yeniRenk);
            cout << "Hayvan d�zenlendi." << endl;
        }
        else 
        {
            cout << "Ge�ersiz indeks. Hayvan d�zenlenemedi." << endl;
        }
     
    }
    void hayvanBesle(int besle)
    {
        setlocale(LC_ALL, "Turkish");
        for (int i = 0; i < 6; i++)
        {
            COORD ekle1 = {1,8+ i };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle1);
            cout << "                                                                           " << endl;
        }
        
        if (besle >= 0 && besle < hayvanlar.size())
        {
            Hayvan& hayvan = hayvanlar[besle];
            
            COORD besle = { 1,10 };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), besle);
            cout << hayvan.getIsim() <<  " `in Yama�i veriliyor..." << endl;
        }
        else
        {
            COORD besle = { 1,10 };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), besle);
            cout << "Ge�ersiz say�. Hayvan�n yeme�i verilemedi." << endl;
        }
    }
};



void konumxy(int x, int y)// Kordinat
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}

int main()
{

    setlocale(LC_ALL, "Turkish"); // T�rkce karakterlerin dogru goruntulenmesi icin	
    HayvanatBahcesi hayvanatBahcesi;
    int durum = 0;
    bool ext = true;
    bool devam = false;
    char key;
    char tus;
    int x = 2, y = 4;
    int ekleX = 40, ekleY = 3;
  
    // 1. Hayvan
    Hayvan hayvan1("Alex","Aslan", 2, "Sar�");
    hayvanatBahcesi.hayvanEkle(hayvan1);

    // 2. Hayvan
    Hayvan hayvan2("Komba", "Komodo Ejderhas�", 4, "Kahverengi");
    hayvanatBahcesi.hayvanEkle(hayvan2);

    // 3. Hayvan
    Hayvan hayvan3( "Marti","Zebra", 2, "Siyah-Beyaz");
    hayvanatBahcesi.hayvanEkle(hayvan3);

    // 4. Hayvan
    Hayvan hayvan4( "Boo","Panda", 3, "Siyah-Beyaz");
    hayvanatBahcesi.hayvanEkle(hayvan4);
	cout <<"--------------" << "HAYVANAT BAH�ES� Y�NET�M S�STEM�"<<"-------------" << endl;
    cout << "Hareket etirmek i��in w-s se�im icin q" << endl;
	konumxy(3,4); cout << "Hayvan Ekle : " << endl;
	konumxy(3,5); cout << "Hayvanlar� G�ster : " << endl;
	konumxy(3,6); cout << "Hayvanlar� Besle : " << endl;
	konumxy(3,7); cout << "Hayvan D�zenle : ";
	konumxy(3,8); cout << "��k�� : " << endl;
  

	while(ext)
	{
        do
        {
            key = _getch();
            bool devam = true;
           

            if (key == 's')// a�a�� gider imlec y artar
            {
                y++;
                COORD pos = { x, y };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                if (y == 9)
                {
                    y = 3;
                    COORD pos = { x, y };
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                }
                durum = y;
            }

            if (key == 'w') // yukar� imlec gider y azal�r
            {
                y--;
                COORD pos = { x, y };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                if (y == 3)
                {
                    y = 8;
                    COORD pos = { x, y };
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                }
                durum = y;
            }
            else if(key != 'q' && key != 'Q')
            {

            }

          
        } while (key != 'q' && key != 'Q');

       
      
       do
        {
           char tus;
            if (durum == 4)// Hayvan Ekleme
            {
                string isim, tur, renk;
                int yas = 0;

               
                for (int i = 0; i < 20; i++) // kal�nt�lar� silmek icin
                {
                    COORD ekle1 = { ekleX - 1,ekleY - 2 + i };
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle1);
                    cout << "                                                                              " << endl;
                }
              
                COORD ekle1 = { ekleX,ekleY };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle1);
                cout << "�smi : "; cin >> isim; cout << endl;
                COORD ekle2 = { ekleX,ekleY + 1 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle2);
                cout << "T�r� : "; cin >> tur; cout << endl;
                COORD ekle3 = { ekleX,ekleY + 2 };
               SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle3);
                cout << "Ya�� : "; cin >> yas; cout << endl;
                COORD ekle4 = { ekleX,ekleY + 3 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle4);
                cout << "Rengi : "; cin >> renk; cout << endl;

                Hayvan hayvan(isim, tur, yas, renk);
                hayvanatBahcesi.hayvanEkle(hayvan);

                COORD ekle5 = { ekleX,ekleY + 4 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle5);
                cout << isim<<" Hayvanat bah�esine eklendi." << endl;
              
                bool devam = false;
               

            }
            if (durum == 5)// Hayvanlar� G�sterme
            {
                for (int i = 0; i < 20; i++) // kal�nt�lar� silmek icin
                {
                    COORD ekle1 = { ekleX,ekleY + i };
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle1);
                    cout << "                                                     " << endl;
                }

                COORD ekle1 = { 40,1 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle1);
                cout  << endl;
                hayvanatBahcesi.hayvanlariGoruntule();
                 devam = false;

              
            }
            if (durum == 6)// Hayvanlar� Besle
            {
                int besle = 0;
                for (int i = 0; i < 20; i++) // kal�nt�lar� silmek icin
                {
                    COORD ekle1 = { ekleX,ekleY + i };
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle1);
                    cout << "                                                     " << endl;
                }
                hayvanatBahcesi.hayvanlariGoruntule();

                COORD besle1 = { x-1,y+4  };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), besle1);
                cout << "Beslenecek hayvan numaras� : "; cin >> besle;
                hayvanatBahcesi.hayvanBesle(besle - 1);
                COORD sil2 = { 1,9 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), sil2);
               
                 devam = false;
            }
            if (durum == 7)// Hayvanlar� D�zenle
            {

                for (int i = 0; i < 20; i++)
                {
                    COORD ekle1 = { ekleX-1,ekleY+i };
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle1);
                    cout << "                                                        " << endl;
                }

                int index = -1;
                hayvanatBahcesi.hayvanlariGoruntule();

                COORD d1 = { x-1,y+3 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d1);
                cout << "D�zenlenecek hayvan numaras�  : ";
                cin >> index;

                hayvanatBahcesi.hayvanDuzenle(index-1);

                for (int i = 0; i < 6; i++)
                {
                    COORD ekle1 = { x-2,y+4+i };
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ekle1);
                    cout << "                                                                           " << endl;
                } 
                COORD duzen = { 50,index+4 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), duzen);
                cout << "                                                               ";
                hayvanatBahcesi.hayvanlariGoruntule();
                devam = false;
            }
            if (durum == 8)// ��k��
            {
                devam = false;
                ext = false;

            }
            else if (durum == 0)
            {

            }
            durum = 0;
       } while (devam);
	}
    return 0;
}

