//Rumeysa ÜSTÜN No: 190202011

#include<graphics.h>
#include<math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

float uzaklik(float a, float b);

int main()
{
    char dosya_icerigi[250];
    char nokta[200];
    float noktalar[250][250];
    int i=0,bayrak,sayi,a=0;
    char sayi1[3];
    

    /*-----Dosyadan veri çekme işlemleri-----*/

    FILE *dosya = fopen("dosya.txt","r"); //dosya.txt dosyasını okuyoruz.

    if(dosya == NULL)
    {
        printf("Dosya acilamadi!"); //Dosya yoksa ya da adı değiştirilmişse açamadığını belirtiyor.
        return 0; //Dosyayı açamadığı için programı durduruyor.
    }

    while(!feof(dosya))//Dosyanın sonuna gelene kadar döner.
    {
        dosya_icerigi[i]=fgetc(dosya);  //Dosyanın içeriğini bir char dizisine atadık.
        i++;
    }
    printf("Dosyanin icindekiler: %s\n",&dosya_icerigi); //Dosyanın içeriğini görüntüler.

    for(int j=0,n=strlen(dosya_icerigi); j<n ; j++) //Dosyanın içeriğindeki koordinatları alabilmemiz için bu for döngüsünü kurduk.
    {
        bayrak=0;
        sayi=0;

        if(isdigit(dosya_icerigi[j]) || dosya_icerigi[j]=='-')
        {
            nokta[sayi]=dosya_icerigi[j]; //Rakamı noktanın 0. indisine atıyoruz.
            bayrak=1;
            for(int b=j+1; b<n; b++) //Eğer birden fazla basamağı olan bir sayı ise diğer basamaklarını almak için for döngüsü kurduk.
            {
                sayi++;
                if(!isdigit(dosya_icerigi[b]))
                {
                    j++;
                    break;
                }
                nokta[sayi]	= dosya_icerigi[b];
                j++;
            }
        }
        if(bayrak==1)
        {
            noktalar[a/2][a%2]=atoi(nokta); //Basit bir matematikle ve matris mantığı ile noktalarımızı dizimize yerleştiriyoruz.
            a++;
        }
        for(int r=0; r<n; r++) //Nokta dizisini daha sonra da kullanabilmek için boşaltıyoruz.
            nokta[r]=NULL;
    }
    if(a%2==1||a<3)
    {
        printf("\nHatali koordinat girildi! Lutfen kontrol ediniz.");
        return 0;
    }


    /*-----Çember hesaplamaları-----*/

    float X_ortalama=0,Y_ortalama=0,yaricap,uzak2;
	int indis = 0;
    for ( i = 0; i < a/2; i++)
    {
        X_ortalama += noktalar[i][0];
        Y_ortalama += noktalar[i][1];
    }
    X_ortalama /= (a/2);  //Girilen noktaların x'lerin ortalamasını alır.
    Y_ortalama /= (a/2); //Girilen noktaların y'lerin ortalamasını alır.
    double sbt = 0.1;

    //Aşağıdaki kod, çember merkezinin ve yarıçapının hesaplamasını yapıyor. Kaynakçada belirttiğim videoyu baz alarak yaptım.

    for (int r = 0; r < 20000; r++)
    {
        yaricap = uzaklik(X_ortalama - noktalar[0][0], Y_ortalama - noktalar[0][1]);
        indis=0;
        for (int j = 1; j < (a/2); j++)
        {
            uzak2 = uzaklik(X_ortalama - noktalar[j][0], Y_ortalama - noktalar[j][1]);
            if (yaricap < uzak2)
            {
				indis = j;
                yaricap = uzak2;
            }
        }
        X_ortalama = X_ortalama + (noktalar[indis][0] - X_ortalama)*sbt;
        Y_ortalama = Y_ortalama + (noktalar[indis][1] - Y_ortalama)*sbt;
        sbt = sbt * 0.999;
    }
    printf("\nMerkez noktasi: ( %.3f, %.3f ) \nYaricapi: %.3f", X_ortalama, Y_ortalama, yaricap);

    /*-----Çember ve koordinat sistemi çizme işlemleri-----*/

	int c=-26,b=20;
    initwindow(1300,715);//1300'e 715'lik bir pencere açar.
    line(650,32.5,650,682.5);//y eksenini çizer.
    line(227.5,357.5,1072.5,357.5);//x eksenini çizer.
    setcolor(7);//Rengi ayarlar.
    settextstyle(3,0,3);//yazının stilini, fontunu ayarlar.
    outtextxy(20,20,"Çember Çizimi");
    settextstyle(2,0,4);
	setcolor(15);//Rengi beyaza çevirir.
    for(float i=227.5; i<=1072.5; i=i+16.25)
    {
        sprintf(sayi1,"%d",c);
        line(i,354.5,i,360.5);//x ekseninin kısa çizgilerini çizer.
        outtextxy(i-6,361.5,sayi1);//x ekseninin sayılarını yerleştirir.
        c++;
    }

    for(float i=32.5; i<=682.5; i=i+16.25)
    {

        if(!b==0)
        {
            sprintf(sayi1,"%d",b);
            outtextxy(654,i-6,sayi1);//y ekseninin sayılarını yerleştirir.
        }

        line(647,i,653,i);//y ekseninin kısa çizgilerini çizer.
        b--;
    }

    for(int i=0; i<a/2; i++)
    {
        setlinestyle(1,3,1);
        if(noktalar[i][0]!=0)
            line(650+(noktalar[i][0]*16.5),357.5,650+(noktalar[i][0]*16.5),357.5-(noktalar[i][1])*16.5);//Noktanın x'ini gösteren kesikli çizgi çizer.
        if(noktalar[i][1]!=0)
            line(650,357.5-(noktalar[i][1])*16.5,650+(noktalar[i][0]*16.5),357.5-(noktalar[i][1])*16.5);//Noktanın y'sini gösteren kesikli çizgi çizer.
        setlinestyle(0,0,3);
        fillellipse((20+(noktalar[i][0]/2.0))*32.5,(11-(noktalar[i][1]/2.0))*32.5,2,2);//Noktaları gösterir.
    }
    settextstyle(2,0,5);
    setcolor(3);
    sprintf(sayi1,"Merkez noktasi: ( %.3f, %.3f )",X_ortalama,Y_ortalama);
    outtextxy(1100,30,sayi1);
    setcolor(12);
    sprintf(sayi1,"Yarıçapı: %.3f",yaricap);
    outtextxy(1100,50,sayi1);
    setcolor(9);
    circle(650+(X_ortalama)*16.25,357.5-(Y_ortalama)*16.25,(yaricap)*16.25); //Çemberi çizer.


    setcolor(12);
    line(650+(X_ortalama)*16.25,357.5-(Y_ortalama)*16.25,(650+(X_ortalama)*16.25)+(yaricap)*16.25,357.5-(Y_ortalama)*16.25); //Yarıçapı çizer.
    setcolor(3);
    fillellipse(650+(X_ortalama)*16.25,357.5-(Y_ortalama)*16.25,2,2);//Merkez noktasını gösterir.
    setlinestyle(1,3,1);
    line(650,357.5-(Y_ortalama)*16.5,650+(X_ortalama*16.5),357.5-(Y_ortalama)*16.5);
    line(650+(X_ortalama*16.5),357.5,650+(X_ortalama*16.5),357.5-(Y_ortalama)*16.5);
    setcolor(15);
    
	getch();
    clearviewport(); //Ekranı temizler.

	/*-----Koordinat çizimi-----*/

    setlinestyle(0,0,1);
    c=-26,b=20;
    setcolor(7);//Rengi ayarlar.
    settextstyle(3,0,3);//yazının stilini, fontunu ayarlar.
    outtextxy(20,20,"Eğri Çizimi");
    settextstyle(2,0,4);
    setcolor(15);
    line(650,32.5,650,682.5);//y eksenini çizer.
    line(227.5,357.5,1072.5,357.5);//x eksenini çizer.
    for(float i=227.5; i<=1072.5; i=i+16.25)
    {
        sprintf(sayi1,"%d",c);
        line(i,354.5,i,360.5);//x ekseninin kısa çizgilerini çizer.
        outtextxy(i-6,357.5+4,sayi1);//x ekseninin sayılarını yerleştirir.
        c++;
    }

    for(float i=32.5; i<=682.5; i=i+16.25)
    {

        if(!b==0)
        {
            sprintf(sayi1,"%d",b);
            outtextxy(654,i-6,sayi1);//y ekseninin sayılarını yerleştirir.
        }

        line(647,i,653,i);//y ekseninin kısa çizgilerini çizer.
        b--;
    }
    for(int i=0; i<a/2; i++)
    {
        setlinestyle(1,3,1);
        if(noktalar[i][0]!=0)
            line(650+(noktalar[i][0]*16.5),357.5,650+(noktalar[i][0]*16.5),357.5-(noktalar[i][1])*16.5);//Noktanın x'ini gösteren kesikli çizgi çizer.
        if(noktalar[i][1]!=0)
            line(650,357.5-(noktalar[i][1])*16.5,650+(noktalar[i][0]*16.5),357.5-(noktalar[i][1])*16.5);//Noktanın y'sini gösteren kesikli çizgi çizer.
        setlinestyle(0,0,3);
        fillellipse((20+(noktalar[i][0]/2.0))*32.5,(11-(noktalar[i][1]/2.0))*32.5,2,2);//Noktaları çizer.
    }

    /*-----Eğri hesaplamaları ve çizdirmesi-----*/

    //Aşağıdaki kod ile noktaları x'e göre küçükten büyüğe sıralıyoruz.
    int temp;
    for(int e=0; e<a/2; e++)
    {
        for(int o=e+1; o<a/2; o++)
        {
            //Burada e. indexteki noktanın x'ini dizinin e. indexten büyük elemanlarıyla sırayla karşılaştırma yapar. Küçük olan ile yer değiştirir.

            if(noktalar[e][0]>noktalar[o][0])
            {
                //Noktanın x'lerinin yerini değiştirir.
                temp=noktalar[e][0];
                noktalar[e][0]=noktalar[o][0];
                noktalar[o][0]=temp;
                //Noktanın y'lerinin yerini değiştirir.
                temp=noktalar[e][1];
                noktalar[e][1]=noktalar[o][1];
                noktalar[o][1]=temp;
            }
            else if(noktalar[e][0]==noktalar[o][0]) //x'ler eşitse y'lere göre sıralama yapar.
            {
                if(noktalar[e][1]>noktalar[o][1])
                {
                    //Noktanın x'lerinin yerini değiştirir.
                    temp=noktalar[e][0];
                    noktalar[e][0]=noktalar[o][0];
                    noktalar[o][0]=temp;
                    //Noktanın y'lerinin yerini değiştirir.
                    temp=noktalar[e][1];
                    noktalar[e][1]=noktalar[o][1];
                    noktalar[o][1]=temp;
                }
            }

        }
    }
    setlinestyle(0,0,3);
    float bi[50],ci[50],hi[50];
    ci[0]=0;
    float s;
    setcolor(9);	
    //Aşağıdaki kod, eğri hesaplaması ve çizdirmesini yapıyor. Raporda belirttiğim formülü kullanarak yaptım.
    hi[0]=noktalar[1][0]-0.001-noktalar[0][0]-0.001;
    bi[0]=(noktalar[1][1]-0.001-(noktalar[0][1])-0.001)/hi[0];
    for(int nt=0; nt<(a/2)-1; nt++)
    {
        for(float nt2=noktalar[nt][0]; nt2<noktalar[nt+1][0]; nt2+=0.0001)
        {
            hi[nt]=noktalar[nt+1][0]-noktalar[nt][0];
            bi[nt]=bi[nt-1]+2.0*ci[nt-1]*hi[nt-1];
            ci[nt]=(noktalar[nt+1][1]-noktalar[nt][1]-bi[nt]*hi[nt])/pow(hi[nt],2);
            s=noktalar[nt][1]+bi[nt]*(nt2+0.001-noktalar[nt][0])+ci[nt]*pow((nt2+0.001-noktalar[nt][0]),2);
            line(650+(nt2)*16.5,357.5-s*16.5,650+(nt2+0.001)*16.5,357.5-s*16.5); //Burada eğrinin x'ine sürekli 0.001 ekleyerek çizdiriyoruz.
        }
    }

    getch();
    closegraph();
    return 0;
}

float uzaklik(float a, float b)
{
    return sqrt(a*a + b*b);
}


/*
 graphics.h kütüphanesi için gerekli olan parametreler.
 
 Project options > parameters > linker aşağıdaki parametreleri bu kısma yapıştırıyoruz.
 
-lbgi
-lgdi32
-luser32

*/
