#include "leetcode.hpp"

namespace LeetCode {

SolutionDescriptor::SolutionDescriptor(const SolutionDescriptor &descriptor)
    : id{descriptor.id}, path{descriptor.path}, title{descriptor.title}, categories{descriptor.categories} {}

SolutionDescriptor::SolutionDescriptor(SolutionDescriptor &&descriptor) noexcept
    : id(descriptor.id),
      path(std::move(descriptor.path)),
      title(std::move(descriptor.title)),
      categories(std::move(descriptor.categories)) {}

SolutionDescriptor::SolutionDescriptor(const size_t id,
                                       std::string &&path,
                                       std::string &&title,
                                       std::vector<Category> &&categories)
    : id{id}, path{std::move(path)}, title{std::move(title)}, categories{std::move(categories)} {}

SolutionDescriptor &SolutionDescriptor::operator=(const SolutionDescriptor &descriptor) {
  id = descriptor.id;
  path = descriptor.path;
  title = descriptor.title;
  categories = descriptor.categories;
}

SolutionDescriptorInjector::SolutionDescriptorInjector(const size_t id,
                                                       std::string &&path,
                                                       std::string &&title,
                                                       std::vector<Category> &&categories) {
  solution_manager.append(SolutionDescriptor{id, std::move(path), std::move(title),
                                             std::move(categories)});
}

void SolutionManager::append(const SolutionDescriptor &descriptor) {
  id_solution[descriptor.id] = descriptor;
  path_solution[descriptor.path] = descriptor;
  for (auto cat : descriptor.categories) {
    const auto iter = cat_solutions.find(cat);
    if (iter == cat_solutions.cend()) {
      cat_solutions.emplace(cat, std::vector<SolutionDescriptor>());
    }
    cat_solutions[cat].push_back(descriptor);
  }
}

SolutionManager solution_manager;

}
