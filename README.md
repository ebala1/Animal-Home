# Animal-Home
In meiner Arbeit geht es um ein Programm für einen Tierheim. An erster Stelle kann man durch eine Menüführung von verschiedenen Möglichkeiten auswählen. Unter anderem stehen hier zur Verfügung: 
1.Laden von Tierinformationen (Xml)
2.Laden von der Gehegeinformation (Textdatei)
3.Laden von der Gehegeinformation(XML-Format) 
4.Speichern einer Datei, welche die oberen zwei Dateien beinhaltet
5. Beenden des Programms
Bei der Speicherung einer Datei werden die zwei Dateien (Tierheiminformationen und Gehegeinformationen) in eine neu erstellte Datei konvertiert. Diese Datei muss vom Benutzer selbst benannt werden. In der selbst gespeicherten Datei, welche im build-Ordner zu finden ist, sind beide Dateien als eine einzige Datei konvertiert worden. Auf diesen Datei kann im build-Ordner zu jeder Zeit zurückgegriffen werden. Bei der Auswahl der ersten Wahl im Menü wird zunächst die Datei der Tieriformationenen in der Konsole selbst angezeigt. Bei der Auswahl der Zweiten Wahl werden die Gehegeinformationen in der Konsole angezeigt. Dabei ist entscheidend, dass die Tierinformationen und der Gehegeplan schon vorher im Ordner angelegt worden sind und durch das Programm nur noch gelesen werden müssen (ifstream).
Der Benutzer kann entscheiden, ob er/sie den Gehegeplan im XML-Format oder im Txt-Format auf der Konsole angezeigt werden möchte. Dies ist daher wichtig, da der Benutzer schon vor dem Speichern der beiden Dateien sehen kann, wie der Gehegeplan als XML-Datei eingespeichert wird.
Das Beenden des Programms läuft ganz einfach ab. Der Benutzer muss in seiner Angabe die gewünschte Zahl für das Beenden (im Menü sichtbar) des Programms eintippen und das Programm/Konsole schließt.


Repository: Animal-Home
