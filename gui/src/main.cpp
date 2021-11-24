// COPYING: Copyright 2017-2021 Tyler Gilbert and Stratify Labs. All rights
// reserved

#include <printer/JsonPrinter.hpp>
#include <printer/Printer.hpp>
#include <sys/Cli.hpp>
#include <var/StackString.hpp>

int main(int argc, char *argv[]) {

  sys::Cli cli(argc, argv);

  printer::Printer default_printer;
  printer::JsonPrinter json_printer;

  const auto is_json = cli.get_option("json") == "true";
  printer::Printer &printer = is_json ? json_printer : default_printer;

  //open the root object -- closes on deconstruction
  printer::Printer::Object root_object(printer, "cli");


  printer.key("name", cli.get_name())
      .key("argCount", var::NumberString(cli.count()));

  if (cli.count() > 1) {
    printer::Printer::Array args(printer, "args");
    for (auto index : api::Index(cli.count())) {
      if (index) {
        printer.key(var::NumberString(index, "[%03d]"), cli.at(index));
      }
    }
  }

  return 0;
}
