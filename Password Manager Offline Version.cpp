#include<stdio.h>
#include<stdlib.h>
#include<direct.h>
#include<fstream>
#include<iostream>
using namespace std;
string encript(string text)
{
char set[] = "abcdefghijklmnopqrstuvwxyz{}(ABCDEFGHIJKLMNOPQRSTUVWXYZ<>*";
int j;
    for(int x=0; x<text.length();x++)
	{
		j=0;
		while(j<58)
		{
			if(text[x]==set[j] && (j<26 || (j>=26 && j<58)))
			{
				text[x]=set[j+3];
				j=58;
			}
			if(text[x]==set[j] && (j>=26 && j<28))
			{
				if(text[x]=='x'){text[x]='{';}
				if(text[x]=='y'){text[x]='}';}
				if(text[x]=='z'){text[x]='(';}
				j=58;
			}
			if(text[x]==set[j] && (j>=51 && j<58))
			{
				if(text[x]=='X'){text[x]='<';}
				if(text[x]=='Y'){text[x]='>';}
				if(text[x]=='Z'){text[x]='*';}
				j=58;
			}
			j++;
		}
	}
	return text;
}
string desencript(string text)
{
char set[] = "abcdefghijklmnopqrstuvwxyz{}(ABCDEFGHIJKLMNOPQRSTUVWXYZ<>*";
int k;
    for(int x=0; x<text.length();x++)
	{k=0;
		while(k<58)
		{
			if(text[x]==set[k] && (k<26 || (k>=26 && k<58)))
			{
				text[x]=set[k-3];
				k=58;
			}
			if(text[x]==set[k] && (k>=26 && k<28))
			{
				if(text[x]=='{'){text[x]='x';}
				if(text[x]=='}'){text[x]='y';}
				if(text[x]=='('){text[x]='z';}
				if(text[x]=='x'){text[x]='u';}
				if(text[x]=='y'){text[x]='v';}
				if(text[x]=='z'){text[x]='w';}
				k=58;
			}
			if(text[x]==set[k] && (k>=51 && k<58))
			{
				if(text[x]=='<'){text[x]='X';}
				if(text[x]=='>'){text[x]='Y';}
				if(text[x]=='*'){text[x]='Z';}
				if(text[x]=='X'){text[x]='U';}
				if(text[x]=='Y'){text[x]='V';}
				if(text[x]=='Z'){text[x]='W';}
				k=58;
			}
			k++;
			}
		}
	return text;
}
string compressProcess(string text, int type)
{
	int amount=99;
	bool passe = false;
	if(type==1)
	{
		while(amount>0)
		{
			amount=0;
			fflush(stdin);
			cout<<"ingrese: ";
	        cin>>text;
	        for(int x=0; x<text.length();x++)
			{
				if(text[x] == ' ' || text[x] == '\xA0' || text[x] == '\x82' || text[x] == '\xA1' ||
				text[x] == '\xA2' || text[x] == '\xA3' || text[x] == '\xA4' ||
				text[x] == '\xA5')
				{
					cout<<"\n\nError el campo no puede contener espacios ni caracteres especiales";
					amount++;
				}
				else
				{
					passe = true;
				}
			}
	        if(passe==true && amount==0)
			{
				text = encript(text);
			}
		}
	}
	if(type==2)
	{
		text = desencript(text);
	}
	return text;
}
string upperCase(string text)
{
    for(int x=0; x<text.length();x++)
	{
		text[x] = toupper(text[x]);
	}
		return text;
}
void users(ofstream &usr, ifstream &lec){
    system("cls");
    string user, newuser;
    bool encontrado = false;
    usr.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::out | ios::app);
    usr.close();
    cout<<"\n\t>>Ingrese el nombre de su usuario a crear: ";
    cin.ignore();
    getline(cin, newuser);
    newuser = upperCase(newuser);
	lec.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::in);
    lec>>user;
    while(!lec.eof() && encontrado==false)
	{
        if(user == newuser)
        {
            cout<<"\n\n\tEl usuario ya existe..\n"<<endl;
            encontrado = true;
            system("pause");
        }
        lec>>user;
    }
    lec.close();
    if(encontrado==false)
	{
        usr.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::out | ios::app);
        usr<<"\n"<<newuser<<"\n";
        usr.close();
        usr.open(("C://tvjcflesx32//Users//"+newuser+".txt").c_str(), ios::out);
        usr.close();
        cout<<"\n\n\tUsuario creado exitosamente..\n\n";
        system("pause");
    }
}
void userList()
{
    ifstream Lect;
	system("cls");
    cout<<"\n\n\t\t   Usuarios Existentes \n\n";
    string seekuser;
    Lect.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::in);
    Lect>>seekuser;
    while(!Lect.eof())
	{
        cout<<"\tUsuario: "<<seekuser<<endl;
        cout<<"\t-------------------------------------------\n"<<endl;
        Lect>>seekuser;
    }
	Lect.close();
	cout<<endl<<endl;
    system("pause");
}
void deleteUser(ofstream &Temp, ifstream &Lec){
    system("cls");
    ifstream Leci;
    string usersystem, seekusr;
    userList();
    cout<<"\n\n\tIngrese su usuario a eliminar: ";
    cin.ignore();
    getline(cin, usersystem);
    usersystem = upperCase(usersystem);
    Lec.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::in);
    Temp.open("C://tvjcflesx32//Users//USERSLISTemp.txt", ios::out | ios::app);
    Lec>>seekusr;
	while(!Lec.eof())
	{
        if(seekusr == usersystem)
        {
    		remove(("C://tvjcflesx32//Users//"+usersystem+".txt").c_str());
            cout<<endl<<endl<<endl;
            cout<<"\n\tUsuario Eliminado Correctamente..\n\n"<<endl;
        	system("pause");
		}
	    else
		{
	        Temp<<seekusr<<"\n";
	    }
	    Lec>>seekusr;
	}
    Temp.close();
    Lec.close();
    remove("C://tvjcflesx32//Users//USERSLIST.txt");
	rename("C://tvjcflesx32//Users//USERSLISTemp.txt", "C://tvjcflesx32//Users//USERSLIST.txt");
    Lec.close();
}
void editUser(ofstream &Temp, ifstream &Lec){
    system("cls");
    ifstream Lec2, Lect;
    string usersystem, seekusr, newusersystem, seekusrinto;
    bool encontrado = false;
    userList();
    cout<<"\n\n\tIngrese su usuario de los existentes: ";
    cin.ignore();
    getline(cin, usersystem);
    usersystem = upperCase(usersystem);
    Temp.open("C://tvjcflesx32//Users//USERSLISTemp.txt", ios::out | ios::app);
    Lec.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::in);
    Lec>>seekusr;
    while(!Lec.eof() && encontrado==false)
	{
        if(seekusr == usersystem)
        {

        	bool into = true;
        	Lec2.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::in);
        	string seekuser;
        	cout<<"\n\n\tIngrese el nuevo nombre de usuario \n\t(No Repita Usuarios ya creados): ";
			getline(cin, newusersystem);
		    newusersystem = upperCase(newusersystem);
            Temp<<"\n"<<newusersystem<<"\n";
            rename(("C://tvjcflesx32//Users//"+usersystem+".txt").c_str(), ("C://tvjcflesx32//Users//"+newusersystem+".txt").c_str());
            remove(("C://tvjcflesx32//Users//"+usersystem+".txt").c_str());
            Lec2.close();
		}
		else
        {
            Temp<<"\n"<<seekusr<<"\n";
		}
        Lec>>seekusr;
	}
	Temp.close();
	Lec.close();
    remove("C://tvjcflesx32//Users//USERSLIST.txt");
	rename("C://tvjcflesx32//Users//USERSLISTemp.txt", "C://tvjcflesx32//Users//USERSLIST.txt");
}
void aggregate(ofstream &es, ifstream &lec)
{
    system("cls");
    string title, mail, usersystem, user, password, seekusr;
    bool encontrado = false;
    userList();
    cout<<"\n\n\tIngrese su usuario de los existentes: ";
    cin.ignore();
    getline(cin, usersystem);
    usersystem = upperCase(usersystem);
    lec.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::in);
    while(!lec.eof() && encontrado==false)
	{
        lec>>seekusr;
        if(seekusr == usersystem)
        {
            encontrado = true;
            es.open(("C://tvjcflesx32//Users//"+usersystem+".txt").c_str(), ios::out | ios::app);
            cout<<endl<<endl<<endl;
            cout<<"\t>>Ingrese los datos (SIN ESPACIOS) <<"<<endl<<endl;
            cout<<"\tTitulo -- Cuenta De ";
		    title = upperCase(title);
		    title = compressProcess(title, 1);
            cout<<endl;
	        cout<<"\tCorreo ";
	        mail = compressProcess(mail, 1);
            cout<<endl;
            cout<<"\tUsuario ";
            user = compressProcess(user, 1);
            cout<<endl;
            cout<<"\tContrasenia ";
            password = compressProcess(password, 1);
            cout<<endl;
            es<<title<<" "<<mail<<" "<<user<<" "<<password<<"\n";
            cout<<"----------------------------------------------"<<endl;
            es.close();
            system("pause");
        }
    }
    lec.close();
	if(encontrado == false)
	{
	    cout<<"\n\nUsuario No Existe... "<<endl;
	    system("pause");
	}
}
void lectura(ifstream &Lec)
{
    system("cls");
    ifstream Leci;
    string title, mail, usersystem, user, password, seekusr, checktitle;
    bool encontrado = false;
    userList();
    cout<<"\n\n\tIngrese su usuario de los existentes: ";
    cin.ignore();
    getline(cin, usersystem);
    usersystem = upperCase(usersystem);
    Lec.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::in);
    while(!Lec.eof() && encontrado==false)
	{
        Lec>>seekusr;
        if(seekusr == usersystem)
        {
            Leci.open(("C://tvjcflesx32//Users//"+usersystem+".txt").c_str(), ios::in);
            Leci>>title;
            title = upperCase(title);
		    title = compressProcess(title, 2);
            while(!Leci.eof() && encontrado==false)
            {
                Leci>>mail;
		    	mail = compressProcess(mail, 2);
                Leci>>user;
		    	user = compressProcess(user, 2);
                Leci>>password;
		    	password = compressProcess(password, 2);
                cout<<"\n\nCuenta De: "<<title<<endl;
                cout<<"\nCorreo :"<<mail<<endl;
                cout<<"\nUsuario : "<<user<<endl;
                cout<<"\nContrasenia: "<<password<<endl;
                cout<<"----------------------------------------------"<<endl;
              	Leci>>title;
              	title = upperCase(title);
		    	title = compressProcess(title, 2);
            }
             encontrado = true;
             Leci.close();
             system("pause");
            if(Leci.eof() && encontrado==false)
            {
                cout<<"Dato no encontrado"<<endl;;
                system("pause");
                break;
            }
        }
        else if(Lec.eof() && encontrado==false)
        {
            cout<<"\n\nUsuario No Existe... "<<endl;
            system("pause");
        }
    }Lec.close();
}
void editC(ofstream &es, ifstream &Lec)
{
    system("cls");
    ifstream Leci;
    string title, mail, usersystem, user, password, seekusr, checktitle, ntitle, nmail, npassword, nuser;
    bool encontrado = false;
    userList();
    cout<<"\n\n\tIngrese su usuario de los existentes: ";
    cin.ignore();
    getline(cin, usersystem);
    usersystem = upperCase(usersystem);
    Lec.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::in);
    while(!Lec.eof() && encontrado==false)
	{
        Lec>>seekusr;
        if(seekusr == usersystem)
        {
            Leci.open(("C://tvjcflesx32//Users//"+usersystem+".txt").c_str(), ios::in);
            ofstream Temp;
    		Temp.open(("C://tvjcflesx32//Users//"+usersystem+"temp.txt").c_str(), ios::out | ios::app);
            cout<<"Ingrese el titulo de su cuenta: ";
		    cin>>checktitle;
		    checktitle = upperCase(checktitle);
		    Leci>>title;
		    title = upperCase(title);
		    title = compressProcess(title, 2);
		    while(!Leci.eof())
			{
		    	Leci>>mail;
		    	mail = compressProcess(mail, 2);
                Leci>>user;
                user = compressProcess(user, 2);
                Leci>>password;
                password = compressProcess(password, 2);
	            if(checktitle == title)
				{
            		encontrado = true;
		            cout<<endl<<endl<<endl;
		            cout<<">>Ingrese los datos a actualizar<<"<<endl<<endl;
		            cout<<"Nuevo Titulo -- Cuenta De ";
		            ntitle = upperCase(ntitle);
		    		ntitle = compressProcess(ntitle, 1);
		            cout<<endl;
		            cout<<"Nuevo Correo ";
		    		nmail = compressProcess(nmail, 1);
		            cout<<endl;
		            cout<<"Nuevo Usuario ";
		    		nuser = compressProcess(nuser, 1);
		            cout<<endl;
		            cout<<"Nueva Contrasenia ";
		    		npassword = compressProcess(npassword, 1);
		            cout<<endl;
		            Temp<<ntitle<<" "<<nmail<<" "<<nuser<<" "<<npassword<<"\n";
		            cout<<"----------------------------------------------"<<endl;
		            system("pause");
				}
	            else
				{
					title = encript(title); mail = encript(mail); user = encript(user); password = encript(password);
	                Temp<<title<<" "<<mail<<" "<<user<<" "<<password<<"\n";
	            }
	            Leci>>title;
	            title = upperCase(title);
		    	title = compressProcess(title, 2);
	        }
	        Temp.close();
	        Leci.close();
	        encontrado==true;
	       	remove(("C://tvjcflesx32//Users//"+usersystem+".txt").c_str());
   			rename(("C://tvjcflesx32//Users//"+usersystem+"temp.txt").c_str(), ("C://tvjcflesx32//Users//"+usersystem+".txt").c_str());
            if(Leci.eof() && encontrado==false)
            {
                cout<<"Dato no encontrado"<<endl;;
                system("pause");
                break;
            }
        }
        else if(Lec.eof() && encontrado==false)
        {
            cout<<"\n\nUsuario No Existe... "<<endl;
            system("pause");
        }
    }Lec.close();
}
void deleteC(ofstream &es, ifstream &Lec)
{
    system("cls");
    ifstream Leci;
    string title, mail, usersystem, user, password, seekusr, checktitle;
    bool encontrado = false;
    userList();
    cout<<"\n\n\tIngrese su usuario de los existentes: ";
    cin.ignore();
    getline(cin, usersystem);
    usersystem = upperCase(usersystem);
    Lec.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::in);
    while(!Lec.eof() && encontrado==false)
	{
        Lec>>seekusr;
        if(seekusr == usersystem)
        {
            Leci.open(("C://tvjcflesx32//Users//"+usersystem+".txt").c_str(), ios::in);
            ofstream Temp;
    		Temp.open(("C://tvjcflesx32//Users//"+usersystem+"temp.txt").c_str(), ios::out | ios::app);
            cout<<"\n\n\tIngrese el titulo de su cuenta: ";
		    cin>>checktitle;
		    checktitle = upperCase(checktitle);
		    Leci>>title;
		    title = upperCase(title);
		    title = compressProcess(title, 2);
		    while(!Leci.eof())
			{
		    	Leci>>mail;
		    	mail = compressProcess(mail, 2);
                Leci>>user;
		    	user = compressProcess(user, 2);
                Leci>>password;
                password = compressProcess(password, 2);
	            if(checktitle == title)
				{
            		encontrado = true;
		            cout<<endl<<endl<<endl;
		            cout<<"Credencial Eliminado Correctamente.."<<endl;
		        	system("pause");
				}
	            else
				{
					title = encript(title); mail = encript(mail); user = encript(user); password = encript(password);
	                Temp<<title<<" "<<mail<<" "<<user<<" "<<password<<"\n";
	            }
	            Leci>>title;
	            title = upperCase(title);
		    	title = compressProcess(title, 2);
	        }
	        Temp.close();
	        Leci.close();
	        encontrado==true;
	       	remove(("C://tvjcflesx32//Users//"+usersystem+".txt").c_str());
   			rename(("C://tvjcflesx32//Users//"+usersystem+"temp.txt").c_str(), ("C://tvjcflesx32//Users//"+usersystem+".txt").c_str());
            if(Leci.eof() && encontrado==false)
            {
                cout<<"Dato no encontrado"<<endl;;
                system("pause");
                break;
            }
        }
        else if(Lec.eof() && encontrado==false)
        {
            cout<<"\n\nUsuario No Existe... "<<endl;
            system("pause");
        }
    }Lec.close();
}
int main()
{
	system("color F0");
	mkdir("C://tvjcflesx32");
	mkdir("C://tvjcflesx32//Users");
	string rec;
	bool pass=false;
	system("cls");
    for(;;)
    {
    	ofstream Esc;
		ifstream Lec;
		Lec.open("C://tvjcflesx32//Users//USERSLIST.txt", ios::in);
		while(!Lec.eof())
		{
			Lec>>rec;
			if(rec.length()>1)
			{
				pass=true;
				break;
			}
			else{
				pass=false;
				cout<<"\n\n\n\tNo existe ningun usuario, registre uno primero..\n\n"<<endl;
				system("pause");
				break;
			}
		}Lec.close();
        int option=0;
        system("cls");
        cout<<"version 2.02.2"<<endl;
		cout<<"\n\n\n\t\t\tOpcion 1:			 Ingresar nuevo usuario"<<endl;
		cout<<"\n\n\n\t\t\tOpcion 2:			 Ver lista de usuarios"<<endl;
	    cout<<"\n\n\n\t\t\tOpcion 3:			 Eliminar Usuario"<<endl;
	    cout<<"\n\n\n\t\t\tOpcion 4:			 Renombrar Usuario"<<endl;
	    cout<<"\n\n\n\t\t\tOpcion 5:			 Ingresar nueva credencial"<<endl;
	    cout<<"\n\n\n\t\t\tOpcion 6:			 Leer credenciales completas"<<endl;
	    cout<<"\n\n\n\t\t\tOpcion 7:			 Editar credenciales"<<endl;
	    cout<<"\n\n\n\t\t\tOpcion 8:			 Eliminar credencial"<<endl;
	    cout<<"\n\n\n\t\t\tOpcion 9:			 Salir"<<endl;
	    cout<<"\n\n\n\t\t\tIngrese una opcion: ";
        fflush(stdin);
        cin>>option;
        if(option == 1)
        {
            users(Esc, Lec);
        }
        else if(option == 2 && pass==true)
        {
			userList();
        }
        else if(option == 3 && pass==true)
        {
        	deleteUser(Esc, Lec);
        }
        else if(option == 4 && pass==true)
        {
        	editUser(Esc, Lec);
        }
        else if(option == 5 && pass==true)
        {
        	aggregate(Esc, Lec);
        }
        else if(option == 6 && pass==true)
        {
        	lectura(Lec);
        }
        else if(option == 7 && pass==true)
        {
        	editC(Esc, Lec);
        }
        else if(option == 8 && pass==true)
        {
        	deleteC(Esc, Lec);
        }
        else if(option == 9)
        {
            exit(0);
        }
    }
	return 0;
}
