#include "CGI.hpp"

namespace hhpp {
	CGI::CGI() {}
	CGI::~CGI() {}

	bool CGI::isForMe(Request request) {
		(void)request;
		return (true);
	}

	std::string CGI::execute(Request request) {
		(void)request;
		return (NULL);
	}

	void CGI::addExtension(const std::string& extension) {
		(void)extension;
	}

	void CGI::setLocation(const std::string& location)
	{
		_location = location;
	}

	bool CGI::match(const std::string& query) const
	{
		for (std::vector<std::string>::iterator it; it != _extension.end(); it++) {
			std::string extension = query.substr(query.size() - (*it).size());
			if (extension == (*it))
				return true;
		}
		return false;
	}

}
