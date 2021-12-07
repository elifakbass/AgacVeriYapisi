#include<stdio.h>
#include<stdlib.h>

struct n{
	int sayi;
	n *sag;
	n *sol;
};
typedef n agac;

agac* ekle(agac *kok,int x){
	
	if(kok==NULL){
		agac *root=(agac*)malloc(sizeof(agac));
		root->sayi=x;
		root->sag=NULL;
		root->sol=NULL;
		return root;
	}
	agac *iter=kok;
	if(iter->sayi > x){
			kok->sol=ekle(iter->sol,x);
			return kok;
    }
    if(iter->sayi < x){
    	kok->sag=ekle(iter->sag,x);
	    return kok;
	}

		
}
int a=0,b=0;
void seviye_yaz(agac *kok,int x){
	agac *gecici=kok;
	if(a+b <= x && gecici!=NULL){
		
		if(a+b==x && gecici!=NULL){
			printf("%d ",gecici->sayi);
		}
		a++;
		seviye_yaz(gecici->sol,x);
		a--;
	
		
		b++;
		seviye_yaz(gecici->sag,x);
		b--;
		
	}
	
}

int adim_sayisi(agac *kok,int x){
	int sayac=0;
	agac *gecici=kok;
	while(gecici!=NULL){
		sayac++;
		if(gecici->sayi==x)	return sayac;
	   
	    else if(gecici->sayi < x) gecici=gecici->sag;
	    
	    else if(gecici->sayi > x) gecici=gecici->sol;
	    
	}
	
	return -1;
}
int toplam=0,syc=0;
float yaprak_dugum(agac *kok){
	agac *gecici=kok;

	if(gecici!=NULL){
		if(gecici->sag==NULL && gecici->sol==NULL){
		syc++;
		toplam+=gecici->sayi;
	}
		yaprak_dugum(gecici->sol);
	    yaprak_dugum(gecici->sag);
	}
	
	
	
	return (float)toplam/syc;
	
}
void byk_yaz(agac *kok,int x){
	agac *gecici=kok;
	if(gecici!=NULL){
		if(gecici->sayi > x){
			printf("%d ",gecici->sayi);
		}
		byk_yaz(gecici->sol,x);
		byk_yaz(gecici->sag,x);
	}

}


int main(){
	agac *kok=NULL;
	int sayi,secim=1,y,z,sonuc,a;
	while(secim){
		printf("sayi giriniz:");scanf("%d",&sayi);
	    kok=ekle(kok,sayi);
	    printf("devam etmek icin 1'e basiniz(cikis icin 0'a basiniz.):");scanf("%d",&secim);
	
	}
	printf("yazdirmak istediginiz seviyeyi giriniz:");scanf("%d",&y);
	printf("%d. seviyedeki elemanlar:",y);seviye_yaz(kok,y);

	printf("\nkac adimda bulundugunu ogrenmek icin sayi giriniz:");scanf("%d",&z);
	sonuc=adim_sayisi(kok,z);
	if(sonuc==-1){
		printf("%d sayisi bulunamadi!");
	}
	else{
		printf("%d elemani %d adimda bulundu.",z,sonuc);
	}
	float snc=yaprak_dugum(kok);
	printf("\nyaprak dugumlerinin ortalamasi:%.2f",(float)snc);
	
	printf("\nhangi degerden buyuk sayilari yazdirmak istersiniz:");scanf("%d",&a);
	byk_yaz(kok,a);
	
	
	
	return 0;
}
