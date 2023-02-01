#ifndef SERVER_HPP
#define SERVER_HPP

#include <string>
#include <vector>
#include <map>
#include "IServer.hpp"
#include "CGI.hpp"
#include "Location.hpp"
#include "Redirect.hpp"
#include "ErrorPage.hpp"
#include "Request.hpp"
#include "ResponseError.hpp"
#include "ResponseFile.hpp"
#include "ResponseRedirect.hpp"

namespace hhpp {

//	TODO check la request, cree la reponse puis envoie au bon srv

	class Server : public IServer
	{

	public:

		Server();
		~Server();

		virtual void setSocket(const int socket);
		virtual void setBinding(IBinding* binding);
		virtual void setRoot(const std::string& root);
		virtual void addDomain(const std::string& domain);
		virtual void addIndex(const std::string& index);
		virtual void addRedirect(Redirect* redirect);
		virtual void addErrorPage(ErrorPage* errorpage);
		virtual void addLocation(Location* location);
		virtual void setAutoIndex(const bool autoindex);
		virtual void setAccessLog(const std::string& log);
		virtual void setClientMaxBodySize(const int max);
		virtual void addAllowedMethod(const std::string& method);
		virtual void addCGI(CGI* cgi);
		virtual void addMimeType(const std::string& mimeType, const std::string& extension);

		virtual bool isForMe(const Request& request) const;
		virtual Response treatRequest(const Request& request);

	private:

		bool isAllowedMethod(const std::string& method) const;
		Redirect* getUrlRedirect(const std::string& query) const;
		std::string getLocalPath(const std::string& query) const;

		std::string _host;
		IBinding* _binding;
		std::string _root;
		std::vector<CGI*> _cgi;
		std::map<std::string, std::string> _mimetypes;
		std::vector<std::string> _domains;
		std::vector<std::string> _indexes;
		std::vector<Location*> _locations;
		std::vector<Redirect*> _redirect;
		std::string _accessLog;
		std::vector<ErrorPage*> _errorPages;
		std::vector<std::string> _allowedMethods;
		bool _autoIndex;
		int _maxBodySize;

	};
}


#endif
