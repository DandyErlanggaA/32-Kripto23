#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    int x = 0;
    char option;
    char retry;
    char ofile;
    char enorde;
    string input_file;
    string output_file;
    string plain_text;
    string stringtofile;

    do{
        cout << "Apakah anda ingin membuka file? (y/n)" << endl;
        cin >> option;

        cin.clear ();    
        cin.ignore (100 , '\n');

        if (option != 'y' && option != 'Y' && option != 'n' && option != 'N'){
            cout << "Opsi salah" << endl;
        }

        else if (option == 'y' || option == 'Y'){

            cout << "Masukkan nama file anda yang akan digunakan :" << endl;
            getline(cin,input_file);

            ifstream file;
            file.open(input_file);

            if (file.fail()){
                cout << "File gagal dibuka" << endl;
                return 1;
            }

            stringstream buffer;
            buffer << file.rdbuf();
            string file_contents;
            file_contents = buffer.str();
            plain_text = file_contents;
            file.close();
        }

        else if (option == 'n' || option == 'N'){
            cout << "Masukkan kalimat yang anda inginkan : " << endl;
            getline(cin, plain_text);
        }

        cout << "Masukkan kunci pergeseran : " << endl;
        cin >> x;

        cin.clear ();    
        cin.ignore (100 , '\n');

        cout << "Apakah anda ingin melakukan enkripsi atau dekripsi? (e/d) :";
        cin >> enorde;

        if (enorde != 'e' && enorde != 'E' && enorde != 'd' && enorde != 'D'){
            cout << "Opsi salah" << endl;
        }
        else if (enorde == 'e' || enorde == 'E'){
            cout << "Hasil Enkripsi :" << endl;
        }
        else if (enorde == 'd' || enorde == 'D'){
            x = 0 - x;
            cout << "Hasil Dekripsi :" << endl;
        }
        
        for (int i = 0; i < plain_text.length(); i++){

            if (plain_text[i] != ' '){
            
                if (97 <= int(char(plain_text[i])) && int(char(plain_text[i])) <= 122) {
                    char a = char(int((plain_text[i] + x - 97) % 26) + 97);
                    
                    if (a - 97 < 0){
                        cout << char(int(a + 26));
                        stringtofile.push_back(char(int(a + 26)));
                    }
                    
                    else{
                        cout << a;
                        stringtofile.push_back(a);
                    }
                }

                else if (65 <= int(char(plain_text[i])) && int(char(plain_text[i])) <= 90) {
                    char a = char(int((plain_text[i] + x - 65) % 26) + 65);
                    
                    if (a - 65 < 0){
                        cout << char(int(a + 26));
                        stringtofile.push_back(char(int(a + 26)));
                    }

                    else{
                        cout << a;
                        stringtofile.push_back(a);
                    }
                }

                else {
                    cout << plain_text[i];
                    stringtofile.push_back(plain_text[i]);
                }

            }
            
            else {
                cout << " ";
                stringtofile.push_back(' ');
            }

        }

        cout << endl;
        
        
        cout << "Apakah anda ingin membuat file output? (y/n)" << endl;
        cin >> ofile;

        if (ofile != 'y' && ofile != 'Y' && ofile != 'n' && ofile != 'N'){
            cout << "Opsi salah" << endl;
        }

        else if (ofile == 'y' || ofile == 'Y')
        {
            cin.clear ();    
            cin.ignore (100 , '\n');
            ofstream fileOut;
            cout << "Masukkan nama file output yang diinginkan : " << endl;
            getline(cin, output_file);
            fileOut.open(output_file);
            fileOut << stringtofile << endl;
            fileOut.close();
        }
        stringtofile = "";
        cout << endl;
        cout << "Apakah anda ingin mengulang proses? (y/n)" << endl;
        cin >> retry;
        
        if (retry != 'y' && retry != 'Y' && retry != 'n' && retry != 'N'){
            cout << "Opsi salah" << endl;
        }

    } while (retry == 'y' || retry == 'Y');
    
}