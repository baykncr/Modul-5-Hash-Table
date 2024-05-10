#include <iostream> 
#include <string>   
#include <vector>   
#include <iomanip>  

using namespace std; 

const int TABLE_SIZE = 100; 

struct Mahasiswa
{
    string nama;
    string nim;
    int nilai;
};
class HashNode
{
public:
    string name_031;
    string nim_031;
    int nilai_031;

    HashNode(string name, string nim, int nilai)
    {
        this->name_031 = name;
        this->nim_031 = nim;
        this->nilai_031 = nilai;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }
    void insert(string name, string nim, int nilai)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name_031 == name)
            {
                node->nim_031 = nim;
                node->nilai_031 = nilai;
                cout << "Data Mahasiswa dengan Nama " << name << " berhasil ditambahkan." << endl;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, nim, nilai));
    }
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); ++it)
        {
            if ((*it)->name_031 == name)
            {
                delete *it;
                table[hash_val].erase(it);
                cout << "Data Mahasiswa dengan nama " << name << " berhasil dihapus." << endl;
                return;
            }
        }
    }
    void searchByNIM(string nim)
    {
        bool found = false;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            for (auto node : table[i])
            {
                if (node->nim_031 == nim)
                {
                    // Menampilkan data mahasiswa pakai setw agar rapi
                    cout << "\n ============2031 MENCARI DATA NIM MAHASISWA 2031============" << endl;
                    cout << " ---------------------------------------------------" << endl;
                    cout << left << "| " << setw(15) << "Nama"
                         << "| " << setw(20) << "NIM"
                         << "| " << setw(10) << "Nilai"
                         << " |" << endl;
                    cout << " ---------------------------------------------------" << endl;
                    cout << "| " << left << setw(15) << node->name_031
                         << "| " << left << setw(20) << node->nim_031
                         << "| " << left << setw(10) << node->nilai_031 << " |" << endl;
                    cout << " ---------------------------------------------------" << endl;
                    found = true;
                    return;
                }
            }
        }
        if (!found)
        {
            cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        }
    }

    void CariRentangNilai(int NilaiMin, int NilaiMax)
    {
        bool found = false;
        cout << "\n =======2031 MENCARI DATA RENTANG NILAI MAHASISWA 2031=======" << endl;
        cout << " ---------------------------------------------------" << endl;
        cout << left << "| " << setw(15) << "Nama"
             << "| " << setw(20) << "NIM"
             << "| " << setw(10) << "Nilai"
             << " |" << endl;
        cout << " ---------------------------------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            for (auto node : table[i])
            {
                if (node->nilai_031 >= NilaiMin && node->nilai_031 <= NilaiMax)
                {
                    cout << "| " << left << setw(15) << node->name_031
                         << "| " << left << setw(20) << node->nim_031
                         << "| " << left << setw(10) << node->nilai_031 << " |" << endl;
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout << "Tidak ada data Mahasiswa dengan nilai antara " << NilaiMin << " dan " << NilaiMax << "." << endl;
        }
        cout << " ---------------------------------------------------" << endl;
    }

    void print()
    {
        cout << "\n ==================2031 DATA MAHASISWA 2031=================" << endl;
        cout << " ---------------------------------------------------" << endl;
        cout << left << "| " << setw(15) << "Nama"
             << "| " << setw(20) << "NIM"
             << "| " << setw(10) << "Nilai"
             << " |" << endl;
        cout << " ---------------------------------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            for (auto pair : table[i])
            {
                cout << "| " << left << setw(15) << pair->name_031
                     << "| " << left << setw(20) << pair->nim_031
                     << "| " << left << setw(10) << pair->nilai_031 << " |" << endl;
            }
        }
        cout << " ---------------------------------------------------" << endl;
    }
};

int main()
{
    HashMap map;
    int choice_031;
    string name_031;
    string nim_031;
    int nilai_031;
    int search1_031, search2_031;
    do
    {
        // Menampilkan menu
        cout << "\n ============2031 DAFTAR NILAI MAHASISWA 2031============" << endl;
        cout << "1. Tambah data Mahasiswa" << endl;
        cout << "2. Menghapus data Mahasiswa" << endl;
        cout << "3. Mencari data Nim Mahasiswa" << endl;
        cout << "4. Mencari data Rentang Nilai Mahasiswa" << endl;
        cout << "5. Tampilkan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice_031;
        switch (choice_031)
        {
        case 1:
            cout << "\n ==============2031 TAMBAHKAN DATA MAHASISWA 2031==============" << endl;
            cout << "Masukkan nama: ";
            cin >> name_031;
            cout << "Masukkan NIM: ";
            cin >> nim_031;
            cout << "Masukkan nilai: ";
            cin >> nilai_031;
            map.insert(name_031, nim_031, nilai_031);
            break;
        case 2:
            cout << "\n ===========2031 MENGHAPUS DATA MAHASISWA 2031===========" << endl;
            cout << "Masukkan nama: ";
            cin >> name_031;
            map.remove(name_031);
            break;
        case 3:
            cout << "\n ============2031 MENCARI DATA NIM MAHASISWA 2031============" << endl;
            cout << "Masukkan NIM: ";
            cin >> nim_031;
            map.searchByNIM(nim_031);
            break;
        case 4:
            cout << "\n =======2031 MENCARI DATA RENTANG NILAI MAHASISWA 2031=======" << endl;
            cout << "Masukkan nilai minimum: ";
            cin >> search1_031;
            cout << "Masukkan nilai maksimum: ";
            cin >> search2_031;
            map.CariRentangNilai(search1_031, search2_031);
            break;

        // Pilihan 5: Tampilkan data
        case 5:
            map.print();
            break;

        // Pilihan 6: Keluar
        case 6:
            break;

        // Pilihan tidak tersedia
        default:
            cout << "Pilihan tidak tersedia!" << endl;
        }
    } while (choice_031 != 6);

    return 0;
}