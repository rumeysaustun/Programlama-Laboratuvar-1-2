# Minimum Çevreleyen Çember ve Noktalardan Geçen Eğri

Rumeysa ÜSTÜN <br>
Bu proje C dili ile yazılmıştır.<br>
**UYARI:** Bu projede istenen B-spline yerine Bezier Spline yapılmıştır.<br>

Özet
-------------
Programlama Laboratuvarı 1 dersinde bizden, dosyadan çekilen koordinatları iki boyutlu düzlemde gösteren, bu noktaları çevreleyen en küçük çemberi çizen ve bu noktalardan veya bu noktaların yakınından geçen eğriyi çizdirmemiz istendi.

Bunlar için bize sunulan arayüz tasarım kütüphanelerinden Graphics.h kütüphanesini kullandım. Graphics.h kütüphanesini ise kullanım kolaylığı ve proje yeterliliği için seçtim. Detaylar Raporda mevcuttur.


Kurulum
-----------------
+ Graphics.h kütüphanesini [buradan](https://drive.google.com/file/d/1DdLhqOUfz95W8nG3weN_KUcYQn_TUSL7/view) indirebilirsiniz.<br>

+ Kütüphanenin kurulumu için [bu videodan](https://www.youtube.com/watch?v=H5bjXTz-HHo&feature=emb_logo) yardım alabilirsiniz.<br>

Projeyi Çalıştırma
-------------------

* Kütüphane kurulumları yapıldıktan sonra projeyi indiriniz.<br>

* Programı çalıştıracağınız klasöre "dosya.txt" adında bir txt dosyası açınız. <br>

* Dosyanın içine noktaları şu formatta giriniz:<br>

`{{x1,y1}{x2,y2}{x3,y3}{x4,y4}...{xn,yn}}`

* main.c kodlarını derleyip çalıştırın.<br>

**Not:**  Önünüze gelen minimum çevreleyen çember grafiğini geçip eğri grafiğine geçmek için klavyeden bir tuşa basınız. <br>
**Not-2:** Bu program aynı x değerleri verdiğiniz zaman Bezier spline'ı kesik olarak çizmektedir.  <br>

**ERROR 1 :** sstream hatası alınıyorsa kullanılan dosyanın uzantısının ".cpp" olmasına dikkat etmeliyiz.<br>
**ERROR 2 :** [$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)] Kod satırı hata veriyorsa graphics.h kütüphanesini tekrar kurmanız gerekir. <br>
_(Tekrar indirmeye gerek yok sadece kurulum yapılırsa yeterli olur)_

Projeden Görseller
------------

+ **Girilen noktalar:**

`{{1,2}{3,-3}{-5,-5}{-4,0}}`

+ **Çember çizen ekran:**

![ÇemberEkranı](https://user-images.githubusercontent.com/59111328/120503883-56169f80-c3cc-11eb-868e-0bd116b5716e.PNG)

+ **Eğri çizen ekran:**

![EğriEkranı](https://user-images.githubusercontent.com/59111328/120504244-a5f56680-c3cc-11eb-8c14-d0d84c0cf4d9.PNG)

+ **Konsol ekranı:**

![KonsolEkranı](https://user-images.githubusercontent.com/59111328/120504255-a857c080-c3cc-11eb-812f-3ae85ecca972.PNG)





