// 123210093; 123210118; 123210119
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;
string hapus_space(string kata)
{

    string noSpace = "";

    for (char karakter : kata)
    {
        if (karakter != ' ')
        {
            noSpace += karakter;
        }
    }
    input = noSpace;

    return noSpace;
}

string enkripsi_rail_fence_chiper(string plain, int kunci)
{
    string ciphertext;
    int baris = kunci;
    int kolom = plain.length();

    char railMatriks[baris][kolom];

    // Menginisialisasi Matriks dengan karakter kosong
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            railMatriks[i][j] = '#';
        }
    }

    int b = 0;
    bool turun = false;

    // Mengisi plainteks ke Matriks
    for (int k = 0; k < kolom; k++)
    {
        railMatriks[b][k] = plain[k];
        if (b == 0 || b == baris - 1)
        {
            turun = !turun;
        }

        if (turun)
        {
            b++;
        }
        else
        {
            b--;
        }
    }

    // Membaca Matriks
    for (int b = 0; b < baris; b++)
    {
        for (int k = 0; k < kolom; k++)
        {
            if (railMatriks[b][k] != '#')
            {
                ciphertext += railMatriks[b][k];
            }
        }
    }

    return ciphertext;
}

string dekripsi_rail_fence_chiper(string cipher, int kunci)
{
    string plaintext;
    int baris = kunci;
    int kolom = cipher.length();

    char railMatriks[baris][kolom];

    // Menginisialisasi Matriks dengan karakter kosong
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            railMatriks[i][j] = '#';
        }
    }

    int b = 0;
    bool turun = false;

    // Mengisi * ke Matriks untuk melihat pola
    for (int k = 0; k < kolom; k++)
    {
        railMatriks[b][k] = '*';
        if (b == 0 || b == baris - 1)
        {
            turun = !turun;
        }

        if (turun)
        {
            b++;
        }
        else
        {
            b--;
        }
    }

    // Memasukkan cipher teks ke matriks
    int index = 0;
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {

            if (railMatriks[i][j] == '*' && index < kolom)
            {
                railMatriks[i][j] = cipher[index];
                index++;
            }
        }
    }

    b = 0;
    turun = false;

    // Membaca plaintext pada matriks
    for (int k = 0; k < kolom; k++)
    {
        plaintext += railMatriks[b][k];
        if (b == 0 || b == baris - 1)
        {
            turun = !turun;
        }
        if (turun)
        {
            b++;
        }
        else
        {
            b--;
        }
    }

    return plaintext;
}
void enkripsiR(string &plaintext)
{
    for (char &a : plaintext)
    {
        if (isalpha(a))
        {
            if (isupper(a))
            {
                a = 'Z' - (a - 'A');
            }
            else
            {
                a = 'z' - (a - 'a');
            }
        }
    }
}

void dekripsiR(string &ciphertext)
{
    for (char &c : ciphertext)
    {
        if (isalpha(c))
        {
            if (isupper(c))
            {
                c = 'A' + ('Z' - c);
            }
            else
            {
                c = 'a' + ('z' - c);
            }
        }
    }
}

void enkripsiCP()
{
    string plaintext, ciphertext;
    int k;
    char p;
    // cin.ignore();
    cout << "PlainText: " << input << endl;
    plaintext = input;
    cout << "Masukkan kunci (0-25)	: ";
    cin >> k;

    for (size_t i = 0; i < plaintext.length(); i++)
    { // size_t digunakan agar i mengembalikan tipe data seperti plaintext.length()
        p = plaintext[i];
        if (isalpha(p))
        {                   // Memeriksa apakah karakter adalah huruf
            p = toupper(p); // Mengubah karakter menjadi huruf besar
            p = p - 65;     // Mengonversi huruf menjadi angka 0-25
            p = (p + k) % 26;
            p = p + 65;
        }
        ciphertext = ciphertext + p;
    }
    cout << "Hasil Enkripsi :\n";
    cout << "Ciphertext		: " << ciphertext << endl;
    input = ciphertext;
    system("pause");
}

void dekripsiCP()
{
    string plaintext, ciphertext;
    int k;
    char c;

    ciphertext = input;
    cout << "Masukkan kunci (0-25)	: ";
    cin >> k;

    for (size_t i = 0; i < ciphertext.length(); i++)
    {
        c = ciphertext[i];
        if (isalpha(c))
        {
            c = toupper(c);
            c = c - 65;
            c = (c - k + 26) % 26;
            c = c + 65;
            c = tolower(c);

            plaintext = plaintext + c;
        }
        else
        {
            plaintext = plaintext + c;
        }
    }
    cout << "plaintext		: " << plaintext << endl;
    input = plaintext;
    system("pause");
}

