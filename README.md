# SoalShiftSISOP20_modul4_A04
Praktikum Modul 4 Sisop 2020<br/>
05111840000051 Juwita Kartika Rani<br/>
05111840000097 Alie Husaini R.<br/>

# Soal 1
Enkripsi versi 1:<br/>
a.Jika sebuah direktori dibuat dengan awalan “encv1_”, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v1.<br/>
b.Jika sebuah direktori di-rename dengan awalan “encv1_”, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v1.<br/>
c.Apabila sebuah direktori terenkripsi di-rename menjadi tidak terenkripsi, maka isi adirektori tersebut akan terdekrip.<br/>
d.Setiap pembuatan direktori terenkripsi baru (mkdir ataupun rename) akan tercatat ke sebuah database/log berupa file.<br/>
e.Semua file yang berada dalam direktori ter enkripsi menggunakan caesar cipher dengan key.<br/>

`9(ku@AW1[Lmvgax6q5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO`<br/>

Misal kan ada file bernama “kelincilucu.jpg” dalam directory FOTO_PENTING, dan key yang dipakai adalah 10<br/>
“encv1_rahasia/FOTO_PENTING/kelincilucu.jpg” => “encv1_rahasia/ULlL@u]AlZA(/g7D.|_.Da_a.jpg<br/>
Note : Dalam penamaan file ‘/’ diabaikan, dan ekstensi tidak perlu di encrypt.<br/>

# Soal 4
a.Sebuah berkas nantinya akan terbentuk bernama "fs.log" di direktori *home* pengguna (/home/[user]/fs.log) yang berguna menyimpan daftar perintah system call yang telah dijalankan.<br/>
b.Agar nantinya pencatatan lebih rapi dan terstruktur, log akan dibagi menjadi beberapa level yaitu INFO dan WARNING.<br/>
c.Untuk log level WARNING, merupakan pencatatan log untuk syscall rmdir dan unlink.<br/>
d.Sisanya, akan dicatat dengan level INFO.<br/>
e.Format untuk logging yaitu:<br/>
`[LEVEL]::[yy][mm][dd]-[HH]:[MM]:[SS]::[CMD]::[DESC ...]`<br/>
`INFO::200419-18:29:28::MKDIR::/iz1`<br/>
`INFO::200419-18:29:33::CREAT::/iz1/yena.jpg`<br/>
`INFO::200419-18:29:33::RENAME::/iz1/yena.jpg::/iz1/yena.jpeg`<br/>

# PEMBAHASAN
![direktori](https://user-images.githubusercontent.com/56763570/80864562-5c21d600-8c38-11ea-8f03-355b918e19d3.PNG)<br/>
Deklarasi untuk direktori encv1_, array untuk menampung `9(ku@AW1[Lmvgax6q5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO`, dan key.
<br/>![exte](https://user-images.githubusercontent.com/56763570/80864659-f6821980-8c38-11ea-9bf3-d9a5810c3f51.PNG)<br/>
Digunakan untuk mengetahui  extension file.
<br/>![ekrip](https://user-images.githubusercontent.com/56763570/80864699-25988b00-8c39-11ea-80ae-c97862ab797e.PNG)
Digunakan untuk enskripsi versi 1
<br/>![dekrip](https://user-images.githubusercontent.com/56763570/80864750-77411580-8c39-11ea-8b2d-013b7eb3c1d2.PNG)<br/>
Digunakan untuk dekrip versi 1


