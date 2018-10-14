#include "ros/ros.h"
#include "chapter2_tutorials/chapter2_srv1.h"
// Belajar membuat msg dan srv file
// disini  gimana caranya membuat message sendiri dengan tools ROS

// Pertama create msg folder dulu
// isi folder nya adalah file dengan nama chapter2_msg1.msg
// Setelah selesai membuat file chapter2_msg1.msg dan mengisi file tersebut

// Langkah selanjutnya adalah edit package.xml
// aktifkan
// <build_depend>message_generation</build_depend>
// <exec_depend>message_runtime</exec_depend>
// Setelah selesai di package.xml, kemudian

// Langkah selanjutnya adalah edit si CMakeList.xml
// caranya adalah aktifkan
/*
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation    ##ini di panggil untuk example2_a.cpp saat menggunakan msg
)

add_message_files(
 FILES
 chapter2_msg1.msg
)

generate_messages(
 DEPENDENCIES
 std_msgs
)
*/
// DI ATAS ADALAH TUTORIAL TENTANG MESSAGES

// CATETAN DI ATAS DAN BAWAH BERBEDA
// SOALNYA UNTUK MEMBUAT MESSAGE TIDAK MEMBUTUHKAN FILE .cpp ATAU .py, DIA HANYA MEMBUAT FOLDER msg YGN DI DALAMNYA ADA chapter2_msg1.msg



// DI BAWAH INI ADALAH TUTORIAL TENTANG SERVICES, SRV
// Langkah-langkah untuk latihan SERVICE
// 1. Buatlah folder srv dimana file .srv nanti di simpan
// 2. Buatlah file dengan nama chapter2_srv1.srv sebegai contoh latihannya
// 3. Isi file .srv tersebut dengan
/*
int32 A
int32 B
int32 C
---
int32 sum
*/
// tanda --- untuk memisahkan antara input dan output, yg di atasnya berarti INPUT, sedangkan yang dibawahnya berarti OUTPUT
// 4. Kemudian buka file package.xml dan kemudian aktifkan bagian ini
/*
<build_depend>message_generation</build_depend>
<run_depend>message_runtime</run_depend>
*/
// 5. kemudian test dengan caranya
// $ rossrv show chapter2_tutorials/chapter2_srv1
// 6. kalau hasilnya sama dengan isi si file .srv yang ada di folder srv, berarti bikin srv nya berhasil
// 7. TERUS, abis ini ngapain
// 8. setelah persiapannya selesai, kemudian langkah selanjutnya adalah buat program service, seperti di bawah ini
// 9. Ceritanya gini, ada 2 buah node, dengan nama example2_a.cpp dan example2_b.roscpp
//    si




bool add(chapter2_tutorials::chapter2_srv1::Request &req, chapter2_tutorials::chapter2_srv1::Response &res) {
  res.sum = req.A + req.B + req.C;
  ROS_INFO("request: A=%1d, B=%1d, C=%1d", (int)req.A, (int)req.B, (int)req.C);
  ROS_INFO("sending back response: [%1d]", (int)res.sum);
  return true;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "add_3_ints_server");
  ros::NodeHandle n;
  ros::ServiceServer service = n.advertiseService("add_3_ints", add);
  ROS_INFO("Ready to add 3 ints");
  ros::spin();
  return 0;
}
