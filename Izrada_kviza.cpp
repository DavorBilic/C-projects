#include <stdio.h>
#include<stdlib.h>
#include<time.h>

/*************************************************************************************************************************************
	SLJEDEĆI PROGRAM ČINI JEDNOSTAVAN KVIZ... NA POČETKU KVIZA NA POTEZU JE PRVI IGRAČ, TE ON DOBIJA PET PITANJA REDOM...
   POMOĆU KONZOLE ODGOVARA NA SVAKO PITANJE, A TOČNOST PITANJA SE PROVJERAVA... NAKON TOGA JE NA POTEZU DRUGI IGRAČ ZA 
   KOJEGA VRIJEDI ISTO... PO ZAVRŠETKU KVIZA NA EKRAN SE ISPISUJE BROJ TOČNIH ODGOVORA OBA IGRAČA, TE KOJI IGRAČ JE POBJEDIO... 
   POMOĆU RANDOM NUMBER GENERATORA GENERIRA SE BROJ OD 1 DO 20 NA OSNOVU KOJEGA SE BIRA JEDNO PITANJE IZ BAZE 
   (BROJ JE 1-20 JER JE 20 PITANJA U BAZI)... 
**************************************************************************************************************************************/
/*																										AUTOR: DAVOR BILIC			*/
   
void pitanje_odgovor(int a);				// deklaracija funkcije za pitanje i odgovor
void random_number(int* a);				// deklaracija funkcije random_number
void pobjeda(int* m, int* n);				// deklaracija funkcije za proglasenje pobjednika

static int brojac = 0;						

int main(){
	int rnd_broj, i, j, prvi, drugi;		
	
	printf("Prvi igrac je na potezu: \n \n");
	for(i = 0; i < 5; i++){
		random_number(&rnd_broj);			
		pitanje_odgovor(rnd_broj);			
		system("pause");			// pauza sustava radi bolje preglednosti
	}
	
	prvi = brojac;				// vrijednost brojaca (tocnih odgovora) spremamo u varijablu prvi koji postaje brojac tocnih odgovora prvog igraca
	
	
	printf("Drugi igrac je na potezu: \n \n");
	for(j = 0; j < 5; j++){
		random_number(&rnd_broj);			
		pitanje_odgovor(rnd_broj);			
		system("pause");					
	}
	
	drugi = brojac - prvi;					// brojac nastavlja brojati, pa mu zato oduzmemo broj prvi, kao da je poceo od broja prvi brojati
	
	pobjeda(&prvi, &drugi);					// poziv funkcije za proglasenje pobjednika, slanje adresa brojaca prvi i drugi
	
}

