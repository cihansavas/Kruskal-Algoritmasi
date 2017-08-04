#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <graphics.h>
#include <iostream>

int nereden=0,nereye=1,uzaklik=2,yolindex=3,X_kordinat=0,Y_kordinat=1,pixel_x,pixel_y;
void matrisgorsel(int dugumsayisi,int Matris[][4],int YedekMatris[][4])
{
    int j,i,k=0,y=60;

    for(i=0;i<=dugumsayisi;i++)//KARE MATRİS TABLO OLUŞTURMA
    {
line(600,i*30+40,600+dugumsayisi*30,i*30+40);
line(600+i*30,40,600+i*30,40+dugumsayisi*30);
    }
for(i=0;i<dugumsayisi;i++)  //MATRiSiN DİKEY DUGUM ADI
    {
char s1[20];
sprintf(s1,"D%d",i);
  outtextxy(570,30*i+50,s1);
  outtextxy(605+i*30,20,s1);
    }



int sayac=0;
    for(k=0;k<dugumsayisi;k++)
    {
char s1[20];
sprintf(s1,"%d",YedekMatris[sayac][uzaklik]);
sayac++;
    //printf("sayac:%d-uzaklık:%d\n",sayac,YedekMatris[sayac][uzaklik]);
    outtextxy(600+15,30*k+50,s1);
    for(i=1;i<dugumsayisi;i++)
    {
char s2[20];
sprintf(s2,"%d",YedekMatris[sayac][uzaklik]);
sayac++;
//printf("sayac:%d-uzaklık:%d\n",sayac,YedekMatris[sayac][uzaklik]);
        outtextxy(600+i*30+10,30*k+50,s2);
    }
    }




}


void grafikdugum(int sayac, int kruskalsehir[], int cizimyap[][2], int Matris[][4],int dugumsayisi,int YedekMatris[][4],int toplamyoluzunlugu)
{
    int driver,mode,errcode=0;
    driver=DETECT;

   // initgraph(&driver,&mode,"C:\\TC\\BGI");

int ekran=initwindow(1240,680);
    //Garafik Ekran Yükleme Hatalarý
    errcode=graphresult();
    if(errcode!=0)
    {
        printf("graph error:%d",errcode);
        exit(1); //hata ile cik
    }
int j,i=1;
char s1[100],s2[100];

//int baslangicsehri,bitissehri,yolindeksi;  buraya matrisigönder ordan  işlem yapcan
outtextxy(600,0,"DUGUMLER ARASI UZAKLIK BILGISI ASAGIDAKI TABLODA YER ALMAKTADIR");
matrisgorsel(dugumsayisi,Matris,YedekMatris);
for(j=0;j<=20;j++)
{
sprintf(s1,"%d",j);
outtextxy(25*j+20,0,s1);
outtextxy(0,20*j+20,s1);
}


rectangle(20,18,550,18);
rectangle(18,18,18,420);
setcolor(YELLOW);
line(565,0,565,800);
setcolor(WHITE);


for(i=0;i<dugumsayisi;i++)//HARFLERİ YAZDIR
{
char s1[100]="D",s2[100];
sprintf(s2,"%d",i);
strcat(s1,s2);

outtextxy(cizimyap[i][0]*25+20,cizimyap[i][1]*20+20,s1);

}
int yol,sehirnereden,sehirnereye;
for(i=0;i<dugumsayisi*dugumsayisi;i++)//TÜM YOLLAR
{
yol=i;
sehirnereden=Matris[yol][nereden];
sehirnereye=Matris[yol][nereye];
line(cizimyap[sehirnereden][X_kordinat]*25+20,cizimyap[sehirnereden][Y_kordinat]*20+20,cizimyap[sehirnereye][X_kordinat]*25+20,cizimyap[sehirnereye][Y_kordinat]*20+20);
Sleep(100);
}

setcolor(RED);
setlinestyle(0,10,3);
for(i=0;i<sayac;i++)//KRUSKAL SONUÇ ÇİZGİSİ
{
yol=kruskalsehir[i];
sehirnereden=Matris[yol][nereden];
sehirnereye=Matris[yol][nereye];
line(cizimyap[sehirnereden][X_kordinat]*25+20,cizimyap[sehirnereden][Y_kordinat]*20+20,cizimyap[sehirnereye][X_kordinat]*25+20,cizimyap[sehirnereye][Y_kordinat]*20+20);
Sleep(1000);
}

for(i=0;i<dugumsayisi;i++)//HARFLERİ YAZDIR
{
char s1[20]="D",s2[20];
sprintf(s2,"%d",i);
strcat(s1,s2);
outtextxy(cizimyap[i][X_kordinat]*25+20,cizimyap[i][Y_kordinat]*20+20,s1);

}

sprintf(s1,"%s","GRAFIKTE BELIRTILEN KRUSKAL'IN TOPLAM MALIYETI=");
sprintf(s2,"%d BIRIM",toplamyoluzunlugu);
strcat(s1,s2);
setcolor(8);
outtextxy(0,470,"EN KISA YOL SORGUSU TAMAMLANDI");
line(0,490,250,490);
setcolor(9);
outtextxy(0,500,s1);

getch();
closegraph(ekran);
//setcurrentwindow
int x;
scanf("%d",&x);

}



