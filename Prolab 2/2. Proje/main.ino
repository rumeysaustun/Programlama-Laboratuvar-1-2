#include <LiquidCrystal_I2C_AvrI2C.h>
LiquidCrystal_I2C_AvrI2C lcd(0x27, 16, 2);

//Txt den cekilmesi gereken bilgiler aşagida direkt olarak verilmiştir. Cunku bunun icin ayri bir modul gerekiyordu. Elimde bu modulden yoktu.
int  HizmetID[4]        = {1, 2, 3, 4};
char HizmetAd[4][50]    = {"Kopukleme", "Yikama", "Kurulama", "Cilalama"};
int  KalanHizmetAdet[4] = {30, 50, 100, 20};
int  HizmetFiyat[4]     = {15, 10, 5, 50};
int  kasa5TL = 20, kasa10TL = 20, kasa20TL = 10, kasa50TL = 30, kasa100TL = 5;

int  buton_1 = 7, buton_2 = 8, buton_3 = 9, buton_4 = 10, buton_5 = 11, buton_devam = 12, buton_iptal = 13; // Buton pinleri ayarlanir
int  led_kirmizi = 2, led_yesil = 3; // Led pinleri ayarlanir
int  kasaToplam, atilanPara, tutar, paraSikisti, hizmet1adet = 0, hizmet2adet = 0, hizmet3adet = 0,
                                                 hizmet4adet = 0, paraustu5 = 0, paraustu10 = 0, paraustu20 = 0, paraustu50 = 0, paraustu100 = 0, paraustu, temp;

