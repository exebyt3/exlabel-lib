#include <iostream>
#include <vector>
#include <Windows.h>
#include "../include/exlabel.h"

std::string Exlabel::extractLabel(std::string label, char separator, bool takeSeparator) {
	std::string filtredLabel;
	std::vector<std::string> vecLabel;

	while (true) {
		size_t endlPos = label.find('\n');

		if (endlPos != std::string::npos) {
			std::string tempLab = label.substr(0, endlPos);
			vecLabel.push_back(tempLab);
			label.erase(0, endlPos + 1);
		}
		else {
			if (!label.empty()) {
				vecLabel.push_back(label);
			}
			break;
		}
	}

	// filtering and merging
	for (int i = 0; i < vecLabel.size(); i++) {
		size_t sepPos = vecLabel[i].find(separator);
		std::string filtred = vecLabel[i].erase(0, sepPos + 1);
		vecLabel[i] = filtred;

		filtredLabel += vecLabel[i];
		if (i+1 != vecLabel.size()) // fix extra \n at the end
			filtredLabel += '\n';
	}

	return filtredLabel;
}

std::string Exlabel::findAndExtract(std::string label, std::string keyword, char separator, bool takeSeparator) {
	std::string filtredLabel;
	std::vector<std::string> vecLabel;

	while (true) {
		size_t endlPos = label.find('\n');

		if (endlPos != std::string::npos) {
			std::string tempLab = label.substr(0, endlPos);
			vecLabel.push_back(tempLab);
			label.erase(0, endlPos + 1);
		}
		else {
			if (!label.empty()) {
				vecLabel.push_back(label);
			}
			break;
		}
	}

	// finding, filtering and merging
	for (int i = 0; i < vecLabel.size(); i++) {
		size_t keywordPos = vecLabel[i].find(keyword);

		if (keywordPos != std::string::npos) {
			size_t sepPos = vecLabel[i].find(separator);
			std::string filtred = vecLabel[i].erase(0, sepPos + 1);
			vecLabel[i] = filtred;

			filtredLabel += vecLabel[i];
		}
		else {
			continue;
		}
		break;
	}

	return filtredLabel;
}