void matrisigoster(int dugumsayisi,int Matris[][4],int YedekMatris[][4])
{
    int sutunkaydir=0,kontrol=0,satir=0;

    for(int i=0;i<dugumsayisi*dugumsayisi;i++)
{
    printf("D%d-D%d ARASi= %d KM\n",Matris[i][nereden],Matris[i][nereye],Matris[i][uzaklik]);

char s1[20];
//**********************ALTTAKİ KOD SATIR VE SUTUNA GORE YAZDIRABİLİYOR
sprintf(s1, "%d - %d ARASi= %d KM",YedekMatris[i][nereden],YedekMatris[i][nereye],YedekMatris[i][uzaklik]);
if(kontrol==20)
{
sutunkaydir+=150;
satir=0;
kontrol=0;
}
kontrol++;
outtextxy(sutunkaydir,satir*25+20,s1 );
satir++;
//strcat(s1,s2);
//outtextxy(cizimyap[i][0]*20+20,cizimyap[i][1]*20+20,s1);
//pixel_x=0;
//pixel_y=i*25+50;
}
//pixel_y+=25;
}
int sirala(int dugumsayisi, int matris[][4])
{
int g1,g2,g3,adet=dugumsayisi*dugumsayisi;

//BU DONGUDE YOL UZUNLUKLARINI SIRALAYACAĞIZ AYNI ZAMANDA YOL İNDEXLERİDE YER DEĞİŞTİRECEK
for( int j=2;j<adet;j++)
{
for(int k=0;k<j;k++)
{
     if (matris[k][uzaklik]>matris[j][uzaklik])
      {
        //YOL UZUNLUKLARI YER DEĞİŞTİRİYOR
        g1=matris[k][nereden];
        g2=matris[k][nereye];
        g3=matris[k][uzaklik];
       matris[k][nereden]=matris[j][nereden];
       matris[k][nereye]=matris[j][nereye];
       matris[k][uzaklik]=matris[j][uzaklik];

         matris[j][nereden]=g1;
        matris[j][nereye]=g2;
        matris[j][uzaklik]=g3;
      }
    }
  }
}

