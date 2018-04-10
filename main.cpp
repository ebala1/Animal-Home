#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>              //Wird benötigt, da ich Dateien einlesen/erstellen werde
#include "tierheimjia.h"       //Hier wird die Header-datei durch include für die main.cpp sichtbar gemacht, damir auf Daten im Datein zurückgegriffen werden kann

#include <sstream>              // Da ich die ifstream/fstream/ofstream funktionen benutze muss dies hinzugefügt werden, sonst funktioniert es nicht
#include <string>               // Für die Variablen string

using namespace std;


int main()                      //Die Oberfunktion beginnt hier mit dem int main()
{
    char Auswahl;


 do                            //An dieser Stelle beginnt die do-Schleife, welche die switch-Funktionen für die Menüführung beinhaltet
 {
    //Hier wird mithilfe von cout ein Menü erzeugt, welches den Benutzern zeigt, was mit diesem Programm ausgeführt werden kann

    cout << "Willkommen im Startmenue fuer unser Tierheimprogramm \n" << endl;             // Bei diesen "cout" Befehlen wird der Benutzer auf das Programm aufmerksam gemacht, bedeutet dem Benutzer werden hier die Funktionen für seine Auswahl bekannt gegeben.
    cout << "Tippen Sie die (1) um die Tierinformationen zu oeffnen." << endl;
    cout << "Tippen Sie die (2) um unseren Gehegeplan zu oeffnen.(In XML-Format)" << endl;
    cout << "Tippen Sie die (3) um beide Dateien in eine zu speichern." << endl;
    cout << "Tippen Sie die (4) um unseren Gehegeplan zu oeffnen. (In Text-Format)" << endl;
    cout << "Tippen Sie die (5) um das Programm zu beenden!" << endl;


    cout << "Eingabe: " << endl;
    cin >> Auswahl;                 //Hier ist die Eingabe der Benutzer sehr wichtig, da diese Eingabe (1,2,3,4 oder 5) entscheiden wird zu welchen Case das Programm springen wird und was es ausführen wird.

    // Bei Auswahl 1 vom Benutzer wird hier die Xml Datei geladen:
    switch (Auswahl) {      // "Auswahl" steht für die Auswahl, welcher der Benutzer in cin in der Zeile 31 eingibt.
    case ('1'):    // Bei Auswahl von der Nummer 1 wird diese nachfolgende Funktionen ausgeführt:

        cout << "Tierinformationen werden geladen.... \n"<< endl;      // Erst erscheint ein cout, dieses hat kein entscheidenden Zweck und dient nur zur Orientation, um sehen zu können was jetzt geladen wird.



        string line;            // string line, weil die nachfolgende Funktion einen string ("line") erfordert
        ifstream myfile ("tierxml.xml");  // ifstream <- da wir die Datei lesen wollen

        if (myfile.is_open())           // hier fängt das Programm mit der if/while/else Funktion zu kontrollieren. "myfile" ist die Datei, die im Ordner schon besteht und is.open öffnet die Datei um im nachfolgenden mi der Datei arbeite zu können.
        {
        while ( getline (myfile,line) ) // Wenn die Datei myfile(tierxml.xml) vorhanden ist soll etwas damit geschehen.
        {
         cout << line << '\n';          // durch die cout Funktion wird der ganze Inhalt durch "line" in der Konsole angezeigt. Die Datei wird genauso wie das XML-Beispiel auf der HKI-Seite für die Semesterarbeit.
         }
        myfile.close();                 // Hier wird die Datei wieder nach dem Öfnnen und lesen geschlossen.
       }

     else cout << "Datei nicht moeglich zu oeffnen \n"; // Falls die Datei nicht vorhanden ist oder andere Komplikationen verhindern sollten die Datei zu lesen, wird durch den else Aufruf, das Problem dem Benutzer mitgeteilt
      break;


}
 //Textdatei wird bei Angabe von 2 geladen :
    switch (Auswahl) {        // eine weitere switch-Funktion wird für die Auswahl des Benutzers erstellt.Dieses Mal für die Auswahl 2.
    case ('2'):
        cout << "Gehegeplan wird geladen....(Im XML-Format)\n"<< endl; // Sobald 2 gewählt wird erscheint dies

       // string line;

        string id;              //Alle nötigen Variablen werden durch einen string hier ergänzt. Dies erleichtert das parsen der Datei und es wird übersichtlicher.
        string etage;           // In der txt. Datei sind Daten für die ID, die Etage und den Raum der Tiere, welche in der xml-Datei beschrieben wurden.
        string raum;
        string id1;
        string etage1;
        string raum1;
        string id2;
        string etage2;
        string raum2;
        ifstream myfile ("tierheimtxt.txt"); // Genauso wie im Beispiel für die xml-Datei wird hier ifstream zum lesen der Datei benutzt.
        myfile >> id;                        // Hier werden die Wörter in der Datei nach den strings benannt, damit sie später herausgelesen werden können.
        myfile >> etage;
        myfile >> raum;
        myfile >> id1;
        myfile >> etage1;
        myfile >> raum1;
        myfile >> id2;
        myfile >> etage2;
        myfile >> raum2;
        cout << "-<listGehegeplan>" << endl;                      //Ab hier werden die Wörter in die Konsole geschrieben/gelesen und sind sichtbar für den Benutzer.
        cout << "<Id>" << id << "</Id>\n" << endl;      // bei "id" wird das Wort in der Datei für id hineingefügt/herausgelesen
        cout << "<Etage>" << etage  << "</Etage>\n" <<endl;
        cout << "<Raum>" << raum  << "</Raum>\n"<<endl;

        cout << "<Id>" << id1  << "</Id>\n"<<endl;
        cout << "<Etage>" << etage1  << "</Etage>\n"<<endl;
        cout << "<Raum>" << raum1  << "</Raum>\n"<<endl;

        cout << "<Id>" << id2  << "</Id>\n"<<endl;
        cout << "<Etage>" << etage2  << "</Etage>\n"<<endl;
        cout << "<Raum>" << raum2  << "</Raum>\n"<<endl;
        cout << "-</listGehegeplan>"  << endl;
        break;


    }
    switch (Auswahl) {
    case ('3'):             //Bei der Auswahl von 3 wird hier in dieser Funktion konvertiert, unzwar die xml-Datei und txt-Datei in eine einzige Datei, welche im build-Ordner gespeichert mit den Informationen der beiden Dateien vorliegt.
        string name;        // Dieser string wird für die Eingabe der neuen Datei benötigt. Dieser wird die zukünftig erstellte Datei benennen.
        string line;
        string id;
        string etage;
        string raum;
        string id1;
        string etage1;
        string raum1;
        string id2;
        string etage2;
        string raum2;
cout << "Benennen Sie die neue Datei (Bitte benutzen SIe die Endung .xml):" << endl;
    cin >> name;                                // hier wird der Benutzer nach einer Eingabe gefragt. Die Eingabe ist also der string name, womit später weitergearbeitet werden kann.
    ofstream myfilenew (name, ios::out);        // Hier benutze ich ofstream und nicht ifstream, da ich eine Datei beschreiben möchte. Falls keine Datei vorhanden ist wird eine neue Datei erstellt, die unter den Namen der "name" gespeichert wird.(Im build-Ordner kan man die Datei unter dem eingegeben Namen finden.)
                                                // ios::out erlaubt die Ausgabe (Schreiboperationen) in einen Stream, diese wird benötigt, da wir ja in die neu erstellte Datei hineinschreiben werden.
    ifstream myfile3 ("tierxml.xml");           // Ab hier kommen die Datein ins Spiel, welche in die neu erstellte Datei hineingeschrieben werden sollen.

    if (myfile3.is_open())                      // Sobald das Programm sieht, dass myfile3(tierxml.xml) vorhanden ist führt er die while-Schleife durch.

    {
    while ( getline (myfile3,line) )            // Hier wird wie im oberen Beispiel
    {
     myfilenew << line << '\n';                 // Hier kann man sehen, dass die "line" aus der myfile3 in die neu erstellte Datei myfilenew geschrieben wird.
     }
    myfile3.close();                            // Wichtig ist, dass hier myfile3 geschlossen wird und nicht myfilenew. Die Daten von myfile3 wurden soeben schon in die neue hineingeschrieben aber die eu erstellte Datei braucht noch die Informationen des Gehegeplans, also die txt-Datei und darf nicht geschlossen werden.
   }

 else cout << "Oeffnen nicht moeglich! \n";     // Falls es nicht möglich war myfile3 zu öffnen, erscheint eine Mitteilung.


    ifstream myfile ("tierheimtxt.txt");        // Die xml-Datei ist hineingeschrieben worden, fehlt somit noch die txt-Datei. Hier mit ifstream, da diese Datei nur gelesen werden soll.

    myfile >> id;                               // Ab Zeile 135 bis zur Zeile 155 erfolgt das lesen und hineinschreiben der txt-Datei in die myfilenew-Datei.
    myfile >> etage;
    myfile >> raum;
    myfile >> id1;
    myfile >> etage1;
    myfile >> raum1;
    myfile >> id2;
    myfile >> etage2;
    myfile >> raum2;
    myfilenew << "Tier 1:\n" << endl;
    myfilenew << "<Id>" << id << "</Id>\n" << endl;
    myfilenew << "<Etage>" << etage  << "</Etage>\n" <<endl;
    myfilenew << "<Raum>" << raum  << "</Raum>\n"<<endl;
    myfilenew << "Tier 2:"  << endl;
    myfilenew << "<Id>" << id1  << "</Id>\n"<<endl;
    myfilenew << "<Etage>" << etage1  << "</Etage>\n"<<endl;
    myfilenew << "<Raum>" << raum1  << "</Raum>\n"<<endl;
    myfilenew << "Tier 3:\n" << endl;
    myfilenew << "<Id>" << id2  << "</Id>\n"<<endl;
    myfilenew << "<Etage>" << etage2  << "</Etage>\n"<<endl;
    myfilenew << "<Raum>" << raum2  << "</Raum>\n"<<endl;


    cout << "Datei wurde gespeichert!" << endl;    // Nachdem das lesen, hineinschreiben und Speichern wird man durch eine Mitteilung darüber benachrichtigt.
    myfilenew.close();                             // Wichtig ist die neu erstellte myfilenew-Datei am Ende nach dem Prozess wieder mit .close() zu schließen

    return 0;





}

    switch (Auswahl) {      // "Auswahl" steht für die Auswahl, welcher der Benutzer in cin in der Zeile 31 eingibt.
    case ('4'):    // Bei Auswahl von der Nummer 4 wird diese nachfolgende Funktionen ausgeführt:

        cout << "Gehegeplan wird geladen.... (In Text-Format)\n"<< endl;      // Erst erscheint ein cout, dieses hat kein entscheidenden Zweck und dient nur zur Orientation, um sehen zu können was jetzt geladen wird.



        string line;            // string line, weil die nachfolgende Funktion einen string ("line") erfordert
        ifstream myfile ("tierheimtxt.txt");  // ifstream <- da wir die Datei lesen wollen

        if (myfile.is_open())           // hier fängt das Programm mit der if/while/else Funktion zu kontrollieren. "myfile" ist die Datei, die im Ordner schon besteht und is.open öffnet die Datei um im nachfolgenden mi der Datei arbeite zu können.
        {
        while ( getline (myfile,line) ) // Wenn die Datei myfile(tierheimtxt.txt) vorhanden ist, soll etwas damit geschehen.
        {
         cout << line << '\n';          // durch die cout Funktion wird der ganze Inhalt durch "line" in der Konsole angezeigt. Diesemal in Text-Format.
         }
        myfile.close();                 // Hier wird die Datei wieder nach dem Öfnnen und lesen geschlossen.
       }

     else cout << "Datei nicht moeglich zu oeffnen \n"; // Falls die Datei nicht vorhanden ist oder andere Komplikationen verhindern sollten die Datei zu lesen, wird durch den else Aufruf, das Problem dem Benutzer mitgeteilt
      break;


}


    getch();                            // Die getch()-Funktion wartet immer auf die eine Eingabe im Keyboard also wird die Konsole sonst nicht schließen
    system("cls");                      // Nach der do-Schleife wird durch system("cls")(steht für ClearScreen) das System/Bildschirm gereinigt.
    }
 while (Auswahl!='5');                  // Bei Auswahl des Benutzers der Wahl 5 wird das Programm durch cin.ignore() ganz beendet und die Konsole schließt
 cin.ignore();
    return 0;
}
