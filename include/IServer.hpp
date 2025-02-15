#ifndef ISERVER_HPP
#define ISERVER_HPP

#include "Binding.hpp"
#include "CGI.hpp"
#include "ErrorPage.hpp"
#include "Location.hpp"
#include "MimeType.hpp"
#include "Redirect.hpp"
#include "Request.hpp"
#include "Response.hpp"

namespace hhpp
{
	class IBinding;

	class IServer
	{

	public:
		IServer(){};
		virtual ~IServer(){};

		virtual bool isForMe(const Request &request) const = 0;
		virtual void setBinding(IBinding *binding) = 0;
		virtual void setRoot(const std::string &root) = 0;
		virtual std::string getRoot() const = 0;
		virtual void addDomain(const std::string &domain) = 0;
		virtual void addIndex(const std::string &index) = 0;
		virtual void addRedirect(Redirect *redirect) = 0;
		virtual void addErrorPage(ErrorPage *errorpage) = 0;
		virtual void addLocation(Location *location) = 0;
		virtual void setAutoIndex(const bool autoindex) = 0;
		virtual void setAccessLog(const std::string &log) = 0;
		virtual void setClientMaxBodySize(const int max) = 0;
		virtual void addAllowedMethod(const std::string &method) = 0;
		virtual void addCGI(CGI *cgi) = 0;
		virtual void addMimeType(MimeType *mime) = 0;
		virtual Response *treatRequest(const Request &request) = 0;
		virtual std::vector<ErrorPage *> getErrorPages() = 0;
	};
} // namespace hhpp

#endif