// funkcija koja kao argument prima random broj te na osnovu njega bira koje pitanje će se postaviti igraču
// nakon toga igrac odgovara na pitanje koje se provjerava
// ukoliko je tocno brojac se povecava za 1
void pitanje_odgovor(int a){						
	int odg;					

	switch(a){							
		case 1:									
			printf("Kako glasi mnozina rijeci 'vrabac'?\n");
			printf("1) vrapcevi\n2) vrabaci\n3) vrapci \n4) vrabci\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 3){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !! \n \n");
			
			break;
		case 2:
			printf("Kako glasi mnozina rijeci 'orah'?\n");
			printf("1) orasi\n2) orahi\n3) orahovi \n4) orahsi\n");
			printf("\n");
			
			printf("Unesite odgovor: \n \n");
			scanf("%d", &odg);
			
			if(odg == 1){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n");
				
			break;
		case 3:
			printf("Kako glasi mnozina rijeci 'stol'?\n");
			printf("1) stolovi\n2) stolevi\n3) stoli \n4) stolovci\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 1){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;
		case 4:
			printf("Kako glasi mnozina rijeci 'rep'?\n");
			printf("1) repci\n2) repovi\n3) repevi \n4) repi\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 2){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;
		case 5:
			printf("Sto znaci ovaj pojam - homonimi?\n");
			printf("1) rijeci razlicitog znacenja, a jednakog izraza\n2) rijeci razlicitog izraza a jednakog znacenja\n3) rijeci razlicitog izraza i jednakog znacenja \n4) rijeci razlicitog izraza i razlicitog znacenja\n");	
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 1){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;
		case 6:
			printf("Sto znaci ovaj pojam - gradacija?\n");
			printf("1) postupno pojacavanje ili slabljenje\n2) ponavljanje rijeci na pocetku stihova\n3) oponasanje zvukova iz prirode \n4) ponavljanje rijeci na kraju stihova\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 1){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;
		case 7:
			printf("Sto znaci ovaj pojam - aluzija?\n");
			printf("1) izbor izmedju dviju mogucnosti \n2) jezgrovita, smislena i duhovita izreka \n3) ciljanje rijecima na nesto drugo od onog sto se kaze \n4) oponasanje zvukova iz prirode\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 3){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;
		case 8:
			printf("Eliza ima 14 godina, a Luka je dvostruko stariji od Elize. Koliko ce Luka imati godina kada Eliza bude imala 30 godina?\n");
			printf("1) 28\n2) 44\n3) 46 \n4) 60\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 2){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;
		case 9:
			printf("Koji broj bi trebao ici nakon ovih brojeva: 48, 24, 12,........ ?\n");
			printf("1) 16\n2) 6\n3) 2 \n4) 4\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 2){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;	
		case 10:
			printf("Koliko vrhova ima kocka?\n");
			printf("1) 12\n2) 6\n3) 8 \n4) 4\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 3){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;	
		case 11:
			printf("Sve tri Leove sestre imaju kceri, a Leo ima ukupno 12 necakinja. Svaka necakinja ima jednog brata. Koliko Leo ima necaka?\n");
			printf("1) 12\n2) 6\n3) 3 \n4) 9\n");
			printf("\n");
			
			printf("Unesite odgovor: \n \n");
			scanf("%d", &odg);
			
			if(odg == 3){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;	
		case 12:
			printf("Ako preslozis slova u rijeci 'TOOKY' dobit ces ime...?\n");
			printf("1) grada\n2) rijeke\n3) planine \n4) drzave\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 1){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;	
		case 13:
			printf("U kojoj talijanskoj regiji se nalazi grad Pisa?\n");
			printf("1) Lombardiji\n2) Siciliji\n3) Toskani \n4) Kalabriji\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 3){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;	
		case 14:
			printf("U kojem europskom gradu su odrzane VI. Zimske olimpijske igre?\n");
			printf("1) Stockholmu\n2) Oslu\n3) Londonu \n4) Rigi\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 2){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;	
		case 15:
			printf("Koje je ime grad Vukovar nosio sve do 14. stoljeca?\n");
			printf("1) Vukovo\n2) Vrankovo\n3) Vukovaran \n4) Vukovari\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 1){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;
		case 16:
			printf("Koji je najveci grad Svicarske?\n");
			printf("1) Bern\n2) Basel\n3) Geneva \n4) Zurich\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 4){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;	
		case 17:
			printf("Kazalisni okrug West End nalazi se u kojem gradu?\n");
			printf("1) Amsterdamu\n2) Londonu\n3) Dublinu \n4) Glasgowu\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 2){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;	
		case 18:
			printf("Koji je vulkan nastao urusavanjem vulkana Some?\n");
			printf("1) Etna\n2) Erebus\n3) Pinatubo \n4) Vezuv\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 4){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;
		case 19:
			printf("Koji glumac igra naslovnu ulogu u filmu 'Spasavanje vojnika Ryana?\n");
			printf("1) Tom Hanks\n2) Al Pacino\n3) Brad Pitt \n4) Matt Damon\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 4){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;	
		case 20:
			printf("Oblik kojeg geometrijskog tijela opisuje os Zemljine vrtnje?\n");
			printf("1) krug\n2) elipsa\n3) stozac \n4) kocka\n");
			printf("\n");
			
			printf("Unesite odgovor: \n");
			scanf("%d", &odg);
			
			if(odg == 3){
				brojac++;
				printf("Odgovor je tocan !! \n \n");}
			else
				printf("Odgovor je netocan !!\n \n");
				
			break;				
	}
}

void random_number(int* a){				
	srand(time(0));						 
    *a = rand() % 20;					
}

void pobjeda(int* m, int* n){
	printf("Prvi igrac je imao %d tocnih odgovora. \n \n", *m);		// ispis broja tocnih odgovora na ekran (prvi)
	printf("Drugi igrac je imao %d tocnih odgovora. \n \n", *n);		// ispis broja tocnih odgovora na ekran	(drugi)
	
	if(*m > *n)
		printf("Prvi igrac je pobjedio !! \n");
	else if(*m == *n)
		printf("Rezultat je izjednacen !! \n");
	else
		printf("Drugi igrac je pobjedio !!");
}