int main()
{
menu:
    vector<string> menu = {"CAESAR CIPHER", "RAIL FANCE CIPHER", "REVERSE CIPHER", "KEMBALI"};
    vector<string> originalMenu = menu;
    int choice, key;
    int pilihmenu;
    system("cls");
    cout << "PROGRAM ENKRIPSI DAN DEKRIPSI\n";
    cout << "Pilih :\n";
    cout << "1. Enkripsi\n";
    cout << "2. Dekripsi\n";
    cout << "3. Keluar\n";
    cout << "->";
    cin >> pilihmenu;

    switch (pilihmenu)
    {
    case 1:
        system("cls");
        cout << "SUPER ENKRIPSI\n";
        cout << "Masukkan teks: ";
        cin.ignore();
        getline(cin, input); // Pindahkan getline() ke sini

        while (!menu.empty())
        {
            system("cls");
            cout << "SUPER ENKRIPSI\n";
            // Pindahkan getline() ke sini
            // Menampilkan menu yang tersedia
            cout << "Pilih salah satu menu:" << endl;
            for (int i = 0; i < menu.size(); i++)
            {
                cout << i + 1 << ". " << menu[i] << endl;
            }
            cout << "0. KELUAR\n";
            // Membaca pilihan pengguna
            cout << "Pilihan Anda: ";
            cin >> choice;

            // Membersihkan newline setelah memasukkan pilihan
            cin.ignore();

            // Memeriksa apakah pilihan valid
            if (choice >= 1 && choice <= menu.size())
            {
                system("cls");
                cout << "Anda memilih: " << menu[choice - 1] << endl;
                if (menu[choice - 1] == "CAESAR CIPHER")
                {
                    enkripsiCP();
                }
                else if (menu[choice - 1] == "RAIL FANCE CIPHER")
                {
                    cout << "masukkan kunci";
                    cin >> key;
                    hapus_space(input);
                    string enkripsi = enkripsi_rail_fence_chiper(input, key);

                    cout << "hasil enkripsi : " << enkripsi << endl;
                    input = enkripsi;
                    system("pause");
                }
                else if (menu[choice - 1] == "REVERSE CIPHER")
                {
                    // Panggil fungsi enkripsiR() dengan input yang telah dibaca
                    enkripsiR(input);
                    cout << "Teks terenkripsi: " << input << endl;
                    system("pause");
                    // hasilE = input;
                }
                else if (menu[choice - 1] == "KEMBALI")
                {
                    goto menu;
                }
                else
                    break;
                // Menghapus menu yang dipilih dari vektor
                menu.erase(menu.begin() + choice - 1);
            }
            else if (choice == 0)
            {
                return 0;
            }
            else
            {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
        break;

    case 2:
        system("cls");
        cout << "MENU DEKRIPSI\n";
        cout << "Masukkan teks: ";
        cin.ignore();
        getline(cin, input);

        while (!menu.empty())
        {
            system("cls");
            cout << "MENU DEKRIPSI\n";
            // Menampilkan menu yang tersedia
            cout << "Pilih salah satu menu:" << endl;
            for (int i = 0; i < menu.size(); i++)
            {
                cout << i + 1 << ". " << menu[i] << endl;
            }
            cout << "0. KELUAR\n";
            // Membaca pilihan pengguna
            cout << "Pilihan Anda: ";
            cin >> choice;

            // Membersihkan newline setelah memasukkan pilihan
            cin.ignore();

            // Memeriksa apakah pilihan valid
            if (choice >= 1 && choice <= menu.size())
            {
                cout << "Anda memilih: " << menu[choice - 1] << endl;
                if (menu[choice - 1] == "CAESAR CIPHER")
                {
                    // Panggil fungsi enkripsiCP() dengan input yang telah dibaca
                    dekripsiCP();
                }
                else if (menu[choice - 1] == "RAIL FANCE CIPHER")
                {

                    cout << "masukkan kunci :";
                    cin >> key;
                    hapus_space(input);
                    string deskripsi = dekripsi_rail_fence_chiper(input, key);
                    cout << "Hasil Dekripsi :" << deskripsi << endl;
                    input = deskripsi;
                    system("pause");
                }
                else if (menu[choice - 1] == "REVERSE CIPHER")
                {
                    // Panggil fungsi enkripsiR() dengan input yang telah dibaca
                    dekripsiR(input);
                    cout << "Teks terenkripsi: " << input << endl;
                    system("pause");
                }
                else if (menu[choice - 1] == "KEMBALI")
                {
                    goto menu;
                }
                else
                    break;
                // Menghapus menu yang dipilih dari vektor
                menu.erase(menu.begin() + choice - 1);
            }
            else if (choice == 0)
            {

                return 0;
            }
            else
            {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
        break;
    case 3:
        return 0;
        break;
    default:
        cout << "Pilihan tidak valid. Silakan coba lagi.";
        goto menu;
    }
}
