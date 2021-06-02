# Minimum Çevreleyen Çember ve Noktalardan Geçen Eğri
UYARI: Bu projede istenen B-spline yerine Bezier Spline yapılmıştır.

1- Programı çalıştıracağınız klasöre "dosya.txt" adında bir txt dosyası açınız. 

2- Dosyanın içine noktaları şu formatta giriniz:

{{x1,y1}{x2,y2}{x3,y3}{x4,y4}...{xn,yn}}

3- Main dosyasını açınız ve kullanacağınız idede graphics.h kütüphanesi yüklü ise adım 6'ya geçiniz.

4- Eğer yüklü değilse şu adresten graphics.h kütüphanesini yükleyiniz : 

 https://drive.google.com/file/d/1DdLhqOUfz95W8nG3weN_KUcYQn_TUSL7/view

5- Yüklediğiniz kütüphanenin kurulumu için şu videodaki talimatlara uyunuz : 

 https://www.youtube.com/watch?v=H5bjXTz-HHo&feature=emb_logo

6- Programı derleyip çalıştırınız.

Not:  Önünüze gelen minimum çevreleyen çember grafiğini geçip eğri grafiğine geçmek için klavyeden bir tuşa basınız.
Not-2: Bu program aynı x değerleri verdiğiniz zaman B-spline'ı kesik olarak çizmektedir.  

ERROR 1 : sstream hatası alınıyorsa kullanılan dosyanın uzantısının ".cpp" olmasına dikkat etmeliyiz.
ERROR 2 : [$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)] Kod satırı hata veriyorsa graphics.h kütüphanesini tekrar kurmanız gerekir. 
(Tekrar indirmeye gerek yok sadece kurulum yapılırsa yeterli olur) 
