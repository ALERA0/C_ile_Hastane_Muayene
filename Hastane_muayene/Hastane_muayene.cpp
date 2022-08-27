#include <iostream>
#include <queue>
#include <list>

using namespace std;


class Insan{
	protected:
		string ad;
		int yas;
		bool engelliMi;
	public :
		Insan(string ad,int yas,bool engelliMi=false):ad(ad),yas(yas),engelliMi(engelliMi){    }
		void yazdir()const{
			cout << "Ad :"<< ad<<endl
				 << "Yas :"<< yas<< endl
				 <<"Engellilik durumu :";
				 if(engelliMi)
				 	cout<<"Evet ";
				else
					cout<<"Hayir ";
				cout << endl;
		}
		
	
};
class Hasta:public Insan{
	int hastaNo;
	int oncelikPuani;
	public:
		Hasta(int hastaNo,Insan& i): hastaNo(hastaNo),Insan(i),oncelikPuani(0){
			oncelikPuaniHesapla();
		}
		Hasta(int hastaNo,string ad,int yas,bool engelliMi=false) : hastaNo(hastaNo),Insan(ad,yas,engelliMi),oncelikPuani(0){
			oncelikPuaniHesapla();
		}
		void oncelikPuaniHesapla(){
			if(engelliMi)
				oncelikPuani+=30;
			if(yas>65)
				oncelikPuani+=yas-65;
		}
		
		bool operator <(const Hasta& h)const{
			return oncelikPuani< h.oncelikPuani;
		}
		
		void yazdir()const{
			cout << "Hasta No : " << hastaNo << endl;
			Insan :: yazdir();
			cout << "Oncelik Puani: "<< oncelikPuani << endl;
			
		}
};

class HastaKayit {
	list<Hasta> kayitSirasi;
	priority_queue<Hasta> muayeneSirasi;
	public:
		void kayit(Insan& i){
			Hasta hasta(kayitSirasi.size()+1,i);
			kayitSirasi.push_back(hasta);
			muayeneSirasi.push(hasta);
		}
		
		void kayitSirasiYazdir(){
			cout<<"### Hasta Kayit Sirasi ###"<< endl;
			if(kayitSirasi.empty())
				cout<<"Kayitli hasta yok"<<endl;
			else{
				list<Hasta>::iterator iter = kayitSirasi.begin();
				while(iter != kayitSirasi.end()){
					Hasta hasta =* iter;
					hasta.yazdir();
					iter++;
					if(iter!= kayitSirasi.end())
						cout<<endl;
				}
				
			}
			cout<<"### Hasta Kayit Sonu ###"<<  endl;
			
		}
		void muayeneSirasiYazdir(){
			cout<<"### Muayene Kayit Sirasi ###"<< endl;
			if(muayeneSirasi.empty())
				cout<<"Muayene bekleyen hasta yok"<<endl;
			else{
				priority_queue<Hasta> kuyruk = muayeneSirasi;
				while(!kuyruk.empty()){
					Hasta hasta = kuyruk.top();
					hasta.yazdir();
					kuyruk.pop();
					if(!kuyruk.empty())
						cout <<endl;					
				}
			}
			cout<<"### Muayene Sirasi Sonu ###"<<  endl;
			cout<<endl;
		}
		
		void hastaCagir(){
			cout<<"### Muayenehaneye cagirilan hasta bilgileri ###"<<endl;
			if(muayeneSirasi.empty())
				cout << "Muayene için bekleyen hasta yok."<<endl;
			else{
				Hasta hasta = muayeneSirasi.top();
				hasta.yazdir();
				muayeneSirasi.pop();
				
			}
			cout<< endl;
		}
			
};


int main(){
	Insan insanlar []={
		Insan ("Arif",30),
		Insan ("Ali",35,1),
		Insan ("Kemal",70),
		Insan ("Veli",55,1),
		Insan ("Fatma",75,1),
		Insan ("Aliye",45)
	};
	
	HastaKayit banko;
	
	banko.kayit(insanlar[0]);
	banko.kayit(insanlar[1]);
	banko.kayit(insanlar[2]);
	banko.kayit(insanlar[3]);
	banko.kayit(insanlar[4]);
	banko.kayit(insanlar[5]);
	banko.kayitSirasiYazdir();
	cout<< endl;
	banko.muayeneSirasiYazdir();
	
	
	return 0;
}
