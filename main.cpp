#include "User.hpp"
#include "Message.hpp"
#include <fstream>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;


int main()
{

  /*подготавливаем файл, с необходимым правами по условию:
   "Сделайте это таким образом, чтобы файлы были недоступны для других пользователей,
   то есть чтобы  прочитать или записать информацию в файлы мог бы только пользователь,
   который запускает программу." */
  std::fstream users_states_file = std::fstream("users_states_file.txt", std::ios::in | std::ios::out);
  if (!users_states_file)
  {
    users_states_file = std::fstream("users_states_file.txt", std::ios::in | std::ios::out | std::ios::trunc);
    fs::permissions("users_states_file.txt", fs::perms::owner_read | fs::perms::owner_write); // Назначаем права на файл только для владельца (rwx)
  }

  if (users_states_file)
  {
    // Read file
    User user1;
    while (!users_states_file.eof()) // Цикл по условию, читаем файл пока не конец файла
    {
      user1 >> users_states_file;
      user1 << std::cout << std::endl;
    }

    users_states_file.clear(std::ios_base::goodbit);

    // Write in file
    User usr_login("Alesha_Popovich", "Alex", "Qwerty123");
    usr_login << users_states_file;
  }
  else
  {
    std::cout << "File opening failed !" << '\n';
    return 0;
  }

  // Message_file
  std::fstream msg_states_file = std::fstream("msg_states_file.txt", std::ios::in | std::ios::out);
  if (!msg_states_file)
  {
  }
  msg_states_file = std::fstream("msg_states_file.txt", std::ios::in | std::ios::out | std::ios::trunc);

  fs::permissions("msg_states_file.txt", fs::perms::owner_read | fs::perms::owner_write);

  if (msg_states_file)
  {
    // Чтение файла
    Message msg;
    while (!msg_states_file.eof())
    {
      msg >> msg_states_file;
      msg << std::cout << std::endl;
    }

    msg_states_file.clear(std::ios_base::goodbit);

    // Запишем данные в файл сообщения
    Message obj_msg1("Hello world", "Vasya", "Petya");
    obj_msg1 << msg_states_file;
  }
  else
  {
    std::cout << "File opening failed !" << '\n';
    return 0;
  }

  return 0;
}