void setup() {
  lcd.begin(); //LCD ekranı başlatılıyor
  lcd.backlight(); //LCD ekran arka plan isigi ayarlaniyor
  Serial.begin(9600); //Serial ekran başlatılıyor
  pinMode(buton_1, INPUT);
  pinMode(buton_2, INPUT);
  pinMode(buton_3, INPUT);
  pinMode(buton_4, INPUT);
  pinMode(buton_5, INPUT);
  pinMode(buton_devam, INPUT);
  pinMode(buton_iptal, INPUT);
  pinMode(led_kirmizi, OUTPUT);
  pinMode(led_yesil, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
bas:
  lcd.clear();
  atilanPara = paraustu5 =  paraustu10 =  paraustu20 = paraustu50 = paraustu100 = paraustu = hizmet1adet = hizmet2adet = hizmet3adet = hizmet4adet = tutar = 0;
  digitalWrite(led_kirmizi, LOW);
  digitalWrite(led_yesil, LOW);

  Serial.println();
  for (int x = 0; x < 4; x++)
  {
    Serial.println(String(HizmetID[x]) + "." + HizmetAd[x] + " kalan: " + String(KalanHizmetAdet[x]));
  }

  Serial.println("\nKasada kalan para: ");
  Serial.println("100 TL : " + String(kasa100TL));
  Serial.println("50 TL : " + String(kasa50TL));
  Serial.println("20 TL : " + String(kasa20TL));
  Serial.println("10 TL : " + String(kasa10TL));
  Serial.println("5 TL : " + String(kasa5TL));

  lcd.setCursor(0, 0);
  lcd.print("  Para girisi");
  lcd.setCursor(0, 1);
  lcd.print("    yapiniz");

  // Bu while dongusu ile para atma islemi yapilir.
  while (digitalRead(buton_devam) != 1)
  {
    if (digitalRead(buton_1) == 1)
    {
      atilanPara += 5;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Atilan para:");
      lcd.setCursor(2, 1);
      lcd.print(atilanPara);
      lcd.setCursor(6, 1);
      lcd.print("TL");
      delay(500);
    }
    if (digitalRead(buton_2) == 1)
    {
      atilanPara += 10;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Atilan para:");
      lcd.setCursor(2, 1);
      lcd.print(atilanPara);
      lcd.setCursor(6, 1);
      lcd.print("TL");
      delay(500);
    }
    if (digitalRead(buton_3) == 1)
    {
      atilanPara += 20;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Atilan para:");
      lcd.setCursor(2, 1);
      lcd.print(atilanPara);
      lcd.setCursor(6, 1);
      lcd.print("TL");
      delay(500);
    }
    if (digitalRead(buton_4) == 1)
    {
      atilanPara += 50;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Atilan para:");
      lcd.setCursor(2, 1);
      lcd.print(atilanPara);
      lcd.setCursor(6, 1);
      lcd.print("TL");
      delay(500);
    }
    if (digitalRead(buton_5) == 1)
    {
      atilanPara += 100;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Atilan para:");
      lcd.setCursor(2, 1);
      lcd.print(atilanPara);
      lcd.setCursor(6, 1);
      lcd.print("TL");
      delay(500);
    }
    if (digitalRead(buton_iptal) == 1)// Yapilan islemleri iptal eder
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Islem iptal");
      lcd.setCursor(2, 1);
      lcd.print("  edildi!");
      delay(1500);
      goto bas;
    }

  }
  // para atma islemi biter
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Lutfen hizmet");
  lcd.setCursor(2, 1);
  lcd.print("  seciniz");
  Serial.println();
  for (int x = 0; x < 4; x++)
  {
    Serial.println(String(HizmetID[x]) + "." + HizmetAd[x] + " fiyat: " + String(HizmetFiyat[x]));
  }
  delay(500);
  // Bu while dongusu ile hizmet secme islemi yapilir.
  while (digitalRead(buton_devam) != 1 )
  {
    if (digitalRead(buton_1) == 1)
    {
      tutar += HizmetFiyat[0];
      if ((atilanPara - tutar) >= 0 && KalanHizmetAdet[0] != 0) {
        KalanHizmetAdet[0]--;
        hizmet1adet++;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Secim: ");
        lcd.setCursor(7, 0);
        lcd.print(HizmetAd[0]);
        lcd.setCursor(0, 1);
        lcd.print("Kalan para:");
        lcd.setCursor(11, 1);
        lcd.print(atilanPara - tutar);
      }
      else if (KalanHizmetAdet[0] == 0)
      {
        tutar -= HizmetFiyat[0];
        lcd.setCursor(0, 0);
        lcd.print("Hizmet kalmadigi");
        lcd.setCursor(0, 1);
        lcd.print("icin secilemiyor");
      }
      else
      {
        tutar -= HizmetFiyat[0];
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Yetersiz bakiye!");
        lcd.setCursor(0, 1);
        lcd.print("Bakiyeniz:");
        lcd.setCursor(11, 1);
        lcd.print(atilanPara - tutar);
        delay(1500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Lutfen baska bir");
        lcd.setCursor(0, 1);
        lcd.print(" hizmet seciniz");
      }
      delay(500);

    }
    if (digitalRead(buton_2) == 1)
    {
      tutar += HizmetFiyat[1];
      if (atilanPara - tutar >= 0 && KalanHizmetAdet[1] != 0) {
        KalanHizmetAdet[1]--;
        hizmet2adet++;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Secim: ");
        lcd.setCursor(7, 0);
        lcd.print(HizmetAd[1]);
        lcd.setCursor(0, 1);
        lcd.print("Kalan para:");
        lcd.setCursor(11, 1);
        lcd.print(atilanPara - tutar);
      }
      else if (KalanHizmetAdet[1] == 0)
      {
        tutar -= HizmetFiyat[1];
        lcd.setCursor(0, 0);
        lcd.print("Hizmet kalmadigi");
        lcd.setCursor(0, 1);
        lcd.print("icin secilemiyor");
      }
      else
      {
        tutar -= HizmetFiyat[1];
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Yetersiz bakiye!");
        lcd.setCursor(0, 1);
        lcd.print("Bakiyeniz:");
        lcd.setCursor(11, 1);
        lcd.print(atilanPara - tutar);
        delay(1500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Lutfen baska bir");
        lcd.setCursor(0, 1);
        lcd.print(" hizmet seciniz");
      }
      delay(500);
    }
    if (digitalRead(buton_3) == 1 && KalanHizmetAdet[2] != 0)
    {
      tutar += HizmetFiyat[2];
      if (atilanPara - tutar >= 0) {
        KalanHizmetAdet[2]--;
        hizmet3adet++;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Secim: ");
        lcd.setCursor(7, 0);
        lcd.print(HizmetAd[2]);
        lcd.setCursor(0, 1);
        lcd.print("Kalan para:");
        lcd.setCursor(11, 1);
        lcd.print(atilanPara - tutar);

      }
      else if (KalanHizmetAdet[2] == 0)
      {
        tutar -= HizmetFiyat[2];
        lcd.setCursor(0, 0);
        lcd.print("Hizmet kalmadigi");
        lcd.setCursor(0, 1);
        lcd.print("icin secilemiyor");
      }
      else
      {
        tutar -= HizmetFiyat[2];
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Yetersiz bakiye!");
        lcd.setCursor(0, 1);
        lcd.print("Bakiyeniz:");
        lcd.setCursor(11, 1);
        lcd.print(atilanPara - tutar);
        delay(1500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Lutfen baska bir");
        lcd.setCursor(0, 1);
        lcd.print(" hizmet seciniz");
      }
      delay(500);
    }
    if (digitalRead(buton_4) == 1)
    {
      tutar += HizmetFiyat[3];
      if (atilanPara - tutar >= 0 && KalanHizmetAdet[3] != 0) {
        KalanHizmetAdet[3]--;
        hizmet4adet++;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Secim: ");
        lcd.setCursor(7, 0);
        lcd.print(HizmetAd[3]);
        lcd.setCursor(0, 1);
        lcd.print("Kalan para:");
        lcd.setCursor(11, 1);
        lcd.print(atilanPara - tutar);
      }
      else if (KalanHizmetAdet[3] == 0)
      {
        tutar -= HizmetFiyat[3];
        lcd.setCursor(0, 0);
        lcd.print("Hizmet kalmadigi");
        lcd.setCursor(0, 1);
        lcd.print("icin secilemiyor");
      }
      else
      {
        tutar -= HizmetFiyat[3];
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Yetersiz bakiye!");
        lcd.setCursor(0, 1);
        lcd.print("Bakiyeniz:");
        lcd.setCursor(11, 1);
        lcd.print(atilanPara - tutar);
        delay(1500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Lutfen baska bir");
        lcd.setCursor(0, 1);
        lcd.print(" hizmet seciniz");
      }
      delay(500);
    }
    if (digitalRead(buton_iptal) == 1) // Yapilan islemleri iptal eder
    {
      KalanHizmetAdet[0] += hizmet1adet;
      KalanHizmetAdet[1] += hizmet2adet;
      KalanHizmetAdet[2] += hizmet3adet;
      KalanHizmetAdet[3] += hizmet4adet;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  Islem iptal");
      lcd.setCursor(2, 1);
      lcd.print("  edildi!");
      delay(1500);
      goto bas;
    }
  }
  // Hizmet secme islemi biter.

  paraSikisti = random(1, 5);
  if (paraSikisti == 2)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Paraniz sikisti!");
    lcd.setCursor(0, 1);
    lcd.print("Tekrar deneyiniz");
    digitalWrite(led_kirmizi, HIGH);
    delay(3000);
    KalanHizmetAdet[0] += hizmet1adet;
    KalanHizmetAdet[1] += hizmet2adet;
    KalanHizmetAdet[2] += hizmet3adet;
    KalanHizmetAdet[3] += hizmet4adet;
    goto bas;
  }

  digitalWrite(led_yesil, HIGH);
  for (int x = 0 ; x < 2 ; x++)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Para ustu");
    lcd.setCursor(0, 1);
    lcd.print("   sayiliyor.");
    delay(300);
    lcd.setCursor(0, 0);
    lcd.print("   Para ustu");
    lcd.setCursor(0, 1);
    lcd.print("   sayiliyor..");
    delay(300);
    lcd.setCursor(0, 0);
    lcd.print("   Para ustu");
    lcd.setCursor(0, 1);
    lcd.print("   sayiliyor...");
    delay(300);
  }
  digitalWrite(led_yesil, LOW);
  paraustu = atilanPara - tutar;
  kasaToplam = (kasa100TL * 100) + (kasa50TL * 50) + (kasa20TL * 20) + (kasa10TL * 10) + (kasa5TL * 5);
  if (paraustu > kasaToplam) // Kasada para ustunu verecek kadar para yoksa bu uyariyi verir.
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Kasada yeterli");
    lcd.setCursor(0, 1);
    lcd.print("para yoktur!");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Hizmetler ve");
    lcd.setCursor(0, 1);
    lcd.print("para iade edildi");
    delay(3000);
    KalanHizmetAdet[0] += hizmet1adet;
    KalanHizmetAdet[1] += hizmet2adet;
    KalanHizmetAdet[2] += hizmet3adet;
    KalanHizmetAdet[3] += hizmet4adet;
    goto bas;
  }
  // Asagidaki kod para ustunu hesaplar.
para:

  if ((paraustu / 100 != 0) && kasa100TL > 0)
  {
    paraustu100++;
    paraustu -= 100;
    kasa100TL--;
    goto para;
  }
  if ((paraustu / 50 != 0) && kasa50TL > 0)
  {
    paraustu50++;
    paraustu -= 50;
    kasa50TL--;
    goto para;
  }
  if ((paraustu / 20 != 0) && kasa20TL > 0)
  {
    paraustu20++;
    paraustu -= 20;
    kasa20TL--;
    goto para;
  }
  if ((paraustu / 10 != 0) && kasa10TL > 0)
  {
    paraustu10++;
    paraustu -= 10;
    kasa10TL--;
    goto para;
  }
  if ((paraustu / 5 != 0) && kasa5TL > 0)
  {
    paraustu5++;
    paraustu -= 5;
    kasa5TL--;
    goto para;
  }
  paraustu = atilanPara - tutar;
  temp = (paraustu100 * 100) + (paraustu50 * 50) + (paraustu20 * 20) + (paraustu10 * 10) + (paraustu5 * 5);
  if (temp != paraustu) // Gerekli olan banknot yok ise asagidaki hatayi verir.
  {
    Serial.println(temp);
    Serial.println(paraustu);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" Kasada gereken");
    lcd.setCursor(0, 1);
    lcd.print("banknot yok :(");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Hizmetler ve");
    lcd.setCursor(0, 1);
    lcd.print("para iade edildi");
    KalanHizmetAdet[0] += hizmet1adet;
    KalanHizmetAdet[1] += hizmet2adet;
    KalanHizmetAdet[2] += hizmet3adet;
    KalanHizmetAdet[3] += hizmet4adet;
    kasa100TL += paraustu100;
    kasa50TL += paraustu50;
    kasa20TL += paraustu20;
    kasa10TL += paraustu10;
    kasa5TL += paraustu5;

    delay(3000);
    goto bas;
  }
  // Para ustunu yazdirir.
  lcd.clear();
  if (paraustu == 0)
  {
    lcd.setCursor(0, 0);
    lcd.print(" Para ustu yok");
    Serial.println("\nPara üstü yok");
  }
  else {
    Serial.println("\nPara üstünüz: ");
    Serial.println("100 TL : " + String(paraustu100));
    Serial.println("50 TL : " + String(paraustu50));
    Serial.println("20 TL : " + String(paraustu20));
    Serial.println("10 TL : " + String(paraustu10));
    Serial.println("5 TL : " + String(paraustu5));

    lcd.setCursor(0, 0);
    lcd.print("  Para Ustunuz ");
    lcd.setCursor(0, 1);
    lcd.print("100TL:   50TL:");
    lcd.setCursor(6, 1);
    lcd.print(paraustu100);
    lcd.setCursor(14, 1);
    lcd.print(paraustu50);
    delay(4000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("20TL:   10TL:");
    lcd.setCursor(0, 1);
    lcd.print("    5TL:");
    lcd.setCursor(5, 0);
    lcd.print(paraustu20);
    lcd.setCursor(13, 0);
    lcd.print(paraustu10);
    lcd.setCursor(8, 1);
    lcd.print(paraustu5);
  }
  delay(4000);

}