void CihanCihatMehmetKuruskal(int dugumsayisi,int Matris[][4],int Dugum[][2],int YedekMatris[][4])//DİKKAT ALAN KODUNU ve Bölge kodunu dugumsayisi kadar DOLDUR
{
int yoltoplamuzunluk=0,alansirasi=0,alankodu[dugumsayisi],bolgekodu[dugumsayisi],kruskalsehir[dugumsayisi],sayac=0;/*BÖLGE KODU HER DÜĞÜMÜN BAŞLANGIÇ DEĞERİNİ GÖSTERİR

EĞER DÜĞÜM GEZİLİRSE BAŞLANGIÇ DEĞERİNE ALAN KODU ATANACAK bolgekodu nun her bir değeri aslında bir köyün alan kodunu
göstermektedir. bolgekodu[4] yani 4 tane dugumun gezilip gezilmediği durumununu belirtir 0 gezilmemiş anlamındadır alankodu
aynı zaman diliminde gezilip gezilmediğini belirtir.*/
 //alankodu[dugumsayisi]={100,200,300,400},bolgekodu[4]={0,0,0,0};/*ÖRNEKTİR
int i;
 for(i=1;i<=dugumsayisi;i++)
 {

     alankodu[i-1]=i*100;
     bolgekodu[i-1]=0;
}

int baslangic,bitis,index,s,kontrol=0;
for(s=0;s<dugumsayisi*dugumsayisi;s++)// TÜM YOL SORGULARindex YAPILIYOR
{

    //index=yolindex[s];
    if(Matris[s][uzaklik]>0)//YOL UZUNLUĞU 0 DEĞİLSE
    {
baslangic=Matris[s][nereden];//Hangi sehirden
bitis=Matris[s][nereye];

//hangi sehire gidiliyor?
//printf("\n\nkontrol=%d-%d",baslangic,bitis);
if(bolgekodu[baslangic]==0&&bolgekodu[bitis]==0) //gidilen şehirlere ilk kez mi gidilmiş ilk kez se başlangıç  0 değilse  alan kodu atayacaz
{
printf("\n\nD%d-D%d ARASi=%d birim==> D%d ve D%d dugumleri ilk kez geziliyor",Matris[s][nereden],Matris[s][nereye],Matris[s][uzaklik],Matris[s][nereden],Matris[s][nereye]);
 bolgekodu[baslangic]=alankodu[alansirasi];
bolgekodu[bitis]=alankodu[alansirasi];
alansirasi++;// bir sonraki sorgulamada eğer 2 şehirde gezilmemişse farklı bölge kodu atanacak
yoltoplamuzunluk=yoltoplamuzunluk+Matris[s][uzaklik];
kruskalsehir[sayac]=Matris[s][yolindex];
sayac=sayac+1;
}
else if(bolgekodu[baslangic]!=0&&bolgekodu[bitis]==0)//1. şehir gezilmiş 2. şehir gezilmemişse
{
    printf("\n\nD%d-D%d ARASi=%d birim==>D%d dugumu gezilmis ;D%d ise ilk kez geziliyor",Matris[s][nereden],Matris[s][nereye],Matris[s][uzaklik],Matris[s][nereden],Matris[s][nereye]);
bolgekodu[bitis]=bolgekodu[baslangic];//AYNI YOL DÜZERGAHINA BAĞLANMIŞ OLDULAR;
yoltoplamuzunluk=yoltoplamuzunluk+Matris[s][uzaklik];

kruskalsehir[sayac]=Matris[s][yolindex];
sayac=sayac+1;


}
else if(bolgekodu[baslangic]==0&&bolgekodu[bitis]!=0)//1. şehir gezilmemiş 2. şehir gezilmişse
{
     printf("\n\nD%d-D%d ARASi=%d birim==>D%d dugumu gezilmis ;D%d ise ilk kez geziliyor",Matris[s][nereden],Matris[s][nereye],Matris[s][uzaklik],Matris[s][nereye],Matris[s][nereden]);

bolgekodu[baslangic]=bolgekodu[bitis];//AYNI YOL DÜZERGAHINA BAĞLANMIŞ OLDULAR;
yoltoplamuzunluk=yoltoplamuzunluk+Matris[s][uzaklik];
kruskalsehir[sayac]=Matris[s][yolindex];
sayac=sayac+1;


}
else if(bolgekodu[baslangic]!=0&&bolgekodu[bitis]!=0&&bolgekodu[baslangic]!=bolgekodu[bitis])//HER 2 ŞEHİRDE GEZİLMİŞSE ancak bolge kodları farklıysa
{
//printf("\n\nbaslangic:%d,bitis:%d\n",baslangic,bitis);
//printf("\n\nbolbaslangic:%d,bolbitis:%d\n",bolgekodu[baslangic],bolgekodu[bitis]);
printf("%\n\nD%d-D%d ARASi=%d birim==>D%d dugumu gezilmis ;D%d dugumude gezilmis ancak her iki dugum farkli zamanlarda gezilmis",Matris[s][nereden],Matris[s][nereye],Matris[s][uzaklik],Matris[s][nereden],Matris[s][nereye]);
//AYNI YOL DÜZERGAHINA BAĞLANMIŞ OLDULAR ;
yoltoplamuzunluk=yoltoplamuzunluk+Matris[s][uzaklik];
int x,ilk,son;
ilk=bolgekodu[baslangic];
son=bolgekodu[bitis];
kruskalsehir[sayac]=Matris[s][yolindex];
sayac=sayac+1;

for(x=0;x<dugumsayisi;x++)
{
if(bolgekodu[x]==son)
{

    bolgekodu[x]=ilk;
    x=0;

}
}
}
}
}

printf("\n\nCOZUMLEME iSLEMi TAMAMLANDi;\n***********************************************\n YUKARiDA BELiRTiLEN EN KiSA YOLUN TOPLAM UZUNLUGU=%d BiRiMDiR\n\n",yoltoplamuzunluk);
//sprintf(s1,"YUKARIDA BELIRTILEN EN KiSA YOLUN TOPLAM UZUNLUGU= %d BIRIMDIR",yoltoplamuzunluk);
outtextxy(0,700,"asd");
grafikdugum(sayac,kruskalsehir,Dugum,Matris,dugumsayisi,YedekMatris,yoltoplamuzunluk);

}



