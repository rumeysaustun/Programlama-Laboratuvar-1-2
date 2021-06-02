# Minimum Çevreleyen Çember ve Noktalardan Geçen Eğri

Rumeysa ÜSTÜN <br>
Bu proje C dili ile yazılmıştır.<br>
**UYARI:** Bu projede istenen B-spline yerine Bezier Spline yapılmıştır.<br>

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

*Girilen noktalar: 

`{{1,2}{3,-3}{-5,-5}{-4,0}}`

*Çember çizen ekran:



