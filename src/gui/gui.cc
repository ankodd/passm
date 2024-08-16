#include "gui/gui.h"

#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

#include "core/user_entry.h"

void GUI::about_usr() {
  using namespace ftxui;
  const std::string username = UserEntry::name();
  const std::string path = user.path();
  const std::string is_registered =
      UserEntry::is_registered() ? "true" : "false";

  auto table = Table(
      {{"Name", "Path", "Is registered"}, {username, path, is_registered}});
  table.SelectAll().Border(LIGHT);
  table.SelectRow(0).Decorate(bold);
  table.SelectRow(0).Border(DOUBLE);

  auto doc = table.Render();
  doc |= center;
  doc |= border;
  Render(screen, doc);

  screen.Print();
}

void GUI::registration() {
  using namespace ftxui;
  std::string pass;
  auto inopt = InputOption();
  inopt.password = true;

  auto screeni = ScreenInteractive::TerminalOutput();
  auto input = Input(&pass, "Password", inopt);

  input |= CatchEvent([&](const Event& e) {
    if (pass.size() > 10) {
      if (e == Event::Return) {
        screeni.ExitLoopClosure()();
        user.setpass(pass);
        user.fopen();
        user.save();
        return true;
      }
    } else if (e == Event::Return) {
      return true;
    }
    return false;
  });

  auto component = Renderer(input, [&] {
    return vbox({hbox(text("Password:\t"), input->Render()), separator(),
                 text("Hello, your password is " + user.pass()) |
                     color(Color::DeepPink4) | center}) |
           border;
  });

  screeni.Loop(component);
}

void GUI::help() {
  std::cout << "passm\tversion 0.1\n";
  std::cout << "All commands executing only with sudo\n";
  std::cout << "Usage: passm <title>\t Display password to stdout\n";

  std::cout << "Optional settings:\n";
  std::cout << "-n <title> <password>\t Create new entry\n";
  std::cout << "-l\t\t\t Display list of passwords\n";
  std::cout << "-d <title> <password>\t Delete password\n";
  std::cout << "-g <title>\t\t Generate password and copy to clipboard\n";
  std::cout << "-c <title>\t\t Copy password to clipboard\n";
  std::cout << "--version\t\t display version\n";
}
