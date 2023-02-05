#include "Header.hpp"

namespace hhpp {
	Header::Header() {}
	Header::~Header() {}

	std::string Header::get(std::string key) {
		std::map<std::string, std::string>::iterator it;
		it = _params.find(key);
		if (it != _params.end())
			return (it->second);
		return std::string();
	}

	void Header::remove(std::string key) {
		_params.erase(key);
	}

	void Header::removeAll() {
		for (mapStringStringIt it = _params.begin(); it != _params.end(); it++) {
			_params.erase(it->first);
		}
	}

	void Header::append(std::string key, std::string value) {
		_params.insert(std::make_pair(key, value));
	}

	void Header::showParams() {
		for (mapStringStringIt it = _params.begin(); it != _params.end(); it++) {
			std::cout	<< it->first << ": "
						<< it->second << std::endl;
		}
	}
}

