# SoalShiftSISOP20_modul4_A04
Praktikum Modul 4 Sisop 2020<br/>
05111840000051 Juwita Kartika Rani<br/>
05111840000097 Alie Husaini R.<br/>

## Soal 1
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

## Soal 4
a.Sebuah berkas nantinya akan terbentuk bernama "fs.log" di direktori *home* pengguna (/home/[user]/fs.log) yang berguna menyimpan daftar perintah system call yang telah dijalankan.<br/>
b.Agar nantinya pencatatan lebih rapi dan terstruktur, log akan dibagi menjadi beberapa level yaitu INFO dan WARNING.<br/>
c.Untuk log level WARNING, merupakan pencatatan log untuk syscall rmdir dan unlink.<br/>
d.Sisanya, akan dicatat dengan level INFO.<br/>
e.Format untuk logging yaitu:<br/>
`[LEVEL]::[yy][mm][dd]-[HH]:[MM]:[SS]::[CMD]::[DESC ...]`<br/>
`INFO::200419-18:29:28::MKDIR::/iz1`<br/>
`INFO::200419-18:29:33::CREAT::/iz1/yena.jpg`<br/>
`INFO::200419-18:29:33::RENAME::/iz1/yena.jpg::/iz1/yena.jpeg`<br/>

## PEMBAHASAN
![direktori](https://user-images.githubusercontent.com/56763570/80864562-5c21d600-8c38-11ea-8f03-355b918e19d3.PNG)<br/>
Deklarasi untuk key, direktori encv1_, array untuk menampung `9(ku@AW1[Lmvgax6q5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO`.
<br/>![exte](https://user-images.githubusercontent.com/56763570/80864659-f6821980-8c38-11ea-9bf3-d9a5810c3f51.PNG)<br/>
Digunakan untuk mengetahui  extension file.
<br/>![ekrip](https://user-images.githubusercontent.com/56763570/80864699-25988b00-8c39-11ea-80ae-c97862ab797e.PNG)<br/>
Digunakan untuk enskripsi versi 1
<br/>![dekrip](https://user-images.githubusercontent.com/56763570/80864750-77411580-8c39-11ea-8b2d-013b7eb3c1d2.PNG)<br/>
Digunakan untuk dekrip versi 1
<br/>![fslog](https://user-images.githubusercontent.com/56763570/80864803-d737bc00-8c39-11ea-9918-60e681554d87.PNG)<br/>
Digunakan untuk menyimpan daftar command system call. Command akan disimpan di file fs.log dan setiap command baru yang dilakukan ditambahkan ke file fs.log tersebut.

<br/>![runnn](https://user-images.githubusercontent.com/56763570/80865046-8de86c00-8c3b-11ea-8b4f-7e2b986fc005.jpg)<br/>
<br/>![encvgitdocument](https://user-images.githubusercontent.com/56763570/80864941-e53a0c80-8c3a-11ea-9e67-1538f63776c9.jpg)<br/>
<br/>![sbdencv1](https://user-images.githubusercontent.com/56763570/80865075-bbcdb080-8c3b-11ea-81ef-780beb901196.jpg)<br/>
## Hasil Running no.1
<br/>![runsbd](https://user-images.githubusercontent.com/56763570/80865096-dacc4280-8c3b-11ea-92ef-5b166eab6d8a.jpg)<br/>
<br/>![fuse11runn](https://user-images.githubusercontent.com/56763570/80865008-52e63880-8c3b-11ea-867f-01a4136a5541.jpg)<br/>
## Hasil Running no.4
<br/>![fsgithubfile](https://user-images.githubusercontent.com/56763570/80864993-33e7a680-8c3b-11ea-854c-14909ff86700.jpg)<br/>

