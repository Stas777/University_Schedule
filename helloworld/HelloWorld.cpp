#include <fastcgi2/component.h>
#include <fastcgi2/component_factory.h>
#include <fastcgi2/handler.h>
#include <fastcgi2/request.h>

#include <iostream>

class HelloWorldClass : virtual public fastcgi::Component, virtual public fastcgi::Handler {

public:
        HelloWorldClass(fastcgi::ComponentContext *context) :
                fastcgi::Component(context) {
        }
        virtual ~HelloWorldClass() {
        }

public:
        virtual void onLoad() {
        }
        virtual void onUnload() {
        }
        virtual void handleRequest(fastcgi::Request *request, fastcgi::HandlerContext *context) {

                //����� ����������� ��� ��������� �������

                request->setHeader("Hello-Header", "Hello World!");
        }

};

FCGIDAEMON_REGISTER_FACTORIES_BEGIN()
FCGIDAEMON_ADD_DEFAULT_FACTORY("helloworld_factory", HelloWorldClass)
FCGIDAEMON_REGISTER_FACTORIES_END()