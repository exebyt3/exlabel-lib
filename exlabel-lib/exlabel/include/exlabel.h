#pragma once
#include <string>

namespace Exlabel {
	std::string extractLabel(std::string label, char separator, bool takeSeparator = 0);
	std::string findAndExtract(std::string label, std::string keyword, char separator, bool takeSeparator = 0);
}