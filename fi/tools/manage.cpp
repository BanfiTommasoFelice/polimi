#define FMT_HEADER_ONLY

#include "filesystem"
#include "fmt/format.h"
#include "functional"
#include "iostream"
#include "regex"
#include "string"
#include "utility"
#include "vector"

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float f32;
typedef double f64;
typedef long double f80;

u64 fexp(u64 b, u64 e);
std::string find(u32 n);

u32 switcher(std::vector<std::string> haystack, std::string key);
void set_wd();
u32 new_code();
void edit(u32 n);
void compile(u32 n);
void execute(u32 n);
void loop(u32 n);

template <typename T, typename... U>
void caller(T f, U... args) {
  f(args...);
}

int main(int argc, char **argv) {
  std::vector<std::string> args(argv + 1, argv + argc);
  set_wd();
  if (args.size() == 0) return 1;
  std::vector<std::string> keys = {
    "new", "edit", "compile", "execute", "loop",
  };
  std::sort(keys.begin(), keys.end());
  auto chosen = switcher(keys, args[0]);
  if (chosen == -1)
    return 1;
  else if (keys[chosen] == "new") {
    caller(new_code);
  } else {
    if (args.size() == 1) return 1;
    auto code = std::stoi(args[1]);
    if (keys[chosen] == "edit") {
      caller(edit, code);
    } else if (keys[chosen] == "compile") {
      caller(compile, code);
    } else if (keys[chosen] == "execute") {
      caller(execute, code);
    } else if (keys[chosen] == "loop") {
      caller(loop, code);
    }
  }
  return 0;
}

u32 switcher(std::vector<std::string> haystack, std::string key) {
  u32 n     = haystack.size();
  u32 start = 0, end = n - 1;
  // TODO: optimize the search
  while (start < n && !haystack[start].starts_with(key)) start++;
  while (end >= start && !haystack[end].starts_with(key)) end--;
  if (start == n || end < start || start != end) return -1;
  return start;
}

void set_wd() {
  auto wd = std::filesystem::current_path();
  while (wd.filename() != "polimi") wd = wd.parent_path();
  wd /= "fi";
  wd /= "esercizi";
  std::filesystem::current_path(wd);
}

u64 fexp(u64 b, u64 e) {
  if (e == 0) return 1;
  if (e == 1) return b;
  if (e & 1) return b * fexp(b, e ^ 1);
  return fexp(b * b, e >> 1);
}

u32 new_code() {
  const std::regex FILE_FORMAT("\\d+\\.c");
  auto wd = std::filesystem::current_path();
  u32 old_length, new_length, n = 1;
  for (auto &entry : std::filesystem::directory_iterator(wd)) {
    if (!entry.is_regular_file()) continue;
    auto name = entry.path().filename().string();
    if (!std::regex_match(name, FILE_FORMAT)) continue;
    old_length = name.length() - 2;
    n++;
  }
  new_length = old_length;
  while (fexp(10, new_length) > n) new_length--; // FIXME: possible off-by-one
  while (fexp(10, new_length) <= n) new_length++;
  if (new_length != old_length)
    for (u32 i = 1; i < n; i++) {
      const auto new_filename = fmt::format("{:0{}d}.c", i, new_length);
      std::filesystem::rename(find(i), new_filename);
    }
  const auto new_file = fmt::format("{:0{}d}.c", n, new_length);
  std::filesystem::copy_file("base.c", new_file);
  std::cout << new_file << std::endl;
  return n;
}

std::string find(u32 n) {
  if (!n) throw;
  std::string file = fmt::format("{}.c", n);
  if (!std::filesystem::exists(file))
    for (u32 i = 1; i < 10; i++) {
      file = fmt::format("{:0{}d}.c", n, i);
      if (std::filesystem::exists(file)) break;
    }
  if (!std::filesystem::exists(file)) throw;
  return file;
}

void edit(u32 n) {
  const std::string file    = find(n);
  const std::string command = fmt::format("vim {}", file);
  system(command.c_str());
}

void compile(u32 n) {
  const std::string file   = find(n);
  constexpr const char *CC = "gcc";
  constexpr const char *CFLAGS =
      "-Wall -Wextra -Wpedantic -ansi -O3 -g -fsanitize=address,undefined";
  const std::string command = fmt::format("{} {} {}", CC, CFLAGS, file);
  while (system(command.c_str())) edit(n);
}

void execute(u32 n) {
  const std::string file = find(n);
  if (!std::filesystem::exists("./a.out")) compile(n);
  // TODO: check whether a.out is the compiled version of file
  const std::string command = "./a.out";
  system(command.c_str());
}

void loop(u32 n) {
  while (true) execute(n);
  // TODO: add a way to exit the loop
}