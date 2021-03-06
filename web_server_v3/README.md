Simple-Web-Server
=================
###源码阅读，注释，学习

###原作者：[eidheim](https://github.com/eidheim/Simple-Web-Server/blob/master/server_http.hpp)
###源码
    src
     |---client_http.hpp      http的客户端代码
     |---client_https.hpp     https的客户端代码
     |---server_http.hpp      http的服务器端代码
     |---server_https.hpp     https的服务器端代码 
     |---http_example.hpp   http的测试代码
     |---https_example.hpp   https的测试代码
     
###编译：
需要boost和c++11支持，同时链接:

pthread,boost_regex,boost_filesystem,boost_coroutine,,boost_thread,boost_chrono,boost_context,boost_system

https版本还需要依赖boost.ssl &open ssl
*****


A very simple, fast, multithreaded, platform independent HTTP and HTTPS server and client library implemented using C++11 and Boost.Asio. Created to be an easy way to make REST resources available from C++ applications. 

See also https://github.com/eidheim/Simple-WebSocket-Server for an easy way to make WebSocket/WebSocket Secure endpoints in C++. 

### Features

* Thread pool
* Platform independent
* HTTPS support
* HTTP persistent connection (for HTTP/1.1)
* Client supports chunked transfer encoding
* Timeouts, if any of Server::timeout_request and Server::timeout_content are >0 (default: Server::timeout_request=5 seconds, and Server::timeout_content=300 seconds)
* Simple way to add REST resources using regex for path, and anonymous functions
* Possibility to flush response to clients synchronously (Server::Response::flush).

###Usage

See http_examples.cpp or https_examples.cpp for example usage. 

See particularly the JSON-POST (using Boost.PropertyTree) and the GET /match/[number] examples, which are most relevant.

The default_resource includes example use of Server::Response::flush. 

### Dependencies

* Boost C++ libraries
* For HTTPS: OpenSSL libraries 

### Compile and run

Compile with a C++11 compliant compiler:
```
cmake .
make
```

#### HTTP

Run the server and client examples: `./http_examples`

Direct your favorite browser to for instance http://localhost:8080/

#### HTTPS

Before running the server, an RSA private key (server.key) and an SSL certificate (server.crt) must be created. Follow, for instance, the instructions given here (for a self-signed certificate): http://www.akadia.com/services/ssh_test_certificate.html

Run the server and client examples: `./https_examples`

Direct your favorite browser to for instance https://localhost:8080/