int main()
{

    int hata=1,i,j,x,y;//matris[satir][nereden,nereye,uzaklık,yolindex]
    int dugumsayisi;int bayrak=0;
dugumal:
    char karaktermi[8],krsay=0;
    printf("\nDugum sayisini giriniz:\n");

     fgets(karaktermi,8,stdin);


 for(i=0;i<strlen(karaktermi);i++)
{
    if ( isalpha(karaktermi[i])|| ispunct(karaktermi[i]) )
{
    printf("\nHATALI GIRIS YAPTINIZ(HARF VEYA OZEL KARAKTER) \nLUTFEN [0-400] SAYI GIRINIZ \n");
goto dugumal;
}


}

sscanf(karaktermi,"%d",&dugumsayisi);
//dugumsayisi=atoi(karaktermi);


    if(dugumsayisi>400)
    {
        system("cls");
        printf("DUGUM SAYISI 400 DEN FAZLA OLAMAZ LUTFEN TEKRAR GIRIS YAPINIZ\n(YANLIS GIRIS SAYISI %d)\n\n",hata);
        hata++;
        goto dugumal;
    }
    else if(dugumsayisi>254&&dugumsayisi<=400)
    {
     printf("\nRAM'DE YETERLI ALAN YOK\nLUTFEN FARKLI BIR DEGER GIRINIZ.[ ORNEK= 0-254]\n\n");
     goto dugumal;
    }

    printf("\nlutfen asagida belirtilen dugumlerin [x][y] kordinat bilgilerini giriniz\n**************************************************************************\n");
//DUĞUM MATRİSİĞ DUGUME AİT X VE Y DEĞERLERİNİ TUTAR.
int w,Dugum[dugumsayisi][2],Matris[dugumsayisi*dugumsayisi-1][4],YedekMatris[dugumsayisi*dugumsayisi-1][4];
for(i=0;i<dugumsayisi;i++)
{
yeniden_x:
    printf("D%d dugumune ait [x] kordinatini giriniz:  ",i);
     fgets(karaktermi,8,stdin);
  for(w=0;w<strlen(karaktermi);w++)
{
    if ( isalpha(karaktermi[w])|| ispunct(karaktermi[w]) )
{
    printf("\nHATALI GIRIS YAPTINIZ(HARF VEYA OZEL KARAKTER) \nLUTFEN [0-20] SAYI GIRINIZ \n");
goto yeniden_x;
}
}
    sscanf(karaktermi,"%d",&x);

    if(x>20||x<0)
    {
    printf("\nHATALI GIRIS YAPTINIZ LUTFEN 0-20 ARASI BIR DEGER GIRINIZ\n");
    goto yeniden_x;
    }
    Dugum[i][0]=x;
yeniden_y:
	printf("D%d dugumune ait [y] kordinatini giriniz:  ",i);
	 fgets(karaktermi,8,stdin);
  for(w=0;w<strlen(karaktermi);w++)
{
    if ( isalpha(karaktermi[w])|| ispunct(karaktermi[w]) )
{
    printf("\nHATALI GIRIS YAPTINIZ(HARF VEYA OZEL KARAKTER) \nLUTFEN [0-20] SAYI GIRINIZ \n");
goto yeniden_y;
}
}
     sscanf(karaktermi,"%d",&y);
    if(y>20||y<0)
    {
    printf("\nHATALI GIRIS YAPTINIZ LUTFEN 0-20 ARASI BIR DEGER GIRINIZ\n");
    goto yeniden_y;
    }
    Dugum[i][1]=y;
    for(j=0;j<i;j++)
    {
if(Dugum[i][0]==Dugum[j][0]&&Dugum[i][1]==Dugum[j][1])
{
    printf("\n\n%d,%d KORDINATI SISTEMDE KAYITLIDIR\n LUTFEN BASKA BIR DUGUM GIRINIZ\n\n",x,y);
goto yeniden_x;
}
    }

}
 int ekran=initwindow(1240,680);
   outtextxy(100,0,"GRAFLARDA EN KiSA YOL (KRUSKAL ALGORiTMASI)");
int a=0,b=0;
for(int i=0;i<dugumsayisi*dugumsayisi;i++)
{
Matris[i][nereden]=a;
  Matris[i][nereye]=b;
  Matris[i][uzaklik]=fabs(Dugum[a][0]-Dugum[b][0])+fabs(Dugum[a][1]-Dugum[b][1]);
  Matris[i][yolindex]=i;

  YedekMatris[i][nereden]=a;
  YedekMatris[i][nereye]=b;
  YedekMatris[i][uzaklik]=fabs(Dugum[a][0]-Dugum[b][0])+fabs(Dugum[a][1]-Dugum[b][1]);
  YedekMatris[i][yolindex]=i;

  b++;
  if(b==dugumsayisi)
  {
      b=0;
      a++;
  }
}
matrisigoster(dugumsayisi,Matris,YedekMatris);
printf("\n\nEN KISADAN EN UZUNA DOGRU YOL BiLGiSi ASAGiDA SiRALANMiSTiR\n***************************************************************\n");

sirala(dugumsayisi,Matris);
matrisigoster(dugumsayisi,Matris,YedekMatris);
printf("\n\nEN KISA YOL SORGUSU YAPILIYOR(BASLANGiC-->BiTiS=YOL UZUNLUGU)\n*****************************************\n");
//outtextxy(0,300,"EN KISA YOL SORGUSU YAPILIYOR(BASLANGiC-->BiTiS=YOL UZUNLUGU)");

//grafikgosterim(dugumsayisi,Dugum);
CihanCihatMehmetKuruskal(dugumsayisi,Matris,Dugum,YedekMatris);//DİKKAT BU KOD sirala(dugumsayisi,yoluzunluklari,yolindeks); ten sonra çalıştırılmalı çünkü indeksler sıralandıktan sonra yol sorgulaması yapılacak

}

