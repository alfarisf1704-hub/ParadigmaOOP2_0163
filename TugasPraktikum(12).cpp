// Sebuah bank digital bernama "Bank Gibran Jaya" sedang mengembangkan sistem otomatisasi
// akhir bulan untuk memproses biaya administrasi pada berbagai jenis rekening nasabah.
// Saat ini, bank memiliki dua produk utama yaitu Rekening Syariah yang menerapkan prinsip
// bebas biaya admin (saldo tetap utuh) dan Rekening Konvensional yang secara otomatis
// memotong saldo nasabah sebesar Rp 15.000 setiap bulannya. Sistem ini dirancang
// menggunakan abstract base class bernama RekeningBank dengan pure virtual function
// potongAdmin, sehingga server bank dapat memproses semua jenis rekening secara fleksibel
// hanya menggunakan pointer dari base class. Seiring perkembangan bisnis, bank meluncurkan
// produk baru bernama Rekening Premium dengan aturan potongan yang dinamis berdasarkan
// jumlah saldo nasabah. Jika saldo akhir bulan nasabah berada di atas Rp 10.000.000,
// maka nasabah tersebut dibebaskan dari biaya admin, namun jika saldonya di bawah atau
// sama dengan Rp 10.000.000, maka sistem akan memotong saldo sebesar Rp 50.000.
// Anda diminta untuk membantu tim developer Bank Gibran Jaya mengimplementasikan kelas baru
// ini ke dalam arsitektur sistem yang sudah ada.

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class RekeningBank
{
protected:
    std::string namaPemilik;
    double saldo;

public:
    RekeningBank(std::string nama, double saldoAwal)
        : namaPemilik(nama), saldo(saldoAwal) {}

    virtual ~RekeningBank() {}

    virtual void potongAdmin() = 0;

    void tampilkanInformasi() const
    {
        std::cout << "Pemilik: " << std::left << std::setw(15) << namaPemilik
                  << " | Saldo Akhir: Rp " << std::fixed << std::setprecision(0) << saldo << "\n";
    }
};

class RekeningSyariah : public RekeningBank
{
public:
    RekeningSyariah(std::string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        std::cout << "[SYSTEM] Memproses Rekening Syariah (" << namaPemilik << ") -> Bebas biaya admin.\n";
    }
};

class RekeningKonvensional : public RekeningBank
{
public:
    RekeningKonvensional(std::string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        saldo -= 15000;
        std::cout << "[SYSTEM] Memproses Rekening Konvensional (" << namaPemilik << ") -> Dipotong Rp 15.000.\n";
    }
};

class RekeningPremium : public RekeningBank
{
public:
    RekeningPremium(std::string nama, double saldoAwal)
        : RekeningBank(nama, saldoAwal) {}

    void potongAdmin() override
    {
        if (saldo > 10000000)
        {
            std::cout << "[SYSTEM] Memproses Rekening Premium (" << namaPemilik << ") -> Saldo > Rp 10jt (Bebas Biaya Admin).\n";
        }
        else
        {
            saldo -= 50000;
            std::cout << "[SYSTEM] Memproses Rekening Premium (" << namaPemilik << ") -> Saldo <= Rp 10jt (Dipotong Rp 50.000).\n";
        }
    }
};

int main()
{
    std::vector<RekeningBank *> daftarRekening;

    daftarRekening.push_back(new RekeningSyariah("Ahmad Fauzi", 5000000));
    daftarRekening.push_back(new RekeningKonvensional("Budi Santoso", 2500000));

    daftarRekening.push_back(new RekeningPremium("Citra Lestari", 15000000));

    daftarRekening.push_back(new RekeningPremium("Dedi Wijaya", 8000000));

    std::cout << "==================================================\n";
    std::cout << "         BANK GIBRAN JAYA - SALDO AWAL            \n";
    std::cout << "==================================================\n";
    for (const auto &rekening : daftarRekening)
    {
        rekening->tampilkanInformasi();
    }
    std::cout << "\n";

    std::cout << "==================================================\n";
    std::cout << "       PROSES OTOMATISASI AKHIR BULAN            \n";
    std::cout << "==================================================\n";
    for (auto &rekening : daftarRekening)
    {
        rekening->potongAdmin();
        std::cout << "\n";

        std::cout << "==================================================\n";
        std::cout << "         BANK GIBRAN JAYA - SALDO AKHIR            \n";
        std::cout << "==================================================\n";
        for (const auto &rekening : daftarRekening)
        {
            rekening->tampilkanInformasi();
        }
        std::cout << "==================================================\n";
        for (auto &rekening : daftarRekening)
        {
            delete rekening;
        }
        daftarRekening.clear();

        return 0;
    }