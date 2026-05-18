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
