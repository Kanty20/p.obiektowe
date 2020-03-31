import csv
import operator
def reader() :
    path = r"cars.csv"
    file = open(path, newline='')
    reader = csv.reader(file)
    header = next(reader) #Pominięcie pierwszej lini nagłówka
    data = []
    for row in reader:
        #row = [marka,model,rocznik,moc,przebieg,skrzynia]
        marka = row[0]
        model = row[1]
        rocznik = int(row[2])
        moc = int(row[3])
        przebieg = int(row[4])
        skrzynia = row[5]

        data.append([marka, model, rocznik, moc, przebieg, skrzynia])
        
    return data

def sortAsc(parametr):
    data = reader()
    sort = sorted(data,key=operator.itemgetter(parametr))
    for i in range(len(sort)):
        print(sort[i])
def sortD(parametr):
    data = reader()
    sort = sorted(data,key=operator.itemgetter(parametr),reverse = True)
    for i in range(len(sort)):
        print(sort[i])
def lista() :
    auta = reader()
    length = len(auta)
    for i in range(length):
        print(auta[i])

def addCarW(marka,model,rocznik,moc,przebieg,skrzynia):         #możliwośc dodania samochodu i zapisania w pliku csv
     path = r"cars.csv"
     file = open(path, 'a+', newline='')
     writer = csv.writer(file)
     row = [marka,model,rocznik,moc,przebieg,skrzynia]
     writer.writerow(row)
     
def pojedyncza():
    numer = int (input("Podaj numer :"))
    num = 0
    dane  = reader()
    for x in range(len(dane)):
     num += 1
    if numer > num :
     print("maxymalny numer "+str(num))
    else :
     print(dane[numer-1])
class Car: #przechowuje dane samochodu
    def __init__(self,marka,model,rocznik,moc,przebieg,skrzynia,potwierdzenie):
        self.marka = marka
        self.model = model
        self.rocznik = rocznik
        self.moc = moc
        self.przebieg = przebieg
        self.skrzynia = skrzynia
        self.potwierdzenie = potwierdzenie
def addMenu() :
    auto  = Car("marka","model","rocznik","moc","przebieg","skrzynia","potwierdzenie")
    print("Podaj odpowiednio: Marka,Model,Rocznik,Moc,Przebieg,Skrzynia")
    auto.marka = input("Marka: ")
    auto.model = input("Model: ")
    auto.rocznik = input("Rocznik: ")
    auto.moc = input("Moc: ")
    auto.przebieg = input("Przebieg: ")
    auto.skrzynia = input("Skrzynia: ")
    print("czy napewno chcesz zapisać?T-tak N-nie")
    auto.potwierdzenie = input("T/N  ")
    return auto
def menuList() :
    print("1.Marka")
    print("2.Model")
    print("3.Rocznik")
    print("4.Moc")
    print("5.Przebieg")
    print("6.Skrzynia")
    print("7.Wyjście")
    while True:
        try:
            wybrany = int (input("Wybierz:"))
            if wybrany==1:
                return 0
            elif wybrany==2:
                return 1
            elif wybrany==3:
                return 2
            elif wybrany==4:
                return 3
            elif wybrany==5:
                return 4
            elif wybrany==6:
                return 5
            elif wybrany==7:
                return "x"
            else :
                print("Podaj numer")
                menuList()
        except ValueError:
            print("nie poprawna wartosc")


def menu() :
    print("[1] - Wyjdz z programu.")
    print("[2] - Pokaz menu programu.")
    print("[3] -Cala lista samochodow.")
    print("[4] -Dodaj nowy samochod")
    print("[5] - Usun samochodod.")
    print("[6] - Wyœwietlenie pojedynczej pozycji")
    print("[7] - Sortowanie rosnaco")
    print("[8] -Sortowanie malejaco.")
    print("[9] -Próg od jakiego maj¹ byæ wyœwietlone pozycje")
    print("[10] - Zapis")
    while True:
        try:
            selection = int (input("Wybierz:"))
            print(selection)
            if selection==1:
                break
            elif selection == 2:
                showMenu()
                break
            elif selection == 3:
                calalista()
                break
            elif selection == 4:
                addCar()
                break
            elif selection == 5:
                deleteCar()
                break
            elif selection == 6:
                showSingular()
                break
            elif selection == 7:
                sortDesc()
                break
            elif selection == 8:
                sortInc()
                break
            elif selection == 9:
                prog()
                break
            elif selection == 10:
                save()
                break
            else:
                print("Nie poprawny wybor")
                menu()
        except ValueError:
            print("nie poprawna wartosc")
    exit
def showMenu():
    menu()
def calalista():
    lista()
    menu()
def  addCar():
    auto = addMenu()        #dodanie samochodu z możliwością potwierdzenia
    if auto.potwierdzenie == "T" or "t":
        addCarW(auto.marka,auto.model,auto.rocznik,auto.moc,auto.przebieg,auto.skrzynia)
        menu()
    else:
        menu()
def deleteCar():    
    print("test")
    menu()
def  showSingular():
    pojedyncza()
    menu()
def sortDesc():
    parametr = menuList()
    if parametr == "x":
        menu()
    else:               
        sortAsc(parametr)
        menu()
def  sortInc():
    parametr = menuList()
    if parametr == "x":
        menu()
    else:
        sortD(parametr)
        menu()
def  prog():
    print("test")
    menu()
def save():
    print("test")
    menu()

# main rutine
menu()
#brak komend dla 5,9,10 z menu